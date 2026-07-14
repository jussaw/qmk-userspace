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
  [_DEFAULT] = LAYOUT_split_3x6_3_wrapper(
      JW_DEF_L1, JW_DEF_R1,
      JW_DEF_L2, JW_DEF_R2,
      JW_DEF_L3, JW_DEF_R3,
                 KC_HYPR, LOWER,   KC_SPC,    KC_BSPC, UPPER,   XXXXXXX
  ),

  [_LOWER] = LAYOUT_split_3x6_3_wrapper(
      JW_LOW_L1, JW_LOW_R1,
      JW_LOW_L2, JW_LOW_R2,
      JW_LOW_L3, JW_LOW_R3,
                 KC_HYPR, KC_TRNS, KC_SPC,    KC_BSPC, ADJUST,  XXXXXXX
  ),

  [_UPPER] = LAYOUT_split_3x6_3_wrapper(
      JW_UPP_L1, JW_UPP_R1,
      JW_UPP_L2, JW_UPP_R2,
      JW_UPP_L3, JW_UPP_R3,
                 KC_HYPR, ADJUST,  KC_SPC,    KC_BSPC, KC_TRNS, XXXXXXX
  ),

  [_ADJUST] = LAYOUT_split_3x6_3_wrapper(
      JW_ADJ_L1, JW_ADJ_R1,
      JW_ADJ_L2, JW_ADJ_R2,
      JW_ADJ_L3, JW_ADJ_R3,
                 KC_HYPR, KC_TRNS, XXXXXXX,   XXXXXXX, KC_TRNS, XXXXXXX
  ),

  [_SETTINGS] = LAYOUT_split_3x6_3_wrapper(
      JW_SET_L1, JW_SET_R1,
      JW_SET_L2, JW_SET_R2,
      JW_SET_L3, JW_SET_R3,
                 XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_TRNS, XXXXXXX
  ),

  [_GAME] = LAYOUT_split_3x6_3_wrapper(
      JW_GAM_L1, JW_GAM_R1,
      JW_GAM_L2, JW_GAM_R2,
      JW_GAM_L3, JW_GAM_R3,
                 KC_ESC,  KC_LALT, KC_SPC,    XXXXXXX, XXXXXXX, TG_GAME
  ),
};
// clang-format on
