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

#define VENDOR_ID       0x1337
#define PRODUCT_ID      0xDEAD
#define DEVICE_VER      0xBEEF
#define MANUFACTURER    Kodosaurus
#define PRODUCT         Orthosarus
#define DESCRIPTION     custom ortho

#define MATRIX_ROWS 5
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { B7, D5, C7, F1, F0 }
#define MATRIX_COL_PINS { D1, D0, D4, C6, D7, E6, B3, B1, F7, F6, F5, F4 }


#define LEADER_TIMEOUT 300
#endif
