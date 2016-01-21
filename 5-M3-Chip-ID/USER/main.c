/******************** (C) COPYRIGHT 2013 **************************
 * �ļ���  ��main.c
 * ����    ����ȡCPU��96bit ID �� flash�Ĵ�С����ͨ��USART1�ӳ����ն˴�ӡ������
 *           �Ӵ��ڿɿ�����Ϣ��
 *           оƬ��ΨһIDΪ: 43038438-33324332-547EFF39
 *           оƬflash������Ϊ: 512K         
 * ʵ��ƽ̨��STM32������
 * ��汾  ��ST3.5.0
 *

**********************************************************************************/
#include "stm32f10x.h"
#include "chipid.h"
#include "usart1.h"

extern uint32_t ChipUniqueID[3];
/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	/* USART1 config 115200 8-N-1 */
	USART1_Config();

	/* to get the chipid and put it in ChipUniqueID[3] */
	Get_ChipID();	
	
	/* printf the chipid */
	printf("\r\nоƬ��ΨһIDΪ: %X-%X-%X\r\n",
	        ChipUniqueID[0],ChipUniqueID[1],ChipUniqueID[2]);
	
	/* printf the flash memory amount */
	printf("\r\nоƬflash������Ϊ: %dK \r\n", *(__IO u16 *)(0X1FFFF7E0));

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
