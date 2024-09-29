/*
 * Exercise5.c
 *
 *
 *
 */

#include "Exercise5.h"

int hour = 15;
int minute = 8;
int second = 50;
void updateClockBuffer() {
	LED_buffer[0] = hour / 10;
	LED_buffer[1] = hour % 10;
	LED_buffer[2] = minute / 10;
	LED_buffer[3] = minute % 10;

	update7SEG(index_LED++);
}
