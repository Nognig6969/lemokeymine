#pragma once
#include "stdint.h"
#include "stdlib.h"
#include "time.h"
#include "quantum_keycodes.h"


enum more_keycodes {
    INJECT_PASSWORD = SAFE_RANGE
};

typedef struct code {
    size_t code_capacity;
    size_t occupied;
    uint16_t *keycode_array;
} Code;

typedef struct codes {
    size_t index;
    size_t decision_point;
    Code *code_array;
} Codes;


void initializeCode(Code *code, size_t initial_codes_size);
void codeAppend(Code *code, uint16_t keycode);
void freeCode(Code *code);
void sendCode(Code code, int delay);
