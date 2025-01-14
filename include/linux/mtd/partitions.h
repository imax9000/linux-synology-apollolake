#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/*
 * MTD partitioning layer definitions
 *
 * (C) 2000 Nicolas Pitre <nico@fluxnic.net>
 *
 * This code is GPL
 */

#ifndef MTD_PARTITIONS_H
#define MTD_PARTITIONS_H

#include <linux/types.h>


/*
 * Partition definition structure:
 *
 * An array of struct partition is passed along with a MTD object to
 * mtd_device_register() to create them.
 *
 * For each partition, these fields are available:
 * name: string that will be used to label the partition's MTD device.
 * size: the partition size; if defined as MTDPART_SIZ_FULL, the partition
 * 	will extend to the end of the master MTD device.
 * offset: absolute starting position within the master MTD device; if
 * 	defined as MTDPART_OFS_APPEND, the partition will start where the
 *	previous one ended; if MTDPART_OFS_NXTBLK, at the next erase block;
 *	if MTDPART_OFS_RETAIN, consume as much as possible, leaving size
 *	after the end of partition.
 * mask_flags: contains flags that have to be masked (removed) from the
 * 	master MTD flag set for the corresponding MTD partition.
 * 	For example, to force a read-only partition, simply adding
 * 	MTD_WRITEABLE to the mask_flags will do the trick.
 *
 * Note: writeable partitions require their size and offset be
 * erasesize aligned (e.g. use MTDPART_OFS_NEXTBLK).
 */

struct mtd_partition {
	const char *name;		/* identifier string */
	uint64_t size;			/* partition size */
	uint64_t offset;		/* offset within the master MTD space */
	uint32_t mask_flags;		/* master MTD flags to mask out for this partition */
	struct nand_ecclayout *ecclayout;	/* out of band layout for this partition (NAND only) */
};

#define MTDPART_OFS_RETAIN	(-3)
#define MTDPART_OFS_NXTBLK	(-2)
#define MTDPART_OFS_APPEND	(-1)
#define MTDPART_SIZ_FULL	(0)


struct mtd_info;
struct device_node;

/**
 * struct mtd_part_parser_data - used to pass data to MTD partition parsers.
 * @origin: for RedBoot, start address of MTD device
 * (for armada37xx 16.12)
 * @of_node: for OF parsers, device node containing partitioning information.
 *           This field is deprecated, as the device node should simply be
 *           assigned to the master struct device.
 * (for others)
 * @of_node: for OF parsers, device node containing partitioning information
 */
struct mtd_part_parser_data {
	unsigned long origin;
	struct device_node *of_node;
};


/*
 * Functions dealing with the various ways of partitioning the space
 */

struct mtd_part_parser {
	struct list_head list;
	struct module *owner;
	const char *name;
#if defined(MY_DEF_HERE)
	int (*parse_fn)(struct mtd_info *, const struct mtd_partition **,
#else /* MY_DEF_HERE */
	int (*parse_fn)(struct mtd_info *, struct mtd_partition **,
#endif /* MY_DEF_HERE */
			struct mtd_part_parser_data *);
#if defined(CONFIG_SYNO_LSP_RTD1619)
	void (*cleanup)(const struct mtd_partition *pparts, int nr_parts);
#endif /* CONFIG_SYNO_LSP_RTD1619 */
};

#if defined(CONFIG_SYNO_LSP_RTD1619)
/* Container for passing around a set of parsed partitions */
struct mtd_partitions {
	const struct mtd_partition *parts;
	int nr_parts;
	const struct mtd_part_parser *parser;
};

extern int __register_mtd_parser(struct mtd_part_parser *parser,
				 struct module *owner);
#define register_mtd_parser(parser) __register_mtd_parser(parser, THIS_MODULE)

#else /* CONFIG_SYNO_LSP_RTD1619 */
extern void register_mtd_parser(struct mtd_part_parser *parser);
#endif /* CONFIG_SYNO_LSP_RTD1619 */
extern void deregister_mtd_parser(struct mtd_part_parser *parser);

#if defined(CONFIG_SYNO_LSP_RTD1619)
/*
 * module_mtd_part_parser() - Helper macro for MTD partition parsers that don't
 * do anything special in module init/exit. Each driver may only use this macro
 * once, and calling it replaces module_init() and module_exit().
 */
#define module_mtd_part_parser(__mtd_part_parser) \
	module_driver(__mtd_part_parser, register_mtd_parser, \
		      deregister_mtd_parser)

#endif /* CONFIG_SYNO_LSP_RTD1619 */
int mtd_is_partition(const struct mtd_info *mtd);
int mtd_add_partition(struct mtd_info *master, const char *name,
		      long long offset, long long length);
int mtd_del_partition(struct mtd_info *master, int partno);
uint64_t mtd_get_device_size(const struct mtd_info *mtd);

#endif
