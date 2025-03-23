#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "oled.h"
#include "stm32f10x.h"
#include "delay.h"
#include "max6675.h"
#include "spi.h"



int main(void)
{
		delay_init();
	  max6675_init();
	  usart1_init(115200);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);						//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
		OLED_Init();			//初始化OLED  
		OLED_Clear();
	
   	float t;
	  uint16_t temperature;
		while(1){
		
     temperature = max6675_readRawValue();
    printf("the raw value is:%d\n",temperature);
	  t = max6675_readTemperature();
	  printf("the temperature is:%.2f\n",t);
			 printf("\n");
	  delay_ms(500);
		char str[20]; sprintf(str, "%.2f", t);
    //char stT[20]; sprintf(stT, "%f", temperature);
 		OLED_ShowCHinese(0,0,0);		//  WEN
		OLED_ShowCHinese(16,0,1);		//  DU
			OLED_ShowChar(32,0,':',16);	//!
			OLED_ShowString(48,0,str,16);
		OLED_ShowCHinese(80,0,2);		//SHE
		OLED_ShowCHinese(96,0,3);		//SHI
		OLED_ShowCHinese(112,0,4);		//DU
		OLED_ShowCHinese(0,2,5);		//YUAN
		OLED_ShowCHinese(16,2,6);		//SHI
		OLED_ShowCHinese(32,2,7);	//ZHI	
			OLED_ShowChar(48,2,':',16);
		OLED_ShowNum(60,2,temperature,3,16);//666
	
		
		
		}
}


