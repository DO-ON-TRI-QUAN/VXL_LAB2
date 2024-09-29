/*
 * Exercise9.c
 *
 *
 *
 */

#include "Exercise9.h"

const int MAX_LED_MATRIX = 8;
uint8_t matrix_buffer[8] = {0x12, 0x02 , 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

void setCOL(uint8_t val) {
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, ((val >> 7) & 0x01));
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, ((val >> 6) & 0x01));
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, ((val >> 5) & 0x01));
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, ((val >> 4) & 0x01));
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, ((val >> 3) & 0x01));
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, ((val >> 2) & 0x01));
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, ((val >> 1) & 0x01));
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, ((val >> 0) & 0x01));
}

void setROW() {
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
}


void updateLEDMatrix(int index) {
	// Make sure the input is in valid range
    if (index >= MAX_LED_MATRIX) {
    	index = index % 8;
    }

    setROW();
    switch(index) {
    case 0:
    	setCOL(matrix_buffer[index]);
    	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
    	break;

    case 1:
        setCOL(matrix_buffer[index]);
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
        break;

    case 2:
        setCOL(matrix_buffer[index]);
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
        break;

    case 3:
        setCOL(matrix_buffer[index]);
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
        break;

    case 4:
        setCOL(matrix_buffer[index]);
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
        break;

    case 5:
        setCOL(matrix_buffer[index]);
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
        break;

    case 6:
        setCOL(matrix_buffer[index]);
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
        break;

    case 7:
        setCOL(matrix_buffer[index]);
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
        break;
    }
}
