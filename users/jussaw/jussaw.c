/* Copyright 2024 Justin Sawyer
 *
 * Shared behavior for every `jussaw` keymap:
 *   - Game-layer SOCD (last-input-priority) cleaning for A/D.
 *   - Momentary Scroll Lock / Num Lock (re-emitted as taps) which drive the
 *     ploopy nano's drag-scroll / DPI cycling over the wire.
 *   - Stale-SOCD cleanup when leaving the game layer.
 *
 * The ploopy nano compiles this too, but with no keys and no game layer these
 * hooks never fire there, so it is inert and harmless.
 */
#include QMK_KEYBOARD_H
#include "jussaw.h"

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

layer_state_t layer_state_set_user(layer_state_t state) {
    // leaving the game layer while A/D is held would leave the SOCD flags
    // stale and re-register a phantom key on the next game session
    if (!layer_state_cmp(state, _GAME)) {
        if (a_pressed) {
            unregister_code(KC_A);
            a_pressed = false;
        }
        if (d_pressed) {
            unregister_code(KC_D);
            d_pressed = false;
        }
    }
    return state;
}
