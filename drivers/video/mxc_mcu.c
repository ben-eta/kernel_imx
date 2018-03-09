/*
 * Copyright (C) 2011-2012 Freescale Semiconductor, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */
/*
 * SH-Mobile High-Definition Multimedia Interface (HDMI) driver
 * for SLISHDMI13T and SLIPHDMIT IP cores
 *
 * Copyright (C) 2010, Guennadi Liakhovetski <g.liakhovetski@gmx.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/fb.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/delay.h>
#include <linux/dma-mapping.h>
#include <linux/err.h>
#include <linux/clk.h>
#include <mach/clock.h>
#include <linux/uaccess.h>
#include <linux/cpufreq.h>
#include <linux/firmware.h>
#include <linux/kthread.h>
#include <linux/regulator/driver.h>
#include <linux/fsl_devices.h>
#include <linux/ipu.h>

#include <linux/console.h>
#include <linux/types.h>

#include <mach/mxc_edid.h>
#include "mxc/mxc_dispdrv.h"

#include <linux/mfd/mxc-hdmi-core.h>
#include <mach/mxc_hdmi.h>
#include <mach/hardware.h>
#include <linux/workqueue.h>

struct i2c_client* mcu_client;
struct delayed_work work1;

int mxc_mcu_poweroff(void)
{
	char databuf[2];
	char addrbuf[2];
	int ret;
	struct i2c_msg msgs[]={
		{mcu_client->addr,0,1,&addrbuf},
		{mcu_client->addr,I2C_M_RD,1,&databuf},
	};

	addrbuf[0] = 0xa1;
	ret = i2c_transfer(mcu_client->adapter,msgs,sizeof(msgs)/sizeof(struct i2c_msg));
	return 0;
}


static void mcu_work1(struct work_struct *w){ 
	mxc_mcu_poweroff();
} 



static int __devinit mxc_hdmi_i2c_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
	//if (!i2c_check_functionality(client->adapter,
	//			I2C_FUNC_SMBUS_BYTE | I2C_FUNC_I2C))
	//	return -ENODEV;

	printk("\n mcu_i2c_probe ...\n");	
	mcu_client = client;
	INIT_DELAYED_WORK(&work1, mcu_work1);

	return 0;
}

static int __devexit mxc_hdmi_i2c_remove(struct i2c_client *client)
{
	
	return 0;
}

static const struct i2c_device_id mxc_hdmi_i2c_id[] = {
	{ "mcu_i2c", 0 },
	{},
};
MODULE_DEVICE_TABLE(i2c, mxc_hdmi_i2c_id);

static void mcu_shutdown(struct i2c_client *client){
	schedule_delayed_work(&work1, (HZ*2)); 
}

static struct i2c_driver mxc_hdmi_i2c_driver = {
	.driver = {
		   .name = "mcu_i2c",
		   },
	.probe = mxc_hdmi_i2c_probe,
	.remove = mxc_hdmi_i2c_remove,
	.id_table = mxc_hdmi_i2c_id,
	.shutdown = mcu_shutdown
};

static int __init mxc_hdmi_i2c_init(void)
{
	return i2c_add_driver(&mxc_hdmi_i2c_driver);
}

static void __exit mxc_hdmi_i2c_exit(void)
{
	i2c_del_driver(&mxc_hdmi_i2c_driver);
}

module_init(mxc_hdmi_i2c_init);
module_exit(mxc_hdmi_i2c_exit);

MODULE_AUTHOR("Freescale Semiconductor, Inc.");
