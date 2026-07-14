/* Copyright 2024 Justin Sawyer
 *
 * Shared row bodies for every keyed `jussaw` board. Each macro is one 6-key
 * half-row; a board's keymap.c feeds them into its own LAYOUT_* macro and
 * supplies its own thumb/bottom row. A board that must diverge (e.g. the
 * charybdis trackball keys) defines its own local half-row and swaps it in.
 *
 * Requires jussaw.h (for the aliases) and QMK_KEYBOARD_H to be included first.
 */
#pragma once

/* Indirection so the half-row macros below are expanded into their comma lists
 * *before* the LAYOUT_* macro counts its arguments. Each board uses the wrapper
 * matching its own LAYOUT macro; the others are defined but never invoked, so
 * referencing a LAYOUT_* that doesn't exist on this board is harmless. */
#define LAYOUT_wrapper(...)              LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)  LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_planck_grid_wrapper(...)  LAYOUT_planck_grid(__VA_ARGS__)

// clang-format off

/* Default (Colemak-DH + home-row mods) */
#define JW_DEF_L1  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define JW_DEF_R1  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL
#define JW_DEF_L2  KC_ESC,  A_LGUI,  R_LALT,  S_LCTL,  T_LSFT,  KC_G
#define JW_DEF_R2  KC_M,    N_RSFT,  E_RCTL,  I_RALT,  O_RGUI,  KC_QUOT
#define JW_DEF_L3  KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V
#define JW_DEF_R3  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT

/* Lower (symbols + mouse/lock cluster) */
#define JW_LOW_L1  KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define JW_LOW_R1  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL
#define JW_LOW_L2  KC_ESC,  XXXXXXX, KC_SCRL, MS_BTN2, MS_BTN1, KC_NUM
#define JW_LOW_R2  KC_GRV,  MIN_RSFT,EQL_RCTL,LBC_RALT,RBC_RGUI,KC_BSLS
#define JW_LOW_L3  KC_CAPS, XXXXXXX, XXXXXXX, MS_BTN4, MS_BTN5, XXXXXXX
#define JW_LOW_R3  KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE

/* Upper (numbers / F-keys / nav) */
#define JW_UPP_L1  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define JW_UPP_R1  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SETTING
#define JW_UPP_L2  KC_F11,  F1_LGUI, F2_LALT, F3_LCTL, F4_LSFT, KC_F5
#define JW_UPP_R2  KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_BSLS
#define JW_UPP_L3  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define JW_UPP_R3  KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENT

/* Adjust (media / mouse / bootloader) */
#define JW_ADJ_L1  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define JW_ADJ_R1  KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX
#define JW_ADJ_L2  XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN2, MS_BTN1, XXXXXXX
#define JW_ADJ_R2  KC_VOLU, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX
#define JW_ADJ_L3  XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN4, MS_BTN5, XXXXXXX
#define JW_ADJ_R3  KC_VOLD, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX

/* Settings (layer toggles) */
#define JW_SET_L1  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define JW_SET_R1  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS
#define JW_SET_L2  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define JW_SET_R2  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define JW_SET_L3  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_GAME
#define JW_SET_R3  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/* Game (left-hand gaming cluster) */
#define JW_GAM_L1  KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R
#define JW_GAM_R1  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC
#define JW_GAM_L2  KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F
#define JW_GAM_R2  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define JW_GAM_L3  KC_B,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V
#define JW_GAM_R3  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT

// clang-format on
