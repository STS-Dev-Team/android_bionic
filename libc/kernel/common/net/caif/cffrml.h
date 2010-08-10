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
#ifndef CFFRML_H_
#define CFFRML_H_
#include <net/caif/caif_layer.h>

struct cffrml;
struct cflayer *cffrml_create(u16 phyid, bool DoFCS);

#endif
