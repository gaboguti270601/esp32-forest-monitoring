#include "data_processor.h"
#include "project_config.h"
#include <math.h>
#include <string.h>
void data_processor_process(const sensor_data_t *input, processed_data_t *output) {
    if (input == NULL || output == NULL) return;
    memset(output, 0, sizeof(*output));
    output->sensor_data = *input;
    output->acceleration_magnitude_g = sqrtf(input->accel_x_g*input->accel_x_g + input->accel_y_g*input->accel_y_g + input->accel_z_g*input->accel_z_g);
    output->temperature_alarm = input->temperature_c >= TEMP_ALERT_C;
    output->humidity_alarm = input->humidity_pct <= HUMIDITY_ALERT_PCT;
    output->air_quality_alarm = input->air_quality_index >= AIR_QUALITY_ALERT;
    output->motion_alarm = fabsf(output->acceleration_magnitude_g - 1.0f) >= MOTION_DELTA_G;
    output->general_alarm = output->temperature_alarm || output->humidity_alarm || output->air_quality_alarm || output->motion_alarm;
}
