#include "lora_transmitter.h"
#include "project_config.h"
#include <stdio.h>
#include "esp_log.h"
static const char *TAG = "lora_transmitter";
esp_err_t lora_transmitter_init(void) {
#if LORA_ENABLED
    ESP_LOGI(TAG, "LoRa enabled");
#else
    ESP_LOGI(TAG, "LoRa disabled");
#endif
    return ESP_OK;
}
esp_err_t lora_transmitter_send(const processed_data_t *data) {
    if (data == NULL) return ESP_ERR_INVALID_ARG;
    char packet[192];
    int result = snprintf(packet,sizeof(packet),"T=%.2f,H=%.2f,AQ=%.2f,AX=%.3f,AY=%.3f,AZ=%.3f,AL=%d",data->sensor_data.temperature_c,data->sensor_data.humidity_pct,data->sensor_data.air_quality_index,data->sensor_data.accel_x_g,data->sensor_data.accel_y_g,data->sensor_data.accel_z_g,data->general_alarm?1:0);
    if (result < 0 || result >= (int)sizeof(packet)) return ESP_ERR_INVALID_SIZE;
#if LORA_ENABLED
    ESP_LOGI(TAG, "LoRa TX: %s", packet);
#else
    ESP_LOGI(TAG, "LoRa packet: %s", packet);
#endif
    return ESP_OK;
}
