/******************** (C) COPYRIGHT 2013 **************************
 * �ļ���  ��main.c
 * ����    ��CRC(����У��)ʵ�顣����������ͨ����Ƭ���ڲ���CRCУ���·������CRCУ��
 *           ��ͨ��USART1(����1)�ڵ����ϵĳ����ն˴�ӡ������         
 * ʵ��ƽ̨��STM32������
 * ��汾  ��ST3.5.0
 * 
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "crc.h" 

extern __IO uint32_t CRCValue;
/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{
	uint8_t i = 0;
		
	/* USART1 config 115200 8-N-1 */
	USART1_Config();
	
	/* ʹ��CRCʱ�� */
	CRC_Config();
	
	printf("\r\n ����һ�� CRC(ѭ������У��)ʵ�� \r\n");
	
	/* Compute the CRC of "DataBuffer" */
	for(i=0; i<BUFFER_SIZE; i++ ) 
	{
		CRCValue = CRC_CalcBlockCRC((uint32_t *)DataBuffer, BUFFER_SIZE);
		printf("\r\n32-bit CRC У����Ϊ:0X%X\r\n", CRCValue);
	}
	printf("\r\nCRC(ѭ������У��)���Գɹ�\r\n");

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
