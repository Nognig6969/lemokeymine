#include QMK_KEYBOARD_H

#include "keymap_italian.h"
#include "sendstring_italian.h"
#include "alias.h"
#include "tap_dance.h"
#include "combo.h"
#include "macro.h"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[INS] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   KC_Q,   KC_W,   TD_E,   KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    NO,      NO,      NO,     NO,
        NO,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,           KC_H,   KC_J,   KC_K,   KC_L,    TD_SCLN, NO,      NO,      NO,
        NO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   BT,     KC_N,   KC_M,   TD_COMM,TD_DOT,  TD_SLSH, NO,      NO,
        NO,   NO,     GONUM,  GONOR,          NO,     NO,     BSPC,   LEAD,   NO,     NO,      NO
),

[NOR] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   NO,     SW_WIN, SW_TAB, FILE,   NO,             QUOT,   UNDS,   DQT,    AMPR,    PIPE,    NO,      NO,      NO,      NO,
        NO,   HOME,   TD_S,   TD_D,   TD_F,   RUN,            LEFT,   DOWN,   UP,     RIGHT,   END,     NO,      NO,      NO,
        NO,   UNDO,   CUT,    TD_C,   PASTE,  REDO,   NO,     EXLM,   TD_RB,  TD_SB,  TD_CB,   PERC,    NO,      NO,
        NO,   NO,     NO,     NO,             NO,     NO,     DEL,    NO,     NO,     NO,      NO
),

[SYM] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,             NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,             AT,     DLR,    HASH,   GRV,     CIRC,    NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     TILD,   NO,     NO,      NO,      NO,      NO,
        NO,   NO,     NO,     SPC,            NO,     NO,     TRNS,   NO,     NO,     NO,      NO
),

[NUM] = LAYOUT_69_ansi(
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,     NO,      NO,      NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,             PLUS,   KC_7,   KC_8,   KC_9,    SLS,     NO,      NO,      NO,      NO,
        NO,   NO,     NO,     CTL,    KC_0,   NO,             MINS,   KC_4,   KC_5,   KC_6,    EQL,     NO,      NO,      NO,
        NO,   NO,     NO,     NO,     NO,     NO,     NO,     AST,    KC_1,   KC_2,   KC_3,    DOT,     NO,      NO,
        NO,   NO,     NO,     NO,             NO,     NO,     TRNS,   NO,     NO,     NO,      NO
),

};
// clang-format on
 uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_Q:
        case KC_A:
        case KC_Z:
        case KC_P:
        case KC_SCLN:
        case KC_SLSH:
            return 0 + get_generic_autoshift_timeout();
        case KC_EQL:
            return 9999;
        default:
            return get_generic_autoshift_timeout();
    }
}
