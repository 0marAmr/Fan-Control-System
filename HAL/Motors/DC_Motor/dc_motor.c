/******************************************************************************
 *
 * [FILE NAME]:     dc_motor.c
 *
 * [AUTHOR]:        Omar Amr
 *
 * [DATE]:          10-10-2022
 *
 * [DESCRIPTION]:   Source file for DC Motor Driver
 *
 *******************************************************************************/

#include "../../../MCAL/GPIO/gpio.h"
#include "dc_motor.h"
#include "../../../MCAL/Timer/pwm.h"

/*Description:
 * Function to Initialize the motor:
 * 1. Setup the direction for the two motor pins.
 * 2. Stop at the DC-Motor at the beginning
 * */
void DcMotor_init(){

	/*Configure Motor pin directions as output pins*/
	GPIO_setupPinDirection(DC_MOTOR_EN_PORT_ID, DC_MOTOR_EN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, PIN_OUTPUT);

	/*Initially the motor is off */
	 DcMotor_off();
}

/*Description:
 * Rotate the DC Motor CW/ or A-CW or stop the motor.
 * Set the required duty cycle via PWM driver according to speed value.
 * */
void DcMotor_rotate(DcMotor_State state, uint8 speed){
	PWM_timer0Start(speed);
	switch (state){
	case CW:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	case ACW:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	}
}

/*Description:
 * Function that turns off the Dc Motor
 * */
void DcMotor_off(void){
	GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
}
