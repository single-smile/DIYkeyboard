#ifndef __WS2812_H
#define __WS2812_H


#include "tim.h"


#define ONE_PULSE        (69)
#define ZERO_PULSE       (34)
#define RESET_PULSE      (48)
#define LED_NUMS         (61)
#define LED_DATA_LEN     (24)
#define WS2812_DATA_LEN  (LED_NUMS*LED_DATA_LEN)
uint16_t static RGB_buffur[RESET_PULSE + WS2812_DATA_LEN] = { 0 };

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void ws2812_set_RGB(uint8_t R, uint8_t G, uint8_t B, uint16_t num);
void ws2812_example(void);
void ws2812_zero(void);
void ws2812_change(void);

#endif
