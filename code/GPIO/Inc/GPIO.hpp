/*****************************************************************************
 * @file GPIO.hpp
 * @author Jose Luis Figueroa
 * @brief The interface definition for the GPIO. This is the header file for
 * the definition of the interface for a general purpose input/output peripheral on
 * a standard microcontroller.
 *
 * @version 1.0
 * @date 2026-May-12
 *
 * @copyright Copyright (c) 2023 Jose Luis Figueroa. MIT License.
 *
 *****************************************************************************/

#ifndef GPIO_HPP_
#define GPIO_HPP_

#include "stm32f4xx.hpp"
#include <tuple>


/*****************************************************************************
 * Class Register
*//**
 *\b Description:
 * The Register class is a template class that provides an interface for accessing
 * hardware registers in a microcontroller. It allows users to read from and write
 * to specific memory addresses that correspond to hardware registers, enabling
 * direct manipulation of peripheral configurations and operations. The class is
 * designed to be flexible and can be instantiated for different types of registers
 * by specifying the data type and the register address as template parameters.
 *
 * @param T The TypeDef structure of the register, which defines the layout
 * 		   and fields of the register.
 * @param address The memory address of the register to be accessed.

*****************************************************************************/
template <typename T, uint32_t address>
class Register final {
	public:
	operator T* () const {
		return reinterpret_cast<T*>(address);
	}

	T* operator->() const {
		return operator T*();
	}
};

/*****************************************************************************
 * Class GPIODriver
*//**
*\b Description:
 * The GPIODriver class is a template class that provides an interface for configuring
 * and controlling the General Purpose Input/Output (GPIO) peripheral of a microcontroller.
 * This class allows users to set up GPIO pins for various functions such as input, output,
 * alternate function, and analog mode.
 *
 * PRE-CONDITION: The GPIOx clocks must be configured and enabled. <br>
 *
 * @param[in]   gpio_idx: The index of the GPIO peripheral to be used (0 for GPIOA,
 * 1 for GPIOB, etc.). This index is used to select the appropriate base address for
 * the GPIO registers and to enable the corresponding clock in the RCC AHB1ENR register.
 *
 * @return  void
 *
 * \b Example:
 * @code
 * GPIODriver<0> GPIO1; // Create an instance
 * @endcode
 *
*****************************************************************************/
template <uint8_t gpio_idx>
class GPIODriver final {
	// Define the GPIO base addresses for the peripheral instances.
	static constexpr std::tuple<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t> gpio_addresses = {
			mcal::reg::gpio::kGPIOA, mcal::reg::gpio::kGPIOB, mcal::reg::gpio::kGPIOC, mcal::reg::gpio::kGPIOD,
			mcal::reg::gpio::kGPIOE, mcal::reg::gpio::kGPIOH };

	// Create a Register instance for the GPIO peripheral using the specified index to select the base address.
	inline static constexpr Register<GPIO_TypeDef, std::get<gpio_idx>(gpio_addresses)> GPIO{};

	// Create a Register instance for the RCC AHB1 peripheral clock enable register.
	inline static constexpr Register<RCC_TypeDef, mcal::reg::kRccBase> RCC{};

	public:

/*****************************************************************************
* Typedefs
*****************************************************************************/
	/**
	 * Defines the possible states for a digital output pin.
	*/
	enum class GPIOPinState : uint8_t {
        GPIO_Low = 0,	/**< Defines digital state ground*/
        GPIO_High = 1	/**< Defines digital state power*/
    };

	/**
	 * Define the ports contained on the MCU device. It is used to identify the
	 * specific port GPIO to configure the register map.
	 */
	enum class GPIOPort : uint8_t {
        GPIOA = 0,	/**< Port A*/
        GPIOB = 1,	/**< Port B*/
        GPIOC = 2,	/**< Port C*/
        GPIOD = 3,	/**< Port D*/
        GPIOH = 4,	/**< Port H*/
    };

	/**
	 * Defines all the pins contained on the MCU device. It is used to set a
	 * specific bit on the ports.
	 */
	enum class GPIOPin : uint8_t {
        GPIO_Pin0 = 0,		/**< GPIO 0 */
        GPIO_Pin1 = 1,		/**< GPIO 1 */
        GPIO_Pin2 = 2,		/**< GPIO 2 */
		GPIO_Pin3 = 3,		/**< GPIO 3 */
		GPIO_Pin4 = 4,		/**< GPIO 4 */
		GPIO_Pin5 = 5,		/**< GPIO 5 */
		GPIO_Pin6 = 6,		/**< GPIO 6 */
		GPIO_Pin7 = 7,		/**< GPIO 7 */
		GPIO_Pin8 = 8,		/**< GPIO 8 */
		GPIO_Pin9 = 9,		/**< GPIO 9 */
		GPIO_Pin10 = 10,	/**< GPIO 10 */
		GPIO_Pin11 = 11,	/**< GPIO 11 */
		GPIO_Pin12 = 12,	/**< GPIO 12 */
		GPIO_Pin13 = 13,	/**< GPIO 13 */
		GPIO_Pin14 = 14,	/**< GPIO 14 */
		GPIO_Pin15 = 15,	/**< GPIO 15 */
    };

	/**
	 * Defines the mode of the GPIO pin as an input, output, alternate function
	 * and analog.
	 */
	enum class GPIOMode : uint8_t {
        GPIO_Input = 0b00,		/**< GPIO pin configured as input */
        GPIO_Output = 0b01,	    /**< GPIO pin configured as output */
		GPIO_Function = 0b10,	/**< GPIO pin configured as alternate function */
		GPIO_Analog = 0b11		/**< GPIO pin configured as analog */
    };

	/**
	 * Define the output type of the Input/output port.
	 */
	enum class GPIOOutputType : uint8_t {
        GPIO_PushPull = 0,	/**< Output type push-pull */
        GPIO_OpenDrain = 1	/**< Output type open-drain */
    };

	/**
	 * Defines the output speed settings available
	 */
	enum class GPIOOutputSpeed : uint8_t {
        GPIO_LowSpeed = 0b00,		/**< Output speed low */
        GPIO_MediumSpeed = 0b01,	/**< Output speed medium */
        GPIO_HighSpeed = 0b10,		/**< Output speed high */
        GPIO_VerySpeed = 0b11		/**< Output speed very */
    };

	/**
	 * Defines the possible states of the channel pull-ups.
	 */
	enum class GPIOPullUpPullDown : uint8_t {
        GPIO_NoPull = 0b00,		/**< No pull-up or pull-down */
        GPIO_PullUp = 0b01,		/**< Pull-up resistor enabled */
        GPIO_PullDown = 0b10	/**< Pull-down resistor enabled */
    };

	/**
	 * Defines the possible DIO alternate function. A multiplexer is used to
	 * select the alternate function
	 */
	enum class GPIOAlternateFunction : uint8_t {
        GPIO_AF0 = 0b0000,		/**< Alternate function AF0 */
        GPIO_AF1 = 0b0001,		/**< Alternate function AF1 */
        GPIO_AF2 = 0b0010,		/**< Alternate function AF2 */
        GPIO_AF3 = 0b0011,		/**< Alternate function AF3 */
        GPIO_AF4 = 0b0100,		/**< Alternate function AF4 */
        GPIO_AF5 = 0b0101,		/**< Alternate function AF5 */
        GPIO_AF6 = 0b0110,		/**< Alternate function AF6 */
        GPIO_AF7 = 0b0111,		/**< Alternate function AF7 */
        GPIO_AF8 = 0b1000,		/**< Alternate function AF8 */
        GPIO_AF9 = 0b1001,		/**< Alternate function AF9 */
        GPIO_AF10 = 0b1010,     /**< Alternate function AF10 */
        GPIO_AF11 = 0b1011,     /**< Alternate function AF11 */
        GPIO_AF12 = 0b1100,     /**< Alternate function AF12 */
        GPIO_AF13 = 0b1101,     /**< Alternate function AF13 */
        GPIO_AF14 = 0b1110,     /**< Alternate function AF14 */
        GPIO_AF15 = 0b1111      /**< Alternate function AF15 */
    };

	// Constructor to enable the clock for the specified GPIO peripheral.
	GPIODriver() {
    }

/*****************************************************************************
 * Function gpio_config
*//**
*\b Description:
 * The gpio_config function is responsible for initializing and configuring the
 * GPIO peripheral based on the template parameters provided during the instantiation
 * of the GPIODriver class. This function sets up the GPIO pins according to
 * the specified configuration, which may include setting the mode (input,
 * output, alternate function, or analog), output type (push-pull or open-drain),
 * output speed, and pull-up/pull-down resistors. The configuration is determined
 * by the template parameters defined in the GPIODriver class, which specify
 * the number of channels, resolution, and GPIO index.
 *
 * PRE-CONDITION: The GPIOx and ADCx clocks must be configured and enabled. <br>
 * PRE-CONDITION: The GPIO class must be instantiated with valid template parameters
 * 				  for the number of channels, resolution, and GPIO index before
 * 				  calling this function. <br>
 *
 * POST-CONDITION: The GPIO peripheral is initialized and configured according to the
 * 				   template parameters.
 *
 * @param  void
 * @return void
 *
 * \b Example:
 * @code
 * GPIODriver<0> GPIO1; // Create an instance
 * gpio.gpio_config(); // Initialize and configure the GPIO peripheral
 * @endcode
 *
*****************************************************************************/
	void gpio_config(){
		// Enable the clock for the specified GPIO peripheral in the RCC AHB1ENR register.
		RCC->AHB1ENR |= (1U << 0);

		// Set PA5 as output
		GPIO->MODER |= (1U<<10);
		GPIO->MODER &=~(1U<<11);


		GPIO->ODR ^= (1U << 5); // Toggle PA5

	}


};

#endif /* GPIO_HPP_ */
