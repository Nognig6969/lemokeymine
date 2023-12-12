typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}
  
enum {
	TD__F,
    TD__C,
    TD__D,
    TD__S,
    TD__RB,
    TD__SB,
    TD__CB,
    TD__E,
    TD__SCLN,
    TD__SLSH,
    TD__COMM,
    TD__DOT,
};

static td_tap_t td_f_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void f_finished(tap_dance_state_t *state, void *user_data) {
    td_f_state.state = cur_dance(state);
    switch (td_f_state.state) {
        case TD_SINGLE_TAP: register_code(CTL); register_code(KC_F); break;
        case TD_SINGLE_HOLD: register_code(SFT); break;
        case TD_DOUBLE_TAP: register_code(CTL); register_code(SFT); register_code(KC_F); break;
        case TD_DOUBLE_SINGLE_TAP: register_code(CTL); register_code(SFT); register_code(KC_F); break;
        default: break;
    }
}

void f_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_f_state.state) {
        case TD_SINGLE_TAP: unregister_code(CTL); unregister_code(KC_F); break;
        case TD_SINGLE_HOLD: unregister_code(SFT); break;
        case TD_DOUBLE_TAP: unregister_code(CTL); unregister_code(SFT); unregister_code(KC_F); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(CTL); unregister_code(SFT); unregister_code(KC_F); break;
        default: break;
    }
    td_f_state.state = TD_NONE;
}

static td_tap_t td_c_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void c_finished(tap_dance_state_t *state, void *user_data) {
    td_c_state.state = cur_dance(state);
    switch (td_c_state.state) {
        case TD_SINGLE_TAP: register_code(CTL); register_code(KC_C); break;
        case TD_SINGLE_HOLD: register_code(CTL); register_code(KC_C); break;
        case TD_DOUBLE_TAP: register_code(CTL); register_code(SFT); register_code(KC_C); break;
        case TD_DOUBLE_SINGLE_TAP: register_code(CTL); register_code(SFT); register_code(KC_C); break;
        default: break;
    }
}

void c_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_c_state.state) {
        case TD_SINGLE_TAP: unregister_code(CTL); unregister_code(KC_C); break;
        case TD_SINGLE_HOLD: unregister_code(CTL); unregister_code(KC_C); break;
        case TD_DOUBLE_TAP: unregister_code(CTL); unregister_code(SFT); unregister_code(KC_C); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(CTL); unregister_code(SFT); unregister_code(KC_C); break;
        default: break;
    }
    td_c_state.state = TD_NONE;
}

static td_tap_t td_d_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void d_finished(tap_dance_state_t *state, void *user_data) {
    td_d_state.state = cur_dance(state);
    switch (td_d_state.state) {
        case TD_SINGLE_TAP: register_code(CTL); register_code(KC_D); break;
        case TD_SINGLE_HOLD: register_code(CTL); break;
        default: break;
    }
}

void d_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_d_state.state) {
        case TD_SINGLE_TAP: unregister_code(CTL); unregister_code(KC_D); break;
        case TD_SINGLE_HOLD: unregister_code(CTL);break;
        default: break;
    }
    td_d_state.state = TD_NONE;
}

static td_tap_t td_s_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void s_finished(tap_dance_state_t *state, void *user_data) {
    td_s_state.state = cur_dance(state);
    switch (td_s_state.state) {
        case TD_SINGLE_TAP: register_code(CTL); register_code(KC_S); break;
        case TD_SINGLE_HOLD: register_code(ALT); break;
        default: break;
    }
}

void s_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_s_state.state) {
        case TD_SINGLE_TAP: unregister_code(CTL); unregister_code(KC_S); break;
        case TD_SINGLE_HOLD: unregister_code(ALT);break;
        default: break;
    }
    td_s_state.state = TD_NONE;
}

static td_tap_t td_rb_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void rb_finished(tap_dance_state_t *state, void *user_data) {
    td_rb_state.state = cur_dance(state);
    switch (td_rb_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("("); break;
        case TD_SINGLE_HOLD: SEND_STRING(")"); break;
        case TD_DOUBLE_TAP:  SEND_STRING("()" SS_TAP(X_LEFT)); break;
        case TD_DOUBLE_SINGLE_TAP: SEND_STRING("() SS_TAP(X_LEFT)"); break;
        default: break;
    }
}

static td_tap_t td_sb_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void sb_finished(tap_dance_state_t *state, void *user_data) {
    td_sb_state.state = cur_dance(state);
    switch (td_sb_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("["); break;
        case TD_SINGLE_HOLD: SEND_STRING("]"); break;
        case TD_DOUBLE_TAP:  SEND_STRING("[]" SS_TAP(X_LEFT)); break;
        case TD_DOUBLE_SINGLE_TAP: SEND_STRING("[]" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

static td_tap_t td_cb_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void cb_finished(tap_dance_state_t *state, void *user_data) {
    td_cb_state.state = cur_dance(state);
    switch (td_cb_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("{"); break;
        case TD_SINGLE_HOLD: SEND_STRING("}"); break;
        case TD_DOUBLE_TAP:  SEND_STRING("{}" SS_TAP(X_LEFT)); break;
        case TD_DOUBLE_SINGLE_TAP: SEND_STRING("{}" SS_TAP(X_LEFT)); break;
        default: break;
    }
}

static td_tap_t td_e_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void e_finished(tap_dance_state_t *state, void *user_data) {
    td_e_state.state = cur_dance(state);
    switch (td_e_state.state) {
        case TD_SINGLE_TAP: register_code(KC_E); break;
        case TD_SINGLE_HOLD: register_code(SFT); register_code(KC_E); break;
        case TD_DOUBLE_TAP: register_code(IT_EGRV); break;
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_E); register_code(KC_E); break;
        default: break;
    }
}

void e_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_e_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_E); break;
        case TD_SINGLE_HOLD: unregister_code(SFT); unregister_code(KC_E); break;
        case TD_DOUBLE_TAP: unregister_code(IT_EGRV); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_E); unregister_code(KC_E); break;
        default: break;
    }
    td_e_state.state = TD_NONE;
}

static td_tap_t td_scln_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void scln_finished(tap_dance_state_t *state, void *user_data) {
    td_scln_state.state = cur_dance(state);
    switch (td_scln_state.state) {
        case TD_SINGLE_TAP: SEND_STRING(";"); break;
        case TD_SINGLE_HOLD: SEND_STRING(":"); break;
        case TD_DOUBLE_TAP: SEND_STRING("::"); break;
        case TD_DOUBLE_SINGLE_TAP: SEND_STRING("::"); break;
        default: break;
    }
}

static td_tap_t td_slsh_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void slsh_finished(tap_dance_state_t *state, void *user_data) {
    td_slsh_state.state = cur_dance(state);
    switch (td_slsh_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("/"); break;
        case TD_SINGLE_HOLD: SEND_STRING("?"); break;
        case TD_DOUBLE_TAP: SEND_STRING("\\"); break;
        case TD_DOUBLE_SINGLE_TAP: SEND_STRING("\\"); break;
        default: break;
    }
}

static td_tap_t td_comm_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void comm_finished(tap_dance_state_t *state, void *user_data) {
    td_comm_state.state = cur_dance(state);
    switch (td_comm_state.state) {
        case TD_SINGLE_TAP: SEND_STRING(","); break;
        case TD_SINGLE_HOLD: SEND_STRING("<"); break;
        case TD_DOUBLE_TAP: SEND_STRING(",,"); break;
        case TD_DOUBLE_SINGLE_TAP: SEND_STRING(",,"); break;
        default: break;
    }
}

static td_tap_t td_dot_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void dot_finished(tap_dance_state_t *state, void *user_data) {
    td_dot_state.state = cur_dance(state);
    switch (td_dot_state.state) {
        case TD_SINGLE_TAP: SEND_STRING("."); break;
        case TD_SINGLE_HOLD: SEND_STRING(">"); break;
        case TD_DOUBLE_TAP: SEND_STRING(".."); break;
        case TD_DOUBLE_SINGLE_TAP: SEND_STRING(".."); break;
        default: break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
  	[TD__F] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, f_finished, f_reset),
    [TD__C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, c_finished, c_reset),
    [TD__D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, d_finished, d_reset),
    [TD__S] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, s_finished, s_reset),
    [TD__RB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rb_finished, NULL),
    [TD__SB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sb_finished, NULL),
    [TD__CB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cb_finished, NULL),
    [TD__E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_finished, e_reset),
    [TD__SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, scln_finished, NULL),
    [TD__SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slsh_finished, NULL),
    [TD__COMM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, comm_finished, NULL),
    [TD__DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_finished, NULL),
}; 
