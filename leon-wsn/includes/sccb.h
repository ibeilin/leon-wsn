#ifndef _SCCB_H
#define _SCCB_H

#include "gpio.h"

//#define SCCB_DDR		DDRC
//#define SCCB_PORT		PORTC
//#define SCCB_PIN		PINC


#define SCCB_CLK	1 << 0	//GPIO[8],PORTB[0]
#define SCCB_DATA	1 << 2	//GPIO[10],PORTB[2]

//#define SCCB_CLK	1<<7
//#define SCCB_DATA	1<<8

/*
#define MAKE_RB_HIGH(_x)			gpio_set(_x)
#define MAKE_RB_LOW(_x)    		gpio_clr(_x)
#define BIT_RB_READ(_x)    		gpio_read(_x)
#define CFG_READ(_x)   			gpio_make_in(_x)
#define CFG_WRITE(_x)  			gpio_make_out(_x)
*//*
#define SIO_C_SET()		gpio_set(SCCB_CLK)
#define SIO_C_CLR()		gpio_clr(SCCB_CLK)
#define SIO_D_SET()		gpio_set(SCCB_DATA)
#define SIO_D_CLR()		gpio_clr(SCCB_DATA)
#define SIO_D_IN()		gpio_make_in(SCCB_DATA)
#define SIO_D_OUT()		gpio_make_out(SCCB_DATA)
#define SIO_D_STATE()		gpio_read(SCCB_DATA)

*/

/////////////////////////////////////

// SCCB ����Ӧ��״̬��־
#define SCCB_ACK             0
#define SCCB_NACK            1

// SCCB ����ʱ�Ӷ˿ڲ���
#define SCCB_CLK_HIGH()      gpio_set(PORTB,SCCB_CLK)
#define SCCB_CLK_LOW()       gpio_clr(PORTB,SCCB_CLK)

// SCCB �������ݶ˿ڲ���
#define SCCB_DAT_HIGH()      gpio_set(PORTB,SCCB_DATA)
#define SCCB_DAT_LOW()       gpio_clr(PORTB,SCCB_DATA)

// SCCB ����ʱ�Ӷ˿ڷ���
#define SCCB_CLK_OUT()        gpio_make_out(PORTB,SCCB_CLK)
#define SCCB_CLK_IN()         gpio_make_in(PORTB,SCCB_CLK)

// SCCB �������ݶ˿ڷ���
#define SCCB_DAT_OUT()       gpio_make_out(PORTB,SCCB_DATA)
#define SCCB_DAT_IN()        gpio_make_in(PORTB,SCCB_DATA)

// SCCB �������ݶ˿ڶ�ȡ
#define SCCB_DAT_RAD()       gpio_read(PORTB,SCCB_DATA)

/* �������ƣ�SCCB_delay()
 * �����������
 * �����������
 * ����������SCCB ������ʱԼ 100us
 */
extern void SCCB_delay(void);

/* �������ƣ�SCCB_start()
 * �����������
 * �����������
 * ����������SCCB ���߷��������ź�
 */
extern void SCCB_start(void);

/* �������ƣ�SCCB_stop()
 * �����������
 * �����������
 * ����������SCCB ���߷���ֹͣ�ź�
 */
extern void SCCB_stop(void);

/* �������ƣ�SCCB_write_byte()
 * �������������
 * ���������Ӧ��״̬
 * ������������һ�ֽ�����д��SCCB ����
 */
extern int8u_t SCCB_write_byte(int8u_t data);

/* �������ƣ�SCCB_read_byte()
 * ���������Ӧ��״̬
 * �������������
 * ������������SCCB ���߶�ȡһ�ֽ�����
 */
extern int8u_t SCCB_read_byte(int8u_t ack);
#endif /* _SCCB_H */


