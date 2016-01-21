/******************** (C) COPYRIGHT 2013 ***************************
 * �ļ���  ��led.c
 * ����    ��led Ӧ�ú�����         
 * ʵ��ƽ̨��
 * Ӳ�����ӣ�-----------------
 *          |   PE5 - LED1     |
 *          |   PE6 - LED2     |
 *         
 *           ----------------- 
 * ��汾  ��ST3.5.0   
**********************************************************************************/
#include "led.h"

/*
 * ��������LED_GPIO_Config
 * ����  ������LED�õ���I/O��
 * ����  ����
 * ���  ����
 */
void LED_GPIO_Config(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*����GPIOC������ʱ��*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE, ENABLE); 

	/*ѡ��Ҫ���Ƶ�GPIOC����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6  ;	

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��GPIOC*/
  	GPIO_Init(GPIOE, &GPIO_InitStructure);		  

	/* �ر�����led��	*/
	GPIO_SetBits(GPIOE, GPIO_Pin_5 | GPIO_Pin_6);	 
}


/******************* (C) COPYRIGHT 2013 *****END OF FILE************/
