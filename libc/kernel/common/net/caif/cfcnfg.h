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
#ifndef CFCNFG_H_
#define CFCNFG_H_
#include <linux/spinlock.h>
#include <linux/netdevice.h>
#include <net/caif/caif_layer.h>
#include <net/caif/cfctrl.h>

struct cfcnfg;

enum cfcnfg_phy_type {
 CFPHYTYPE_FRAG = 1,
 CFPHYTYPE_CAIF,
 CFPHYTYPE_MAX
};

enum cfcnfg_phy_preference {
 CFPHYPREF_UNSPECIFIED,
 CFPHYPREF_LOW_LAT,
 CFPHYPREF_HIGH_BW,
 CFPHYPREF_LOOP
};

struct cfcnfg *cfcnfg_create(void);

struct dev_info *cfcnfg_get_phyid(struct cfcnfg *cnfg,
 enum cfcnfg_phy_preference phy_pref);

#endif
