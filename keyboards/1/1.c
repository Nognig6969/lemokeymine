#include "quantum.h"

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) {
        return false;
    }
    if (index == 0) {
        default_layer_set(1UL << (active ? 0 : 2));
    }
    return true;
}
#endif

void keyboard_post_init_kb(void) {
    setPinOutputPushPull(LED_MAC_OS_PIN);
    setPinOutputPushPull(LED_WIN_OS_PIN);
    writePin(LED_MAC_OS_PIN, !LED_OS_PIN_ON_STATE);
    writePin(LED_WIN_OS_PIN, !LED_OS_PIN_ON_STATE);

    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    if (default_layer_state == (1 << 0)) {
        writePin(LED_MAC_OS_PIN, LED_OS_PIN_ON_STATE);
        writePin(LED_WIN_OS_PIN, !LED_OS_PIN_ON_STATE);
    }
    if (default_layer_state == (1 << 2)) {
        writePin(LED_MAC_OS_PIN, !LED_OS_PIN_ON_STATE);
        writePin(LED_WIN_OS_PIN, LED_OS_PIN_ON_STATE);
    }
}

void suspend_power_down_kb(void) {
    writePin(LED_WIN_OS_PIN, !LED_OS_PIN_ON_STATE);
    writePin(LED_MAC_OS_PIN, !LED_OS_PIN_ON_STATE);
    suspend_power_down_user();
}
