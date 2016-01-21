/******************** (C) COPYRIGHT 2012 **************************
 * �ļ���  ��main.c
 * ����    ��LED��ˮ�ƣ�Ƶ�ʿɵ�����         
 * ʵ��ƽ̨��STM32������
 * ��汾  ��ST3.5.0
 *	
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"

//#define    MI_ERR    (-2)

void Delay(__IO u32 nCount);

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();

	while (1)
	{
		LED1( ON );			  // ��
		Delay(0x0FFFEF);
		LED1( OFF );		  // ��
		
		LED2( ON );
		Delay(0x0FFFEF);
		LED2( OFF );  		
	
	}
}

void Delay(__IO u32 nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
} 


/******************* (C) COPYRIGHT 2012 *****END OF FILE************/
