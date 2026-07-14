/* Copyright 2015-2017 Jack Humbert
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

// Shared layers come from wrappers.h. The planck has no thumb cluster, so its
// 12-wide bottom row carries the crkbd thumb functions (Hyper/Lower/Space/
// Bksp/Upper). Adjust is reached the crkbd way: the opposite layer key becomes
// ADJUST while Lower or Upper is held (no tri-layer).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default
   * ,-----------------------------------------------------------------------------------------------------------.
   * |  Tab   |   Q    |   W    |   F    |   P    |   B    |   J    |   L    |   U    |   Y    |   ;    |  Del   |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |  Esc   | A,LGUI | R,LALT | S,LCTL | T,LSFT |   G    |   M    | N,RSFT | E,RCTL | I,RALT | O,RGUI |   ""   |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |  CAPS  |   Z    |   X    |   C    |   D    |   V    |   K    |   H    |   ,    |   .    |   /    | Enter  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        | Hyper  |  Ctrl  | Lower  | Space  |  Bksp  | Upper  |  RGUI  |        |        |        |
   * `-----------------------------------------------------------------------------------------------------------'
   */
  [_DEFAULT] = LAYOUT_planck_grid_wrapper(
      JS_DEF_L1, JS_DEF_R1,
      JS_DEF_L2, JS_DEF_R2,
      JS_DEF_L3, JS_DEF_R3,
      XXXXXXX, XXXXXXX, KC_HYPR, KC_LCTL, LOWER,   KC_SPC,  KC_BSPC, UPPER,   KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------------------------------.
   * |  Tab   |   !    |   @    |   #    |   $    |   %    |   ^    |   &    |   *    |   (    |   )    |  Del   |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |  Esc   |        |SCRL_LCK| Mouse2 | Mouse1 |NUM_LOCK|   `    | -,RSFT | =,RCTL | [,RALT | ],RGUI |   \    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |  CAPS  |        |        | Mouse4 | Mouse5 |        |   ~    |   _    |   +    |   {    |   }    |   |    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        | Hyper  |  Ctrl  | Trans  | Space  |  Bksp  | Adjust |  RGUI  |        |        |        |
   * `-----------------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid_wrapper(
      JS_LOW_L1, JS_LOW_R1,
      JS_LOW_L2, JS_LOW_R2,
      JS_LOW_L3, JS_LOW_R3,
      XXXXXXX, XXXXXXX, KC_HYPR, KC_LCTL, KC_TRNS, KC_SPC,  KC_BSPC, ADJUST,  KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Upper
   * ,-----------------------------------------------------------------------------------------------------------.
   * |  Tab   |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |SETTINGS|
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |  F11   |F1,LGUI |F2,LALT |F3,LCTL |F4,LSFT |   F5   |  Ins   |  Left  |  Down  |   Up   | Right  |   \    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |  F12   |   F6   |   F7   |   F8   |   F9   |  F10   |PrntScrn|  Home  |Pg Down | Pg Up  |  End   | Enter  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        | Hyper  |  Ctrl  | Adjust | Space  |  Bksp  | Trans  |  RGUI  |        |        |        |
   * `-----------------------------------------------------------------------------------------------------------'
   */
  [_UPPER] = LAYOUT_planck_grid_wrapper(
      JS_UPP_L1, JS_UPP_R1,
      JS_UPP_L2, JS_UPP_R2,
      JS_UPP_L3, JS_UPP_R3,
      XXXXXXX, XXXXXXX, KC_HYPR, KC_LCTL, ADJUST,  KC_SPC,  KC_BSPC, KC_TRNS, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Adjust
   * ,-----------------------------------------------------------------------------------------------------------.
   * | RESET  |        |        |        |        |        |  Play  |  Prev  |  Next  |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        | Mouse2 | Mouse1 |        |  Vol+  |Ms Left |Ms Down | Ms Up  |Ms Right|        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        | Mouse4 | Mouse5 |        |  Vol-  | WhlLft | WhlDwn | WhlUp  | WhlRgt |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        | Trans  |        |        | Trans  |        |        |        |        |
   * `-----------------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_grid_wrapper(
      JS_ADJ_L1, JS_ADJ_R1,
      JS_ADJ_L2, JS_ADJ_R2,
      JS_ADJ_L3, JS_ADJ_R3,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Settings
   * ,-----------------------------------------------------------------------------------------------------------.
   * |        |        |        |        |        |        |        |        |        |        |        | Trans  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |TG(GAME)|        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        |        | Trans  |        |        |        |        |
   * `-----------------------------------------------------------------------------------------------------------'
   */
  [_SETTINGS] = LAYOUT_planck_grid_wrapper(
      JS_SET_L1, JS_SET_R1,
      JS_SET_L2, JS_SET_R2,
      JS_SET_L3, JS_SET_R3,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Game
   * ,-----------------------------------------------------------------------------------------------------------.
   * |   T    |  Tab   |   Q    |   W    |   E    |   R    |   Y    |   U    |   I    |   O    |   P    |  Bksp  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |   G    | Shift  |   A    |   S    |   D    |   F    |   H    |   J    |   K    |   L    |   ;    |   ""   |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |   B    |  Ctrl  |   Z    |   X    |   C    |   V    |   N    |   M    |   ,    |   .    |   /    | Enter  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |  Ctrl  |        |  Esc   |  Alt   | Space  | Space  |        |        |        |        |        |TG(GAME)|
   * `-----------------------------------------------------------------------------------------------------------'
   */
  [_GAME] = LAYOUT_planck_grid_wrapper(
      JS_GAM_L1, JS_GAM_R1,
      JS_GAM_L2, JS_GAM_R2,
      JS_GAM_L3, JS_GAM_R3,
      KC_LCTL, XXXXXXX, KC_ESC,  KC_LALT, KC_SPC,  KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_GAME
  ),
};
// clang-format on
