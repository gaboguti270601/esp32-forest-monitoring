#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "project_config.h"
#include "sensor_driver.h"
#include "data_processor.h"
#include "alert_manager.h"
#include "network_manager.h"
#include "lora_transmitter.h"
static const char *TAG = "SIMF";
void app_main(void) {
    esp_err_t error;
    ESP_LOGI(TAG, "Starting Forest Monitoring System");
    error = nvs_flash_init();
    if (error == ESP_ERR_NVS_NO_FREE_PAGES || error == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        error = nvs_flash_init();
    }
    ESP_ERROR_CHECK(error);
    ESP_ERROR_CHECK(sensor_driver_init());
    ESP_ERROR_CHECK(network_manager_init());
    ESP_ERROR_CHECK(lora_transmitter_init());
    while (1) {
        sensor_data_t sensor_data;
        processed_data_t processed_data;
        error = sensor_driver_read(&sensor_data);
        if (error != ESP_OK) {
            ESP_LOGE(TAG, "Sensor read error: %s", esp_err_to_name(error));
            vTaskDelay(pdMS_TO_TICKS(SAMPLE_PERIOD_MS));
            continue;
        }
        data_processor_process(&sensor_data, &processed_data);
        ESP_LOGI(TAG, "Temperature: %.2f C | Humidity: %.2f %% | Air quality: %.2f", sensor_data.temperature_c, sensor_data.humidity_pct, sensor_data.air_quality_index);
        ESP_LOGI(TAG, "Acceleration: X=%.3f Y=%.3f Z=%.3f g", sensor_data.accel_x_g, sensor_data.accel_y_g, sensor_data.accel_z_g);
        alert_manager_handle(&processed_data);
        ESP_ERROR_CHECK_WITHOUT_ABORT(network_manager_publish(&processed_data));
        ESP_ERROR_CHECK_WITHOUT_ABORT(lora_transmitter_send(&processed_data));
        vTaskDelay(pdMS_TO_TICKS(SAMPLE_PERIOD_MS));
    }
}
