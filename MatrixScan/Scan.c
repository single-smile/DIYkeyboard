#include "Scan.h"

typedef struct
{
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
} GPIO_Pin_TypeDef;

GPIO_Pin_TypeDef keyboardRow[] =
    {
        {ROW0_GPIO_Port, ROW0_Pin},
        {ROW1_GPIO_Port, ROW1_Pin},
        {ROW2_GPIO_Port, ROW2_Pin},
        {ROW3_GPIO_Port, ROW3_Pin},
        {ROW4_GPIO_Port, ROW4_Pin},
};
GPIO_Pin_TypeDef keyboardCol[] =
    {
        {COL0_GPIO_Port, COL0_Pin},
        {COL1_GPIO_Port, COL1_Pin},
        {COL2_GPIO_Port, COL2_Pin},
        {COL3_GPIO_Port, COL3_Pin},
        {COL4_GPIO_Port, COL4_Pin},
        {COL5_GPIO_Port, COL5_Pin},
        {COL6_GPIO_Port, COL6_Pin},
        {COL7_GPIO_Port, COL7_Pin},
        {COL8_GPIO_Port, COL8_Pin},
        {COL9_GPIO_Port, COL9_Pin},
        {COL10_GPIO_Port, COL10_Pin},
        {COL11_GPIO_Port, COL11_Pin},
        {COL12_GPIO_Port, COL12_Pin},
        {COL13_GPIO_Port, COL13_Pin},
};

uint64_t KeyboardScan(void)
{
    uint64_t result = 0, k = 0;

    for (size_t row = 0; row < 5; row++)
    {
        HAL_GPIO_WritePin(keyboardRow[row].GPIOx, keyboardRow[row].GPIO_Pin, GPIO_PIN_RESET); 
        HAL_Delay(1);

        for (size_t col = 0; col < 14; col++)
        {
            result |= (uint64_t)((HAL_GPIO_ReadPin(keyboardCol[col].GPIOx, keyboardCol[col].GPIO_Pin) == GPIO_PIN_RESET)) << k++;
        }

        HAL_GPIO_WritePin(keyboardRow[row].GPIOx, keyboardRow[row].GPIO_Pin, GPIO_PIN_SET); 
    }

    return result;
}
