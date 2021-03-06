#ifndef _OV7660_H
#define _OV7660_H

#include "gpio.h"
#include "sccb.h"
#include "led.h"

#define CHANGE_REG_NUM 320

#define OV7660_PCLK		1<<1 	//PORTB[1]==>IO_B[9]
#define OV7660_VSYNC		1<<6	//PORTB[6]==>IO_B[14]
#define OV7660_HREF		1<<7	//PORTB[7]==>IO_B[15]
#define OV7660_XCLK_EN	1<<0	//PORTE[0]:xclk高使能，低禁用
///////////////////////////////////////////////////////////////////////

// OV7660操作指令
#define OV7660_WR            0x42
#define OV7660_RD            0x43

// 帧  同步信号
#define SYNC_PIN_RD()        gpio_read(PORTB,OV7660_VSYNC)
// 行  同步信号
#define HREF_PIN_RD()        gpio_read(PORTB,OV7660_HREF)
// 像素时钟信号
#define PCLK_PIN_RD()        gpio_read(PORTB,OV7660_PCLK)

// XCLK时钟使能,PORTE[0]==>IO_A[0]
#define XCLK_EN()            gpio_set(PORTE,0)
#define XCLK_DIS()           gpio_clr(PORTE,0)

#define 	OV7670_ROW_SIZE		320//行数
#define 	OV7670_COL_SIZE		240//列数

/* 函数名称：write_OV7660_reg()
 * 输入参数：寄存器地址  数据
 * 输出参数：PASS/成功  FAIL/失败
 * 功能描述：OV7660 寄存器写操作
 */
int8u_t write_OV7660_reg(int8u_t reg_addr, int8u_t data);

/* 函数名称：read_OV7660_reg()
 * 输入参数：寄存器地址  指针
 * 输出参数：PASS/成功  FAIL/失败
 * 功能描述：
 */
int8u_t read_OV7660_reg(int8u_t reg_addr, int8u_t *reg_ptr);

/* 函数名称：OV766_device_id()
 * 输入参数：无
 * 输出参数：PASS/成功  FAIL/失败
 * 功能描述：OV7660 设备PID 检查
 */
int8u_t OV766_device_id(void);

/* 函数名称：OV7660_conf_window()
 * 输入参数：水平像素  垂直像素
 * 输出参数：无
 * 功能描述：OV7660 窗口像素设置
 */
void OV7660_conf_window(int16u_t startx, int16u_t starty,
                               int16u_t width,  int16u_t height);

/* 函数名称：OV7660_init()
 * 输入参数：无
 * 输出参数：PASS/成功  FAIL/失败
 * 功能描述：OV7660 上电复位初始化
 */
int8u_t OV7660_init(void);
void OV7660_work();
void ov7660_pin_test();

#endif /* _OV7660_H */



