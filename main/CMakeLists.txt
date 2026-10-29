idf_component_register(
    SRCS
        "app_main.c"
        "sensor_driver.c"
        "data_processor.c"
        "alert_manager.c"
        "network_manager.c"
        "lora_transmitter.c"
    INCLUDE_DIRS "."
    REQUIRES nvs_flash esp_wifi esp_event mqtt
)
