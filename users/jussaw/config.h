/* Copyright 2024 Justin Sawyer
 *
 * Shared tuning for every `jussaw` keymap. Included before each board's own
 * config.h, so a board can #undef/redefine any of these (the charybdis raises
 * TAP_CODE_DELAY, for example).
 */
#pragma once

/* Mod Tap */
#define TAP_CODE_DELAY 50
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0
#define PERMISSIVE_HOLD

/* Mouse key speed and acceleration (fast, low-accel). */
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
