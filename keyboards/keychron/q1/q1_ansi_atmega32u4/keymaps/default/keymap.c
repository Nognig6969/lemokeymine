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

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER
};

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

//tap dance 2022/7/2 my branch
enum{
    TD_BE, TD_P50, CT_731,TD_LV,TD_ZX,TD_KO,
 TD_1, TD_2, TD_3, TD_4, TD_5, TD_6,
 TD_7, TD_8, TD_9, TD_10, TD_11, TD_12,
    CT_NUM
};

void triple_numpad (qk_tap_dance_state_t *state, void *user_data);
void triple_numpad (qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        register_code16(KC_P7);
    } else if(state->count == 2){
        register_code16(KC_P3);
    } else {
        register_code16(KC_P1);
    }
    
    if (state->count == 1) {
        unregister_code16(KC_P7);
    } else if(state->count == 2) {
        unregister_code16(KC_P3);
    } else {
        unregister_code16(KC_P1);
    }
};

void two_eight (qk_tap_dance_state_t *state, void *user_data);
void two_eight(qk_tap_dance_state_t *state, void *user_data) {
 if (state->count == 1) {
                 register_code16(KC_P8);
    } else if(state->count == 2){
                 register_code16(KC_P6);
    } else if(state->count == 3){
                register_code16(KC_P4);
    }  else {
                register_code16(KC_P2);
    }
 if (state->count == 1) {
              unregister_code16(KC_P8);
    } else if(state->count == 2) {
              unregister_code16(KC_P6);
    } else if(state->count == 3){
              unregister_code16(KC_P4);
    } else {
              unregister_code16(KC_P2);
    }
};

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_P7);
    unregister_code16(KC_P3);
    unregister_code16(KC_P1);
    unregister_code16(KC_P8);
    unregister_code16(KC_P6);
    unregister_code16(KC_P4);
    unregister_code16(KC_P2);
    
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BE] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_E),
    [TD_P50] = ACTION_TAP_DANCE_DOUBLE(KC_P5, KC_P0),
    [CT_731] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_numpad, dance_cln_reset),
    [TD_LV] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_V),
    [TD_ZX] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_X),
    [TD_KO] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_O),
 [TD_1]   = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
 [TD_2]   = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
 [TD_3]   = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
 [TD_4]   = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
 [TD_5]   = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
 [TD_6]   = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
 [TD_7]   = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
 [TD_8]   = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
 [TD_9]   = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
 [TD_10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
 [TD_11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
 [TD_12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),
    [CT_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, two_eight, dance_cln_reset)
};
/*
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
        TG(MAC_FN),          KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,  KC_PLUS, KC_QUES,    KC_NO,
        KC_ESC,     TD(TD_1),TD(TD_2), TD(TD_3), TD(TD_4), TD(TD_5), TD(TD_6), TD(TD_7), TD(TD_8), TD(TD_9), TD(TD_10),TD(TD_11),TD(TD_12),KC_BSPC,             KC_WH_U,
        KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,             KC_WH_D,
        KC_LCTL,    KC_A,    KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,              KC_GRV,
        KC_LSFT,             KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        MO(WIN_FN),KC_LALT,  KC_LGUI,                               KC_SPC,                                  KC_RGUI,  KC_LEAD, MO(WIN_FN),KC_LEFT, KC_DOWN,    KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        TO(WIN_BASE),         KC_F9,    KC_F2,      KC_F3,       KC_F4,     KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_TRNS, KC_TRNS,
        G(KC_EQL),G(KC_MINS), KC_F12,   KC_F7,      KC_F6,       TD(TD_KO), G(KC_K),   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,
        KC_WH_U,  KC_WH_D,    KC_ESC,   KC_SLSH,    ALT_T(KC_R), KC_F1,     G(KC_E),   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,
        KC_LEAD,  TD(CT_NUM), KC_S,     A(KC_LCTL), TD(TD_BE),   KC_G,      KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,          KC_TRNS,
        KC_TRNS,              KC_U,     KC_M,       TD(TD_ZX),   TD(TD_LV), KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,    KC_TRNS,                                      KC_TRNS,                                 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS),

    [WIN_BASE] = LAYOUT_ansi_82(
        TO(MAC_BASE),       KC_F,     KC_F2,    KC_F3,      KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,     KC_TRNS,
        KC_ESC,   KC_1,     KC_2,     KC_3,     TD(TD_P50), KC_GRV,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,               KC_TRNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,       KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,               KC_TRNS,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     TD(CT_NUM), KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
     TD(CT_731),  KC_TRNS,  KC_TRNS,                                  KC_SPC,                                 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,     KC_RGHT),
/*
    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_INS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
*/
    [WIN_FN] = LAYOUT_ansi_82(
        KC_TRNS,            KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_GRV,   KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_PENT,            KC_TRNS,
        KC_TILD,            G(KC_EQL),G(KC_MINS),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_MPLY,  KC_VOLU,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                   KC_TRNS,                                KC_TRNS,  SGUI(KC_4),KC_TRNS, KC_MPRV,  KC_VOLD,  KC_MNXT)
};

// leader key 2022/7/2
LEADER_EXTERNS();
void leader_start(void) {
  // sequence started
}
void leader_end(void) {
  // sequence ended (no success/failure detection)
}


//keymap layer declaration
enum{
    LED_LAYER_1 = 0,
    LED_LAYER_2,
    LED_LAYER_3,
    LED_LAYER_4,
    LED_LAYER_5,
};

void matrix_scan_user(void) {
    /* Set timers for factory reset and backlight test */
//    timer_task_start();
    
    /*set layer indicator 2022/7/2*/
    uint8_t layer = biton32(layer_state);
//darkgrey, aqua, purple, gold
    switch (layer){
        case LED_LAYER_1:
            rgb_matrix_set_color_all(0xA9, 0xA9, 0xA9);
            break;
        case LED_LAYER_2:
            rgb_matrix_set_color_all(0x00, 0xFF, 0xFF);
            break;
        case LED_LAYER_3:
            rgb_matrix_set_color_all(0x80, 0x00, 0x80);
            break;
        case LED_LAYER_4:
            rgb_matrix_set_color_all(0xFF, 0xD7, 0x00);
            break;
    };
    /*set leader key 2022/7/2*/
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
    
}
/*
bool dip_switch_update_user(uint8_t index, bool active) {
    system_switch_state_report(index, active);
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_other_record(keycode, record);
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;   // Process all other keycodes normally
    }
}
*/
