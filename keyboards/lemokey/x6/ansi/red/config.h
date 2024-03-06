/* Copyright 2024 @ Keychron (https://www.keychron.com)
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

#ifdef LED_MATRIX_ENABLE
/* RGB Matrix Driver Configuration */
#    define SNLED27351_DRIVER_COUNT 1
#    define SNLED27351_I2C_ADDRESS_1 0b1110100

/* RGB Matrix Configuration */
#    define LED_MATRIX_LED_COUNT  68

/* Scan phase of led driver set as SNLED27351_PHASE_CHANNEL(defined as 0x03 in SNLED27351.h) */
#    define SNLED27351_PHASE_CHANNEL MSKPHASE_9CHANNEL
#    define SNLED27351_CURRENT_TUNE \
	{ 0xB0, 0xB0, 0xB0, 0xB0,0xB0, 0xB0, 0xB0, 0xB0,0xB0, 0xB0, 0xB0, 0xB0 }

#    define LED_MATRIX_KEYPRESSES
#endif
