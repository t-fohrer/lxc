/*
 * lxc: linux Container library
 *
 * Copyright © 2017 Canonical Ltd.
 *
 * Authors:
 * Christian Brauner <christian.brauner@ubuntu.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __LXC_STORAGE_UTILS_H
#define __LXC_STORAGE_UTILS_H

#include "config.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "conf.h"

struct bdev;
struct lxc_conf;

extern char *dir_new_path(char *src, const char *oldname, const char *name,
			  const char *oldpath, const char *lxcpath);
extern bool attach_block_device(struct lxc_conf *conf);
extern void detach_block_device(struct lxc_conf *conf);
extern int blk_getsize(struct bdev *bdev, uint64_t *size);
extern int detect_fs(struct bdev *bdev, char *type, int len);
extern int do_mkfs_exec_wrapper(void *args);
extern int is_blktype(struct bdev *b);
extern int mount_unknown_fs(const char *rootfs, const char *target,
			    const char *options);
extern int find_fstype_cb(char *buffer, void *data);
extern char *linkderef(char *path, char *dest);
extern bool unpriv_snap_allowed(struct bdev *b, const char *t, bool snap,
				bool maybesnap);
extern bool is_valid_bdev_type(const char *type);
extern int bdev_destroy_wrapper(void *data);

#endif // __LXC_STORAGE_UTILS_H
