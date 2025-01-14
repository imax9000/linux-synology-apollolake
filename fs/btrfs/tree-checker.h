/*
 * Copyright (C) Qu Wenruo 2017.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program.
 */

#ifndef __BTRFS_TREE_CHECKER__
#define __BTRFS_TREE_CHECKER__

#include "ctree.h"
#include "extent_io.h"

/*
 * Comprehensive leaf checker.
 * Will check not only the item pointers, but also every possible member
 * in item data.
 */
int btrfs_check_leaf_full(struct extent_buffer *leaf);

/*
 * Less strict leaf checker.
 * Will only check item pointers, not reading item data.
 */
int btrfs_check_leaf_relaxed(struct extent_buffer *leaf);
int btrfs_check_node(struct extent_buffer *node);

int btrfs_check_chunk_valid(struct extent_buffer *leaf,
			    struct btrfs_chunk *chunk, u64 logical);

#endif
