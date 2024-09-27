/*
 * Exercise2.c
 *
 *
 *
 */

#include "Exercise2.h"
#include "display7seg.h"
#include "softwareTimer.h"

void four7segLED() {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET); // Turn off all LEDs initially
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

    switch (status) {
	case 0:
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		display7SEG(1);
		status = 1;
		break;

	case 1:
	   	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		display7SEG(2);
		status = 2;
		break;

	case 2:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		display7SEG(3);
		status = 3;
		break;

	case 3:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG(0);
		status = 0;
		break;
	}
}
