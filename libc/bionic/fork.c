/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the 
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include <unistd.h>
#include "pthread_internal.h"
#include "cpuacct.h"

extern int  __fork(void);
extern pthread_internal_t* __get_thread(void);

#define MAX_INTERNAL_MUTEX 16
static pthread_mutex_t fork_cb_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t* i_mutex[MAX_INTERNAL_MUTEX];
static i_mutex_tail = 0;

void __add_mutex_fork_cb(pthread_mutex_t *mutex)
{
    /*
     * NOTE:
     * 1. In most cases, pthread-atfork API will always be the first choice. This API
     *    only cover the mutexs/locks that are not able to be coped with pthread-atfork.
     *
     * 2. All mutexs added via this API, will be locked before fork in a reverse way.
     *    And acquire lock before fork will guarantee the critical section's integrity.
     *
     * 3. Add nested mutexs (more than two mutex, which are used in a nested way)
     *    via this API is quite not safe, it will fall into deadlock with very high
     *    probability, as we're not able to guarantee the oder of the mutex added.
     *
     * 4. Currently, this API will be called in malloc mutex initial process, then any
     *    other mutexs/locks should not be added here if its critical section will call
     *    such dlmalloc functions such as malloc, free, calloc, realloc, etc.
     *
     * 5. In child process, pthread_mutex_unlock will be called directly as no attributes
     *    reatained for the mutexs.
     */
    pthread_mutex_lock(&fork_cb_mutex);
    if (i_mutex_tail > (MAX_INTERNAL_MUTEX - 1)) {
        pthread_mutex_unlock(&fork_cb_mutex);
        return;
    }
    i_mutex[i_mutex_tail++] = mutex;
    pthread_mutex_unlock(&fork_cb_mutex);
}

static void mutex_before_fork(void)
{
    int i;
    pthread_mutex_lock(&fork_cb_mutex);
    for (i = i_mutex_tail-1; i >= 0; i--) {
        if (i_mutex[i])
            pthread_mutex_lock(i_mutex[i]);
    }
}

static void mutex_after_fork_parent(void)
{
    int i;
    /* Don't need fork_cb_mutex hold here */
    for (i = 0; i < i_mutex_tail; i++) {
        if (i_mutex[i])
            pthread_mutex_unlock(i_mutex[i]);
    }
    pthread_mutex_unlock(&fork_cb_mutex);
}

static void mutex_after_fork_child(void)
{
    int i;
    for (i = 0; i < i_mutex_tail; i++) {
        if (i_mutex[i])
            pthread_mutex_unlock(i_mutex[i]);
    }
    pthread_mutex_unlock(&fork_cb_mutex);
}

int  fork(void)
{
    int  ret;

    /* Posix mandates that the timers of a fork child process be
     * disarmed, but not destroyed. To avoid a race condition, we're
     * going to stop all timers now, and only re-start them in case
     * of error, or in the parent process
     */
    __timer_table_start_stop(1);
    __bionic_atfork_run_prepare();
    mutex_before_fork();

    ret = __fork();
    if (ret != 0) {  /* not a child process */
        mutex_after_fork_parent();
        __timer_table_start_stop(0);
        __bionic_atfork_run_parent();
    } else {
        mutex_after_fork_child();

        /*
         * Newly created process must update cpu accounting.
         * Call cpuacct_add passing in our uid, which will take
         * the current task id and add it to the uid group passed
         * as a parameter.
         */
        cpuacct_add(getuid());
        __bionic_atfork_run_child();

        //Adjusting kernel id and group id after a fork
        pthread_internal_t *thread = __get_thread();
        thread->kernel_id = thread->group_id = gettid();
    }
    return ret;
}
