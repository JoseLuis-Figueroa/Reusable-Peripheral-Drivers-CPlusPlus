/*****************************************************************************
 * @file main.c
 * @author Jose Luis Figueroa
 * @brief This is the main file for the GPIO example. It demonstrates how
 * to use the GPIODriver class to configure and control the GPIO
 * peripheral of a microcontroller.
 *
 * @version 1.0
 * @date 2026-May-12
 *
 * @copyright Copyright (c) 2026 Jose Luis Figueroa. MIT License.
 *
 *****************************************************************************/

#include "stm32f4xx.hpp"
#include "GPIO.hpp"

uint16_t readRegisterValue;


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

	GPIODriver<1> GPIOB; // Create an instance of the GPIODriver for GPIOB
	using gpiob = GPIODriver<1>;

	// Initialize and configure the GPIOB peripheral for PB6 as an Input.
	GPIOB.init(gpiob::GPIOPin::GPIO_Pin6,
			   gpiob::GPIOMode::GPIO_Output,
			   gpiob::GPIOOutputType::GPIO_PushPull,
			   gpiob::GPIOOutputSpeed::GPIO_LowSpeed,
			   gpiob::GPIOPullUpPullDown::GPIO_NoPull,
			   gpiob::GPIOAlternateFunction::GPIO_AF0);

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

		// Write a specific value to a GPIO register (for demonstration purposes).
		GPIOB.registerWrite(0x40020414, 0x00000040);

		// Read the value back from the GPIO register (for demonstration purposes).
		readRegisterValue = GPIOB.registerRead(0x40020414);

	}

}
