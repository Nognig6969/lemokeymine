/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "test.h"
/*added layer indicator, tapdance, leaderkey
kenichirouyoshioka 2022/7/1 */

//LED MATRIX 5 layers indicator
//keymap layer declaration
enum{
    LED_LAYER_1 = 0,
    LED_LAYER_2,
    LED_LAYER_3,
    LED_LAYER_4,
    LED_LAYER_5,
};

//for leader key

LEADER_EXTERNS();
void leader_start(void) {
  // sequence started
}
void leader_end(void) {
  // sequence ended (no success/failure detection)
}

void matrix_scan_user(void) {
    
    LEADER_DICTIONARY() {
      leading = false;
      leader_end();
        SEQ_ONE_KEY(KC_ESC){
            register_code(KC_ESC);
            unregister_code(KC_ESC);
    }
        SEQ_TWO_KEYS(KC_ESC, KC_ESC) {
          register_code(KC_LGUI);
          register_code(KC_D);
          unregister_code(KC_D);
          unregister_code(KC_LGUI);
        }
      SEQ_THREE_KEYS(KC_ESC, KC_ESC, KC_ESC) {
         register_code(KC_LGUI);
               register_code(KC_T);
             unregister_code(KC_T);
        unregister_code(KC_LGUI);
      }
        
        SEQ_ONE_KEY(KC_SLSH){
            register_code(KC_LGUI);
            register_code(KC_Z);
            unregister_code(KC_LGUI);
            unregister_code(KC_Z);
    }
        SEQ_TWO_KEYS(KC_SLSH, KC_SLSH) {
          register_code(KC_LGUI);
            register_code(KC_LSFT);
                  register_code(KC_Z);
                unregister_code(KC_Z);
            unregister_code(KC_LSFT);
          unregister_code(KC_LGUI);
        }
    };


    uint8_t layer = biton32(layer_state);
//dimgray, brown, fireblick, forestgreen, midnightblue
    switch (layer){
        case LED_LAYER_1:
            rgb_matrix_set_color_all(0x69, 0x69, 0x69);
            break;
        case LED_LAYER_2:
            rgb_matrix_set_color_all(0x60, 0x30, 0x00);
            break;
        case LED_LAYER_3:
            rgb_matrix_set_color_all(0xb2, 0x22, 0x22);
            break;
        case LED_LAYER_4:
            rgb_matrix_set_color_all(0x22, 0x88, 0x22);
            break;
        case LED_LAYER_5:
            rgb_matrix_set_color_all(0x19, 0x19, 0x70);
            break;
    };
};


//tapdance_layerDeclarations
enum{
    TD_BE,
    TD_P50,
    TD_LV,
    TD_ZX,
    CT_731,
    TD_KO
};



void triple_numpad (qk_tap_dance_state_t *state, void *user_data);
void triple_numpad (qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 2) {
        register_code16(KC_P7);
    } else if(state->count == 3){
        register_code16(KC_P3);
    } else {
        register_code(KC_P1);
    }
    
    if (state->count == 2) {
        unregister_code16(KC_P7);
    } else if(state->count == 3) {
        unregister_code16(KC_P3);
    } else {
        unregister_code(KC_P1);

    }
};

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_P7);
    unregister_code16(KC_P3);
    unregister_code16(KC_P1);
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BE] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_E),
    [TD_P50] = ACTION_TAP_DANCE_DOUBLE(KC_P5, KC_P0),
    [TD_LV] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_V),
    [TD_ZX] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_X),
    [CT_731] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_numpad, dance_cln_reset),
    [TD_KO] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_O)
};

enum layers { _BASE = 0, _FN1, _RESERVED1, _RESERVED2, _BOTTOM};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_numpad_6x4(
        TG(_FN1),       MO(_RESERVED1),  TG(_RESERVED2), MO(_BOTTOM),
        KC_A,           KC_PDOT,         KC_TAB,         KC_ESC,
        KC_SPC,         KC_P8,           KC_HOME,
        KC_P4,          TD(TD_P50),      KC_P6,          KC_LEAD,
        TD(CT_731),     KC_P2,           KC_P9,
        KC_LCTL,                         KC_LSFT,        KC_LCTL),

    [_FN1] = LAYOUT_numpad_6x4(
        TO(_BASE),    MO(_RESERVED1), KC_LGUI,     KC_LSFT,
        G(KC_S),      KC_SPC,         A(KC_LCTL),  KC_TRNS,
        KC_WH_U,      KC_SLSH,        ALT_T(KC_R),
        KC_WH_D,      G(KC_EQL),      TD(TD_LV),   TD(TD_BE),
        KC_F1,        G(KC_MINS),     TD(TD_KO),
        KC_TRNS,                      TD(TD_ZX),   KC_LEAD),
    
    [_RESERVED1] = LAYOUT_numpad_6x4(
        KC_PENT,     TO(_BASE),  KC_HOME,        KC_END,
        KC_F10,      KC_F11,     KC_F12,         KC_TRNS,
        KC_F7,       KC_F8,      KC_F9,
        KC_F4,       KC_F5,      KC_F6,          KC_TRNS,
        KC_F1,       KC_F2,      KC_F3,
        KC_TRNS,                 KC_TRNS,        KC_TRNS),

    [_RESERVED2] = LAYOUT_numpad_6x4(
        KC_I,       KC_LGUI,     TO(_BASE),     MO(_BOTTOM),
        KC_1,       KC_2,        KC_3,          KC_TRNS,
        KC_Q,       KC_M,        KC_A,
        KC_G,       KC_Y,        KC_R,          KC_TRNS,
        KC_S,       KC_X,        KC_Z,
        KC_TRNS,                 KC_TRNS,       KC_TRNS),
    
    [_BOTTOM] = LAYOUT_numpad_6x4(
         KC_N,      KC_LGUI,     TO(_BASE),     MO(_RESERVED2),
         KC_L,      KC_J,        KC_TRNS,       KC_TRNS,
         KC_F,      SGUI(KC_Z),        KC_F9,
         KC_E,      KC_ENT,      KC_K,          KC_TRNS,
         KC_D,      KC_H,        KC_C,
         KC_TRNS,                KC_TRNS,       KC_TRNS)
};



//bool dip_switch_update_user(uint8_t index, bool active) {
    /* Send default layer state to host */
//    system_switch_state_report(index, active);
//    return true;
//};


//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    process_other_record(keycode, record);
//    return true;  // Process all other keycodes normally
//};
