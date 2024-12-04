#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _SYMBOLS,
  _NUMBERS,
  _ADJUST,
  _BOOT
};

enum custom_keycodes {
  MA_Z = SAFE_RANGE,
  MA_X,
  MA_C,
  MA_V,
  MA_B
};

//
// Layer activation
//
#define SYMBOLS LT(_SYMBOLS, KC_BSPC)
#define NUMBERS LT(_NUMBERS, KC_SPC)
#define BOOT LT(_BOOT, KC_T)

//
// Qwerty layer
//
#define QW_A LSFT_T(KC_A)    // A
#define QW_S LCTL_T(KC_S)    // S
#define QW_D LALT_T(KC_D)    // D
#define QW_F LGUI_T(KC_F)    // F

#define QW_J LGUI_T(KC_J)    // J
#define QW_K LALT_T(KC_K)    // K
#define QW_L LCTL_T(KC_L)    // L
#define QW_C RSFT_T(KC_SCLN) // ;

//
// Numbers layer
//
#define NU_A LSFT_T(KC_GRV)  // `
#define NU_S LCTL_T(KC_4)    // 4
#define NU_D LALT_T(KC_5)    // 5
#define NU_F LGUI_T(KC_6)    // 6

//
// Symbols layer
//
#define SY_A LSFT_T(KC_MINS) // -   <-- good
#define SY_S LCTL_T(KC_AMPR) // &   <-- override in switch
#define SY_D LALT_T(KC_ASTR) // *   <-- override in switch
#define SY_F LGUI_T(KC_PLUS) // +   <-- override in switch

#define SY_J LGUI_T(KC_LCBR) // {   <-- override in switch
#define SY_K LALT_T(KC_RCBR) // }   <-- override in switch
#define SY_L LCTL_T(KC_DQUO) // "   <-- override in switch
#define SY_C LSFT_T(KC_QUOT) // '   <-- good

//
// Thumb Row
//
#define TAB LSFT_T(KC_TAB)   // Tab


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.    ,------,--------------.
 *                  |      |SYMBOLS|      |    |      |NUMBERS|      |
 *                  `--------------| TAB  |    |ENTER |------+-------.
 *                                 |      |    |      |
 *                                 `------'    `------'
 */
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_E,    KC_R,    BOOT,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  QW_A,    QW_S,    QW_D,    QW_F,    KC_G,         KC_H,    QW_J,    QW_K,    QW_L,    QW_C,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                 _______, SYMBOLS,   TAB,        KC_ENT,   NUMBERS,  _______
),


/**
 * 
 *  !    @    #    $    %        ^    (    )    |    _
 *  -    &    *    +    =        ~    {    }    "    '
 *  m    m    m    m    =             [    ]         \
 * 
 * 
 */
[_SYMBOLS] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_LPRN, KC_RPRN, KC_PIPE, KC_UNDS,
  SY_A,    SY_S,    SY_D,    SY_F,    KC_EQL,        KC_TILD, SY_J,    SY_K,    SY_L,    SY_C,
  MA_Z,    MA_X,    MA_C,    MA_V,    MA_B,          _______, KC_LBRC, KC_RBRC, _______, KC_BSLS,
                    _______, _______, _______,       _______, KC_DEL,  _______                   
),


/**
 * 
 *  ESC    7    8    9    GO+        ZO+    PU    UP    PD    V+
 *  GRV    4    5    6    GO-        ZO-    LE    DW    RI    V-
 *  CAP    1    2    3    =          B-     B+                VX
 * 
 */
[_NUMBERS] = LAYOUT_split_3x5_3(
  KC_ESC,   KC_7,  KC_8,  KC_9,  G(KC_RBRC),       G(KC_PPLS),   KC_PGUP,   KC_UP,     KC_PGDN,   KC_KB_VOLUME_UP,
  NU_A,     NU_S,  NU_D,  NU_F,  G(KC_LBRC),       G(KC_PMNS),   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_KB_VOLUME_DOWN,
  KC_CAPS,  KC_1,  KC_2,  KC_3,  KC_PEQL,          KC_BRID,      KC_BRIU,   _______,   _______,   KC_KB_MUTE,
              _______, _______,   KC_0,         _______, _______, _______
),



[_ADJUST] = LAYOUT_split_3x5_3(
  LSFT(KC_Q),    LSFT(KC_W),    LSFT(KC_E),    LSFT(KC_R),    LSFT(KC_T),         LSFT(KC_Y),    LSFT(KC_U),    LSFT(KC_I),    LSFT(KC_O),    LSFT(KC_P),
  LSFT(KC_A),    LSFT(KC_S),    LSFT(KC_D),    LSFT(KC_F),    LSFT(KC_G),         LSFT(KC_H),    LSFT(KC_J),    LSFT(KC_K),    LSFT(KC_L),    LSFT(KC_C),
  LSFT(KC_Z),    LSFT(KC_X),    LSFT(KC_C),    LSFT(KC_V),    LSFT(KC_B),         LSFT(KC_N),    LSFT(KC_M),    LSFT(KC_COMM), LSFT(KC_DOT),  LSFT(KC_SLSH),
                 _______, _______, _______,      _______, _______, _______
),


[_BOOT] =  LAYOUT_split_3x5_3(
  QK_BOOT, _______, _______, _______, _______,      _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______,      _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______,      _______, _______, _______, _______,  _______,
                    _______, _______, _______,      _______, _______, _______
)

};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    //
    // Tri layers
    //
    // case SYMBOLS:
    //   if (record->event.pressed) {
    //     layer_on(_SYMBOLS);
    //     update_tri_layer(_SYMBOLS, _NUMBERS, _ADJUST);
    //   } else {
    //     layer_off(_SYMBOLS);
    //     update_tri_layer(_SYMBOLS, _NUMBERS, _ADJUST);
    //   }

    //   break;

    // case NUMBERS:
    //   if (record->event.pressed) {
    //     layer_on(_NUMBERS);
    //     update_tri_layer(_SYMBOLS, _NUMBERS, _ADJUST);
    //   } else {
    //     layer_off(_NUMBERS);
    //     update_tri_layer(_SYMBOLS, _NUMBERS, _ADJUST);
    //   }

    //   break;

    // case SYMBOLS:
    //   if (record->event.pressed) {
    //     layer_on(_SYMBOLS);
    //     update_tri_layer(_SYMBOLS, _NUMBERS, _ADJUST);
    //   } else {
    //     layer_off(_SYMBOLS);
    //     update_tri_layer(_SYMBOLS, _NUMBERS, _ADJUST);
    //   }
    //   return false;

    // case NUMBERS:
    //   if (record->event.pressed) {
    //     layer_on(_NUMBERS);
    //     update_tri_layer(_SYMBOLS, _NUMBERS, _ADJUST);
    //   } else {
    //     layer_off(_NUMBERS);
    //     update_tri_layer(_SYMBOLS, _NUMBERS, _ADJUST);
    //   }
    //   return false;

    //
    // Overrides to allow Mod Taps to register shifted keys
    //
    case LCTL_T(KC_AMPR):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_AMPR);
        return false;
      }
      break;

    case LALT_T(KC_ASTR):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_ASTR);
        return false;
      }
      break;

    case LGUI_T(KC_PLUS):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_PLUS);
        return false;
      }
      break;

    case LGUI_T(KC_LCBR):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_LCBR);
        return false;
      }
      break;

    case LALT_T(KC_RCBR):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_RCBR);
        return false;
      }
      break;

    case LCTL_T(KC_DQUO):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_DQUO);
        return false;
      }
      break;


    //
    // Macros
    //
    case MA_Z:
      if (record->event.pressed) {
        SEND_STRING("1zqa!");
      }
      break;

    case MA_X:
      if (record->event.pressed) {
        SEND_STRING("2xws@");
      }
      break;

    case MA_C:
      if (record->event.pressed) {
        SEND_STRING("3ced#");
      }
      break;

    case MA_V:
      if (record->event.pressed) {
        SEND_STRING("4vrf$");
      }
      break;

    case MA_B:
      if (record->event.pressed) {
        SEND_STRING("5btg%");
      }
      break;

  }

  return true;
}
