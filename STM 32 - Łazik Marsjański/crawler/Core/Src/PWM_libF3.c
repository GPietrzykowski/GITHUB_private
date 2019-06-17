#include <PWM_libF3.h>

void PWM_Init()
{

	   HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_1);
	   HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_2);
	   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

void StartMotors(){
	  	   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15 | GPIO_PIN_6, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);

		   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15 | GPIO_PIN_7, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
}
void StopMotors(){
	   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14 | GPIO_PIN_6, GPIO_PIN_SET);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);

	   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15 | GPIO_PIN_7, GPIO_PIN_RESET);
	   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
}
void SetPWM(int16_t counter){
	if (counter>0)
	{
		TIM1->CCR3 = counter;//motor3
		TIM1->CCR4 = 0;

		TIM1->CCR1 = counter;
		TIM1->CCR2 = 0;		//motor2

		TIM15->CCR1 = counter;//motor1
		TIM15->CCR2 = 0;
	}
	else
	{
		TIM1->CCR3= 0;//motor3
		TIM1->CCR4 = -counter;

		TIM1->CCR1 = 0;
		TIM1->CCR2 = -counter;	//motor2

		TIM15->CCR1 = 0;//motor1
		TIM15->CCR2 = -counter;
	}
}



