# STM32F4 LED Toggle Project

This repository contains a simple embedded system program that toggles two LEDs connected to pins PD12 and PD13 on an STM32F4 Discovery board. The project was developed using **IAR Embedded Workbench**.

## Project Overview

The main goal of this program is to demonstrate the basic usage of GPIO pins on the STM32F4 microcontroller to control LEDs. The program toggles the LEDs by manipulating hardware registers directly using bit-masking techniques.

### Features
- Toggles two LEDs (connected to PD12 and PD13).
- Delays implemented using a basic software loop.
- Uses direct register access for GPIO configuration and control.

### Prerequisites

To compile and run this project, you will need:

- **IAR Embedded Workbench for ARM**: This project is developed using IAR Workbench, so you'll need to have it installed to compile and debug the code.
- **STM32F4 Discovery Board**: The code is written for the STM32F4 series of microcontrollers, particularly the STM32F407VG present on the Discovery board.

### Hardware Requirements
- STM32F4 Discovery board.
- USB cable for programming and debugging via ST-LINK.
- LEDs connected to PD12 and PD13 (if not using the onboard LEDs).

### Project Structure

- **`main.c`**: Contains the main application code, including GPIO initialization and LED toggle functionality.
- **`stm32f4xx.h`**: STM32F4 peripheral register definitions, included via the STM32 firmware library.

### How to Build and Run

1. **Open the Project**: Open the project in IAR Embedded Workbench by navigating to the `.ewp` file (project file) in your project folder.
2. **Compile the Code**: Once the project is opened, click on the **Build** button or press **F7** to compile the project.
3. **Download to Target**: After successful compilation, connect your STM32F4 Discovery board and click on the **Download and Debug** button or press **Ctrl + D** to flash the program to the board.
4. **Run the Program**: After flashing, run the program by pressing **F5**. The LEDs connected to PD12 and PD13 will toggle with a delay between each toggle.

### Code Breakdown

#### Main Features in `main.c`:

1. **Clock Configuration for GPIO D**: 
   - The program enables the clock for GPIO Port D using the RCC_AHB1ENR register.

2. **GPIO Configuration**:
   - The program configures PD12 and PD13 as output pins by setting the correct bits in the GPIOD_MODER register.

3. **LED Control**:
   - LEDs are toggled by setting and clearing the respective bits in the GPIOD_ODR register.

4. **Delay Function**:
   - A simple delay loop is used to introduce a visible on-off pattern for the LEDs.

### Example Code Snippet

```c
// Enable clock for GPIO D
*RCC_AHB1ENR |= (1 << 3);

// Configure PD12 and PD13 as output
*GPIOD_MODER |= (1 << 24);  // Set PD12 as output
*GPIOD_MODER |= (1 << 26);  // Set PD13 as output

// Toggle LEDs
*GPIOD_ODR |= (1 << 12);  // Turn on PD12 LED
*GPIOD_ODR |= (1 << 13);  // Turn on PD13 LED
Delay(0x5FFFFF);          // Wait for a while
