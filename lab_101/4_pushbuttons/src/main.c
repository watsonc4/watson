/*
 * main.c
 *
 * this is the main push button application (this code is dependent on the
 * extra shu libraries such as the pinmappings list and the clock configuration
 * library)
 *
 * author:    Alex Shenfield
 * date:      01/09/2017
 * purpose:   55-604481 embedded computer networks : lab 101
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the led to GPIO PI_1 (the inbuilt led) and the push button to PI_11 
// (the user button)
gpio_pin_t led = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t pb1 = {PA_8, GPIOA, GPIO_PIN_8};
gpio_pin_t led2 = {PI_2, GPIOI, GPIO_PIN_2};

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pins
  init_gpio(led, OUTPUT);
  init_gpio(pb1, INPUT);
  init_gpio(led2, OUTPUT);
  // loop forever ...
  while(1)
  {

		// debounce the button using as simple delay
		int buttonstate1 = read_gpio(pb1);
		HAL_Delay(75);
		int buttonstate2 = read_gpio(pb1);
		
		// combine the two readings
		int buttonstate = buttonstate1 & buttonstate2;
		
		if (buttonstate)
		{ 
			toggle_gpio(led);
		
		}
  
			
  
		
  }
}
