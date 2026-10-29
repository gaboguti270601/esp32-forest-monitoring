#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H
#include <stdbool.h>
#include "sensor_driver.h"
typedef struct {
    sensor_data_t sensor_data;
    float acceleration_magnitude_g;
    bool temperature_alarm;
    bool humidity_alarm;
    bool air_quality_alarm;
    bool motion_alarm;
    bool general_alarm;
} processed_data_t;
void data_processor_process(const sensor_data_t *input, processed_data_t *output);
#endif
