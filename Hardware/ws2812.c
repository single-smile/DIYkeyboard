#include "ws2812.h"

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_TIM_PWM_Stop_DMA(&htim1, TIM_CHANNEL_3);
}

void ws2812_set_RGB(uint8_t R, uint8_t G, uint8_t B, uint16_t num)
{

    uint16_t* p = (RGB_buffur + RESET_PULSE) + (num * LED_DATA_LEN);

    for (uint16_t i = 0; i < 8; i++)
    {

        p[i]      = (G << i) & (0x80) ? ONE_PULSE : ZERO_PULSE;
        p[i + 8]  = (R << i) & (0x80) ? ONE_PULSE : ZERO_PULSE;
        p[i + 16] = (B << i) & (0x80) ? ONE_PULSE : ZERO_PULSE;
    }

}
uint8_t	b = 0x22;
uint8_t	c = 0x22;
uint8_t	d = 0x22;
void ws2812_example(void)
{
	

    b = 0;

    for (int a = 0; a < 61; a++)
    {
        ws2812_set_RGB(b, c, d, a);
        b++;
        b++;

        if( b > 255)
            b = 0;
    }

    HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_3, (uint32_t *)RGB_buffur, (1512));
}
void ws2812_zero(void)
{

    for (int a = 0; a < 61; a++)
    {
        ws2812_set_RGB(0, 0, 0, a);
    }

    HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_3, (uint32_t *)RGB_buffur, (1512));
}
int enter = 1;
extern int mark ;
void ws2812_change(void)
{
	if (enter%2)
	{
		ws2812_example();
	}
	else
	{
		ws2812_zero();
	}
	enter++;
	mark = 1;
}
	