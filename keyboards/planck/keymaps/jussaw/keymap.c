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
  [_DEFAULT] = LAYOUT_planck_grid_wrapper(
      JW_DEF_L1, JW_DEF_R1,
      JW_DEF_L2, JW_DEF_R2,
      JW_DEF_L3, JW_DEF_R3,
      XXXXXXX, XXXXXXX, KC_HYPR, KC_LCTL, LOWER,   KC_SPC,  KC_BSPC, UPPER,   KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_LOWER] = LAYOUT_planck_grid_wrapper(
      JW_LOW_L1, JW_LOW_R1,
      JW_LOW_L2, JW_LOW_R2,
      JW_LOW_L3, JW_LOW_R3,
      XXXXXXX, XXXXXXX, KC_HYPR, KC_LCTL, KC_TRNS, KC_SPC,  KC_BSPC, ADJUST,  KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_UPPER] = LAYOUT_planck_grid_wrapper(
      JW_UPP_L1, JW_UPP_R1,
      JW_UPP_L2, JW_UPP_R2,
      JW_UPP_L3, JW_UPP_R3,
      XXXXXXX, XXXXXXX, KC_HYPR, KC_LCTL, ADJUST,  KC_SPC,  KC_BSPC, KC_TRNS, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_ADJUST] = LAYOUT_planck_grid_wrapper(
      JW_ADJ_L1, JW_ADJ_R1,
      JW_ADJ_L2, JW_ADJ_R2,
      JW_ADJ_L3, JW_ADJ_R3,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SETTINGS] = LAYOUT_planck_grid_wrapper(
      JW_SET_L1, JW_SET_R1,
      JW_SET_L2, JW_SET_R2,
      JW_SET_L3, JW_SET_R3,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_GAME] = LAYOUT_planck_grid_wrapper(
      JW_GAM_L1, JW_GAM_R1,
      JW_GAM_L2, JW_GAM_R2,
      JW_GAM_L3, JW_GAM_R3,
      KC_LCTL, XXXXXXX, KC_ESC,  KC_LALT, KC_SPC,  KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_GAME
  ),
};
// clang-format on
