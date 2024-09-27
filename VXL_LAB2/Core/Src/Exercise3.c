/*
 * Exercise3.c
 *
 *
 *
 */

#include "Exercise3.h"
#include "display7seg.h"

const int MAX_LED = 4;
int LED_buffer[4] = {3, 0, 9, 1};

void update7SEG (int index) {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET); // Turn off all LEDs initially
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

	// Make sure the input is in valid range
	if (index >= MAX_LED) {
		index = index % 4;
	}

    switch (index) {
    case 0:
        // Display the first 7 SEG with led_buffer [0]
    	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
    	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
    	display7SEG(LED_buffer[index]);
        break ;

    case 1:
        // Display the second 7 SEG with led_buffer [1]
    	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
    	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
    	display7SEG(LED_buffer[index]);

        break ;

    case 2:
        // Display the third 7 SEG with led_buffer [2]
    	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
    	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
    	display7SEG(LED_buffer[index]);
        break ;

    case 3:
        // Display the forth 7 SEG with led_buffer [3]
    	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
       	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
       	display7SEG(LED_buffer[index]);
        break ;

    }
}
