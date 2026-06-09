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
 * @copyright Copyright (c) 2026 Jose Luis Figueroa. MIT License.
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
 *
 * @param[in] gpio_idx: The index of the GPIO peripheral to be used (GPIOA =0,
 * GPIOB = 1, GPIOC = 2, GPIOD = 3, GPIOE = 4, GPIOH = 5). This index is used to
 * select the appropriate base address for the GPIO registers and to enable the
 * corresponding clock in the RCC AHB1ENR register.
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
	enum class GPIOPinState : uint32_t {
        GPIO_Low = 0,	/**< Defines digital state ground*/
        GPIO_High = 1	/**< Defines digital state power*/
    };

	/**
	 * Define the ports contained on the MCU device. It is used to identify the
	 * specific port GPIO to configure the register map.
	 */
	enum class GPIOPort : uint32_t {
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
	enum class GPIOPin : uint32_t {
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
	enum class GPIOMode : uint32_t {
        GPIO_Input = 0b00,		/**< GPIO pin configured as input */
        GPIO_Output = 0b01,	    /**< GPIO pin configured as output */
		GPIO_Function = 0b10,	/**< GPIO pin configured as alternate function */
		GPIO_Analog = 0b11		/**< GPIO pin configured as analog */
    };

	/**
	 * Define the output type of the Input/output port.
	 */
	enum class GPIOOutputType : uint32_t {
        GPIO_PushPull = 0,	/**< Output type push-pull */
        GPIO_OpenDrain = 1	/**< Output type open-drain */
    };

	/**
	 * Defines the output speed settings available
	 */
	enum class GPIOOutputSpeed : uint32_t {
        GPIO_LowSpeed = 0b00,		/**< Output speed low */
        GPIO_MediumSpeed = 0b01,	/**< Output speed medium */
        GPIO_HighSpeed = 0b10,		/**< Output speed high */
        GPIO_VerySpeed = 0b11		/**< Output speed very */
    };

	/**
	 * Defines the possible states of the channel pull-ups.
	 */
	enum class GPIOPullUpPullDown : uint32_t {
        GPIO_NoPull = 0b00,		/**< No pull-up or pull-down */
        GPIO_PullUp = 0b01,		/**< Pull-up resistor enabled */
        GPIO_PullDown = 0b10	/**< Pull-down resistor enabled */
    };

	/**
	 * Defines the possible DIO alternate function. A multiplexer is used to
	 * select the alternate function
	 */
	enum class GPIOAlternateFunction : uint32_t {
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
 * Function init
*//**
*\b Description:
 * The init function is responsible for initializing and configuring the
 * GPIO peripheral based on the parameters provided. This function sets up
 * the GPIO pins according to the specified configuration, which may include
 * setting the mode (input, output, alternate function, or analog),
 * output type (push-pull or open-drain), output speed, pull-up/pull-down
 * resistors and alternate function selection.
 *
 * PRE-CONDITION: The user must ensure that the appropriate GPIO peripheral
 * is selected by instantiating the GPIODriver class with the correct index
 * corresponding to the desired GPIO port.
 *
 * POST-CONDITION: The specified GPIO pin will be configured according to
 * the provided parameters, and the clock for the GPIO peripheral will be
 * enabled in the RCC AHB1ENR register. The GPIO pin will be ready for use
 * based on the configured settings.
 *
 * @param[in] pin The specific GPIO pin to be configured (e.g., GPIO_Pin0, GPIO_Pin1, etc.).
 * @param[in] mode The mode of the GPIO pin (input, output, alternate function, or analog).
 * @param[in] output_type The output type for the GPIO pin (push-pull or open-drain).
 * @param[in] output_speed The output speed for the GPIO pin (low, medium, high, or very high).
 * @param[in] pull_up_down The pull-up/pull-down configuration for the GPIO pin (no pull, pull-up, or pull-down).
 * @param[in] function The alternate function selection for the GPIO pin (AF0 to AF15)
 *
 * @return void
 *
 * \b Example:
 * @code
 * GPIODriver<0> GPIOA; // Create an instance
 * using gpioa = GPIODriver<0>;
 * GPIOA.init(gpioa::GPIOPin::GPIO_Pin5,
 * 			  gpioa::GPIOMode::GPIO_Output,
 *            gpioa::GPIOOutputType::GPIO_PushPull,
 *            gpioa::GPIOOutputSpeed::GPIO_LowSpeed,
 *            gpioa::GPIOPullUpPullDown::GPIO_NoPull,
 *            gpioa::GPIOAlternateFunction::GPIO_AF0);
 *
 * @endcode
 *
*****************************************************************************/
	void init(GPIOPin pin, GPIOMode mode, GPIOOutputType output_type, GPIOOutputSpeed output_speed, GPIOPullUpPullDown pull_up_down, GPIOAlternateFunction function)
	{
		// Enable the clock for the specified GPIO peripheral in the RCC AHB1ENR register.
		if (gpio_idx == 0) {
            RCC->AHB1ENR |= (1U << 0); // Enable clock for GPIOA
        } else if (gpio_idx == 1) {
            RCC->AHB1ENR |= (1U << 1); // Enable clock for GPIOB
        } else if (gpio_idx == 2) {
            RCC->AHB1ENR |= (1U << 2); // Enable clock for GPIOC
        } else if (gpio_idx == 3) {
            RCC->AHB1ENR |= (1U << 3); // Enable clock for GPIOD
        } else if (gpio_idx == 4) {
            RCC->AHB1ENR |= (1U << 4); // Enable clock for GPIOE
        } else if (gpio_idx == 5) {
            RCC->AHB1ENR |= (1U << 7); // Enable clock for GPIOH
        }

		// Configure the GPIO pin mode in the MODER register.
		if (mode == GPIOMode::GPIO_Input){
			GPIO->MODER &= ~(0b11U << (static_cast<uint32_t>(pin) * 2U));
		}
		else if (mode == GPIOMode::GPIO_Output)
		{
			GPIO->MODER |= (0b01U << (static_cast<uint32_t>(pin) * 2U));
			GPIO->MODER &= ~(0b10U << (static_cast<uint32_t>(pin) * 2U));
        }
		else if (mode == GPIOMode::GPIO_Function)
		{
			GPIO->MODER &= ~(0b01U << (static_cast<uint32_t>(pin) * 2U));
			GPIO->MODER |= (0b10U << (static_cast<uint32_t>(pin) * 2U));
        }
		else if (mode == GPIOMode::GPIO_Analog)
		{
			GPIO->MODER |= (0b01U << (static_cast<uint32_t>(pin) * 2U));
			GPIO->MODER |= (0b10U << (static_cast<uint32_t>(pin) * 2U));
        }

		// Configure the GPIO output type in the OTYPER register.
		if (output_type == GPIOOutputType::GPIO_PushPull)
        {
            GPIO->OTYPER &= ~(1U << static_cast<uint32_t>(pin));
        }
        else if (output_type == GPIOOutputType::GPIO_OpenDrain)
        {
            GPIO->OTYPER |= (1U << static_cast<uint32_t>(pin));
        }

		// Configure the GPIO output speed in the OSPEEDR register.
		if(output_speed == GPIOOutputSpeed::GPIO_LowSpeed)
        {
            GPIO->OSPEEDR &= ~(0b11U << (static_cast<uint32_t>(pin) * 2U));
        }
        else if (output_speed == GPIOOutputSpeed::GPIO_MediumSpeed)
        {
            GPIO->OSPEEDR |= (0b01U << (static_cast<uint32_t>(pin) * 2U));
            GPIO->OSPEEDR &= ~(0b10U << (static_cast<uint32_t>(pin) * 2U));
        }
        else if (output_speed == GPIOOutputSpeed::GPIO_HighSpeed)
        {
        	GPIO->OSPEEDR &= ~(0b01U << (static_cast<uint32_t>(pin) * 2U));
            GPIO->OSPEEDR |= (0b10U << (static_cast<uint32_t>(pin) * 2U));
        }
        else if (output_speed == GPIOOutputSpeed::GPIO_VerySpeed)
        {
            GPIO->OSPEEDR |= (0b11U << (static_cast<uint32_t>(pin) * 2U));
        }

		// Configure the GPIO pull-up/pull-down resistors in the PUPDR register.
		if (pull_up_down == GPIOPullUpPullDown::GPIO_NoPull)
        {
            GPIO->PUPDR &= ~(0b11U << (static_cast<uint32_t>(pin) * 2U));
        }
        else if (pull_up_down == GPIOPullUpPullDown::GPIO_PullUp)
        {
            GPIO->PUPDR |= (0b01U << (static_cast<uint32_t>(pin) * 2U));
            GPIO->PUPDR &= ~(0b10U << (static_cast<uint32_t>(pin) * 2U));
        }
        else if (pull_up_down == GPIOPullUpPullDown::GPIO_PullDown)
        {
        	GPIO->PUPDR &= ~(0b01U << (static_cast<uint32_t>(pin) * 2U));
            GPIO->PUPDR |= (0b10U << (static_cast<uint32_t>(pin) * 2U));
        }

		// Configure the GPIO alternate function in the AFR register if the mode is set to alternate function.
		if (mode == GPIOMode::GPIO_Function)
        {
            if (static_cast<uint32_t>(pin) < 8U)
            {
                GPIO->AFR[0] &= ~(0b1111U << (static_cast<uint32_t>(pin) * 4U));
                GPIO->AFR[0] |= (static_cast<uint32_t>(function) << (static_cast<uint32_t>(pin) * 4U));
            }
            else
            {
                GPIO->AFR[1] &= ~(0b1111U << ((static_cast<uint32_t>(pin) - 8U) * 4U));
                GPIO->AFR[1] |= (static_cast<uint32_t>(function) << ((static_cast<uint32_t>(pin) - 8U) * 4U));
            }
        }

	}

/*****************************************************************************
 * Function: pinRead()
*//**
 *\b Description:
 * The pinRead function is responsible for reading the state of a specific GPIO pin.
 * It accesses the input data register (IDR) of the GPIO peripheral to determine
 * whether the specified pin is in a high or low state. The function returns a
 * boolean value indicating the state of the pin, where true represents a high
 * state and false represents a low state.
 *
 * PRE-CONDITION: The GPIO pin to be read must have been properly initialized
 * and configured as an input pin using the init function of the GPIODriver class.
 *
 * POST-CONDITION: The function will return the current state of the specified GPIO pin.
 *
 * @param[in] pin The specific GPIO pin to be read (e.g., GPIO_Pin0, GPIO_Pin1, etc.).
 *
 * @return A boolean value indicating the state of the GPIO pin (true for high, false for low).
 *
 * \b Example:
 * @code
 *	GPIODriver<1> GPIOB;
 *	using gpiob = GPIODriver<1>;
 *
 *	GPIOB.init(gpiob::GPIOPin::GPIO_Pin6,
 *			   gpiob::GPIOMode::GPIO_Input,
 *			   gpiob::GPIOOutputType::GPIO_PushPull,
 *			   gpiob::GPIOOutputSpeed::GPIO_LowSpeed,
 *			   gpiob::GPIOPullUpPullDown::GPIO_PullUp,
 *			   gpiob::GPIOAlternateFunction::GPIO_AF0);
 *
 *	GPIOB.pinRead(gpiob::GPIOPin::GPIO_Pin6);
 * @endcode
 *
******************************************************************************/
    GPIOPinState pinRead(GPIOPin pin)
    {
        // Read the state of the specified GPIO pin from the input data register (IDR).
        return ((GPIO->IDR & (1U << static_cast<uint16_t>(pin))) ? GPIOPinState::GPIO_High : GPIOPinState::GPIO_Low);
    }

/*****************************************************************************
 * Function: pinWrite()
*//**
 *\b Description:
 * The pinWrite function is responsible for writing a specified state (high or low)
 * to a specific GPIO pin. It accesses the output data register (ODR) of the GPIO
 * peripheral to set the state of the specified pin. The function takes a GPIOPinState
 * as an argument, which indicates whether the pin should be set to a high
 * state (true) or a low state (false).
 *
 * PRE-CONDITION: The GPIO pin to be written must have been properly initialized
 * and configured as an output pin using the init function of the GPIODriver class.
 *
 * POST-CONDITION: The specified GPIO pin will be set to the desired state
 * (high or low) based on the provided GPIOPinState.
 *
 * @param[in] pin The specific GPIO pin to be written (e.g., GPIO_Pin0, GPIO_Pin1, etc.).
 * @param[in] state The desired state to be written to the GPIO pin (true for high, false for low).
 *
 * @return void
 * \b Example:
 * @code
 * GPIODriver<0> GPIOA;
 * GPIOA.init(gpioa::GPIOPin::GPIO_Pin5,
 *            gpioa::GPIOMode::GPIO_Output,
 *            gpioa::GPIOOutputType::GPIO_PushPull,
 *            gpioa::GPIOOutputSpeed::GPIO_LowSpeed,
 *            gpioa::GPIOPullUpPullDown::GPIO_NoPull,
 *            gpioa::GPIOAlternateFunction::GPIO_AF0);
 *
 * GPIOA.pinWrite(gpioa::GPIOPin::GPIO_Pin5, GPIODriver<0>::GPIOPinState::GPIO_High);
 * * @endcode
 *
******************************************************************************/
    void pinWrite(GPIOPin pin, GPIOPinState state)
    {
        // Write the specified state to the output data register (ODR) for the specified GPIO pin.
        if (state == GPIOPinState::GPIO_High)
        {
            GPIO->ODR |= (1U << static_cast<uint16_t>(pin));
        }
        else
        {
            GPIO->ODR &= ~(1U << static_cast<uint16_t>(pin));
        }
    }

/*****************************************************************************
 * Function: pinToggle()
 *
*//**
 *\b Description:
 * The pinToggle function is responsible for toggling the state of a specific
 * GPIO pin. It accesses the output data register (ODR) of the GPIO peripheral
 * to invert the current state of the specified pin. If the pin is currently in
 * a high state, it will be set to low, and if it is currently in a low state,
 * it will be set to high.
 *
 * PRE-CONDITION: The GPIO pin to be toggled must have been properly initialized
 * and configured as an output pin using the init function of the GPIODriver class.
 *
 * POST-CONDITION: The specified GPIO pin will have its state toggled
 * (high to low or low to high).
 *
 * @param[in] pin The specific GPIO pin to be toggled (e.g., GPIO_Pin0, GPIO_Pin1, etc.).
 *
 * @return void
 * \b Example:
 * * @code
 *
 * GPIODriver<0> GPIOA;
 * GPIOA.init(gpioa::GPIOPin::GPIO_Pin5,
 *            gpioa::GPIOMode::GPIO_Output,
 *            gpioa::GPIOOutputType::GPIO_PushPull,
 *            gpioa::GPIOOutputSpeed::GPIO_LowSpeed,
 *            gpioa::GPIOPullUpPullDown::GPIO_NoPull,
 *            gpioa::GPIOAlternateFunction::GPIO_AF0);
 *
 * GPIOA.pinToggle(gpioa::GPIOPin::GPIO_Pin5);
 * * @endcode
******************************************************************************/
    void pinToggle(GPIOPin pin)
    {
        // Toggle the state of the specified GPIO pin in the output data register (ODR).
        GPIO->ODR ^= (1U << static_cast<uint16_t>(pin));
    }

/*****************************************************************************
 * Function: registerWrite()
 *
*//**
 *\b Description:
 * The registerWrite function is responsible for writing a specified value to a
 * specific register of the GPIO peripheral. This function allows users to directly
 * manipulate the registers of the GPIO peripheral for advanced configurations or
 * operations that may not be covered by the standard pin configuration functions.
 *
 * PRE-CONDITION: The user must ensure that the address provided is valid and
 * corresponds to a register within the GPIO peripheral. Additionally, the user
 * must ensure that the value being written is appropriate for the specific
 * register being accessed.
 *
 * POST-CONDITION: The specified value will be written to the targeted register
 * of the GPIO peripheral, potentially altering the configuration or behavior
 * of the GPIO pins based on the register being modified.
 *
 * @param[in] address to the specific register of the GPIO peripheral to be written.
 * @param[in] value to be written to the specified register.
 *
 * @return void
 * \b Example:
 * @code
 * GPIODriver<0> GPIOA;
 * GPIOA.registerWrite(GPIOA->MODER, 0x28000000);
 * @endcode
 *
******************************************************************************/
    void registerWrite(uint32_t address, uint32_t value)
    {
    	volatile uint32_t* const registerPointer = (uint32_t*)address;
        *registerPointer = value;
    }

/*****************************************************************************
 * Function: registerRead()
 *
*//**
 *\b Description:
 * The registerRead function is responsible for reading the value from a specific
 * register of the GPIO peripheral. This function allows users to directly access
 * the registers of the GPIO peripheral to retrieve information about the current
 * configuration or status of the GPIO pins, which can be useful for debugging or
 * monitoring the state of the GPIO peripheral.
 *
 * PRE-CONDITION: The user must ensure that the address provided is valid and
 * corresponds to a register within the GPIO peripheral. Additionally, the user
 * must ensure that the register being accessed is readable and that the value
 * being read is appropriate for the specific register being accessed.
 *
 * POST-CONDITION: The function will return the value read from the targeted
 * register of the GPIO peripheral, providing insight into the current
 * configuration or status of the GPIO pins based on the register being accessed.
 *
 * @param[in] address to the specific register of the GPIO peripheral to be read.
 *
 * @return The value read from the specified register of the GPIO peripheral.
 *
 * \b Example:
 * @code
 * GPIODriver<0> GPIOA;
 * uint32_t moderValue = GPIOA.registerRead(GPIOA->MODER);
 * @endcode
 *
******************************************************************************/
    uint32_t registerRead(uint32_t address)
    {
    	volatile uint32_t* const registerPointer = (uint32_t*)address;
        return *registerPointer;
    }

};

#endif /* GPIO_HPP_ */
