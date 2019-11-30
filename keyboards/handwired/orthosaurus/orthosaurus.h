#ifndef ORTHOSAURUS_H
#define ORTHOSAURUS_H

#include "quantum.h"

#define KEYMAP( \
    L00, L01, L02, L03, L04, L05,            R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,            R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,            R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,            R30, R31, R32, R33, R34, R35,\
    L40, L41, L42, L43,   L44,   L45,   R50,   R51   , R52, R53, R54, R55 \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05,            R00, R01, R02, R03, R04, R05 }, \
        { L10, L11, L12, L13, L14, L15,            R10, R11, R12, R13, R14, R15 }, \
        { L20, L21, L22, L23, L24, L25,            R20, R21, R22, R23, R24, R25 }, \
        { L30, L31, L32, L33, L34, L35,            R30, R31, R32, R33, R34, R35 }, \
        { L40, L41, L42, L43, L44, L45,            R50, R51, R52, R53, R54, R55 } \
    }


#define LAYOUT_orthosaurus KEYMAP

#define KEYMAP2( \
    L00, L01, L02, L03, L04, L05,            R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,            R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,            R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,            R30, R31, R32, R33, R34, R35,\
                             L45,            R50 \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05,                      R00, R01, R02, R03, R04, R05 }, \
        { L10, L11, L12, L13, L14, L15,                      R10, R11, R12, R13, R14, R15 }, \
        { L20, L21, L22, L23, L24, L25,                      R20, R21, R22, R23, R24, R25 }, \
        { L30, L31, L32, L33, L34, L35,                      R30, R31, R32, R33, R34, R35 }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, L45,            R50, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    }

#define LAYOUT_orthosaurusr2 KEYMAP2
#endif
