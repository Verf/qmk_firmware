// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * base
     *
     * ┌───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │Del│
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │CwT│ A │ S⌥│ D⇧│ F⌃│ G │   │ H │ J⌃│ K⇧│ L⌥│ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │Gui│ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ / │ ` │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │Tab│Spc│MO1│   │MO2│Ent│Bsp│   │   │   │
     * └───┴───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        CW_TOGG, KC_A, LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,    KC_H,    RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), KC_SCLN, KC_QUOT,
        KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                                   KC_TAB,  KC_SPC,  MO(1),      MO(2),   KC_ENT,   KC_BSPC
    ),
    /*
     * symbol
     *
     * ┌───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┐
     * │   │Hom│PUp│ ↑ │PDn│ # │   │ - │ + │ [ │ ] │ \ │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │End│ ← │ ↓ │ → │ ! │   │ _ │ = │ ( │ ) │ | │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │   │CGL│CGR│ % │ * │   │ ^ │ $ │ { │ } │ & │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │BOT│TRS│   │   │ @ │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┴───┘
     */
    [1] = LAYOUT_split_3x6_3(
        KC_NO,  KC_HOME, KC_PGUP,      KC_UP,         KC_PGDN, KC_HASH,          KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
        KC_NO,  KC_END,  KC_LEFT,      KC_DOWN,       KC_RGHT, KC_EXLM,          KC_UNDS, KC_EQL,  KC_LPRN, KC_RPRN, KC_PIPE, KC_NO,
        KC_NO,  KC_NO,   LCG(KC_LEFT), LCG(KC_RIGHT), KC_PERC, KC_ASTR,          KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_AMPR, KC_NO,
                                  KC_NO,   QK_BOOT, KC_TRNS,          KC_NO,   KC_AT,   KC_NO
    ),
    /*
     * 0-9 / F1-F12 / func
     *
     * ┌───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┐
     * │   │ 1 │ 2 │ 3 │ 4 │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │F1 │F2 │F3 │F4 │F5 │F6 │   │F7 │F8 │F9 │F10│F11│F12│
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │UDO│CUT│CPY│PST│FND│   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │TRS│BOT│   │   │   │   │
     * └───┴───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┴───┘
     */
    [2] = LAYOUT_split_3x6_3(
        KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,     KC_8,     KC_9,     KC_0,    KC_NO,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        KC_NO,   KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_FIND,       KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
                                   KC_NO,   KC_NO,   KC_NO,         KC_TRNS, QK_BOOT, KC_NO
    )
};

// === Chordal Hold Layout ===
// Maps each matrix position to its hand: 'L' (left), 'R' (right).
// Used by CHORDAL_HOLD to enforce bilateral combinations —
// a mod-tap key only activates its modifier when the next key
// is on the opposite hand.
//
// Cantor split matrix: rows 0-3 = left, rows 4-7 = right
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    // Left half
    {'L', 'L', 'L', 'L', 'L', 'L'},
    {'L', 'L', 'L', 'L', 'L', 'L'},
    {'L', 'L', 'L', 'L', 'L', 'L'},
    {'L', 'L', 'L', 'L', 'L', 'L'},
    // Right half
    {'R', 'R', 'R', 'R', 'R', 'R'},
    {'R', 'R', 'R', 'R', 'R', 'R'},
    {'R', 'R', 'R', 'R', 'R', 'R'},
    {'R', 'R', 'R', 'R', 'R', 'R'},
};
