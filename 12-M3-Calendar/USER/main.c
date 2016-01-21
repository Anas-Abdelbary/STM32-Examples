/******************** (C) COPYRIGHT 2013 **************************
 * �ļ���  ��main.c
 * ����    ����ǿ��������֧��ũ����24�����������������Ĺ��� ����ʱ����1970��ΪԪ�꣬
 *           ��32bit��ʱ��Ĵ����������е�2100�����ҡ�         
 * ʵ��ƽ̨�� STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��  
 * ��̳    �� 
 * �Ա�    ��http://gomcu.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "rtc.h"


/*ʱ��ṹ��*/
struct rtc_time systmtime;


/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int main()
{
			
	  	/* ����RTC���ж����ȼ� */
	  NVIC_Configuration();
	  USART1_Config();
	  RTC_CheckAndConfig(&systmtime);

	
	  /* Display time in infinite loop */
	  Time_Show(&systmtime);
}




/******************* (C) COPYRIGHT 2013 *****END OF FILE************/

