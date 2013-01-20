#ifndef __MACH_SUNXI_CLK_FACTORS_H
#define __MACH_SUNXI_CLK_FACTORS_H

#include <linux/clk-provider.h>
#include <linux/clkdev.h>

struct clk_factors_config {
	u8 n;
	u8 nlen;
	u8 k;
	u8 klen;
	u8 m;
	u8 mlen;
	u8 p;
	u8 plen;
};

struct clk *clk_register_factors(struct device *dev, const char *name,
				const char *parent_name,
				unsigned long flags, void __iomem *reg,
				struct clk_factors_config *config,
				void (*get_factors)(u32 *rate, u8 *n, u8 *k, u8 *m, u8 *p),
				spinlock_t *lock);
#endif
