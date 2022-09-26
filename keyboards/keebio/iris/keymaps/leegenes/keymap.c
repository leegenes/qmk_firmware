#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_GRV,         KC_1,       KC_2,       KC_3,   KC_4,       KC_5,       // LT R1
    KC_6,           KC_7,       KC_8,       KC_9,   KC_0,       KC_BSPC,    // RT R1
    KC_TAB,         KC_Q,       KC_W,       KC_E,   KC_R,       KC_T,       // LT R2
    KC_Y,           KC_U,       KC_I,       KC_O,   KC_P,       KC_BSLS,    // RT R2
    LCTL_T(KC_ESC), KC_A,       KC_S,       KC_D,   KC_F,       KC_G,       // LT R3
    KC_H,           KC_J,       KC_K,       KC_L,   KC_SCLN,    KC_QUOT,    // RT R3
    KC_LSPO,        KC_Z,       KC_X,       KC_C,   KC_V,       KC_B,       // LT R4
    MO(3),                                                                  // LT TH Top
    KC_NO,                                                                  // RT TH Top
    KC_N,           KC_M,       KC_COMM,    KC_DOT, KC_SLSH,    KC_RSPC,    // LT R4
    KC_LGUI,        MO(1),      MO(2),                                      // LT TH Bottom
    KC_ENT,         KC_RALT,    KC_SPC                                      // RT TH Botton
  ),

  [_LOWER] = LAYOUT(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PLUS,    // LT R1
    KC_EQL,     KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_VOLD,    KC_VOLU,    // RT R1
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_MINS,    // LT R2
    KC_UNDS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_MUTE,    // RT R2
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LBRC,    // LT R3
    KC_RBRC,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      // RT R3
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LCBR,    // LT R4
    KC_NO,                                                                  // LT TH Top
    KC_NO,                                                                  // RT TH Top
    KC_RCBR,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      // LT R4
    KC_NO,      MO(0),      KC_NO,                                          // LT TH Bottom
    KC_NO,      KC_NO,      KC_NO                                           // RT TH Bottom
  ),

  [_RAISE] = LAYOUT(
    KC_F12,     KC_F1,      KC_F2,  KC_F3,      KC_F4,  KC_F5,  // LT R1
    KC_F6,      KC_F7,      KC_F8,  KC_F9,      KC_F10, KC_F11, // RT R1
    KC_NO,      KC_NO,      KC_NO,  KC_NO,      KC_NO,  KC_NO,  // LT R2
    KC_NO,      KC_NO,      KC_NO,  KC_NO,      KC_NO,  KC_NO,  // RT R2
    KC_NO,      KC_NO,      KC_NO,  KC_NO,      KC_NO,  KC_NO,  // LT R3
    KC_LEFT,    KC_DOWN,    KC_UP,  KC_RGHT,    KC_NO,  KC_NO,  // RT R3
    KC_NO,      KC_NO,      KC_NO,  KC_NO,      KC_NO,  KC_NO,  // LT R4
    KC_NO,                                                      // LT TH Top
    KC_NO,                                                      // RT TH Top
    KC_NO,      KC_NO,      KC_NO,  KC_NO,      KC_NO,  KC_NO,  // LT R4
    KC_NO,      KC_NO,      MO(0),                              // LT TH Bottom
    KC_NO,      KC_NO,      KC_NO                               // RT TH Bottom
    ),

  [_ADJUST] = LAYOUT(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,   // LT R1
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,   // RT R1
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,   // LT R2
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,   // RT R2
    DB_TOGG,    KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,   // LT R3
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,   // RT R3
    QK_BOOT,    RGB_TOG,    RGB_RMOD,   RGB_MOD,    KC_NO, KC_NO,   // LT R4
    MO(0),                                                          // LT TH Top
    KC_NO,                                                          // RT TH Top
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,   // LT R4
    KC_NO,      KC_NO,      KC_NO,                                  // LT TH Bottom
    KC_NO,      KC_NO,      KC_NO                                   // RT TH Bottom
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
