#ifndef LORA_TRANSMITTER_H
#define LORA_TRANSMITTER_H
#include "esp_err.h"
#include "data_processor.h"
esp_err_t lora_transmitter_init(void);
esp_err_t lora_transmitter_send(const processed_data_t *data);
#endif
