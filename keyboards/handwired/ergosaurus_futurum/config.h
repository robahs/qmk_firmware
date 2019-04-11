/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,kkkksgfds
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#define EE_HANDS
#define USE_SERIAL
#define SOFT_SERIAL_PIN D0

#include "config_common.h"

#define VENDOR_ID       0x1337
#define PRODUCT_ID      0xDEAD
#define DEVICE_VER      0xBEEF
#define MANUFACTURER    Grillapa
#define PRODUCT         Ergosaurus
#define DESCRIPTION     extended iris w/ encoder

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { C7, B4, E6, D7, C6, D4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2 }
#define MATRIX_COL_PINS_RIGHT { B2, B3, B1, F7, F6, F5, F4 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 0

/* ws2812 RGB LED */
#define RGB_DI_PIN B6
#define RGBLED_NUM 16 // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLED_SPLIT { 8, 8 }
#define LEADER_TIMEOUT 300
#endif
