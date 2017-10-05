/*
 * a_traffic_lights.c
 *
 * this is the main application skeleton for the student exercises in task 3
 *
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"
#include "random_numbers.h"

// map the led to GPIO PA8

gpio_pin_t led1 = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led2 = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led3 = {PB_15, GPIOB, GPIO_PIN_15};
gpio_pin_t led4 = {PI_2, GPIOI, GPIO_PIN_2};
gpio_pin_t led5 = {PB_8, GPIOB, GPIO_PIN_8};
gpio_pin_t led6 = {PB_9, GPIOB, GPIO_PIN_9};


// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pin
  init_gpio(led1, OUTPUT);  
  init_gpio(led2, OUTPUT);
	init_gpio(led3, OUTPUT);
	init_gpio(led4, OUTPUT);  
  init_gpio(led5, OUTPUT);
	init_gpio(led6, OUTPUT);
	int change = 0;
	int j;
	
  // loop forever ...
  while(1)
  {
		
    // toggle the led on the gpio pin
    toggle_gpio(led1);
    {
			j = 1;
		}
    // wait for 1 second
    HAL_Delay(1000);
		
    // toggle the led on the gpio pin
    toggle_gpio(led2);
    
    // wait for 1 second
    HAL_Delay(1000);
		
		// toggle the led on the gpio pin
    toggle_gpio(led3);
  
    HAL_Delay(1000);
	

    toggle_gpio(led4);
    
    // wait for 1 second
    HAL_Delay(1000);
		
    // toggle the led on the gpio pin
    toggle_gpio(led5);
    
    // wait for 1 second
    HAL_Delay(1000);
		
		// toggle the led on the gpio pin
    toggle_gpio(led6);
  
    HAL_Delay(1000);
	 
	 uint32_t rnd = (get_random_int() % 6) +	1;
	
	for ( j = 0; j <=rnd; j++ )
{
	toggle_gpio(led1) = rnd; 
	
}  







}
}
