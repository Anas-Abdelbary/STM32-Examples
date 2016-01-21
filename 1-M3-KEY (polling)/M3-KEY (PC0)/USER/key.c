   /******************** (C) COPYRIGHT 2011 ********************
 * �ļ���  ��key.c
 * ����    ������Ӧ�ú�����        
 * ʵ��ƽ̨�� STM32������
 * Ӳ�����ӣ�-------------------------
 *          | PD12 - key2 (��ʵ��û�õ�)|
 *          | PC0  - key3             
 *          |                         |
 *           -------------------------
 * ��汾  ��ST3.5.0
 *	  
**********************************************************************************/

#include "key.h" 

 /*
 * �������� Delay
 * ����  ������ȷ����ʱ
 * ����  ����ʱ������
 * ���  ����
 */
 void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 

 /*
 * ��������Key_GPIO_Config
 * ����  �����ð����õ���I/O��
 * ����  ����
 * ���  ����
 */
void Key_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  	/*���������˿ڣ�PD12����ʱ��*/
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 

	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

 /*
 * ��������Key_Scan
 * ����  ������Ƿ��а�������
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��KEY_OFF(û���°���)��KEY_ON�����°�����
 */
u8 Key_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin)
{			
		/*����Ƿ��а������� */
   	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON ) 
	  {	   
	 	 /*��ʱ����*/
	  	Delay(10000);		
	   		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
					{	 
						/*�ȴ������ͷ� */
						while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
			 			return 	KEY_ON;	 
					}
			else
					return KEY_OFF;
		}
	else
		return KEY_OFF;
}
