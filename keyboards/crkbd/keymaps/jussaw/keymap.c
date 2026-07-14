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
#include "jussaw.h"
#include "wrappers.h"

// The layer enum, keycode aliases, and the SOCD / momentary-lock behavior all
// live in users/jussaw/. This board is the reference: the shared row bodies in
// wrappers.h are taken verbatim from here. Only the thumb rows are board-local.

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |   Q    |   W    |   F    |   P    |   B    |  |   J    |   L    |   U    |   Y    |   ;    |  Del   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   | A,LGUI | R,LALT | S,LCTL | T,LSFT |   G    |  |   M    | N,RSFT | E,RCTL | I,RALT | O,RGUI |   ""   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  CAPS  |   Z    |   X    |   C    |   D    |   V    |  |   K    |   H    |   ,    |   .    |   /    | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            | Hyper  | Lower  | Space  |  |  Bksp  | Upper  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_DEFAULT] = LAYOUT_split_3x6_3_wrapper(
      JW_DEF_L1, JW_DEF_R1,
      JW_DEF_L2, JW_DEF_R2,
      JW_DEF_L3, JW_DEF_R3,
                 KC_HYPR, LOWER,   KC_SPC,    KC_BSPC, UPPER,   XXXXXXX
  ),

  /* Lower
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |   !    |   @    |   #    |   $    |   %    |  |   ^    |   &    |   *    |   (    |   )    |  Del   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  Esc   |        |SCRL_LCK| Mouse2 | Mouse1 |NUM_LOCK|  |   `    | -,RSFT | =,RCTL | [,RALT | ],RGUI |   \    |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  CAPS  |        |        | Mouse4 | Mouse5 |        |  |   ~    |   _    |   +    |   {    |   }    |   |    |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            | Hyper  | Trans  | Space  |  |  Bksp  | Adjust |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_LOWER] = LAYOUT_split_3x6_3_wrapper(
      JW_LOW_L1, JW_LOW_R1,
      JW_LOW_L2, JW_LOW_R2,
      JW_LOW_L3, JW_LOW_R3,
                 KC_HYPR, KC_TRNS, KC_SPC,    KC_BSPC, ADJUST,  XXXXXXX
  ),

  /* Upper
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |  Tab   |   1    |   2    |   3    |   4    |   5    |  |   6    |   7    |   8    |   9    |   0    |SETTINGS|
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  F11   |F1,LGUI |F2,LALT |F3,LCTL |F4,LSFT |   F5   |  |  Ins   |  Left  |  Down  |   Up   | Right  |   \    |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |  F12   |   F6   |   F7   |   F8   |   F9   |  F10   |  |PrntScrn|  Home  |Pg Down | Pg Up  |  End   | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            | Hyper  | Adjust | Space  |  |  Bksp  | Trans  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_UPPER] = LAYOUT_split_3x6_3_wrapper(
      JW_UPP_L1, JW_UPP_R1,
      JW_UPP_L2, JW_UPP_R2,
      JW_UPP_L3, JW_UPP_R3,
                 KC_HYPR, ADJUST,  KC_SPC,    KC_BSPC, KC_TRNS, XXXXXXX
  ),

  /* Adjust
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * | RESET  |        |        |        |        |        |  |  Play  |  Prev  |  Next  |        |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        | Mouse2 | Mouse1 |        |  |  Vol+  |Ms Left |Ms Down | Ms Up  |Ms Right|        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        | Mouse4 | Mouse5 |        |  |  Vol-  | WhlLft | WhlDwn | WhlUp  | WhlRgt |        |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            | Hyper  | Trans  |        |  |        | Trans  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_ADJUST] = LAYOUT_split_3x6_3_wrapper(
      JW_ADJ_L1, JW_ADJ_R1,
      JW_ADJ_L2, JW_ADJ_R2,
      JW_ADJ_L3, JW_ADJ_R3,
                 KC_HYPR, KC_TRNS, XXXXXXX,   XXXXXXX, KC_TRNS, XXXXXXX
  ),

  /* Settings
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |        |        |        |        |        |        |  |        |        |        |        |        | Trans  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |  |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |TG(GAME)|  |        |        |        |        |        |        |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |        |        |        |  |        | Trans  |        |
   *                            `--------------------------'  `--------------------------'
   */
  [_SETTINGS] = LAYOUT_split_3x6_3_wrapper(
      JW_SET_L1, JW_SET_R1,
      JW_SET_L2, JW_SET_R2,
      JW_SET_L3, JW_SET_R3,
                 XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_TRNS, XXXXXXX
  ),

  /* Game
   * ,-----------------------------------------------------.  ,-----------------------------------------------------.
   * |   T    |  Tab   |   Q    |   W    |   E    |   R    |  |   Y    |   U    |   I    |   O    |   P    |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   G    | Shift  |   A    |   S    |   D    |   F    |  |   H    |   J    |   K    |   L    |   ;    |   ""   |
   * |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   * |   B    |  Ctrl  |   Z    |   X    |   C    |   V    |  |   N    |   M    |   ,    |   .    |   /    | Enter  |
   * `--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------'
   *                            |  Esc   |  Alt   | Space  |  |        |        |TG(GAME)|
   *                            `--------------------------'  `--------------------------'
   */
  [_GAME] = LAYOUT_split_3x6_3_wrapper(
      JW_GAM_L1, JW_GAM_R1,
      JW_GAM_L2, JW_GAM_R2,
      JW_GAM_L3, JW_GAM_R3,
                 KC_ESC,  KC_LALT, KC_SPC,    XXXXXXX, XXXXXXX, TG_GAME
  ),
};
// clang-format on
