#include "bluetooth_ee.h"
#include "eeconfig.h"
#include "quantum.h"

bluetooth_ee_config_t bluetooth_ee_config;

void bluetooth_ee_reconnect_buffer_enable(void) {
    bluetooth_ee_config.reconnect_buffer_enabled = true;
}

void bluetooth_ee_reconnect_buffer_disable(void) {
    bluetooth_ee_config.reconnect_buffer_enabled = false;
}

bool bluetooth_ee_reconnect_buffer_is_enabled(void) {
    return bluetooth_ee_config.reconnect_buffer_enabled;
}

/* EE Config Init */
void eeconfig_init_kb(void) {
    /* Set Default Value */
    bluetooth_ee_config.reconnect_buffer_enabled = true;

    eeconfig_update_kb_datablock(&bluetooth_ee_config);
    eeconfig_init_user();
}

void bluetooth_ee_init(void) {
    eeconfig_read_kb_datablock(&bluetooth_ee_config);
}

/* Via Command */
#ifdef VIA_ENABLE

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if ( *channel_id == id_custom_channel ) {
        switch ( *command_id ) {
            case id_custom_set_value: {
                via_bluetooth_ee_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value: {
                via_bluetooth_ee_get_value(value_id_and_data);
                break;
            }
            case id_custom_save: {
                via_bluetooth_ee_save();
                break;
            }
            default: {
                *command_id = id_unhandled;
                break;
            }
        }

        return;
    }

    // Return the unhandled state
    *command_id = id_unhandled;
}

void via_bluetooth_ee_get_value(uint8_t *data) {
    /* data = [ value_id, value_data ] */
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_kc_bluetooth_reconnect_buffer: {
            value_data[0] = bluetooth_ee_reconnect_buffer_is_enabled() ? 1 : 0;
            break;
        }
    }
}

void via_bluetooth_ee_set_value(uint8_t *data) {
    /* data = [ value_id, value_data ] */
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_kc_bluetooth_reconnect_buffer: {
            value_data[0] ? bluetooth_ee_reconnect_buffer_enable() : bluetooth_ee_reconnect_buffer_disable();
            break;
        }
    }
}

void via_bluetooth_ee_save(void) {
    eeconfig_update_kb_datablock(&bluetooth_ee_config);
}

#endif
