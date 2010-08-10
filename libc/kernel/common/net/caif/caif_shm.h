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
#ifndef CAIF_SHM_H_
#define CAIF_SHM_H_

struct shmdev_layer {
 u32 shm_base_addr;
 u32 shm_total_sz;
 u32 shm_id;
 u32 shm_loopback;
 void *hmbx;
 int (*pshmdev_mbxsend) (u32 shm_id, u32 mbx_msg);
 int (*pshmdev_mbxsetup) (void *pshmdrv_cb,
 struct shmdev_layer *pshm_dev, void *pshm_drv);
 struct net_device *pshm_netdev;
};

#endif
