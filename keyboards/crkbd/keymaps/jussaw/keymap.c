/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _DEFAULT,
    _MAC,
    _LOWER,
    _UPPER,
    _UPPER_MAC,
    _ADJUST,
    _SETTINGS,
    _GAME,
};

/* Layer Keys */
#define LOWER MO(_LOWER)
#define UPPER MO(_UPPER)
#define UP_MAC MO(_UPPER_MAC)
#define ADJUST MO(_ADJUST)
#define SETTING MO(_SETTINGS)
#define DF_QWRT DF(_DEFAULT)
#define TO_DEF TO(_DEFAULT)
#define TO_MAC TO(_MAC)
#define TG_GAME TG(_GAME)

/* Mod Tap Keys for Default Layer */
#define A_LGUI LGUI_T(KC_A)
#define R_LALT LALT_T(KC_R)
#define S_LCTL LCTL_T(KC_S)
#define T_LSFT LSFT_T(KC_T)
#define N_RSFT RSFT_T(KC_N)
#define E_RCTL RCTL_T(KC_E)
#define I_RALT RALT_T(KC_I)
#define O_RGUI RGUI_T(KC_O)

/* Mod Tap Keys for Mac Layer */
#define A_LCTL LCTL_T(KC_A)
#define S_LGUI LGUI_T(KC_S)
#define E_RGUI RGUI_T(KC_E)
#define O_RCTL RCTL_T(KC_O)

/* Mod Tap Keys for Lower Layer */
#define MIN_RSFT RSFT_T(KC_MINS)
#define EQL_RCTL RCTL_T(KC_EQL)
#define LBC_RALT RALT_T(KC_LBRC)
#define RBC_RGUI RGUI_T(KC_RBRC)

/* Mod Tap Keys for Upper Layer */
#define F1_LGUI LGUI_T(KC_F1)
#define F2_LALT LALT_T(KC_F2)
#define F3_LCTL LCTL_T(KC_F3)
#define F4_LSFT LSFT_T(KC_F4)

/* Mod Tap Keys for Upper Mac Layer */
#define F1_LCTL LCTL_T(KC_F1)
#define F3_LGUI LGUI_T(KC_F3)


static bool a_pressed = false;
static bool d_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_GAME)) {
        switch (keycode) {
            case KC_A:
                if (record->event.pressed) {
                    if (d_pressed) {
                        unregister_code(KC_D);
                    }
                    register_code(KC_A);
                    a_pressed = true;
                } else {
                    unregister_code(KC_A);
                    a_pressed = false;
                    if (d_pressed) {
                        register_code(KC_D);
                    }
                }
                return false;  // Skip default handling for this key

            case KC_D:
                if (record->event.pressed) {
                    if (a_pressed) {
                        unregister_code(KC_A);
                    }
                    register_code(KC_D);
                    d_pressed = true;
                } else {
                    unregister_code(KC_D);
                    d_pressed = false;
                    if (a_pressed) {
                        register_code(KC_A);
                    }
                }
                return false;  // Skip default handling for this key
        }
    }

    switch (keycode) {
        // makes scroll lock momentary instead of toggle
        // enables momentary drag scroll on ploopy nano
        case KC_SCRL:
            tap_code(KC_SCRL);
            return false;
        // makes num lock momentary instead of toggle
        // prevents accidental ploopy nano going into bootloader
        case KC_NUM:
            tap_code(KC_NUM);
            return false;
    }
    return true;  // Process all other keycodes normally
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |    Q   |    W   |    F   |    P   |    B   |  |    J   |    L   |    U   |    Y   |    ;   |  Del   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   | A,LGUI | R,LALT | S,LCTL | T,LSFT |    G   |  |    M   | N,RSFT | E,RCTL | I,RALT | O,RGUI |   ""   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  CAPS  |    Z   |    X   |    C   |    D   |    V   |  |    K   |    H   |    ,   |    .   |    /   | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Hyper | Lower  | Space  |  |  Bksp  | Upper  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_DEFAULT] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_DEL,
       KC_ESC,  A_LGUI,  R_LALT,  S_LCTL,  T_LSFT,    KC_G,       KC_M,  N_RSFT,  E_RCTL,  I_RALT,  O_RGUI, KC_QUOT,
      KC_CAPS,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                 KC_HYPR,   LOWER,  KC_SPC,    KC_BSPC,   UPPER, XXXXXXX
  ),

  /* Mac
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |    Q   |    W   |    F   |    P   |    B   |  |    J   |    L   |    U   |    Y   |    ;   |  Del   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   | A,LGUI | R,LALT | S,LCTL | T,LSFT |    G   |  |    M   | N,RSFT | E,RCTL | I,RALT | O,RGUI |   ""   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  CAPS  |    Z   |    X   |    C   |    D   |    V   |  |    K   |    H   |    ,   |    .   |    /   | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Hyper | Lower  | Space  |  |  Bksp  | Upper  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_MAC] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_DEL,
       KC_ESC,  A_LCTL,  R_LALT,  S_LGUI,  T_LSFT,    KC_G,       KC_M,  N_RSFT,  E_RGUI,  I_RALT,  O_RCTL, KC_QUOT,
      KC_CAPS,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                 KC_HYPR,   LOWER,  KC_SPC,    KC_BSPC,  UP_MAC, XXXXXXX
  ),

  /* Lower
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |    !   |    @   |    #   |    $   |    %   |  |    ^   |    &   |    *   |    (   |    )   |  Del   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   |        |SCRL_LCK| Mouse2 | Mouse1 |NUM_LOCK|  |    `   | -,RSFT | =,RCTL | [,RALT | ],RGUI |   \    |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  CAPS  |        |        | Mouse4 | Mouse5 |        |  |    ~   |    _   |    +   |    {   |    }   |   |    |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Hyper | Trans  | Space  |  |  Bksp  | Adjust |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_LOWER] = LAYOUT_split_3x6_3(
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
        KC_ESC, XXXXXXX, KC_SCRL, MS_BTN2, MS_BTN1,  KC_NUM,     KC_GRV,MIN_RSFT,EQL_RCTL,LBC_RALT,RBC_RGUI, KC_BSLS,
       KC_CAPS, XXXXXXX, XXXXXXX, MS_BTN4, MS_BTN5, XXXXXXX,    KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                 KC_HYPR, KC_TRNS,  KC_SPC,    KC_BSPC,  ADJUST, XXXXXXX
  ),

  /* Upper
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |    1   |    2   |    3   |    4   |    5   |  |    6   |    7   |    8   |    9   |    0   |SETTINGS|
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   F11  |F1,LGUI |F2,LALT |F3,LCTL |F4,LSFT |   F5   |  |  Ins   |  Left  |  Down  |   Up   | Right  |   \    |
   * +--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   F12  |   F6   |   F7   |   F8   |   F9   |  F10   |  |PrntScrn|  Home  |Pg Down | Pg Up  |  End   | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Hyper | Adjust | Space  |  |  Bksp  | Trans  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_UPPER] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  SETTING,
       KC_F11, F1_LCTL, F2_LALT, F3_LGUI, F4_LSFT,   KC_F5,     KC_INS, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_BSLS,
       KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_ENT,
                                 KC_HYPR,  ADJUST,  KC_SPC,    KC_BSPC, KC_TRNS, XXXXXXX
  ),

  /* Upper Mac
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |    1   |    2   |    3   |    4   |    5   |  |    6   |    7   |    8   |    9   |    0   |SETTINGS|
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   F11  |F1,LGUI |F2,LALT |F3,LCTL |F4,LSFT |   F5   |  |  Ins   |  Left  |  Down  |   Up   | Right  |   \    |
   * +--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   F12  |   F6   |   F7   |   F8   |   F9   |  F10   |  |PrntScrn|  Home  |Pg Down | Pg Up  |  End   | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Hyper | Adjust | Space  |  |  Bksp  | Trans  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_UPPER_MAC] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  SETTING,
       KC_F11, F1_LGUI, F2_LALT, F3_LCTL, F4_LSFT,   KC_F5,     KC_INS, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_BSLS,
       KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_ENT,
                                 KC_HYPR,  ADJUST,  KC_SPC,    KC_BSPC, KC_TRNS, XXXXXXX
  ),

  /* Adjust
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  RESET |        |        |        |        |        |  |  Play  |  Prev  |  Next  |        |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |DF(QWRT)|        |        | Mouse2 | Mouse1 |        |  |  Vol+  |Ms Left |Ms Down | Ms Up  |Ms Right|        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        | Mouse4 | Mouse5 |        |  |  Vol-  | WhlLft | WhlDwn | WhlUp  | WhlRgt |        |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Hyper | Lower  |        |  |        | Upper  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_ADJUST] = LAYOUT_split_3x6_3(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
      DF_QWRT, XXXXXXX, XXXXXXX, MS_BTN2, MS_BTN1, XXXXXXX,     KC_VOLU, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN4, MS_BTN5, XXXXXXX,     KC_VOLD, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
                                 KC_HYPR, KC_TRNS, XXXXXXX,     XXXXXXX, KC_TRNS, XXXXXXX
  ),

  /* Settings
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |        |        |        |        |        |TO(DEF) |  |        |        |        |        |        | Trans  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |TO(MAC) |  |        |        |        |        |        |        |
   * +--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |TG(GAME)|  |        |        |        |        |        |        |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |        |        |        |  |        | Trans  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_SETTINGS] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  TO_DEF,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  TO_MAC,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_GAME,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_TRNS, XXXXXXX
  ),

  /* Game
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |    T   |  Tab   |    Q   |    W   |    E   |    R   |  |    Y   |    U   |    I   |    O   |    P   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |    G   |  Shift |    A   |    S   |    D   |    F   |  |    H   |    J   |    K   |    L   |    ;   |   ""   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |    B   |  Ctrl  |    Z   |    X   |    C   |    V   |  |    N   |    M   |    ,   |    .   |    /   | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |   Esc  |  Alt   | Space  |  |        |        |TG(GAME)|
   *                            `--------------------------'  `--------------------------'
   */
  [_GAME] = LAYOUT_split_3x6_3(
         KC_T,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
         KC_G,  KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
         KC_B,  KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                  KC_ESC, KC_LALT,  KC_SPC,     XXXXXXX, XXXXXXX, TG_GAME
  ),
};
