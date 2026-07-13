/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    _QWERTY = 0,
    _LOWER,
    _UPPER,
    _ADJUST,
    _GAME,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    UPPER,
    ADJUST,
    TG_GAME
};

/* Layer Keys */
#define LOWER MO(_LOWER)
#define UPPER MO(_UPPER)
#define ADJUST MO(_ADJUST)
#define TG_GAME TG(_GAME)

/* Trackball Settings */
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 400
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200
#define CHARYBDIS_MINIMUM_SNIPING_DPI 200
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  /* Qwerty
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |    Q   |    W   |    E   |    R   |    T   |  |    Y   |    U   |    I   |    O   |    P   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   |    A   |    S   |    D   |    F   |    G   |  |    H   |    J   |    K   |    L   |    ;   | "",GUI |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Alt   |    Z   |    X   |    C   |    V   |    B   |  |    N   |    M   |    ,   |    .   |    /   | Enter  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   *                            |  Ctrl  | Lower  | Space  |  | Shift  | Upper  |
   *                            `--------------------------'  `-----------------'
   */
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RGUI_T(KC_QUOT),
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                 KC_LCTL,   LOWER,  KC_SPC,    KC_RSFT,   UPPER
  ),

  [_LOWER] = LAYOUT(
  /* Lower
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |    !   |    @   |    #   |    $   |    %   |  |    ^   |    &   |    *   |    (   |    )   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   |S_D_MOD | DPI_MOD| Mouse2 | Mouse1 | DRGSCRL|  |    `   |    -   |    =   |    [   |    ]   |   \    |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Alt   |S_D_RMOD|DPI_RMOD| Mouse4 | Mouse5 | SNIPING|  |    ~   |    _   |    +   |    {   |    }   |   |    |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   *                            |  Ctrl  | Trans  |  Alt   |  | Shift  | Adjust |
   *                            `--------------------------'  `-----------------'
   */
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
       KC_ESC, S_D_MOD, DPI_MOD, MS_BTN2, MS_BTN1, DRGSCRL,     KC_GRV, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_LALT,S_D_RMOD,DPI_RMOD, MS_BTN4, MS_BTN5, SNIPING,    KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                 KC_LCTL, KC_TRNS, KC_LALT,    KC_RSFT,  ADJUST
  ),

  [_UPPER] = LAYOUT(
  /* Upper
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |    1   |    2   |    3   |    4   |    5   |  |    6   |    7   |    8   |    9   |    0   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   F11  |   F1   |   F2   |   F3   |   F4   |   F5   |  |  Ins   |  Left  |  Down  |   Up   | Right  |  Del   |
   * +--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   F12  |   F6   |   F7   |   F8   |   F9   |  F10   |  |PrntScrn|  Home  |Pg Down | Pg Up  |  End   | Enter  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   *                            |  Ctrl  | Adjust |  Alt   |  | Shift  | Trans  |
   *                            `--------------------------'  `-----------------'
   */
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
       KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_INS, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_DEL,
       KC_F12,   KC_F5,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_ENT,
                                 KC_LCTL,  ADJUST, KC_LALT,    KC_RSFT, KC_TRNS
  ),
  [_ADJUST] = LAYOUT(
  /* Adjust
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  RESET |        |        |        |        |TG(GAME)|  |  Play  |  Prev  |  Next  |        |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |  |  Vol+  |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |  |  Vol-  |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   *                            |        | Trans  |        |  |        | Trans  |
   *                            `--------------------------'  `-----------------'
   */
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_GAME,    KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, KC_TRNS, XXXXXXX,    XXXXXXX, KC_TRNS
  ),
  [_GAME] = LAYOUT(
  /* Game
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |    T   |  Tab   |    Q   |    W   |    E   |    R   |  |    1   |    2   |    3   |    4   |    5   |    6   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |    G   |  Shift |    A   |    S   |    D   |    F   |  |        | Mouse1 | Mouse2 | MsWl U |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |    B   |  Ctrl  |    Z   |    X   |    C   |    V   |  |        | Mouse3 | Mouse4 | MsWl D |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   *                            |   Esc  |  Alt   | Space  |  |TG(GAME)|        |
   *                            `--------------------------'  `-----------------'
   */
         KC_T,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,       KC_1,    KC_2,    KC_3,    KC_4,   KC_5,     KC_6,
         KC_G,  KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    XXXXXXX, MS_BTN1, MS_BTN2, MS_WHLU, XXXXXXX, XXXXXXX,
         KC_B,  KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    XXXXXXX, MS_BTN3, MS_BTN4, MS_WHLD, XXXXXXX, XXXXXXX,
                                  KC_ESC, KC_LALT, KC_SPC,     TG_GAME, XXXXXXX

  ),
};
// clang-format on
