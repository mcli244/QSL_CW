#ifndef __KEY_H__
#define __KEY_H__

#include <stdint.h>

#define KEY_AUTO_PRESSED  0x01
#define KEY_DIT_PRESSED   0x02

void key_init(void);
uint8_t key_scan(void);

#endif /*__KEY_H__*/


