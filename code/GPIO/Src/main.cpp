/*
 * main.cpp
 *
 *  Created on: May 12, 2026
 *      Author: figue
 */
#include "stm32f4xx.hpp"
#include "GPIO.hpp"



int main(void)
{
	GPIODriver<0> GPIOA; // Create an instance of the GPIODriver for GPIOA
	using gpioa = GPIODriver<0>;

	// Initialize and configure the GPIOA peripheral for PA5.
	GPIOA.init(gpioa::GPIOPin::GPIO_Pin5,
			   gpioa::GPIOMode::GPIO_Output,
			   gpioa::GPIOOutputType::GPIO_PushPull,
			   gpioa::GPIOOutputSpeed::GPIO_LowSpeed,
			   gpioa::GPIOPullUpPullDown::GPIO_NoPull,
			   gpioa::GPIOAlternateFunction::GPIO_AF0);

	GPIODriver<2> GPIOC; // Create an instance of the GPIODriver for GPIOB
	using gpioc = GPIODriver<2>;

	// Initialize and configure the GPIOB peripheral for PC13 as an Input.
	GPIOC.init(gpioc::GPIOPin::GPIO_Pin13,
			   gpioc::GPIOMode::GPIO_Input,
			   gpioc::GPIOOutputType::GPIO_PushPull,
			   gpioc::GPIOOutputSpeed::GPIO_LowSpeed,
			   gpioc::GPIOPullUpPullDown::GPIO_NoPull,
			   gpioc::GPIOAlternateFunction::GPIO_AF0);

	while (true)
	{
		// Read the state of PB6
		if (GPIOC.pinRead(gpioc::GPIOPin::GPIO_Pin13) == gpioc::GPIOPinState::GPIO_High)
		{
			// If PB6 is high, set PA5 to low
			GPIOA.pinWrite(gpioa::GPIOPin::GPIO_Pin5, gpioa::GPIOPinState::GPIO_Low);

		}
		else
		{
			// If PB6 is low, set PA5 to High
			GPIOA.pinWrite(gpioa::GPIOPin::GPIO_Pin5, gpioa::GPIOPinState::GPIO_High);
		}

		// Toggle the state of PA5
		GPIOA.pinToggle(gpioa::GPIOPin::GPIO_Pin5);

	}

}
