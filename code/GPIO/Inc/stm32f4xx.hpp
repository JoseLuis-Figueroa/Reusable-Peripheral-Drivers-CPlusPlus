/*****************************************************************************
 * @file stm32f4xx.hpp
 * @author Jose Luis Figueroa
 * @brief CMSIS STM32F401xE device peripheral access layer header file.
 * This file provides a set of data structures and macros to access the hardware
 * registers of the STM32F401xE microcontroller. It is designed to be used in embedded
 * software development for this specific microcontroller, allowing developers to
 * interact with the hardware peripherals in a structured and efficient manner.
 *
 * @version 1.0
 * @date 2026-May-12
 *
 * @copyright Copyright (c) 2023 Jose Luis Figueroa. MIT License.
 *
 *****************************************************************************/

#ifndef STM32F4xx_HPP_
#define STM32F4xx_HPP_


#include <cstdint>

/**
  * @brief Reset and Clock Control
 */

typedef struct
{
	volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
	volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
	volatile uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
	volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
	volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
	volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
	volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
	uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
	volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
	volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
	uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
	volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
	volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
	volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
	uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
	volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
	volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
	uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
	volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
	uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
	volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
	volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
	volatile uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
	uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
	volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
	volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
	uint32_t      RESERVED7[1];  /*!< Reserved, 0x88                                                                    */
	volatile uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
} RCC_TypeDef;


/**
  * @brief General Purpose I/O
 */

typedef struct
{
	volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
	volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
	volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
	volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
	volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
	volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;


/*
 * Peripheral_memory_map
*/

namespace mcal{

	namespace reg{

		// Base address for all peripherals.
		constexpr std::uint32_t kPeripheralBase = 0x40000000U;

		// AHB1 peripheral base address.
		constexpr std::uint32_t kAHB1PeripheralBase = kPeripheralBase + 0x00020000U;

		// RCC base address.
		constexpr std::uint32_t kRccBase = kAHB1PeripheralBase + 0x3800U;


		namespace gpio{
			// GPIO base addresses
			constexpr std::uint32_t kGPIOA = kAHB1PeripheralBase + 0x0000U;
			constexpr std::uint32_t kGPIOB = kAHB1PeripheralBase + 0x0400U;
			constexpr std::uint32_t kGPIOC = kAHB1PeripheralBase + 0x0800U;
			constexpr std::uint32_t kGPIOD = kAHB1PeripheralBase + 0x0C00U;
			constexpr std::uint32_t kGPIOE = kAHB1PeripheralBase + 0x1000U;
			constexpr std::uint32_t kGPIOH = kAHB1PeripheralBase + 0x1C00U;

		} //namespace gpio

	} //namespace reg

} //namespace mcal


#endif /* STM32F4XX_HPP_ */
