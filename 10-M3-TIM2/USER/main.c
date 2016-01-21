/******************** (C) COPYRIGHT 2013 **************************
 * �ļ���  ��main.c
 * ����    ��LED1��300ms��Ƶ����˸(��ʱ�� TIM3 ������ʱ)��        
 * ʵ��ƽ̨�� STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��  
 * ��̳    �� 
 * �Ա�    ��http://gomcu.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h" 
#include "Time_test.h"

volatile u32 time; // ms ��ʱ����

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����	
 */
int main(void)
{
	/* ����ϵͳʱ��Ϊ 72M */  
	SystemInit();

	/* led �˿����� */ 
	LED_GPIO_Config();

	/* TIM2 ��ʱ���� */
	TIM2_NVIC_Configuration();
  TIM2_Configuration();

	/* TIM2 ��ʼ��ʱ */
	START_TIME;
	
  while(1)
  {
    if ( time == 1000 ) /* 1s ʱ�䵽 */
    {
      time = 0;
			/* LED1 ȡ�� */      
			GPIO_WriteBit(GPIOE, GPIO_Pin_5, 
		               (BitAction)((1-GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5)))); 
    }        
  }
}
/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
