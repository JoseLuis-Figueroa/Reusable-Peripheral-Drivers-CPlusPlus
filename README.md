# STM32F4 Reusable Peripheral Drivers (C++).

This repository contains the implementation of a **reusable peripheral driver development** for the **STM32F401RE** microcontroller using modern **C++ template metaprogramming techniques**. The drivers provide a type-safe, reusable, and efficient interface for configuring and controlling peripherals while maintaining direct access to the underlying hardware registers.

Unlike traditional C-based peripheral drivers, this implementation leverages **compile-time abstractions** to eliminate runtime overhead and improve code maintainability. The result is a lightweight, zero-cost hardware abstraction layer suitable for resource-constrained embedded systems.

---

# Table of Contents

1. [About the Project](#about-the-project)
2. [Project Status](#project-status)
3. [Getting Started](#getting-started)
   - [Dependencies](#dependencies)
   - [Getting the Source](#getting-the-source)
   - [Building](#building)
   - [Running Tests](#running-tests)
4. [Usage](#usage)
5. [Release Process](#release-process)
6. [How to Get Help](#how-to-get-help)
7. [Contributing](#contributing)
8. [Further Reading](#further-reading)
9. [License](#license)
10. [Authors](#authors)

---

# About the Project

The peripherals are among the most fundamental building blocks in embedded systems. They provide the interface between the microcontroller and external devices such as LEDs, push buttons, sensors, communication transceivers, and actuators.

The driver is designed for bare-metal applications and interacts directly with the STM32 peripheral register map without requiring the STM32 HAL library.

## Key Features

- Modular and layered architecture.
- Reusable peripheral driver development.
- Type-safe peripheral access.
- Compile-time peripheral selection through templates.
- Minimal runtime overhead
- Zero-cost hardware abstractions.

## Technical Details

- **Microcontroller:** STM32F401RE
- **Architecture:** ARM Cortex-M4
- **Language:** C++17
- **Programming Paradigm:** Template Metaprogramming
- **Development Style:** Bare-Metal
- **IDE:** STM32CubeIDE
- **Compiler:** GNU ARM Embedded Toolchain
- **Documentation:** Doxygen

**[Back to top](#table-of-contents)**

---

# Project Status

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)

Current Version: `v1.0`
Tested on: `Nucleo-F401RE` 

### Implemented Features

- ✅ GPIO.

**[Back to top](#table-of-contents)**

---

# Getting Started

This guide helps you build and run the firmware on the STM32F401RE development board.

## Dependencies

Install the following tools:

- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- [GNU ARM Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm)
- [Git](https://git-scm.com/)

## Getting the Source

Clone the repository:

```bash
git clone https://github.com/JoseLuis-Figueroa/Reusable-Peripheral-Drivers-CPlusPlus.git
cd Reusable-Peripheral-Drivers-CPlusPlus
```

## Building

You can build the project using STM32CubeIDE.

1. Click File -> STM32 project create/import.
2. Select the project file.
3. Select the desired build configuration.
4. Click **Build Project**.

## Running Tests

Click the "_Run as_" or "_Debug as_" to flash the firmware using ST-Link.

### Other Verification Methods

- SWD Debugging using ST-Link.
- Register inspection through STM32CubeIDE debugger.
- Static code analysis (planned).
- Unit testing support (planned).

**[Back to top](#table-of-contents)**

---

# Usage

## General-Purpose Input/Output (GPIO)

The example application demonstrates how to configure and control multiple GPIO peripherals using the `GPIODriver` template class.

The firmware configures:

| Pin | Configuration | Purpose |
|------|------|------|
| PA5 | Output | User LED |
| PB6 | Output | Register access demonstration |
| PC13 | Input | User push button |

The application continuously monitors the state of the user button connected to **PC13**. Depending on the button state, the firmware controls the LED connected to **PA5**.

In addition to standard GPIO operations, the example demonstrates direct register manipulation using the driver's read and write register APIs.

This implementation serves as a **test and validation of the GPIO driver**. A video demonstration provides a visual representation of the physical implementation of the GPIO driver.

<p align="center">
    <img src="https://github.com/JoseLuis-Figueroa/Reusable-Peripheral-Drivers-CPlusPlus/blob/README/documentation/Media/GPIO-Implementation.gif"
         width="20%"
         alt="GPIO_Implementation">
</p>

<p align="center">Image 1. GPIO Hardware Test.</p>

**[Back to top](#table-of-contents)**

---

# Release Process

## Versioning

This project follows [Semantic Versioning](https://semver.org/).

Current Release:

- `v1.0` — Initial GPIO Driver release.

**[Back to top](#table-of-contents)**

---

# How to Get Help

- Open a [GitHub issue](https://github.com/JoseLuis-Figueroa/Reusable-Peripheral-Drivers-CPlusPlus/issues).
- Contact the maintainer through GitHub.

---

# Contributing

Contributions are welcome.

Please refer to the `CONTRIBUTING.md` file for details.

**[Back to top](#table-of-contents)**

---

# Further Reading

- [C++ in Embedded Systems](https://www.amazon.com.mx/Embedded-Systems-practical-transition-English-ebook/dp/B0F2MS788M) by Amar Mahmutbegovic
- [STM32Cube HAL Drivers](https://www.st.com/en/embedded-software/stm32cubef4.html)  
- [MISRA-C Guidelines](https://www.misra.org.uk/)

---

# License

This project is licensed under the MIT License. See the [LICENSE.md](LICENSE) file for details.

---

# Authors

**[JoseLuis-Figueroa](https://github.com/JoseLuis-Figueroa)** – Developer and maintainer

**[Back to top](#table-of-contents)**
