/**
  ******************************************************************************
  * @file    py32f0xx_hal_msp.c
  * @author  MCU Application Team
  * @brief   This file provides code for the MSP Initialization
  *          and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/**
  * @brief 初始化全局MSP
  */
void HAL_MspInit(void)
{
}

/**
  * @brief 初始化全局MSP
  */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  GPIO_InitTypeDef   GPIO_InitStruct;
  /*TIM1时钟使能 */
  __HAL_RCC_TIM1_CLK_ENABLE();                              
  /*GPIOA时钟使能 */
  __HAL_RCC_GPIOA_CLK_ENABLE();                             
  /*复用功能 */
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;                   
  /* 上拉 */
  GPIO_InitStruct.Pull = GPIO_PULLUP;                       
  /* 高速*/
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  /*GPIOA3初始化*/
  GPIO_InitStruct.Pin = TIMx_GPIO_PIN_CHANNEL1;
  GPIO_InitStruct.Alternate = GPIO_AF13_TIM1;
  HAL_GPIO_Init(TIMx_GPIO_PORT_CHANNEL1, &GPIO_InitStruct);
  /*GPIOB3初始化*/
  GPIO_InitStruct.Pin = TIMx_GPIO_PIN_CHANNEL2;
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  HAL_GPIO_Init(TIMx_GPIO_PORT_CHANNEL2, &GPIO_InitStruct);
  /*GPIOA0初始化*/
  GPIO_InitStruct.Pin = TIMx_GPIO_PIN_CHANNEL3;
  GPIO_InitStruct.Alternate = GPIO_AF13_TIM1;
  HAL_GPIO_Init(TIMx_GPIO_PORT_CHANNEL3, &GPIO_InitStruct);
  /*GPIOA1初始化*/
  GPIO_InitStruct.Pin = TIMx_GPIO_PIN_CHANNEL4;
  GPIO_InitStruct.Alternate = GPIO_AF13_TIM1;
  HAL_GPIO_Init(TIMx_GPIO_PORT_CHANNEL4, &GPIO_InitStruct);
}



/************************ (C) COPYRIGHT Puya *****END OF FILE****/
