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
#ifndef CFMUXL_H_
#define CFMUXL_H_
#include <net/caif/caif_layer.h>

struct cfsrvl;
struct cffrml;

struct cflayer *cfmuxl_create(void);

struct cflayer *cfmuxl_remove_dnlayer(struct cflayer *layr, u8 phyid);

struct cflayer *cfmuxl_remove_uplayer(struct cflayer *layr, u8 linkid);

#endif
