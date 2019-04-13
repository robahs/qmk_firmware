#include "ergosaurus.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

#include <print.h>

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

void tap(uint16_t keycode){
    register_code(keycode);
    unregister_code(keycode);
};

/*
                                                 CCW, SW,  ECW, \
    L00, L01, L02, L03, L04, L05, L06,           R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25,                     R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, LT4,           RT4, R30, R31, R32, R33, R34, R35, \
                   LT1, LT2, LT3, LT5,           RT5, RT3, RT2, RT1 \
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ergosaurus( \
                                                                                      KC_VOLD, KC_MUTE, KC_VOLU, \
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINUS,               KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,                 KC_LEAD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI, \
                                   KC_LALT, KC_LOWR, KC_SPC,  KC_LSFT,                KC_LSFT, KC_ENT,  KC_RASE, KC_RALT \
  ), \
  [_COLEMAK] = LAYOUT_ergosaurus( \
                                                                                      KC_VOLD, KC_MUTE, KC_VOLU, \
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINUS,               KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  \
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC,                KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,                 KC_LEAD, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI, \
                                   KC_LALT, KC_LOWR, KC_SPC,  KC_LSFT,                KC_LSFT, KC_ENT,  KC_RASE, KC_RALT \
  ), \
  [_LOWER] = LAYOUT_ergosaurus( \
                                                                                      KC_RHUD, KC_MUTE, KC_RHUI, \
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                 KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
        _______, _______, _______, _______, _______, _______, RGB_RMOD,               RGB_MOD, _______, _______, _______, _______, _______, _______, \
        KC_DEL,  _______, _______, _______, _______, _______,                                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, \
                                   _______, _______, _______, _______,                _______, _______, _______, _______ \
  ), \
  [_RAISE] = LAYOUT_ergosaurus( \
                                                                                      KC_RSAD, KC_MUTE, KC_RSAI, \
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                 KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_RST,  \
        _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                                  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, \
        _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, \
                                   _______, _______, _______, _______,                _______, _______, _______, _______ \
  ), \
  [_ADJUST] = LAYOUT_ergosaurus( \
                                                                                      KC_RVAD, KC_MUTE, KC_RVAI, \
        _______, QWERTY,  COLEMAK, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                                  _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, \
                                   _______, _______, _______, _______,                _______, _______, _______, _______ \
  ), \
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
      case COLEMAK:
          if (record->event.pressed) {
              persistent_default_layer_set(1UL<<_COLEMAK);
          }
          return false;
          break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_H) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) \
                        SS_UP(X_LCTRL) SS_UP(X_LGUI));
        }
        SEQ_ONE_KEY(KC_L) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) \
                        SS_UP(X_LCTRL) SS_UP(X_LGUI));
        }

        SEQ_ONE_KEY(KC_EQL) {
            SEND_STRING("=>");
        }
        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_G, KC_A) {
            SEND_STRING("git add -A");
        }
    }
}