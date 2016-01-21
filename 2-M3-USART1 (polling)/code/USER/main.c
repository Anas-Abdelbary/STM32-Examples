/******************** (C) COPYRIGHT 2013 **************************
 * �ļ���  ��main.c
 * ����    ����c���е�printf()����ʵ�ֵ�����1(USART1)���������ǾͿ�����printf()��
 *           ������Ϣͨ�����ڴ�ӡ�������ϡ�         
 * ʵ��ƽ̨��STM32������
 * ��汾  ��ST3.5.0
 *	   
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"

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
	
	printf("\r\n this is a printf demo \r\n");

	printf("\r\n ��ӭʹ��STM32-M3ʵ���:) \r\n");
		
	USART1_printf(USART1, "\r\n This is a USART1_printf demo \r\n");
	
	USART1_printf(USART1, "\r\n ("__DATE__ " - " __TIME__ ") \r\n");

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
