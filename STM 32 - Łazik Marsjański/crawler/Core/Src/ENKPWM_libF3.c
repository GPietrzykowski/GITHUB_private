/*
 * ENKPWM_libF3.c
 *
 *  Created on: 08.01.2019
 *      Author: natal
 */
#include "ENKPWM_libF3.h"

void ENK_Init(){

	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_Base_Start(&htim16);
	HAL_TIM_Base_Start(&htim17);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
	HAL_TIM_IC_Start_IT(&htim16, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim17, TIM_CHANNEL_1);
	__HAL_TIM_ENABLE_IT(&htim2, TIM_IT_UPDATE);
	__HAL_TIM_ENABLE_IT(&htim16, TIM_IT_UPDATE);
	__HAL_TIM_ENABLE_IT(&htim17, TIM_IT_UPDATE);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{

	 if (htim->Instance==TIM2)
	  {
		 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == SET)
		 {
			 abs_period_motor_1 = period_motor_1;
		 }
		 else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == RESET)
		 {
			 abs_period_motor_1 = - period_motor_1;
		 }
		 __HAL_TIM_SET_COUNTER(&htim2, 0);
		 period_motor_1 = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_2);

	  }

	 if (htim->Instance==TIM16)
		  {
			 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10) == SET)
			 {
				 abs_period_motor_2 = period_motor_2;
			 }
			 else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10) == RESET)
			 {
				 abs_period_motor_2 = - period_motor_2;
			 }
			 __HAL_TIM_SET_COUNTER(&htim16, 0);
			 period_motor_2 = HAL_TIM_ReadCapturedValue(&htim16, TIM_CHANNEL_1);

		  }

	 if (htim->Instance==TIM17)
		  {
			 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11) == SET)
			 {
				 abs_period_motor_3 = period_motor_3;
			 }
			 else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11) == RESET)
			 {
				 abs_period_motor_3 = - period_motor_3;
			 }
			 __HAL_TIM_SET_COUNTER(&htim17, 0);
			 period_motor_3 = HAL_TIM_ReadCapturedValue(&htim17, TIM_CHANNEL_1);

		  }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	 if (htim->Instance==TIM2)
	  {
		 period_motor_1 = 0;
		 abs_period_motor_1 = 0;
	  }
	 if (htim->Instance==TIM16)
	  {
		 period_motor_2 = 0;
		 abs_period_motor_2 = 0;
	  }
	 if (htim->Instance==TIM17)
	  {
		 period_motor_3 = 0;
		 abs_period_motor_3 = 0;
	  }
}
void frequency_ret(int32_t abs_period1,int32_t abs_period2, int32_t abs_period3){
	int32_t pres = 10;
	int32_t freq = 8000000;
	f_obr_motor_1 = freq*50/(abs_period1*pres*64);
	f_obr_motor_2 = freq*50/(abs_period2*pres*64);
	f_obr_motor_3 = freq*50/(abs_period3*pres*64);
	return 0;
}
