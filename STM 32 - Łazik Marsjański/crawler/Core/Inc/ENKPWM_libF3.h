/*
 * ENKPWm_libF3.h
 *
 *  Created on: 08.01.2019
 *      Author: natal
 */

#ifndef INC_ENKPWM_LIBF3_H_
#define INC_ENKPWM_LIBF3_H_
#include "stm32f3xx_hal.h"

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim16;
TIM_HandleTypeDef htim17;

volatile uint32_t period_motor_1;
volatile int32_t abs_period_motor_1;
volatile int32_t f_obr_motor_1;

volatile uint32_t period_motor_2;
volatile int32_t abs_period_motor_2;
volatile int32_t f_obr_motor_2;

volatile uint32_t period_motor_3;
volatile int32_t abs_period_motor_3;
volatile int32_t f_obr_motor_3;

void ENK_Init();
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void frequency_ret(int32_t,int32_t,int32_t);
#endif /* INC_ENKPWM_LIBF3_H_ */
