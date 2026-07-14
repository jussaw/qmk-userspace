/* Copyright 2024 Justin Sawyer
 *
 * Shared layer scheme and keycode aliases for every `jussaw` keymap.
 * This is the single source of truth: edit here and all boards follow.
 * Requires QMK_KEYBOARD_H to be included first (for the mod-tap/layer macros).
 */
#pragma once

/* Layers shared by every keyed board (ploopy nano has no keys and ignores these). */
enum layers {
    _DEFAULT,
    _LOWER,
    _UPPER,
    _ADJUST,
    _SETTINGS,
    _GAME,
};

/* Layer Keys */
#define LOWER MO(_LOWER)
#define UPPER MO(_UPPER)
#define ADJUST MO(_ADJUST)
#define SETTING MO(_SETTINGS)
#define TG_GAME TG(_GAME)

/* Home-row mods for the Default layer (Colemak-DH, GACS order) */
#define A_LGUI LGUI_T(KC_A)
#define R_LALT LALT_T(KC_R)
#define S_LCTL LCTL_T(KC_S)
#define T_LSFT LSFT_T(KC_T)
#define N_RSFT RSFT_T(KC_N)
#define E_RCTL RCTL_T(KC_E)
#define I_RALT RALT_T(KC_I)
#define O_RGUI RGUI_T(KC_O)

/* Mod-tap keys for the Lower layer */
#define MIN_RSFT RSFT_T(KC_MINS)
#define EQL_RCTL RCTL_T(KC_EQL)
#define LBC_RALT RALT_T(KC_LBRC)
#define RBC_RGUI RGUI_T(KC_RBRC)

/* Mod-tap keys for the Upper layer */
#define F1_LGUI LGUI_T(KC_F1)
#define F2_LALT LALT_T(KC_F2)
#define F3_LCTL LCTL_T(KC_F3)
#define F4_LSFT LSFT_T(KC_F4)
