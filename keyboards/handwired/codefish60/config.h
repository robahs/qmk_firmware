#ifndef CONFIG_H
#define CONFIG_H

#define VENDOR_ID       0xC0DE
#define PRODUCT_ID      0xDEAD
#define DEVICE_VER      0xBEEF
#define MANUFACTURER    Kodosaurus
#define PRODUCT         Codefish
#define DESCRIPTION     custom fancy keyboard

#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 4
#define MATRIX_COLS 13

#define MATRIX_ROW_PINS {  B4, D7, D6, D4 }
#define MATRIX_COL_PINS { D2, D1, D0, D3, D5, B5, F0, B6, C6, C7, F1, F4, F5 }


#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
#endif
