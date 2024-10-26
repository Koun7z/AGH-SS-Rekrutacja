/*
 * LED.h
 *
 *  Created on: Oct 25, 2024
 *      Author: pwoli
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_

#define LED_HIGH 72U
#define LED_LOW 24U
#define LED_DIFF (LED_HIGH - LED_LOW)

struct LED_DataBuffer
{
	uint32_t G[8];
	uint32_t R[8];
	uint32_t B[8];
};

struct LED_DataBuffer LED_getColorBuffer(uint8_t R, uint8_t G, uint8_t B)
{
	struct LED_DataBuffer color;

	for(int i = 0; i < 8; i++)
	{
		uint8_t mask = 1 << i;
		color.R[7 - i] =  LED_DIFF * ((R & mask) >> i) + LED_LOW;
	}

	for(int i = 0; i < 8; i++)
	{
		uint8_t mask = 1 << i;
		color.G[7 - i] =  LED_DIFF * ((G & mask) >> i) + LED_LOW;
	}

	for(int i = 0; i < 8; i++)
	{
		uint8_t mask = 1 << i;
		color.B[7 - i] =  LED_DIFF * ((B & mask) >> i) + LED_LOW;
	}

	return color;
}

struct LED_DataBuffer LED_getResetCode()
{
	struct LED_DataBuffer color;

	for(int i = 0; i < 24; i++)
	{
		*((uint32_t*)&color + i) = 0;
	}

	return color;
}

#endif /* SRC_LED_H_ */
