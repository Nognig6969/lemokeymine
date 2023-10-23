#include "hack_common.h"
#include QMK_KEYBOARD_H


void initializeCode(Code *code, size_t initial_code_size) {
    code->code_capacity = initial_code_size;
    code->occupied = 0;
    code->keycode_array = (uint16_t*)malloc(initial_code_size * sizeof(uint16_t));
    
}

void codeAppend(Code *code, uint16_t keycode) {
    if(code->occupied == code->code_capacity) {
        code->code_capacity += 1;
        code->keycode_array = realloc(code->keycode_array, code->code_capacity * sizeof(uint16_t));
    }
    code->keycode_array[code->occupied++] = keycode;
}

void freeCode(Code *code) {
    free(code->keycode_array);
    code->keycode_array = NULL;
    code->occupied = 0; 
}

void sendCode(Code code, int delay) {
    for(int i = 0; i < code.occupied; i++){
        tap_code16_delay(code.keycode_array[i], delay);
    }
}