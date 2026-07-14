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
#include "jussaw.h"
#include "wrappers.h"

// Shared layers come from wrappers.h. Charybdis diverges in two places, both
// forced by its hardware:
//   1. The trackball keycodes (charybdis-only) replace the mouse/lock cluster
//      on the Lower left half.
//   2. It has only 2 right-thumb keys (no room for a Backspace thumb like the
//      crkbd), so Backspace stays on the Default R1 edge in place of Delete.
#define JW_LOW_L2_CHARY  KC_ESC,  S_D_MOD,  DPI_MOD,  MS_BTN2, MS_BTN1, DRGSCRL
#define JW_LOW_L3_CHARY  KC_CAPS, S_D_RMOD, DPI_RMOD, MS_BTN4, MS_BTN5, SNIPING
#define JW_DEF_R1_CHARY  KC_J,    KC_L,     KC_U,     KC_Y,    KC_SCLN, KC_BSPC

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |   Q    |   W    |   F    |   P    |   B    |  |   J    |   L    |   U    |   Y    |   ;    |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   | A,LGUI | R,LALT | S,LCTL | T,LSFT |   G    |  |   M    | N,RSFT | E,RCTL | I,RALT | O,RGUI |   ""   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  CAPS  |   Z    |   X    |   C    |   D    |   V    |  |   K    |   H    |   ,    |   .    |   /    | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Ctrl  | Lower  | Space  |  | Shift  | Upper  |
   *                            `--------------------------'  `-----------------'
   */
  [_DEFAULT] = LAYOUT_wrapper(
      JW_DEF_L1,       JW_DEF_R1_CHARY,
      JW_DEF_L2,       JW_DEF_R2,
      JW_DEF_L3,       JW_DEF_R3,
                    KC_LCTL, LOWER,   KC_SPC,    KC_RSFT, UPPER
  ),

  /* Lower
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |   !    |   @    |   #    |   $    |   %    |  |   ^    |   &    |   *    |   (    |   )    |  Del   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   |SnpDPI+ |  DPI+  | Mouse2 | Mouse1 |DrgScrl |  |   `    | -,RSFT | =,RCTL | [,RALT | ],RGUI |   \    |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  CAPS  |SnpDPI- |  DPI-  | Mouse4 | Mouse5 |Sniping |  |   ~    |   _    |   +    |   {    |   }    |   |    |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Ctrl  | Trans  |  Alt   |  | Shift  | Adjust |
   *                            `--------------------------'  `-----------------'
   */
  [_LOWER] = LAYOUT_wrapper(
      JW_LOW_L1,       JW_LOW_R1,
      JW_LOW_L2_CHARY, JW_LOW_R2,
      JW_LOW_L3_CHARY, JW_LOW_R3,
                    KC_LCTL, KC_TRNS, KC_LALT,   KC_RSFT, ADJUST
  ),

  /* Upper
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |   1    |   2    |   3    |   4    |   5    |  |   6    |   7    |   8    |   9    |   0    |SETTINGS|
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  F11   |F1,LGUI |F2,LALT |F3,LCTL |F4,LSFT |   F5   |  |  Ins   |  Left  |  Down  |   Up   | Right  |   \    |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  F12   |   F6   |   F7   |   F8   |   F9   |  F10   |  |PrntScrn|  Home  |Pg Down | Pg Up  |  End   | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Ctrl  | Adjust |  Alt   |  | Shift  | Trans  |
   *                            `--------------------------'  `-----------------'
   */
  [_UPPER] = LAYOUT_wrapper(
      JW_UPP_L1,       JW_UPP_R1,
      JW_UPP_L2,       JW_UPP_R2,
      JW_UPP_L3,       JW_UPP_R3,
                    KC_LCTL, ADJUST,  KC_LALT,   KC_RSFT, KC_TRNS
  ),

  /* Adjust
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * | RESET  |        |        |        |        |        |  |  Play  |  Prev  |  Next  |        |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        | Mouse2 | Mouse1 |        |  |  Vol+  |Ms Left |Ms Down | Ms Up  |Ms Right|        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        | Mouse4 | Mouse5 |        |  |  Vol-  | WhlLft | WhlDwn | WhlUp  | WhlRgt |        |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |        | Trans  |        |  |        | Trans  |
   *                            `--------------------------'  `-----------------'
   */
  [_ADJUST] = LAYOUT_wrapper(
      JW_ADJ_L1,       JW_ADJ_R1,
      JW_ADJ_L2,       JW_ADJ_R2,
      JW_ADJ_L3,       JW_ADJ_R3,
                    XXXXXXX, KC_TRNS, XXXXXXX,   XXXXXXX, KC_TRNS
  ),

  /* Settings
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |        |        |        |        |        |        |  |        |        |        |        |        | Trans  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |  |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |TG(GAME)|  |        |        |        |        |        |        |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |        |        |        |  |        | Trans  |
   *                            `--------------------------'  `-----------------'
   */
  [_SETTINGS] = LAYOUT_wrapper(
      JW_SET_L1,       JW_SET_R1,
      JW_SET_L2,       JW_SET_R2,
      JW_SET_L3,       JW_SET_R3,
                    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_TRNS
  ),

  /* Game
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |   T    |  Tab   |   Q    |   W    |   E    |   R    |  |   Y    |   U    |   I    |   O    |   P    |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   G    | Shift  |   A    |   S    |   D    |   F    |  |   H    |   J    |   K    |   L    |   ;    |   ""   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   B    |  Ctrl  |   Z    |   X    |   C    |   V    |  |   N    |   M    |   ,    |   .    |   /    | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Esc   |  Alt   | Space  |  |TG(GAME)|        |
   *                            `--------------------------'  `-----------------'
   */
  [_GAME] = LAYOUT_wrapper(
      JW_GAM_L1,       JW_GAM_R1,
      JW_GAM_L2,       JW_GAM_R2,
      JW_GAM_L3,       JW_GAM_R3,
                    KC_ESC,  KC_LALT, KC_SPC,    TG_GAME, XXXXXXX
  ),
};
// clang-format on
