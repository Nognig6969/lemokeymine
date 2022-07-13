<<<<<<<< HEAD:keyboards/keychron/s1/s1.h
/* Copyright 2022 @ Keychron (https://www.keychron.com)
========
/* Copyright 2021 @ Keychron (https://www.keychron.com)
>>>>>>>> playground:keyboards/keychron/v7/v7.h
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

<<<<<<<< HEAD:keyboards/keychron/s1/s1.h
#if   defined(KEYBOARD_keychron_s1_s1_ansi_stm32l432)
#    include "s1_ansi_stm32l432.h"
#elif defined(KEYBOARD_keychron_s1_s1_iso_stm32l432)
#    include "s1_iso_stm32l432.h"
========
#if defined(KEYBOARD_keychron_v7_v7_ansi_stm32l432)
#    include "v7_ansi_stm32l432.h"
#elif defined(KEYBOARD_keychron_v7_v7_iso_stm32l432)
#    include "v7_iso_stm32l432.h"
>>>>>>>> playground:keyboards/keychron/v7/v7.h
#endif
