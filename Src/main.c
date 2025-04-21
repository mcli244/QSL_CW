/**
  ******************************************************************************
  * @file    main.c
  * @author  MCU Application Team
  * @brief   Main program body
  * @date
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
#include "key.h"
#include "led.h"

/* Private define ------------------------------------------------------------*/
#define  PULSE4_VALUE       25
/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef    TimHandle;
TIM_OC_InitTypeDef sConfig;

/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Error_Handler(void);
static void APP_TIM1_INIT(void);
static void APP_TIM1_PWM(void);

/**
  * @brief  应用程序入口函数.
  * @retval int
  */
int main(void)
{
  /* 初始化所有外设，Flash接口，SysTick */
  HAL_Init();
  
  APP_TIM1_INIT();
  APP_TIM1_PWM();

  led_init();
  key_init();

  while (1)
  {
    uint8_t key_value = key_scan();
    if (key_value & KEY_AUTO_PRESSED)
    {
      do
      {
        HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_4);
        led_ctrl(LED_ON);
        HAL_Delay(10);
        HAL_TIM_PWM_Stop(&TimHandle, TIM_CHANNEL_4);
        HAL_Delay(10);
        led_ctrl(LED_OFF);
      }while (key_scan() & KEY_AUTO_PRESSED);
      
    }
    else if (key_value & KEY_DIT_PRESSED)
    {
      led_ctrl(LED_ON);
      do
      {
        HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_3);
      }while (key_scan() & KEY_DIT_PRESSED);
      HAL_TIM_PWM_Stop(&TimHandle, TIM_CHANNEL_4);
      led_ctrl(LED_OFF);
    }

  }
}
/**
  * @brief  TIM1初始化函数
  * @param  无
  * @retval 无
  */
static void APP_TIM1_INIT(void)
{
  /* 选择TIM1 */
  TimHandle.Instance = TIM1;                                                  
  TimHandle.Init.Period            = 50;                                     
  TimHandle.Init.Prescaler         = 800 - 1;                                 
  TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;                  
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;                      
  TimHandle.Init.RepetitionCounter = 1 - 1;                                   
  TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;          
  if (HAL_TIM_Base_Init(&TimHandle) != HAL_OK)                                
  {
    Error_Handler();
  }

}
/**
  * @brief  TIM1 PWM配置
  * @param  无
  * @retval 无
  */
static void APP_TIM1_PWM(void)
{
  /*输出配置为翻转模式 */
  sConfig.OCMode       = TIM_OCMODE_PWM1;                                     
  sConfig.OCPolarity   = TIM_OCPOLARITY_HIGH;                                 
  sConfig.OCFastMode   = TIM_OCFAST_DISABLE;                                  
  sConfig.OCNPolarity  = TIM_OCNPOLARITY_HIGH;                                
  sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;                              
  sConfig.OCIdleState  = TIM_OCIDLESTATE_RESET;                               

  /* CC4值为25,占空比=25/50=80% */
  sConfig.Pulse = PULSE4_VALUE;                                               

  /*通道4配置 */
  if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  错误执行函数
  * @param  无
  * @retval 无
  */
void Error_Handler(void)
{
  /* 无限循环 */
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  输出产生断言错误的源文件名及行号
  * @param  file：源文件名指针
  * @param  line：发生断言错误的行号
  * @retval 无
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* 用户可以根据需要添加自己的打印信息,
     例如: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* 无限循环 */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/
