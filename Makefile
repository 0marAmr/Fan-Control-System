CC := avr-gcc
CC_FLAGS := -O0 -w -std=c99	 #disable optimization. disable warnings. compiler switch ISO-C
MCU := atmega32
FREQUENCY := 1000000UL
SRC_FILES := main.c .\MCAL\GPIO\gpio.c .\MCAL\ADC\adc.c .\MCAL\Timer\pwm.c .\HAL\LCD\lcd.c .\HAL\Motors\DC_Motor\dc_motor.c .\HAL\Sensors\lm35_temp_sensor\lm35_temp_sensor.c
EXECUTABLE := project3

default: compile

compile:
	@echo "Compiling.." 
	@$(CC) $(CC_FLAGS) -mmcu=$(MCU) -DF_CPU=$(FREQUENCY)  $(SRC_FILES) -o $(EXECUTABLE).elf	
	@avr-objcopy -j .text -j .data -O ihex $(EXECUTABLE).elf $(EXECUTABLE).hex
	@echo "------Program Size------"
	@avr-size --format=avr --mcu=$(MCU) $(EXECUTABLE).elf

clean:
	@echo "removing compilation files.." 
	@rm $(EXECUTABLE).elf $(EXECUTABLE).hex