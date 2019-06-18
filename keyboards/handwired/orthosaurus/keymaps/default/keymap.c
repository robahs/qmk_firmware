#include "orthosaurus.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_orthosaurus( \
    KC_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           KC_6,     KC_7,     KC_8,     KC_9,    KC_0,    KC_DEL,    \
    KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,           KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,    KC_BSLS,   \
    KC_BSPC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,           KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,   \
    KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,           KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,   \
    KC_LCTL,   KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LOWR,  KC_SPC,         KC_ENT,   KC_RASE,  KC_RALT,  KC_LEAD, KC_NO,   KC_LGUI    \
  ), \
  [_LOWER]  = LAYOUT_orthosaurus( \
    _______,  _______,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______, _______, _______,   \
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,            KC_6,     KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPACE, \
    KC_DEL,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, _______,   \
    _______,  _______,  _______,  _______,  _______, _______,          _______,  _______,  _______,  _______, _______, _______,   \
    _______,  _______,  _______,  _______,  KC_LOWR, _______,          _______,  KC_RASE,  _______,  _______, _______, _______   \
  ), \
  [_RAISE]  = LAYOUT_orthosaurus( \
    KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12, \
    _______,  _______, _______, _______, _______, _______,             _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_PIPE, \
    _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,             KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______, \
    _______,  _______, _______, _______, _______, _______,             _______,  _______,  _______,  _______,  _______,  _______, \
    _______,  _______, _______, _______, KC_LOWR, _______,             _______,  KC_RASE,  _______,  _______,  _______,  _______ \
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