
/*
 * Copyright (C) 2012-2014 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <mach/iomux-mx6dl.h>

static iomux_v3_cfg_t mx6dl_sabreauto_pads[] = {

	/* UART4 for debug */
	MX6DL_PAD_KEY_COL0__UART4_TXD,
	MX6DL_PAD_KEY_ROW0__UART4_RXD,
	/* USB HSIC ports use the same pin with ENET */
#ifdef CONFIG_USB_EHCI_ARC_HSIC
	/* USB H2 strobe/data pin */
	MX6DL_PAD_RGMII_TX_CTL__USBOH3_H2_STROBE,
	MX6DL_PAD_RGMII_TXC__USBOH3_H2_DATA,

	/* USB H3 strobe/data pin */
	MX6DL_PAD_RGMII_RXC__USBOH3_H3_STROBE,
	MX6DL_PAD_RGMII_RX_CTL__USBOH3_H3_DATA,
	/* ENET */
#else
	MX6DL_PAD_KEY_COL1__ENET_MDIO,
	MX6DL_PAD_KEY_COL2__ENET_MDC,
	MX6DL_PAD_RGMII_TXC__ENET_RGMII_TXC,
	MX6DL_PAD_RGMII_TD0__ENET_RGMII_TD0,
	MX6DL_PAD_RGMII_TD1__ENET_RGMII_TD1,
	MX6DL_PAD_RGMII_TD2__ENET_RGMII_TD2,
	MX6DL_PAD_RGMII_TD3__ENET_RGMII_TD3,
	MX6DL_PAD_RGMII_TX_CTL__ENET_RGMII_TX_CTL,
	MX6DL_PAD_ENET_REF_CLK__ENET_TX_CLK,
	MX6DL_PAD_RGMII_RXC__ENET_RGMII_RXC,
	MX6DL_PAD_RGMII_RD0__ENET_RGMII_RD0,
	MX6DL_PAD_RGMII_RD1__ENET_RGMII_RD1,
	MX6DL_PAD_RGMII_RD2__ENET_RGMII_RD2,
	MX6DL_PAD_RGMII_RD3__ENET_RGMII_RD3,
	MX6DL_PAD_RGMII_RX_CTL__ENET_RGMII_RX_CTL,
	/*RGMII Phy Interrupt */
	MX6DL_PAD_GPIO_19__GPIO_4_5,
#endif
	/* MCLK for csi0 */
	MX6DL_PAD_GPIO_0__CCM_CLKO,
	/*MX6DL_PAD_GPIO_3__CCM_CLKO2,i*/

	/* Android GPIO keys */
	MX6DL_PAD_SD2_CMD__GPIO_1_11, /* home */
	MX6DL_PAD_SD2_DAT3__GPIO_1_12, /* back */
	MX6DL_PAD_SD4_DAT4__GPIO_2_12, /* prog */
	MX6DL_PAD_SD4_DAT7__GPIO_2_15, /* vol up */
	MX6DL_PAD_DISP0_DAT20__GPIO_5_14, /* vol down */

	/* SD1 */
	MX6DL_PAD_SD1_CLK__USDHC1_CLK_50MHZ_40OHM,
	MX6DL_PAD_SD1_CMD__USDHC1_CMD_50MHZ_40OHM,
	MX6DL_PAD_SD1_DAT0__USDHC1_DAT0_50MHZ_40OHM,
	MX6DL_PAD_SD1_DAT1__USDHC1_DAT1_50MHZ_40OHM,
	MX6DL_PAD_SD1_DAT2__USDHC1_DAT2_50MHZ_40OHM,
	MX6DL_PAD_SD1_DAT3__USDHC1_DAT3_50MHZ_40OHM,

	/* SD1_CD and SD1_WP */
	MX6DL_PAD_GPIO_1__GPIO_1_1,
	MX6DL_PAD_CSI0_DATA_EN__GPIO_5_20,

	/* SD3 */
	MX6DL_PAD_SD3_CLK__USDHC3_CLK_50MHZ,
	MX6DL_PAD_SD3_CMD__USDHC3_CMD_50MHZ,
	MX6DL_PAD_SD3_DAT0__USDHC3_DAT0_50MHZ,
	MX6DL_PAD_SD3_DAT1__USDHC3_DAT1_50MHZ,
	MX6DL_PAD_SD3_DAT2__USDHC3_DAT2_50MHZ,
	MX6DL_PAD_SD3_DAT3__USDHC3_DAT3_50MHZ,
	MX6DL_PAD_SD3_DAT4__USDHC3_DAT4_50MHZ,
	MX6DL_PAD_SD3_DAT5__USDHC3_DAT5_50MHZ,
	MX6DL_PAD_SD3_DAT6__USDHC3_DAT6_50MHZ,
	MX6DL_PAD_SD3_DAT7__USDHC3_DAT7_50MHZ,

	/* SD3 VSelect */
	MX6DL_PAD_GPIO_18__USDHC3_VSELECT,
	/* SD3_CD and SD3_WP */
	MX6DL_PAD_NANDF_CS2__GPIO_6_15,
	MX6DL_PAD_SD2_DAT2__GPIO_1_13,

	/* ESAI */
	MX6DL_PAD_ENET_CRS_DV__ESAI1_SCKT,
	MX6DL_PAD_ENET_RXD1__ESAI1_FST,
	MX6DL_PAD_ENET_TX_EN__ESAI1_TX3_RX2,
	MX6DL_PAD_GPIO_5__ESAI1_TX2_RX3,
	MX6DL_PAD_ENET_TXD0__ESAI1_TX4_RX1,
	MX6DL_PAD_ENET_MDC__ESAI1_TX5_RX0,
	MX6DL_PAD_GPIO_17__ESAI1_TX0,
	MX6DL_PAD_NANDF_CS3__ESAI1_TX1,
	MX6DL_PAD_ENET_MDIO__ESAI1_SCKR,
	MX6DL_PAD_GPIO_9__ESAI1_FSR,
	/* esai interrupt */
	MX6DL_PAD_SD2_CLK__GPIO_1_10,

	/* I2C2 */
	MX6DL_PAD_EIM_EB2__I2C2_SCL,
	MX6DL_PAD_KEY_ROW3__I2C2_SDA,
	MX6DL_PAD_SD2_DAT0__GPIO_1_15,

	/* DISPLAY */
	MX6DL_PAD_DI0_DISP_CLK__IPU1_DI0_DISP_CLK,
	MX6DL_PAD_DI0_PIN15__IPU1_DI0_PIN15,
	MX6DL_PAD_DI0_PIN2__IPU1_DI0_PIN2,
	MX6DL_PAD_DI0_PIN3__IPU1_DI0_PIN3,
	MX6DL_PAD_DISP0_DAT0__IPU1_DISP0_DAT_0,
	MX6DL_PAD_DISP0_DAT1__IPU1_DISP0_DAT_1,
	MX6DL_PAD_DISP0_DAT2__IPU1_DISP0_DAT_2,
	MX6DL_PAD_DISP0_DAT3__IPU1_DISP0_DAT_3,
	MX6DL_PAD_DISP0_DAT4__IPU1_DISP0_DAT_4,
	MX6DL_PAD_DISP0_DAT5__IPU1_DISP0_DAT_5,
	MX6DL_PAD_DISP0_DAT6__IPU1_DISP0_DAT_6,
	MX6DL_PAD_DISP0_DAT7__IPU1_DISP0_DAT_7,
	MX6DL_PAD_DISP0_DAT8__IPU1_DISP0_DAT_8,
	MX6DL_PAD_DISP0_DAT9__IPU1_DISP0_DAT_9,
	MX6DL_PAD_DISP0_DAT10__IPU1_DISP0_DAT_10,
	MX6DL_PAD_DISP0_DAT11__IPU1_DISP0_DAT_11,
	MX6DL_PAD_DISP0_DAT12__IPU1_DISP0_DAT_12,
	MX6DL_PAD_DISP0_DAT13__IPU1_DISP0_DAT_13,
	MX6DL_PAD_DISP0_DAT14__IPU1_DISP0_DAT_14,
	MX6DL_PAD_DISP0_DAT15__IPU1_DISP0_DAT_15,
	MX6DL_PAD_DISP0_DAT16__IPU1_DISP0_DAT_16,
	MX6DL_PAD_DISP0_DAT17__IPU1_DISP0_DAT_17,
	MX6DL_PAD_DISP0_DAT18__IPU1_DISP0_DAT_18,
	MX6DL_PAD_DISP0_DAT19__IPU1_DISP0_DAT_19,
	MX6DL_PAD_DISP0_DAT21__IPU1_DISP0_DAT_21,
	/* LITE_SENS_INT_B */
	MX6DL_PAD_DISP0_DAT23__GPIO_5_17,
	/*PMIC INT*/
	MX6DL_PAD_DISP0_DAT22__GPIO_5_16,

	/* ipu1 csi0 */
	MX6DL_PAD_CSI0_DAT4__IPU1_CSI0_D_4,
	MX6DL_PAD_CSI0_DAT5__IPU1_CSI0_D_5,
	MX6DL_PAD_CSI0_DAT6__IPU1_CSI0_D_6,
	MX6DL_PAD_CSI0_DAT7__IPU1_CSI0_D_7,
	MX6DL_PAD_CSI0_DAT8__IPU1_CSI0_D_8,
	MX6DL_PAD_CSI0_DAT9__IPU1_CSI0_D_9,
	MX6DL_PAD_CSI0_DAT10__IPU1_CSI0_D_10,
	MX6DL_PAD_CSI0_DAT11__IPU1_CSI0_D_11,
	MX6DL_PAD_CSI0_DAT12__IPU1_CSI0_D_12,
	MX6DL_PAD_CSI0_DAT13__IPU1_CSI0_D_13,
	MX6DL_PAD_CSI0_DAT14__IPU1_CSI0_D_14,
	MX6DL_PAD_CSI0_DAT15__IPU1_CSI0_D_15,
	MX6DL_PAD_CSI0_DAT16__IPU1_CSI0_D_16,
	MX6DL_PAD_CSI0_DAT17__IPU1_CSI0_D_17,
	MX6DL_PAD_CSI0_DAT18__IPU1_CSI0_D_18,
	MX6DL_PAD_CSI0_DAT19__IPU1_CSI0_D_19,
	MX6DL_PAD_CSI0_VSYNC__IPU1_CSI0_VSYNC,
	MX6DL_PAD_CSI0_MCLK__IPU1_CSI0_HSYNC,
	MX6DL_PAD_CSI0_PIXCLK__IPU1_CSI0_PIXCLK,

	/* PWM3 and PMW4 */
	MX6DL_PAD_SD4_DAT1__PWM3_PWMO,
	MX6DL_PAD_SD4_DAT2__PWM4_PWMO,

	/* DISP0 RESET */
	MX6DL_PAD_EIM_WAIT__GPIO_5_0,

	/* eCompass int */
	MX6DL_PAD_EIM_EB1__GPIO_2_29,

	/* Acc int */
	MX6DL_PAD_EIM_BCLK__GPIO_6_31,

	/*  SPDIF */
	MX6DL_PAD_KEY_COL3__SPDIF_IN1,

	/* Touchscreen interrupt */
	MX6DL_PAD_EIM_EB0__GPIO_2_28,

	/* USBOTG ID pin */
	MX6DL_PAD_ENET_RX_ER__ANATOP_USBOTG_ID,

	/* VIDEO adv7180 INTRQ */
	MX6DL_PAD_ENET_RXD0__GPIO_1_27,
	/* UART 2 */
	MX6DL_PAD_GPIO_7__UART2_TXD,
	MX6DL_PAD_GPIO_8__UART2_RXD,
	MX6DL_PAD_SD4_DAT6__UART2_CTS,
	MX6DL_PAD_SD4_DAT5__UART2_RTS,

	/*USBs OC pin */
	MX6DL_PAD_EIM_WAIT__GPIO_5_0,  /*HOST1_OC*/
	MX6DL_PAD_SD4_DAT0__GPIO_2_8,  /*OTG_OC*/

	/* DISP0 I2C ENABLE*/
	MX6DL_PAD_EIM_D28__GPIO_3_28,

	/* DISP0 DET */
	MX6DL_PAD_EIM_D31__GPIO_3_31,

	/* DISP0 RESET */
	MX6DL_PAD_EIM_WAIT__GPIO_5_0,

	/* HDMI */
	MX6DL_PAD_EIM_A25__HDMI_TX_CEC_LINE,
 };

static iomux_v3_cfg_t mx6dl_sabreauto_can0_pads[] = {
	/* CAN1 */
	MX6DL_PAD_KEY_COL2__CAN1_TXCAN,
	MX6DL_PAD_KEY_ROW2__CAN1_RXCAN,
};


static iomux_v3_cfg_t mx6dl_sabreauto_can1_pads[] = {
	/* CAN2 */
	MX6DL_PAD_KEY_COL4__CAN2_TXCAN,
	MX6DL_PAD_KEY_ROW4__CAN2_RXCAN,
};

static iomux_v3_cfg_t mx6dl_sabreauto_mipi_sensor_pads[] = {
	MX6DL_PAD_CSI0_MCLK__CCM_CLKO,
};

#define MX6DL_USDHC_PAD_SETTING(id, speed)	\
mx6dl_sd##id##_##speed##mhz[] = {		\
	MX6DL_PAD_SD##id##_CLK__USDHC##id##_CLK_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_CMD__USDHC##id##_CMD_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_DAT0__USDHC##id##_DAT0_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_DAT1__USDHC##id##_DAT1_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_DAT2__USDHC##id##_DAT2_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_DAT3__USDHC##id##_DAT3_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_DAT4__USDHC##id##_DAT4_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_DAT5__USDHC##id##_DAT5_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_DAT6__USDHC##id##_DAT6_##speed##MHZ,	\
	MX6DL_PAD_SD##id##_DAT7__USDHC##id##_DAT7_##speed##MHZ,	\
}

static iomux_v3_cfg_t MX6DL_USDHC_PAD_SETTING(3, 50);
static iomux_v3_cfg_t MX6DL_USDHC_PAD_SETTING(3, 100);
static iomux_v3_cfg_t MX6DL_USDHC_PAD_SETTING(3, 200);

/* The GPMI is conflicted with SD3, so init this in the driver. */
static iomux_v3_cfg_t mx6dl_gpmi_nand[] __initdata = {
	MX6DL_PAD_NANDF_CLE__RAWNAND_CLE,
	MX6DL_PAD_NANDF_ALE__RAWNAND_ALE,
	MX6DL_PAD_NANDF_CS0__RAWNAND_CE0N,
	MX6DL_PAD_NANDF_CS1__RAWNAND_CE1N,
	MX6DL_PAD_NANDF_RB0__RAWNAND_READY0,
	MX6DL_PAD_SD4_DAT0__RAWNAND_DQS,
	MX6DL_PAD_NANDF_D0__RAWNAND_D0,
	MX6DL_PAD_NANDF_D1__RAWNAND_D1,
	MX6DL_PAD_NANDF_D2__RAWNAND_D2,
	MX6DL_PAD_NANDF_D3__RAWNAND_D3,
	MX6DL_PAD_NANDF_D4__RAWNAND_D4,
	MX6DL_PAD_NANDF_D5__RAWNAND_D5,
	MX6DL_PAD_NANDF_D6__RAWNAND_D6,
	MX6DL_PAD_NANDF_D7__RAWNAND_D7,
	MX6DL_PAD_SD4_CMD__RAWNAND_RDN,
	MX6DL_PAD_SD4_CLK__RAWNAND_WRN,
	MX6DL_PAD_NANDF_WP_B__RAWNAND_RESETN,
};

static iomux_v3_cfg_t mx6dl_i2c3_pads_rev_a[] __initdata = {
	MX6DL_PAD_GPIO_3__I2C3_SCL,
	MX6DL_PAD_GPIO_16__I2C3_SDA,
};

static iomux_v3_cfg_t mx6dl_i2c3_pads_rev_b[] __initdata = {
	MX6DL_PAD_GPIO_3__I2C3_SCL,
	MX6DL_PAD_EIM_D18__I2C3_SDA,
};
static iomux_v3_cfg_t mx6dl_tuner_pads[] __initdata = {
	MX6DL_PAD_DISP0_DAT16__AUDMUX_AUD5_TXC,
	MX6DL_PAD_DISP0_DAT18__AUDMUX_AUD5_TXFS,
	MX6DL_PAD_DISP0_DAT19__AUDMUX_AUD5_RXD,
};
static iomux_v3_cfg_t mx6dl_extra_pads_rev_b[] __initdata = {
	MX6DL_PAD_EIM_A24__GPIO_5_4,
	MX6DL_PAD_GPIO_16__ENET_ANATOP_ETHERNET_REF_OUT,
};
static iomux_v3_cfg_t mx6dl_spinor_pads[] __initdata = {
	/* eCSPI1 */
	MX6DL_PAD_EIM_D16__ECSPI1_SCLK,
	MX6DL_PAD_EIM_D17__ECSPI1_MISO,
	MX6DL_PAD_EIM_D18__ECSPI1_MOSI,
	MX6DL_PAD_EIM_D19__ECSPI1_SS1,

	MX6DL_PAD_EIM_D19__GPIO_3_19,
};

/*Bluetooth is conflicted with GMPI and NOR chips*/
static iomux_v3_cfg_t mx6dl_bluetooth_pads[] __initdata = {
	/* UART 3 */
	MX6DL_PAD_SD4_CLK__UART3_RXD,
	MX6DL_PAD_SD4_CMD__UART3_TXD,
	MX6DL_PAD_EIM_D30__UART3_CTS,
	MX6DL_PAD_EIM_EB3__UART3_RTS,
};

static iomux_v3_cfg_t mx6dl_weimnor_pads[] __initdata = {
	/* Parallel NOR */
	MX6DL_PAD_EIM_OE__WEIM_WEIM_OE,
	MX6DL_PAD_EIM_RW__WEIM_WEIM_RW,
	MX6DL_PAD_EIM_WAIT__WEIM_WEIM_WAIT,
	MX6DL_PAD_EIM_CS0__WEIM_WEIM_CS_0,
	/*Control NOR reset using gpio mode*/
	MX6DL_PAD_DISP0_DAT8__GPIO_4_29,

	MX6DL_PAD_EIM_LBA__WEIM_WEIM_LBA,
	MX6DL_PAD_EIM_BCLK__WEIM_WEIM_BCLK,
	/* Parallel Nor Data Bus */
	MX6DL_PAD_EIM_D16__WEIM_WEIM_D_16,
	MX6DL_PAD_EIM_D17__WEIM_WEIM_D_17,
	MX6DL_PAD_EIM_D18__WEIM_WEIM_D_18,
	MX6DL_PAD_EIM_D19__WEIM_WEIM_D_19,
	MX6DL_PAD_EIM_D20__WEIM_WEIM_D_20,
	MX6DL_PAD_EIM_D21__WEIM_WEIM_D_21,
	MX6DL_PAD_EIM_D22__WEIM_WEIM_D_22,
	MX6DL_PAD_EIM_D23__WEIM_WEIM_D_23,
	MX6DL_PAD_EIM_D24__WEIM_WEIM_D_24,
	MX6DL_PAD_EIM_D25__WEIM_WEIM_D_25,
	MX6DL_PAD_EIM_D26__WEIM_WEIM_D_26,
	MX6DL_PAD_EIM_D27__WEIM_WEIM_D_27,
	MX6DL_PAD_EIM_D28__WEIM_WEIM_D_28,
	MX6DL_PAD_EIM_D29__WEIM_WEIM_D_29,
	MX6DL_PAD_EIM_D30__WEIM_WEIM_D_30,
	MX6DL_PAD_EIM_D31__WEIM_WEIM_D_31,

	/* Parallel Nor 25 bit Address Bus */
	MX6DL_PAD_EIM_A24__GPIO_5_4,
	MX6DL_PAD_EIM_A23__WEIM_WEIM_A_23,
	MX6DL_PAD_EIM_A22__WEIM_WEIM_A_22,
	MX6DL_PAD_EIM_A21__WEIM_WEIM_A_21,
	MX6DL_PAD_EIM_A20__WEIM_WEIM_A_20,
	MX6DL_PAD_EIM_A19__WEIM_WEIM_A_19,
	MX6DL_PAD_EIM_A18__WEIM_WEIM_A_18,
	MX6DL_PAD_EIM_A17__WEIM_WEIM_A_17,
	MX6DL_PAD_EIM_A16__WEIM_WEIM_A_16,

	MX6DL_PAD_EIM_DA15__WEIM_WEIM_DA_A_15,
	MX6DL_PAD_EIM_DA14__WEIM_WEIM_DA_A_14,
	MX6DL_PAD_EIM_DA13__WEIM_WEIM_DA_A_13,
	MX6DL_PAD_EIM_DA12__WEIM_WEIM_DA_A_12,
	MX6DL_PAD_EIM_DA11__WEIM_WEIM_DA_A_11,
	MX6DL_PAD_EIM_DA10__WEIM_WEIM_DA_A_10,
	MX6DL_PAD_EIM_DA9__WEIM_WEIM_DA_A_9,
	MX6DL_PAD_EIM_DA8__WEIM_WEIM_DA_A_8,
	MX6DL_PAD_EIM_DA7__WEIM_WEIM_DA_A_7,
	MX6DL_PAD_EIM_DA6__WEIM_WEIM_DA_A_6,
	MX6DL_PAD_EIM_DA5__WEIM_WEIM_DA_A_5,
	MX6DL_PAD_EIM_DA4__WEIM_WEIM_DA_A_4,
	MX6DL_PAD_EIM_DA3__WEIM_WEIM_DA_A_3,
	MX6DL_PAD_EIM_DA2__WEIM_WEIM_DA_A_2,
	MX6DL_PAD_EIM_DA1__WEIM_WEIM_DA_A_1,
	MX6DL_PAD_EIM_DA0__WEIM_WEIM_DA_A_0,
};

static iomux_v3_cfg_t mx6dl_sabreauto_hdmi_ddc_pads[] = {
	MX6DL_PAD_EIM_EB2__HDMI_TX_DDC_SCL,  /* HDMI DDC SCL */
	MX6DL_PAD_KEY_ROW3__HDMI_TX_DDC_SDA, /* HDMI DDC SDA */
};

static iomux_v3_cfg_t mx6dl_sabreauto_i2c2_pads[] = {
	MX6DL_PAD_EIM_EB2__I2C2_SCL,    /* I2C2 SCL */
	MX6DL_PAD_KEY_ROW3__I2C2_SDA,   /* I2C2 SDA */
};
