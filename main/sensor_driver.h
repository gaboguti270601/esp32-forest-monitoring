#ifndef SENSOR_DRIVER_H
#define SENSOR_DRIVER_H
#include "esp_err.h"
typedef struct {
    float temperature_c;
    float humidity_pct;
    float air_quality_index;
    float accel_x_g;
    float accel_y_g;
    float accel_z_g;
} sensor_data_t;
esp_err_t sensor_driver_init(void);
esp_err_t sensor_driver_read(sensor_data_t *data);
#endif
