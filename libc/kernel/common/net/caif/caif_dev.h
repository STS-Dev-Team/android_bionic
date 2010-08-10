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
#ifndef CAIF_DEV_H_
#define CAIF_DEV_H_

#include <net/caif/caif_layer.h>
#include <net/caif/cfcnfg.h>
#include <linux/caif/caif_socket.h>
#include <linux/if.h>

struct caif_param {
 u16 size;
 u8 data[256];
};

struct caif_connect_request {
 enum caif_protocol_type protocol;
 struct sockaddr_caif sockaddr;
 enum caif_channel_priority priority;
 enum caif_link_selector link_selector;
 int ifindex;
 struct caif_param param;
};

struct cfcnfg *get_caif_conf(void);

#endif
