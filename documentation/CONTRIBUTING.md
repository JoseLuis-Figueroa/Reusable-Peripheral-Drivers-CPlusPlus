# Contributing to Reusable Peripheral Drivers C++

Thank you for considering contributing to the **Reusable Peripheral Drivers C++** project!

This repository demonstrates the development of reusable peripheral drivers using **modern C++**, **template metaprogramming**, and **bare-metal firmware development** techniques for ARM Cortex-M microcontrollers.

Contributions of all kinds are welcome, including bug fixes, documentation improvements, new driver implementations, examples, and testing enhancements.

---

# Table of Contents

1. [Getting Started](#getting-started)
2. [Code of Conduct](#code-of-conduct)
3. [Ways to Contribute](#ways-to-contribute)
4. [Development Setup](#development-setup)
5. [Coding Standards](#coding-standards)
6. [Template Metaprogramming Guidelines](#template-metaprogramming-guidelines)
7. [Making a Pull Request](#making-a-pull-request)
8. [Commit Message Guidelines](#commit-message-guidelines)
9. [Doxygen Documentation](#doxygen-documentation)
10. [Need Help?](#need-help)

---

# Getting Started

To contribute:

1. **Fork** the repository.

2. **Clone** your fork:

```bash
git clone https://github.com/your-username/Reusable-Peripheral-Drivers-CPlusPlus.git
```

3. Navigate to the project directory:

```bash
cd Reusable-Peripheral-Drivers-CPlusPlus
```

4. Create a feature branch:

```bash
git checkout -b your-feature-branch
```

---

# Code of Conduct

We are committed to fostering an open, inclusive, and respectful environment.

Please:

- Be respectful and constructive.
- Provide clear technical explanations.
- Focus discussions on improving the project.
- Welcome feedback and collaboration.

---

# Ways to Contribute

You can contribute in many ways:

- Improve or correct documentation.
- Fix bugs.
- Add reusable peripheral drivers.
- Improve existing drivers.
- Add unit tests.
- Add hardware validation examples.
- Add support for additional STM32 peripherals.
- Improve template metaprogramming abstractions.

---

# Development Setup

Install the following tools:

- STM32CubeIDE
- GNU ARM Embedded Toolchain
- Git
- Doxygen
- STM32F401RE Nucleo Board (recommended)
- ST-Link Debugger

## Building the Project

Build using STM32CubeIDE:

1. Import the project.
2. Select the desired build configuration.
3. Click **Build Project**.

## Flashing the Firmware

Click the "_Run as_" option to flash the firmware using ST-Link.

## Debugging

Click the "_Debug as_" option to debug the firmware using ST-Link. 

---

# Coding Standards

To maintain consistency across the project:

- Use modern C++17 features where appropriate.
- Prefer compile-time solutions over runtime solutions when practical.
- Keep code modular and reusable.
- Use descriptive naming conventions.
- Follow MISRA-C style guidelines wherever possible.
- Minimize dynamic memory allocation.
- Avoid unnecessary runtime overhead.
- Maintain hardware abstraction without sacrificing performance.
- Document public APIs using Doxygen.

---

# Template Metaprogramming Guidelines

This repository heavily utilizes **template metaprogramming**.

When contributing:

- Prefer compile-time configuration whenever possible.
- Use `constexpr` instead of macros where applicable.
- Avoid introducing runtime polymorphism unless required.
- Favor zero-cost abstractions.
- Ensure generated code remains readable and efficient.
- Verify that template usage improves maintainability and performance.

## Example

Preferred:

```cpp
template<uint8_t Port>
class GPIODriver
{
};
```

Avoid:

```cpp
class GPIODriver
{
public:
    void init(uint8_t port);
};
```

When the peripheral can be selected at compile time.

---

# Making a Pull Request

Before submitting a pull request:

1. Ensure the project builds successfully.
2. Verify the firmware executes correctly on hardware.
3. Update documentation if applicable.
5. Commit your changes using meaningful commit messages.

Push your branch:

```bash
git push origin your-feature-branch
```

Then:

1. Open a Pull Request.
2. Provide a clear description of your changes.
3. Reference any related issues.
4. Include screenshots, logs, or test results when appropriate.

---

# Commit Message Guidelines

This project follows the [Conventional Commits](https://www.conventionalcommits.org/) specification:

| Type | Description |
|--------|-------------|
| feat | New feature |
| fix | Bug fix |
| docs | Documentation changes |
| style | Formatting changes |
| refactor | Code restructuring |
| test | Adding or updating tests |
| chore | Maintenance tasks |
| ci | CI/CD workflow updates |

## Examples

```text
feat(gpio): add compile-time alternate function support
```

```text
fix(gpio): correct pull-up configuration for input mode
```

```text
docs(readme): update GPIO usage examples
```

```text
refactor(gpio): simplify register abstraction layer
```

---

# Need Help?

If you have questions:

- Open an [issue](https://github.com/JoseLuis-Figueroa/Reusable-Peripheral-Drivers-CPlusPlus/issues) in the repository.
- Start a discussion in GitHub Discussions (if enabled).
- Contact the maintainer through GitHub.

We're always happy to help contributors get started.

---

Thank you for contributing to **Reusable Peripheral Drivers C++**!
