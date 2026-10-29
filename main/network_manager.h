#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H
#include "esp_err.h"
#include "data_processor.h"
esp_err_t network_manager_init(void);
esp_err_t network_manager_publish(const processed_data_t *data);
#endif
