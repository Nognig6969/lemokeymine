#include QMK_KEYBOARD_H


RGB_MATRIX_EFFECT(flash_code_rgb) 

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#include "getter.h"

#define KEYCODE 0
#define RGB_INDEX 1
#define SHIFTED 59
#define ALTED 77

uint16_t keycode_to_led_mapping[MATRIX_ROWS][MATRIX_COLS][2] = {
    { {KC_ESC, 0},   {KC_F1, 1},    {KC_F2, 2},    {KC_F3, 3}, {KC_F4, 4}, {KC_F5, 5}, {KC_F6, 6},   {KC_F7, 7}, {KC_F8, 8}, {KC_F9, 9},   {KC_F10, 10},   {KC_F11, 11},  {KC_F12, 12},  {KC_DEL, 13},  {0,0},         {KC_MUTE, 14} },
    { {KC_GRV, 15},  {KC_1, 16},    {KC_2, 17},    {KC_3, 18}, {KC_4, 19}, {KC_5, 20}, {KC_6, 21},   {KC_7, 22}, {KC_8, 23}, {KC_9, 24},    {KC_0, 25},    {KC_MINS, 26}, {KC_EQL, 27},  {KC_BSPC, 28}, {0,0},         {KC_PGUP, 29} },
    { {KC_TAB, 30},  {KC_Q, 31},    {KC_W, 32},    {KC_E, 33}, {KC_R, 34}, {KC_T, 35}, {KC_Y, 36},   {KC_U, 37}, {KC_I, 38}, {KC_O, 39},    {KC_P, 40},    {KC_LBRC, 41}, {KC_RBRC, 42}, {KC_ENT, 57},  {0,0},         {KC_PGDN, 43} },
    { {KC_CAPS, 44}, {KC_A, 45},    {KC_S, 46},    {KC_D, 47}, {KC_F, 48}, {KC_G, 49}, {KC_H, 50},   {KC_J, 51}, {KC_K, 52}, {KC_L, 53},    {KC_SCLN, 54}, {KC_QUOT, 55}, {0,0},         {KC_NUHS, 56}, {0,0},         {KC_HOME, 58} },
    { {KC_LSFT, 59}, {KC_NUBS, 60}, {KC_Z, 61},    {KC_X, 62}, {KC_C, 63}, {KC_V, 64}, {KC_B, 65},   {KC_N, 66}, {KC_M, 67}, {KC_COMM, 68}, {KC_DOT, 69},  {KC_SLSH, 70}, {0,0},         {KC_RSFT, 71}, {KC_UP, 72},   {0,0} },
    { {KC_LCTL, 73}, {KC_LWIN, 74}, {KC_LALT, 75}, {0,0},      {0,0},      {0,0},      {KC_SPC, 76}, {0,0},      {0,0},      {0,0},         {KC_RALT, 77}, {0, 78},       {KC_RCTL, 79}, {KC_LEFT, 80}, {KC_DOWN, 81}, {KC_RGHT, 82} }
};

static uint16_t key_timer = 0;
int occupied_index = 0;
int prev_row = 5;
int prev_col = 0;
bool change = true;
bool shifted = false;
bool alted = false;
bool init_timer = false;

bool set_new_RGB_state(int row, int col, bool mod, int led_index) {
    rgb_matrix_set_color(keycode_to_led_mapping[row][col][RGB_INDEX], RGB_RED);
    prev_row = row;
    prev_col = col;
    change = false;
    
    if(mod) {
        rgb_matrix_set_color(led_index, RGB_RED); // Shifted
        return true;
    } 
    return false;
}

void checkTimer(void) {
    if(timer_elapsed(key_timer) > 2000) {
        change = true;
        key_timer = 0;
        rgb_matrix_set_color(keycode_to_led_mapping[prev_row][prev_col][RGB_INDEX], RGB_BLACK);
        if(shifted) {
            rgb_matrix_set_color(SHIFTED, RGB_BLACK);
            shifted = false;
        }
        else if(alted) {
            rgb_matrix_set_color(ALTED, RGB_BLACK);
            alted = false;
        }
    }
}


static bool flash_code_rgb(effect_params_t* params) {

    if(!getReady()) {
        rgb_matrix_set_color(keycode_to_led_mapping[prev_row][prev_col][RGB_INDEX], RGB_BLACK);
        rgb_matrix_set_color(SHIFTED, RGB_BLACK);
        rgb_matrix_set_color(ALTED, RGB_BLACK);
    }

    if(init_timer) {
        key_timer = timer_read();
        init_timer = false;
    }

    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    checkTimer();
    
    Code keycodes = getCode();
    if(getReady() && change) {
        for(uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
            for(uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
                if(keycode_to_led_mapping[row_index][col_index][KEYCODE] == keycodes.keycode_array[occupied_index]){
                    set_new_RGB_state(row_index, col_index, false, 0);
                    break;
                }
                else if ((0 < row_index)  && (row_index < 6) && (0 < col_index) && (col_index < 12) && keycode_to_led_mapping[row_index][col_index][KEYCODE] != 0) {
                    if(LSFT(keycode_to_led_mapping[row_index][col_index][KEYCODE]) == keycodes.keycode_array[occupied_index]) {
                        shifted = set_new_RGB_state(row_index, col_index, true, SHIFTED);
                        break;
                    }
                    else if(RALT(keycode_to_led_mapping[row_index][col_index][KEYCODE]) == keycodes.keycode_array[occupied_index]) {
                        alted = set_new_RGB_state(row_index, col_index, true, ALTED);
                        break;
                    }
                }
            }
            if(!change) {
                occupied_index++;
                init_timer = true;
                break;
            }
        }
    }
    
    if(occupied_index >= keycodes.occupied) {
        occupied_index = 0;
    }
    
    return rgb_matrix_check_finished_leds(led_max);
}


#endif //RGB_MATRIX_CUSTOM_EFFECT_IMPLS

