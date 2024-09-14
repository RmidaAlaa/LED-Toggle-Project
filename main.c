/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/**
  ******************************************************************************
  * @file    main.c 
  * @author  Ala Rmida
  * @mail    ala.rmida.98@gmail.com
  * @Tel     (+216)53.230.717
  * @version V1.0.0
  * @date    02-09-2024
  ******************************************************************************
  * @brief   This program toggles two LEDs connected to pins PD12 and PD13
  *          on the STM32F4 Discovery board using bit-masking and delays.
  ******************************************************************************
*/

/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 50  // Number of loop iterations

/* Private variables ---------------------------------------------------------*/

/* Define the address of RCC_AHB1ENR register to enable the clock for GPIO D */
volatile unsigned short int *RCC_AHB1ENR = (unsigned short int *)(0x40023800 + 0x30);

/* Define the address of GPIOD_MODER register for configuring GPIO D mode */
volatile unsigned int *GPIOD_MODER = (unsigned int *)0x40020C00;

/* Define the address of GPIOD_ODR register for controlling the output data of GPIO D */
volatile unsigned int *GPIOD_ODR = (unsigned int *)(0x40020C00 + 0x14);

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nCount);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program entry point.
  * @param  None
  * @retval None
  */
int main(void)
{
  unsigned int counter = 0x00;  // Loop counter

  /* Enable the clock for GPIO D by setting the 3rd bit of RCC_AHB1ENR */
  *RCC_AHB1ENR |= (1 << 3);

  /* Configure PD12 as output: set MODER[25:24] to '01' */
  *GPIOD_MODER |= (1 << 24);   // Set bit 24 to 1
  *GPIOD_MODER &= ~(1 << 25);  // Set bit 25 to 0

  /* Configure PD13 as output: set MODER[27:26] to '01' */
  *GPIOD_MODER |= (1 << 26);   // Set bit 26 to 1
  *GPIOD_MODER &= ~(1 << 27);  // Set bit 27 to 0

  /* Loop for NOMBRE_BOUCLES iterations */
  for (counter = 0; counter < NOMBRE_BOUCLES; counter++)
  {
    /* Set PD12 to high (turn on LED) */
    *GPIOD_ODR |= (1 << 12);

    /* Set PD13 to high (turn on LED) */
    *GPIOD_ODR |= (1 << 13);

    /* Delay for a short period */
    Delay(0x5FFFFF);

    /* Set PD12 to low (turn off LED) */
    *GPIOD_ODR &= ~(1 << 12);

    /* Set PD13 to low (turn off LED) */
    *GPIOD_ODR &= ~(1 << 13);

    /* Delay for a short period */
    Delay(0x5FFFFF);
  }

  /* Infinite loop to prevent program from exiting */
  while (1)
  {}
}

/**
  * @brief  Simple delay function.
  * @param  nCount: specifies the delay duration.
  * @retval None
  */
void Delay(__IO uint32_t nCount)
{
  /* Decrease nCount until it reaches 0 */
  while (nCount--)
  {
  }
}

/**
  * @}
  */ 

/**
  * @}
  */ 

/***************************END OF FILE*******************/
