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

#pragma once

#include "quantum.h"
<<<<<<< HEAD:keyboards/keychron/k8_pro/k8_pro.h
#ifdef VIA_ENABLE
#    include "via.h"
=======

#if   defined(KEYBOARD_keychron_q2_ansi)
#    include "ansi.h"
#elif defined(KEYBOARD_keychron_q2_ansi_encoder)
#    include "ansi_encoder.h"
#elif defined(KEYBOARD_keychron_q2_iso)
#    include "iso.h"
#elif defined(KEYBOARD_keychron_q2_iso_encoder)
#    include "iso_encoder.h"
>>>>>>> master:keyboards/keychron/q2/q2.h
#endif

#define ___ KC_NO

#ifdef VIA_ENABLE
#    define USER_START USER00
#else
#    define USER_START SAFE_RANGE
#endif

// clang-format off
enum {
    KC_LOPTN = USER_START,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_MCTL,
    KC_LNPD,
    KC_TASK,
    KC_FILE,
    KC_SNAP,
    KC_CTANA,
    KC_SIRI,
#ifdef KC_BLUETOOTH_ENABLE
    BT_HST1,
    BT_HST2,
    BT_HST3,
#endif
    BAT_LVL,
	NEW_SAFE_RANGE,
};
