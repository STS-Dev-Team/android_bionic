/*
 * one_time_construction.cpp
 *
 * Copyright 2006 The Android Open Source Project
 *
 * This file contains C++ ABI support functions for one time
 * constructors as defined in the "Run-time ABI for the ARM Architecture"
 * section 4.4.2
 */

#include <stddef.h>
#include <sys/atomics.h>
#include <bionic_futex.h>
#include <bionic_atomic_inline.h>

// Even gcc define the GUARD_BIT, it's actually maped to byte
#define GUARD_BIT       0x00001 // Byte 0
#define GUARD_PENDING   0x00100 // Byte 1
#define GUARD_WAITING   0x10000 // Byte 2

extern "C" int __cxa_guard_acquire(int volatile * gv)
{
    // 0 -> 0x00100, return 1
    // 0x00100 -> 0x10000, wait and return 0
    // 0x10000 untouched, wait and return 0
    // 0x00001 untouched, return 0
retry:
    if (__atomic_cmpxchg(0, GUARD_PENDING, gv) == 0) {
        ANDROID_MEMBAR_FULL();
        return 1;
    }
    __atomic_cmpxchg(GUARD_PENDING, GUARD_WAITING, gv); // Indicate there is a waiter
    __futex_wait(gv, GUARD_WAITING, NULL);

    if(*gv != GUARD_BIT) // __cxa_guard_abort was called, let every thread try since there is no return code for this condition
        goto retry;

    ANDROID_MEMBAR_FULL();
    return 0;
}

extern "C" void __cxa_guard_release(int volatile * gv)
{
    // 0x00100 -> 0x00001
    // 0x10000 -> 0x00001, and wake
    ANDROID_MEMBAR_FULL();
    if (__atomic_cmpxchg(GUARD_PENDING, GUARD_BIT, gv) == 0) {
        return;
    }

    *gv = GUARD_BIT;
    __futex_wake(gv, 0x7fffffff);
}

extern "C" void __cxa_guard_abort(int volatile * gv)
{
    ANDROID_MEMBAR_FULL();
    *gv = 0;
    __futex_wake(gv, 0x7fffffff);
}
