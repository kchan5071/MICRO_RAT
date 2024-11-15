/*
 * start_button.c
 *
 *  Created on: Nov 15, 2024
 *      Author: kzc
 */

#include "start_button.h"

void wait_for_start_button() {
	GPIO_PinState enabled = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	while (enabled == GPIO_PIN_SET) {

		enabled = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	}
}


