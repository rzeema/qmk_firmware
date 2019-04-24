/* Copyright 2019 %YOUR_NAME%
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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  HELLO = SAFE_RANGE,
  Gmail,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"
#define KC_DRS1 DYN_REC_START1
#define KC_DRS2 DYN_REC_START2
#define KC_DRSP DYN_REC_STOP
#define KC_DMP1 DYN_MACRO_PLAY1
#define KC_DMP2 DYN_MACRO_PLAY2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, \
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, \
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, \
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL, \
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), MO(2), KC_LEFT, KC_DOWN, KC_RGHT \
  ),

  [1] = LAYOUT( /* Fn1 */
		_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_MS_U, _______, _______, \
		_______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_MS_L, KC_MS_R, _______, \
		_______, _______, _______, _______, _______, _______, KC_BRIU, KC_BRID, KC_END, KC_PGDN, KC_MS_D, KC_INS, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [2] = LAYOUT( /* Fn2 RGB & Macros*/
		_______, HELLO, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DMP1, KC_DMP2, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, Gmail, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, _______, \
		MO(3), _______, _______, RGB_TOG, _______, _______, RGB_RMOD, RGB_VAD, RGB_MOD \
  ),

  [3] = LAYOUT( /* Macro Recording */
		RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DRS1, KC_DRS2, KC_DRSP, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Dynamic Macros
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case HELLO:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("Hello world!" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case Gmail:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("@gmail.com");
      } else {
        // when keycode QMKBEST is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
