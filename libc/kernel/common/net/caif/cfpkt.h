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
#ifndef CFPKT_H_
#define CFPKT_H_
#include <net/caif/caif_layer.h>
#include <linux/types.h>
struct cfpkt;

struct cfpkt *cfpkt_create(u16 len);

struct cfpkt *cfpkt_create_uplink(const unsigned char *data, unsigned int len);

struct cfpkt *cfpkt_append(struct cfpkt *dstpkt, struct cfpkt *addpkt,
 u16 expectlen);

struct cfpkt *cfpkt_split(struct cfpkt *pkt, u16 pos);

struct cfpkt *cfpkt_fromnative(enum caif_direction dir, void *nativepkt);

struct cfpkt *cfpkt_dequeue(struct cfpktq *pktq);

struct cfpkt *cfpkt_qpeek(struct cfpktq *pktq);

struct cfpktq *cfpktq_create(void);

struct cfpkt *cfpkt_clone_release(struct cfpkt *pkt);

struct caif_payload_info *cfpkt_info(struct cfpkt *pkt);

#endif
