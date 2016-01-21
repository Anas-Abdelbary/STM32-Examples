/******************** (C) COPYRIGHT 2013 **************************
 * �ļ���  ��main.c
 * ����    ��PC0���ӵ�key2��PC0����ΪIO����ģʽ�� ��
 *           LED2=DS2״̬ȡ����         
 * ʵ��ƽ̨��STM32������
 * ��汾  ��ST3.5.0
 *	   
**********************************************************************************/

#include "stm32f10x.h"
#include "led.h"
#include "key.h"  

/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int main(void)
{ 
	/* config the sysclock to 72m */      
  SystemInit();

	/* config the led */
	LED_GPIO_Config();
	LED1( ON );
	/*config key*/
	Key_GPIO_Config();


  while(1)                            
  {	   
 	if( Key_Scan(GPIOC,GPIO_Pin_0) == KEY_ON  )
	{
			/*LED2-DS2��ת*/
		   	GPIO_WriteBit(GPIOE, GPIO_Pin_6, 
		             (BitAction)((1-GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_6))));
	}   
  }
}

/******************* (C) COPYRIGHT 2013 *****END OF FILE****/
