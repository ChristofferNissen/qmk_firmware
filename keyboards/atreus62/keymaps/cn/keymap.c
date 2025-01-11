// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _NAV 1
#define _RESET 2
#define _LOWER 3
#define _RAISE 4
#define _MOUSEL 5
#define _MOUSER 6

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MOUSEL TT(_MOUSEL)
#define MOUSER TT(_MOUSER)
#define NAV MO(_NAV)

// Mod taps left
// #define MT_A MT(MOD_LGUI, KC_A)
// #define MT_S MT(MOD_LALT, KC_S)
// #define MT_D MT(MOD_LSFT, KC_D)
// #define MT_F MT(MOD_LCTL, KC_F)
#define MT_A KC_A
#define MT_S KC_S
#define MT_D KC_D
#define MT_F KC_F

// Mod taps right
// #define MT_J MT(MOD_RCTL, KC_J)
// #define MT_K MT(MOD_RSFT, KC_K)
// #define MT_L MT(MOD_LALT, KC_L)
// #define MT_SCLN MT(MOD_RGUI, KC_SCLN)
#define MT_J KC_J
#define MT_K KC_K
#define MT_L KC_L
#define MT_SCLN KC_SCLN

// Thumb keys

#define MT_L1 LT(MOUSEL, KC_ESC)
#define MT_L2 LT(NAV, KC_BSPC)
#define MT_L3 LT(LOWER, KC_SPC)

#define MT_R1 LT(RAISE, KC_TAB)
#define MT_R2 KC_ENT
#define MT_R3 LT(MOUSER, KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* qwerty */
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS ,
    KC_BSLS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,   KC_U,    KC_I,    KC_O,    KC_P, KC_RBRC ,
    KC_TAB,   MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                        KC_H,   MT_J,    MT_K,    MT_L,    MT_SCLN,    KC_QUOT ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_EQL,  MT_L1,   MT_L2,   MT_L3,     MT_R1,   MT_R2,  MT_R3,   KC_MINS, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_MOUSEL] = LAYOUT(
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, XXXXXXX ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_MOUSER] = LAYOUT(
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX ,
    XXXXXXX,  XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX ,
    XXXXXXX,  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX ,
    XXXXXXX,  XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN2, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_NAV] = LAYOUT(
    TO(_DEFAULT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,
    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX ,
    TO(_RESET),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX ,
    XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_RESET] = LAYOUT(
    TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_SYSTEM_POWER   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , QK_BOOT
  ),

  [_LOWER] = LAYOUT(
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,
    XXXXXXX,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,      RAISE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_RAISE] = LAYOUT(
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_PLUS, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX ,
    XXXXXXX,  KC_TILDE,KC_SLSH, KC_BSLS, KC_PIPE, KC_GRV,                      KC_EQL,  KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, XXXXXXX ,
    XXXXXXX,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX ,
    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,      RAISE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT
  ),
};

