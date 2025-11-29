/*
 * temp_sensor.c
 *
 *  Created on: Nov 25, 2025
 *      Author: chiando
 */

// temp_sensor.c
#include "temp_sensor.h"

extern ADC_HandleTypeDef hadc1;

float TS_GetTemperature(void)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

    uint16_t adcValue = HAL_ADC_GetValue(&hadc1);

    float VSENSE = adcValue * 3.0f / 4095.0f;  // 若 Vref=3.3 改成 3.3f
    float temp = ((VSENSE - 0.76f) / 0.0025f) + 25.0f;
    return temp;    // 单位 ℃
}

