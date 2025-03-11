// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum layers {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _ADJUST = 3,
    _ARROW,
    _MOUSEL,
    _MOUSER
};

#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_RAISE_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 3

enum custom_keycodes {
// Layer overlay keycodes
    LOWER = MO(_LOWER),
    RAISE = MO(_RAISE),
    ARROW = MO(_ARROW),
    MOUSEL = TT(_MOUSEL),
    MOUSER = TT(_MOUSER),
// Thumb keys
    T0 = LT(MOUSEL, KC_ESC),
    T1 = LT(ARROW, KC_BSPC),
    T2 = LT(LOWER, KC_SPC),
    T3 = LT(RAISE, KC_TAB),
    T4 = KC_ENT,
    T5 = LT(MOUSER, KC_QUOT),
// Mod taps homerow
    HR_A = MT(MOD_LGUI, KC_A),
    HR_S = MT(MOD_LALT, KC_S),
    HR_D = MT(MOD_LSFT, KC_D),
    HR_F = MT(MOD_LCTL, KC_F),
    HR_J = MT(MOD_RCTL, KC_J),
    HR_K = MT(MOD_RSFT, KC_K),
    HR_L = MT(MOD_LALT, KC_L),
    HR_SCLN = MT(MOD_RGUI, KC_SCLN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    HR_A,    HR_S,    HR_D,    HR_F,    KC_G,                         KC_H,    HR_J,    HR_K,    HR_L, HR_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               T0,      T1,      T2,         T3,      T4,      T5
                                      //`--------------------------'  `--------------------------'
  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, TL_LOWR,    TL_UPPR, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PLUS, XXXXXXX, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,KC_TILDE, KC_SLSH, KC_BSLS, KC_PIPE,  KC_GRV,                       KC_EQL, KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_DEL, TL_LOWR,    TL_UPPR, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, TL_LOWR,    TL_UPPR, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_ARROW] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSEL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX,                      KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN2, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BTN2, KC_BTN1,    KC_BTN1, KC_BTN2, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, KC_WH_L,KC_MS_UP, KC_WH_R, KC_WH_U,                      XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN2, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BTN2, KC_BTN1,    KC_BTN1, KC_BTN2, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

//   [_TEMPLATE] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           _______, _______, _______,     _______, _______, _______
//                                       //`--------------------------'  `--------------------------'
//   ),

//     [_RAISE] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//       _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           XXXXXXX, XXXXXXX,   LOWER,      RAISE, XXXXXXX, XXXXXXX
//                                       //`--------------------------'  `--------------------------'
//   ),

};
