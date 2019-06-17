/*
 * PWM_LIB.h
 *
 *  Created on: 20.11.2018
 *      Author: grzec
 */

#ifndef PWM_LIB_H_
#define PWM_LIB_H_

#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_tim.h"

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim15;

//void initTIM2();
void PWM_Init();
void StartMotors();
void StopMotors();
void SetPWM(int16_t counter);
#endif /* PWM_LIB_H_ */
