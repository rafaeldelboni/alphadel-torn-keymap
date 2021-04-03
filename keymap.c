/* 
 * Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
 * Copyright 2021 Rafael Delboni (rafael@delboni.cc)
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

#define CTRLESC LCTL_T(KC_ESC)  // Hold for Left Ctrl, Tap for ESC
#define ALTQUOT LALT_T(KC_QUOT) // Hold for Left Alt, Tap for Quote

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTRLESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, ALTQUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_LGUI,   MO(1),  KC_SPC,  KC_SPC,     KC_ENT,  KC_ENT,   MO(2), KC_RALT
                             //`-----------------------------------'  `-----------------------------------'
  ),

  [1] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTRLESC,KC_VOLD ,KC_VOLU ,KC_MPRV ,KC_MNXT , KC_MPLY,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_LGUI, _______,  KC_SPC,  KC_SPC,    KC_ENT,   KC_ENT,   MO(3), KC_RALT
                             //`-----------------------------------'  `-----------------------------------'
  ),

  [2] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTRLESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, KC_CAPS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_LGUI,   MO(3),  KC_SPC,  KC_SPC,     KC_ENT,  KC_ENT, _______, KC_RALT
                             //`-----------------------------------'  `-----------------------------------'
  ),

  [3] = LAYOUT_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, KC_NLCK,   KC_P7,   KC_P8,   KC_P9, XXXXXXX,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_P4,   KC_P5,   KC_P6, XXXXXXX,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_P0, _______,  KC_SPC,  KC_SPC,     KC_ENT,  KC_ENT, _______, KC_RALT
                             //`-----------------------------------'  `-----------------------------------'
  )
};

const uint16_t PROGMEM encoder_keymaps[][2][2] = {
  { { KC_PGDN, KC_PGUP }, { KC__VOLDOWN, KC__VOLUP } }
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, 1));
    torn_set_led(1, IS_LAYER_ON_STATE(state, 2));
    torn_set_led(2, IS_LAYER_ON_STATE(state, 3));
    return state;
}
