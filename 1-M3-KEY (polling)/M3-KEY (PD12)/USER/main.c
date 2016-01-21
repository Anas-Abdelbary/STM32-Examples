/******************** (C) COPYRIGHT 2013 **************************
 * �ļ���  ��main.c
 * ����    ��PD12����Ϊ����ģʽ������K2 LED1 -- DS1 ��ת״̬������Ϊɨ��ģʽ        
 * ʵ��ƽ̨��STM32������
 * ��汾  ��ST3.5.0
 *
**********************************************************************************/
#include "stm32f10x.h" 
#include "led.h"
#include "key.h"  

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	/* config the led */
	LED_GPIO_Config();
	LED1( ON );

	/*config key*/
	Key_GPIO_Config();	
	
	while(1)                            
	{	   
		if( Key_Scan(GPIOD,GPIO_Pin_12) == KEY_ON  )
		{
			if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12)!= KEY_ON)
			{
				/*LED1-DS1��ת*/
				GPIO_WriteBit(GPIOE, GPIO_Pin_5, 
					(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5))));
			}
		}   
	}
}


/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
