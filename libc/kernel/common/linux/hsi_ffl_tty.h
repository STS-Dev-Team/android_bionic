/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _HSI_FFL_TTY_H
#define _HSI_FFL_TTY_H

#include <linux/ioctl.h>

enum {
 HU_TIMEOUT = 1,
 HU_RESET = 2,
 HU_COREDUMP = 4,
};

struct hsi_ffl_stats {
 unsigned long long data_sz;
 unsigned int frame_cnt;
 unsigned int overflow_cnt;
};

#define FFL_TTY_MAGIC 0x77

#define FFL_TTY_RESET_TX _IO(FFL_TTY_MAGIC, 0)

#define FFL_TTY_RESET_RX _IO(FFL_TTY_MAGIC, 1)

#define FFL_TTY_GET_TX_STATE _IOR(FFL_TTY_MAGIC, 2, unsigned int)

#define FFL_TTY_GET_RX_STATE _IOR(FFL_TTY_MAGIC, 3, unsigned int)

#define FFL_TTY_MODEM_RESET _IO(FFL_TTY_MAGIC, 4)

#define FFL_TTY_MODEM_STATE _IOR(FFL_TTY_MAGIC, 5, int)

#define FFL_TTY_GET_HANGUP_REASON _IOR(FFL_TTY_MAGIC, 6, int)

#define FFL_TTY_SET_TX_WAIT_MAX _IOW(FFL_TTY_MAGIC, 8, unsigned int)

#define FFL_TTY_GET_TX_WAIT_MAX _IOR(FFL_TTY_MAGIC, 8, unsigned int)

#define FFL_TTY_SET_RX_WAIT_MAX _IOW(FFL_TTY_MAGIC, 9, unsigned int)

#define FFL_TTY_GET_RX_WAIT_MAX _IOR(FFL_TTY_MAGIC, 9, unsigned int)

#define FFL_TTY_SET_TX_CTRL_MAX _IOW(FFL_TTY_MAGIC, 10, unsigned int)

#define FFL_TTY_GET_TX_CTRL_MAX _IOR(FFL_TTY_MAGIC, 10, unsigned int)

#define FFL_TTY_SET_RX_CTRL_MAX _IOW(FFL_TTY_MAGIC, 11, unsigned int)

#define FFL_TTY_GET_RX_CTRL_MAX _IOR(FFL_TTY_MAGIC, 11, unsigned int)

#define FFL_TTY_SET_TX_DELAY _IOW(FFL_TTY_MAGIC, 12, unsigned int)

#define FFL_TTY_GET_TX_DELAY _IOR(FFL_TTY_MAGIC, 12, unsigned int)

#define FFL_TTY_SET_RX_DELAY _IOW(FFL_TTY_MAGIC, 13, unsigned int)

#define FFL_TTY_GET_RX_DELAY _IOR(FFL_TTY_MAGIC, 13, unsigned int)

#define FFL_TTY_SET_TX_FLOW _IOW(FFL_TTY_MAGIC, 16, unsigned int)

#define FFL_TTY_GET_TX_FLOW _IOR(FFL_TTY_MAGIC, 16, unsigned int)

#define FFL_TTY_SET_RX_FLOW _IOW(FFL_TTY_MAGIC, 17, unsigned int)

#define FFL_TTY_GET_RX_FLOW _IOR(FFL_TTY_MAGIC, 17, unsigned int)

#define FFL_TTY_SET_TX_MODE _IOW(FFL_TTY_MAGIC, 18, unsigned int)

#define FFL_TTY_GET_TX_MODE _IOR(FFL_TTY_MAGIC, 18, unsigned int)

#define FFL_TTY_SET_RX_MODE _IOW(FFL_TTY_MAGIC, 19, unsigned int)

#define FFL_TTY_GET_RX_MODE _IOR(FFL_TTY_MAGIC, 19, unsigned int)

#define FFL_TTY_SET_TX_CHANNELS _IOW(FFL_TTY_MAGIC, 20, unsigned int)

#define FFL_TTY_GET_TX_CHANNELS _IOR(FFL_TTY_MAGIC, 20, unsigned int)

#define FFL_TTY_SET_RX_CHANNELS _IOW(FFL_TTY_MAGIC, 21, unsigned int)

#define FFL_TTY_GET_RX_CHANNELS _IOR(FFL_TTY_MAGIC, 21, unsigned int)

#define FFL_TTY_SET_TX_CHANNEL _IOW(FFL_TTY_MAGIC, 22, unsigned int)

#define FFL_TTY_GET_TX_CHANNEL _IOR(FFL_TTY_MAGIC, 22, unsigned int)

#define FFL_TTY_SET_RX_CHANNEL _IOW(FFL_TTY_MAGIC, 23, unsigned int)

#define FFL_TTY_GET_RX_CHANNEL _IOR(FFL_TTY_MAGIC, 23, unsigned int)

#define FFL_TTY_SET_TX_FRAME_LEN _IOW(FFL_TTY_MAGIC, 24, unsigned int)

#define FFL_TTY_GET_TX_FRAME_LEN _IOR(FFL_TTY_MAGIC, 24, unsigned int)

#define FFL_TTY_SET_RX_FRAME_LEN _IOW(FFL_TTY_MAGIC, 25, unsigned int)

#define FFL_TTY_GET_RX_FRAME_LEN _IOR(FFL_TTY_MAGIC, 25, unsigned int)

#define FFL_TTY_SET_TX_ARB_MODE _IOW(FFL_TTY_MAGIC, 28, unsigned int)

#define FFL_TTY_GET_TX_ARB_MODE _IOR(FFL_TTY_MAGIC, 28, unsigned int)

#define FFL_TTY_SET_TX_FREQUENCY _IOW(FFL_TTY_MAGIC, 30, unsigned int)

#define FFL_TTY_GET_TX_FREQUENCY _IOR(FFL_TTY_MAGIC, 30, unsigned int)

#define FFL_TTY_RESET_TX_STATS _IO(FFL_TTY_MAGIC, 32)

#define FFL_TTY_GET_TX_STATS _IOR(FFL_TTY_MAGIC, 32,   struct hsi_ffl_stats)

#define FFL_TTY_RESET_RX_STATS _IO(FFL_TTY_MAGIC, 33)

#define FFL_TTY_GET_RX_STATS _IOR(FFL_TTY_MAGIC, 33,   struct hsi_ffl_stats)

#endif


