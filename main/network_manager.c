#include "network_manager.h"
#include "project_config.h"
#include <stdio.h>
#include "esp_log.h"
static const char *TAG = "network_manager";
esp_err_t network_manager_init(void) {
#if WIFI_ENABLED
    ESP_LOGI(TAG, "Wi-Fi enabled");
#else
    ESP_LOGI(TAG, "Wi-Fi disabled");
#endif
#if MQTT_ENABLED
    ESP_LOGI(TAG, "MQTT enabled");
#else
    ESP_LOGI(TAG, "MQTT disabled");
#endif
    return ESP_OK;
}
esp_err_t network_manager_publish(const processed_data_t *data) {
    if (data == NULL) return ESP_ERR_INVALID_ARG;
    char payload[384];
    int result = snprintf(payload,sizeof(payload),"{\"temperature_c\":%.2f,\"humidity_pct\":%.2f,\"air_quality\":%.2f,\"acceleration\":{\"x\":%.3f,\"y\":%.3f,\"z\":%.3f},\"alarm\":%s}",data->sensor_data.temperature_c,data->sensor_data.humidity_pct,data->sensor_data.air_quality_index,data->sensor_data.accel_x_g,data->sensor_data.accel_y_g,data->sensor_data.accel_z_g,data->general_alarm?"true":"false");
    if (result < 0 || result >= (int)sizeof(payload)) return ESP_ERR_INVALID_SIZE;
#if MQTT_ENABLED
    ESP_LOGI(TAG, "MQTT: %s", payload);
#else
    ESP_LOGI(TAG, "Network payload: %s", payload);
#endif
    return ESP_OK;
}
