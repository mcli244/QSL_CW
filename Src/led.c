#include "led.h"
#include "main.h"

#define LED_PIN GPIO_PIN_2

/**
  * @brief  LED配置函数
  * @param  无
  * @retval 无
  */
void led_init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  __HAL_RCC_GPIOA_CLK_ENABLE();                          /* GPIOA时钟使能 */

  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
  GPIO_InitStruct.Pull = GPIO_NOPULL;                    /* 使能上拉 */
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;          /* GPIO速度 */

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);                /* GPIO初始化 */
}

/**
  * @brief  LED控制函数
  * @param  sta: LED状态
  * @retval 无
  */
void led_ctrl(uint8_t sta)
{
  HAL_GPIO_WritePin(GPIOA, LED_PIN, (sta == LED_ON) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}


/**
  * @brief  LED翻转
  * @param  sta: LED状态
  * @retval 无
  */
void led_toggle(void)
{
  HAL_GPIO_TogglePin(GPIOA, LED_PIN);
}

