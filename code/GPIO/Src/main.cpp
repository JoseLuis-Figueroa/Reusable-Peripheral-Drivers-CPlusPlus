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

	GPIODriver<1> GPIOB; // Create an instance of the GPIODriver for GPIOA
	using gpiob = GPIODriver<1>;

	// Initialize and configure the GPIOB peripheral for PB6 as an Input with pull-up resistor.
	GPIOB.init(gpiob::GPIOPin::GPIO_Pin6,
			   gpiob::GPIOMode::GPIO_Input,
			   gpiob::GPIOOutputType::GPIO_PushPull,
			   gpiob::GPIOOutputSpeed::GPIO_LowSpeed,
			   gpiob::GPIOPullUpPullDown::GPIO_PullUp,
			   gpiob::GPIOAlternateFunction::GPIO_AF0);

	GPIODriver<2> GPIOC; // Create an instance of the GPIODriver for GPIOA
	using gpioc = GPIODriver<2>;

	// Initialize and configure the GPIOC peripheral for PC7 as an Alternate Function for USART6.
	GPIOC.init(gpioc::GPIOPin::GPIO_Pin7,
			   gpioc::GPIOMode::GPIO_Function,
			   gpioc::GPIOOutputType::GPIO_PushPull,
			   gpioc::GPIOOutputSpeed::GPIO_LowSpeed,
			   gpioc::GPIOPullUpPullDown::GPIO_NoPull,
			   gpioc::GPIOAlternateFunction::GPIO_AF8);

	while (true)
	{

	}


}
