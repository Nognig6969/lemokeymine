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
    LAYER_1,
    LAYER_2,
    LAYER_3,
    LAYER_4
};




LEADER_EXTERNS();

/*void leader_start(void) {
}
void leader_end(void) {
}
*/

void matrix_scan_user(void) {

    LEADER_DICTIONARY() {
      leading = false;
      leader_end();
        SEQ_ONE_KEY(KC_SLSH){
            register_code(KC_LGUI);
            register_code(KC_D);
            unregister_code(KC_D);
            unregister_code(KC_LGUI);
            
    }
        SEQ_TWO_KEYS(KC_SLSH, KC_SLSH) {
            register_code(KC_LGUI);
             register_code(KC_T);
             unregister_code(KC_T);
           unregister_code(KC_LGUI);

        }

        
        SEQ_ONE_KEY(KC_ESC){
            register_code(KC_LGUI);
            register_code(KC_Z);
            unregister_code(KC_Z);
            unregister_code(KC_LGUI);
    }
        SEQ_TWO_KEYS(KC_ESC, KC_ESC) {
          register_code(KC_LGUI);
            register_code(KC_LSFT);
                  register_code(KC_Z);
                unregister_code(KC_Z);
            unregister_code(KC_LSFT);
          unregister_code(KC_LGUI);
        }
        
        SEQ_ONE_KEY(KC_SPC){
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
    }
    };

    /*set layer indicator 2022/7/2*/
    uint8_t layer = biton32(layer_state);
//gray, darkturquoise, fireblick, forestgreen
    switch (layer){
        case LAYER_1:
            rgb_matrix_set_color_all(0x80, 0x80, 0x80);
            break;
        case LAYER_2:
            rgb_matrix_set_color_all(0x00, 0xCE, 0xD1);
            break;
        case LAYER_3:
            rgb_matrix_set_color_all(0xb2, 0x22, 0x22);
            break;
        case LAYER_4:
            rgb_matrix_set_color_all(0x22, 0x88, 0x22);
            break;
    }
};

/*
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
*/

//tap dance 2022/7/2 my branch
enum{
    TD_BE, TD_P50, CT_731,TD_LV,TD_ZX,TD_KO,
 TD_1, TD_2, TD_3, TD_4, TD_5, TD_6,
 TD_7, TD_8, TD_9, TD_10, TD_11, TD_12,
    CT_NUM,
    CT_F679,CT_GUM
};


void triple_numpad (qk_tap_dance_state_t *state, void *user_data);
void triple_numpad (qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        register_code16(KC_P7);
    } else if(state->count == 2){
        register_code(KC_P3);
    } else {
        register_code(KC_P1);
    }
    
    if (state->count == 1) {
        unregister_code16(KC_P7);
    } else if(state->count == 2) {
        unregister_code(KC_P3);
    } else {
        unregister_code(KC_P1);
    }
};

void g_u_m (qk_tap_dance_state_t *state, void *user_data);
void g_u_m (qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        register_code16(KC_G);
    } else if(state->count == 2){
        register_code16(KC_U);
    } else {
        register_code16(KC_M);
    }
    
    if (state->count == 2) {
        unregister_code16(KC_G);
    } else if(state->count == 3) {
        unregister_code16(KC_U);
    } else {
        unregister_code16(KC_M);

    }
};

void triple_function (qk_tap_dance_state_t *state, void *user_data);
void triple_function (qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        register_code16(KC_F6);
    } else if(state->count == 2){
        register_code16(KC_F7);
    } else {
        register_code16(KC_F9);
    }
    
    if (state->count == 2) {
        unregister_code16(KC_F6);
    } else if(state->count == 3) {
        unregister_code16(KC_F7);
    } else {
        unregister_code16(KC_F9);

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
    } else {
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

typedef enum{
    TD_NONE,
 TD_SINGLE_TAP ,
 TD_SINGLE_HOLD,
 TD_DOUBLE_TAP,
 TD_DOUBLE_HOLD,
// TD_DOUBLE_SINGLE_TAP

}td_state_t;

typedef struct { bool is_press_action;
  td_state_t  state; } td_tap_t;

enum{ TD_BEA = 0, SOME_OTHER_DANCE};


td_state_t cur_dance (qk_tap_dance_state_t *state){
 if(state -> count == 1){
   if (state -> interrupted || !state -> pressed) return TD_SINGLE_TAP;
     else return TD_SINGLE_HOLD;
 }else  if (state -> count == 2 ){
  if(state -> interrupted) return TD_DOUBLE_TAP;
  else if (state -> pressed) return  TD_DOUBLE_HOLD;
  else return TD_DOUBLE_TAP;
     
 }else if (state->count == 3) {
           if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
           else return TD_DOUBLE_HOLD;
       }
    return 0;
}

static td_tap_t xtap_state = {
 .is_press_action = true,
 .state = TD_NONE
};

void x_finished (qk_tap_dance_state_t *state, void *user_data){
 xtap_state.state = cur_dance(state);
  switch (xtap_state.state){
   case TD_SINGLE_TAP:  register_code16(KC_B); break;
   case TD_SINGLE_HOLD: register_code16(A(KC_LCTL)); break;
   case TD_DOUBLE_TAP:  register_code16(KC_E); break;
      case TD_DOUBLE_HOLD: register_code16(A(KC_LCTL));
//   case TD_DOUBLE_SINGLE_TAP: register_code(KC_E); unregister_code(KC_E); register_code(KC_E);
   case TD_NONE: unregister_code16(KC_LALT);
  }
    xtap_state.state = TD_NONE;
}


void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code16(KC_P8);
    unregister_code16(KC_P7);
    unregister_code16(KC_P6);
    unregister_code16(KC_P4);
    unregister_code16(KC_P2);
    unregister_code16(KC_P3);
    unregister_code16(KC_P1);
    unregister_code16(KC_B);
    unregister_code16(KC_E);
    unregister_code16(A(KC_LCTL));
    unregister_code16(KC_F6);
    unregister_code16(KC_F7);
    unregister_code16(KC_F9);
    unregister_code16(KC_G);
    unregister_code16(KC_U);
    unregister_code16(KC_M);
    unregister_code16(KC_T);
    unregister_code16(KC_D);
    
};



qk_tap_dance_action_t tap_dance_actions[] = {
//    [TD_BE] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_E),
    [TD_P50] = ACTION_TAP_DANCE_DOUBLE(KC_P5, KC_P0),
    [CT_731] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_numpad, dance_cln_reset),
    [TD_LV] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_V),
    [TD_ZX] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_Z),
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
 [TD_10]  = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
 [TD_11]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
 [TD_12]  = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),
    [CT_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, two_eight, dance_cln_reset),
    [TD_BEA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, dance_cln_reset),
    [CT_F679] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, triple_function, dance_cln_reset),
    [CT_GUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, g_u_m, dance_cln_reset)
};
/*
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_1] = LAYOUT_ansi_82(
        TG(LAYER_2),         KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,  KC_PLUS, KC_QUES,    KC_NO,
        KC_ESC,     TD(TD_1),TD(TD_2), TD(TD_3), TD(TD_4), TD(TD_5), TD(TD_6), TD(TD_7), TD(TD_8), TD(TD_9), TD(TD_10),TD(TD_11),TD(TD_12),KC_BSPC,             KC_WH_U,
        KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,             KC_WH_D,
        KC_LCTL,    KC_A,    KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,              KC_GRV,
        KC_LSFT,             KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        MO(LAYER_4),KC_LALT, KC_LGUI,                                KC_SPC,                                 KC_RGUI,  KC_RCTL,MO(LAYER_4),KC_LEFT, KC_DOWN,    KC_RGHT),

    [LAYER_2] = LAYOUT_ansi_82(
        TO(LAYER_3),       KC_F12,     KC_F2,     KC_F3,      KC_F4,       KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_TRNS, KC_TRNS,
        KC_LBRC,  KC_RBRC, TD(CT_NUM), TD(TD_P50),TD(CT_731), G(KC_K),     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,
        G(KC_0),  G(KC_N), KC_SLSH,    KC_ESC,    KC_F1,      TD(CT_F679), KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,
        KC_LCTL,  KC_LEAD, KC_WH_D,    KC_WH_U,   TD(TD_BEA), ALT_T(KC_R), KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,          KC_TRNS,
        KC_TRNS,           TD(CT_GUM), TD(TD_ZX), TD(TD_LV),  TD(TD_KO),   G(KC_E),   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS,                                        KC_TRNS,                                 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS),

    [LAYER_3] = LAYOUT_ansi_82(
        TO(LAYER_1),       KC_F,     KC_F2,    KC_F3,      KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,     KC_TRNS,
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
    [LAYER_4] = LAYOUT_ansi_82(
        KC_TRNS,            KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_GRV,   KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,     RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,     RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_PENT,            KC_TRNS,
        KC_TILD,            G(KC_EQL),G(KC_MINS),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_MPLY,  KC_VOLU,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                   KC_TRNS,                                KC_TRNS,  SGUI(KC_4),KC_TRNS, KC_MPRV,  KC_VOLD,  KC_MNXT)
};

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
