#include "sensor_driver.h"
#include <stddef.h>
#include "esp_log.h"
static const char *TAG = "sensor_driver";
esp_err_t sensor_driver_init(void) {
    ESP_LOGI(TAG, "Sensor subsystem initialized");
    return ESP_OK;
}
esp_err_t sensor_driver_read(sensor_data_t *data) {
    if (data == NULL) return ESP_ERR_INVALID_ARG;
    data->temperature_c = 0.0f;
    data->humidity_pct = 0.0f;
    data->air_quality_index = 0.0f;
    data->accel_x_g = 0.0f;
    data->accel_y_g = 0.0f;
    data->accel_z_g = 1.0f;
    return ESP_OK;
}
