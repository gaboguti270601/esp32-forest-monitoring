#include "alert_manager.h"
#include "esp_log.h"
static const char *TAG = "alert_manager";
void alert_manager_handle(const processed_data_t *data) {
    if (data == NULL) return;
    if (!data->general_alarm) { ESP_LOGI(TAG, "System status: NORMAL"); return; }
    ESP_LOGW(TAG, "Environmental alert detected");
    if (data->temperature_alarm) ESP_LOGW(TAG, "High temperature: %.2f C", data->sensor_data.temperature_c);
    if (data->humidity_alarm) ESP_LOGW(TAG, "Low humidity: %.2f %%", data->sensor_data.humidity_pct);
    if (data->air_quality_alarm) ESP_LOGW(TAG, "Abnormal air quality: %.2f", data->sensor_data.air_quality_index);
    if (data->motion_alarm) ESP_LOGW(TAG, "Abnormal movement detected: %.3f g", data->acceleration_magnitude_g);
}
