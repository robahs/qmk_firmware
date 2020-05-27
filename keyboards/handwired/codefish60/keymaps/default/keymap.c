#include "codefish60.h"
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_QWERTY] = LAYOUT_codefish( \
               KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,    KC_BSLS,            \
               KC_BSPC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                          KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,            \
               KC_LCTL,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_ESC,           KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_LGUI,            \
                                    KC_LALT,  LOWER,  KC_SPC,   KC_LSFT,       KC_LEAD,          KC_LSFT,  KC_ENT,   RAISE,  KC_RALT                                 \
  ), \
  [_LOWER]  = LAYOUT_codefish( \
             KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                             KC_6,     KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPACE,          \
             KC_DEL,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,                           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_TRNS,            \
             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,         KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,            \
                                 KC_TRNS,  LOWER,  KC_TRNS, KC_TRNS,           KC_TRNS,          KC_TRNS,  KC_TRNS,  RAISE,  KC_TRNS                                 \
  ), \
  [_RAISE]  = LAYOUT_codefish( \
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,                           KC_TRNS, KC_MINS,  KC_EQL,   KC_LBRC, KC_RBRC, KC_PIPE,            \
              KC_TRNS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,  KC_TRNS,                           KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT, KC_TRNS, KC_TRNS,           \
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,        KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,           \
                                  KC_TRNS,  LOWER,  KC_TRNS, KC_TRNS,          KC_TRNS,           KC_TRNS,  KC_TRNS,  RAISE,  KC_TRNS                                \
  ), \
  [_ADJUST]  = LAYOUT_codefish( \
             KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                 KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,           \
             KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          \
             KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_PSCR,           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          \
                                KC_TRNS,  LOWER,  KC_TRNS, KC_TRNS,            KC_TRNS,           KC_TRNS,  KC_TRNS,  RAISE,  KC_TRNS                                 \
  ) \
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

        SEQ_THREE_KEYS(KC_G, KC_P, KC_U) {
            SEND_STRING("git push --set-upstream origin ");
        }
        SEQ_TWO_KEYS(KC_G, KC_P) {
            SEND_STRING("git push");
        }

        SEQ_TWO_KEYS(KC_G, KC_F) {
            SEND_STRING("git fetch --prune");
        }

        SEQ_THREE_KEYS(KC_Y, KC_U, KC_L) {
            SEND_STRING("yarn upgrade-interactive --latest");
        }
        SEQ_TWO_KEYS(KC_Y, KC_U) {
            SEND_STRING("yarn upgrade-interactive");
        }

        SEQ_THREE_KEYS(KC_Y, KC_L, KC_P) {
            SEND_STRING("yarn lerna publish --conventional-commits");
        }
        SEQ_TWO_KEYS(KC_Y, KC_L) {
            SEND_STRING("yarn lint --fix");
        }


    }
}