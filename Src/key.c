#include "key.h"
#include "main.h"

#define KEY_AUTO    GPIO_PIN_4
#define KEY_DIT     GPIO_PIN_3

/**
  * @brief  LED配置函数
  * @param  无
  * @retval 无
  */
void key_init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  __HAL_RCC_GPIOA_CLK_ENABLE();                          /* GPIOA时钟使能 */

  GPIO_InitStruct.Pin = KEY_AUTO | KEY_DIT;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
  GPIO_InitStruct.Pull = GPIO_NOPULL;                    /* 使能上拉 */
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;          /* GPIO速度 */

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);                /* GPIO初始化 */
}

/**
  * @brief  按键扫描函数
  * @param  无
  * @retval 无
  */
uint8_t key_scan(void)
{
    uint8_t key_value = 0;
    
    if (HAL_GPIO_ReadPin(GPIOA, KEY_AUTO) == GPIO_PIN_SET)
    {
        HAL_Delay(10); // 防抖延时
        if (HAL_GPIO_ReadPin(GPIOA, KEY_AUTO) == GPIO_PIN_SET)
        {
            key_value |= KEY_AUTO_PRESSED;
        }
    }
    
    if (HAL_GPIO_ReadPin(GPIOA, KEY_DIT) == GPIO_PIN_SET)
    {
        HAL_Delay(10); // 防抖延时
        if (HAL_GPIO_ReadPin(GPIOA, KEY_DIT) == GPIO_PIN_SET)
        {
            key_value |= KEY_DIT_PRESSED;
        }
    }
    
    return key_value;
}



