/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY;
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "test.h"
#include "print.h"

#define MY_RGB_ORANGE       0xFF, 0x22, 0x00
#define MY_RGB_GREEN        0x00, 0x4F, 0x00
#define MY_RGB_CYAN         0x00, 0x4F, 0x4F

enum custom_keycodes {
    MACRO000 = SAFE_RANGE,
    MACRO001
};

enum layers { _FN, _KP, _RGB};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_FN] = LAYOUT_numpad_6x4(
      KC_F1,    KC_F2,    KC_F3,    OSL(_KP),
      KC_F4,    KC_F5,    KC_F6,    MACRO000,
      KC_F7,    KC_F8,    KC_F9,
      KC_F10,   KC_F11,   KC_F12,   MACRO001,
      KC_VOLD,  KC_VOLU,  KC_MUTE,
      KC_MPLY,            KC_MNXT,  KC_ENT),

    [_KP] = LAYOUT_numpad_6x4(
      KC_CAPS,  KC_SLCK,  KC_PSCR,  OSL(_RGB),
      KC_NLCK,  KC_PAST,  KC_PSLS,  KC_PMNS,
      KC_P7,    KC_P8,    KC_P9,
      KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
      KC_P1,    KC_P2,    KC_P3,
      KC_P0,              KC_PDOT,  KC_PENT),

    [_RGB] = LAYOUT_numpad_6x4(
      RGB_TOG,  RGB_RMOD, RGB_MOD,  TO(_FN),
      RGB_HUI,  RGB_SAI,  RGB_VAI,  TO(_RGB),
      RGB_HUD,  RGB_SAD,  RGB_VAD,
      RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_SPI,
      RGB_M_SW, RGB_M_SN, RGB_M_K,
      RGB_M_X,            RGB_M_G,  RGB_SPD)
};

bool dip_switch_update_user(uint8_t index, bool active) {
    /* Send default layer state to host */
    system_switch_state_report(index, active);
    return true;
}

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(8, 255, 192);
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (layer_state_is(_FN)) {
        // rgb_matrix_sethsv_noeeprom(136, 255, 144);
        rgb_matrix_set_color( 0, MY_RGB_ORANGE);
        rgb_matrix_set_color( 1, MY_RGB_ORANGE);
        rgb_matrix_set_color( 2, MY_RGB_ORANGE);
        rgb_matrix_set_color( 3, RGB_MAGENTA);

        rgb_matrix_set_color( 4, MY_RGB_ORANGE);
        rgb_matrix_set_color( 5, MY_RGB_ORANGE);
        rgb_matrix_set_color( 6, MY_RGB_ORANGE);
        rgb_matrix_set_color( 7, RGB_BLUE);

        rgb_matrix_set_color( 8, MY_RGB_ORANGE);
        rgb_matrix_set_color( 9, MY_RGB_ORANGE);
        rgb_matrix_set_color(10, MY_RGB_ORANGE);
        rgb_matrix_set_color(11, MY_RGB_ORANGE);

        rgb_matrix_set_color(12, MY_RGB_ORANGE);
        rgb_matrix_set_color(13, MY_RGB_ORANGE);
        rgb_matrix_set_color(14, RGB_BLUE);

        rgb_matrix_set_color(15, MY_RGB_CYAN);
        rgb_matrix_set_color(16, MY_RGB_CYAN);
        rgb_matrix_set_color(17, MY_RGB_CYAN);

        rgb_matrix_set_color(18, MY_RGB_CYAN);
        rgb_matrix_set_color(19, MY_RGB_CYAN);
        rgb_matrix_set_color(20, RGB_GREEN);

        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();

        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();

        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();
        rgb_matrix_decrease_val_noeeprom();

    } else if (layer_state_is(_KP)) {
        rgb_matrix_set_color_all(RGB_SPRINGGREEN);
    } else if (layer_state_is(_RGB)) {
        // int h = rgb_matrix_get_hue();
        // int s = rgb_matrix_get_sat();
        // int v = rgb_matrix_get_val();
        // dprintf("HSV: %i %i %i", h, s, v);
        // rgb_matrix_set_color_all(RGB_CHARTREUSE);
    } else {
        rgb_matrix_set_color_all(RGB_WHITE);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO000:
            if (record->event.pressed) { // when keycode is pressed
                SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_F23) SS_UP(X_LALT) SS_UP(X_LCTRL));
            } else { // when keycode is released
            }
            break;

        case MACRO001:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_F24) SS_UP(X_LALT) SS_UP(X_LCTRL));
            } else {
            }
            break;
    }
    return true;
}
