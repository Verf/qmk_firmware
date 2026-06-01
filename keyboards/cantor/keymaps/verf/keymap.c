// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * MO(0)
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │DEL│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │CW │G+A│A+S│C+D│S+F│ G │       │ H │S+J│C+K│A+L│G+;│ ' │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │SFT│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │ ` │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *             ┌───┬───┬───┐             ┌───┬───┬───┐
     *             │SPC│TAB│MO1│             │MO2│ENT│BSP│
     *             └───┴───┴───┘             └───┴───┴───┘
     */
    [0] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        CW_TOGG, LGUI(KC_A), LALT(KC_S), LCTL(KC_D), LSFT(KC_F), KC_G,          KC_H,    LSFT(KC_J), LCTL(KC_K), LALT(KC_L), LGUI(KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                                   KC_SPC,  KC_TAB,  MO(1),          MO(2),   KC_ENT,  KC_BSPC
    ),

    /*
     * MO(1)
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │   │PgU│ ↑ │PgD│Hme│   │       │ - │ + │ [ │ ] │ : │ \ │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ ← │ ↓ │ → │End│   │       │ _ │ = │ ( │ ) │ ! │ | │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │       │ ^ │ $ │ { │ } │ * │ & │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *             ┌───┬───┬───┐             ┌───┬───┬───┐
     *             │   │QBT│TRN│             │ @ │ % │ # │
     *             └───┴───┴───┘             └───┴───┴───┘
     */
    [1] = LAYOUT_split_3x6_3(
        KC_NO,   KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_NO,         KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_COLN, KC_BSLS,
        KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_NO,         KC_UNDS, KC_EQL,  KC_LPRN, KC_RPRN, KC_EXLM, KC_PIPE,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_ASTR, KC_AMPR,
                                   KC_NO,   QK_BOOT, KC_TRNS,       KC_AT,   KC_PERC, KC_HASH
    ),

    /*
     * MO(2)
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │F1 │F2 │F3 │F4 │F5 │F6 │       │   │ 7 │ 8 │ 9 │   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │F7 │F8 │F9 │F10│F11│F12│       │   │ 4 │ 5 │ 6 │   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │       │   │ 1 │ 2 │ 3 │ 0 │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *             ┌───┬───┬───┐             ┌───┬───┬───┐
     *             │   │   │   │             │TRN│QBT│   │
     *             └───┴───┴───┘             └───┴───┴───┘
     */
    [2] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,        KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_1,    KC_2,    KC_3,    KC_0,    KC_NO,
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
    {'L', 'L', 'L', 'L', 'L', 'L'},  // Row 0: Esc, Q, W, E, R, T
    {'L', 'L', 'L', 'L', 'L', 'L'},  // Row 1: CW, G+A, A+S, C+D, S+F, G
    {'L', 'L', 'L', 'L', 'L', 'L'},  // Row 2: SFT, Z, X, C, V, B
    {'L', 'L', 'L', 'L', 'L', 'L'},  // Row 3: SPC, TAB, MO1 (thumb keys)
    // Right half
    {'R', 'R', 'R', 'R', 'R', 'R'},  // Row 4: Y, U, I, O, P, DEL
    {'R', 'R', 'R', 'R', 'R', 'R'},  // Row 5: H, S+J, C+K, A+L, G+;, '
    {'R', 'R', 'R', 'R', 'R', 'R'},  // Row 6: N, M, ,, ., /, `
    {'R', 'R', 'R', 'R', 'R', 'R'},  // Row 7: MO2, ENT, BSP (thumb keys)
};
