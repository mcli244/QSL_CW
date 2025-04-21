#ifndef __LED_H__
#define __LED_H__


#include <stdint.h>

#define LED_ON      0
#define LED_OFF     1

void led_init(void);
void led_ctrl(uint8_t sta);
void led_toggle(void);

#endif /*__LED_H__*/

