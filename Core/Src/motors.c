/*
 * motors.c
 */

#include "motors.h"

float limitPWM(float pwm) {
	if (pwm >= PWM_MAX) {
		return PWM_MAX;
	}
	else if (pwm <= -1 * PWM_MAX) {
		return PWM_MAX;
	}
	return abs(pwm);
}

void setMotorLPWM(float pwm) {
	if (pwm > 0) {
		TIM4->CCR3 = (uint32_t) (limitPWM(pwm) * MAX_TIMER_COUNTS);
		TIM4->CCR4 = 0;
	}
	else if (pwm < 0) {
		TIM4->CCR4 = (uint32_t) (limitPWM(pwm) * MAX_TIMER_COUNTS);
		TIM4->CCR3 = 0;
	}
}

void setMotorRPWM(float pwm) {
	if (pwm > 0) {
		TIM4->CCR1 = (uint32_t) (limitPWM(pwm) * MAX_TIMER_COUNTS);
		TIM4->CCR2 = 0;
	}
	else if (pwm < 0) {
		TIM4->CCR2 = (uint32_t) (limitPWM(pwm) * MAX_TIMER_COUNTS);
		TIM4->CCR1 = 0;
	}
}

void move_forward(float pwm) {
	setMotorRPWM(pwm);
	setMotorLPWM(pwm);
}

void move_backward(float pwm) {
	setMotorRPWM(-1 * pwm);
	setMotorLPWM(-1 * pwm);
}


void resetMotors() {
	
}
