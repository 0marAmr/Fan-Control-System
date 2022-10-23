#include "HAL/LCD/lcd.h"
#include "HAL/Motors/DC_Motor/dc_motor.h"
#include "HAL/Sensors/lm35_temp_sensor/lm35_temp_sensor.h"
#include "MCAL/ADC/adc.h"
#include <util/delay.h>

int main(){
	uint8 temp_value;
	LCD_init();
	LM35_init();
	DcMotor_init();

	ADC_ConfigType adc_configuration = {
			.prescaler = F_CPU_8,
			.ref_volt = ADC_InternalVoltageRef
	};

	LCD_displayStringRowColumn(0,3,"FAN is");
	LCD_displayStringRowColumn(1,2,"Temp =     C");
	ADC_init(&adc_configuration);
	while(1){

		temp_value = LM35_getTemperature();
		if (temp_value<30){
			LCD_displayStringRowColumn(0,11,"OFF");
			DcMotor_off();
		}
		else{
			LCD_displayStringRowColumn(0,11,"ON ");
			if(temp_value>=120){
				DcMotor_rotate(ACW, 100);
			}
			else if(temp_value >= 90){
				DcMotor_rotate(ACW, 75);
			}
			else if(temp_value >= 60){
				DcMotor_rotate(ACW, 50);
			}
			else{
				DcMotor_rotate(ACW, 25);
			}
		}

		LCD_moveCursor(1,9);
		if(temp_value<100){
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,10);
		}
		LCD_intgerToString(temp_value);

	}
}
