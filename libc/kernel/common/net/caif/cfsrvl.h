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
#ifndef CFSRVL_H_
#define CFSRVL_H_
#include <linux/list.h>
#include <linux/stddef.h>
#include <linux/types.h>
#include <linux/kref.h>

struct cfsrvl {
 struct cflayer layer;
 bool open;
 bool phy_flow_on;
 bool modem_flow_on;
 bool supports_flowctrl;
 void (*release)(struct kref *);
 struct dev_info dev_info;
 struct kref ref;
};

struct cflayer *cfvei_create(u8 linkid, struct dev_info *dev_info);
struct cflayer *cfdgml_create(u8 linkid, struct dev_info *dev_info);
struct cflayer *cfutill_create(u8 linkid, struct dev_info *dev_info);
struct cflayer *cfvidl_create(u8 linkid, struct dev_info *dev_info);
struct cflayer *cfrfml_create(u8 linkid, struct dev_info *dev_info,
 int mtu_size);
struct cflayer *cfdbgl_create(u8 linkid, struct dev_info *dev_info);

#endif
