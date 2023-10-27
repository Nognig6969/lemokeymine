#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifndef EECONFIG_KB_DATA_SIZE
#   define EECONFIG_KB_DATA_SIZE 1
#endif

void bluetooth_ee_init(void);

/* Reconnect Buffer Function */
typedef struct {
    bool reconnect_buffer_enabled;
} bluetooth_ee_config_t;

void bluetooth_ee_reconnect_buffer_enable(void);
void bluetooth_ee_reconnect_buffer_disable(void);
bool bluetooth_ee_reconnect_buffer_is_enabled(void);

/* Via Command */
#ifdef VIA_ENABLE
enum via_bluetooth_ee_value {
    id_kc_bluetooth_reconnect_buffer = 1,
};

void via_bluetooth_ee_set_value(uint8_t *data);
void via_bluetooth_ee_get_value(uint8_t *data);
void via_bluetooth_ee_save(void);
#endif