// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );

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
     * │   │   │   │Tab│Sp1│MO1│   │MO2│En2│Bsp│   │   │   │
     * └───┴───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        LCTL_T(CW_TOGG), KC_A, LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,   KC_H,   RCTL_T(KC_J),    RSFT_T(KC_K), LALT_T(KC_L), KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                                   KC_TAB,  LT(1,KC_SPC),  KC_LALT,      KC_LGUI,   LT(2,KC_ENT),   KC_BSPC
    ),
    /*
     * symbol
     *
     * ┌───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┐
     * │   │LA1│LA2│LA3│LA4│   │   │ - │ + │ [ │ ] │ \ │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │Hom│PDn│PUp│End│ ! │   │ _ │ = │ ( │ ) │ | │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │ ← │ ↓ │ ↑ │ → │ % │   │ ^ │ $ │ { │ } │ & │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │BOT│TRS│   │ * │ @ │ # │   │   │   │
     * └───┴───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┴───┘
     */
    [1] = LAYOUT_split_3x6_3(
        KC_NO, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), KC_NO,    KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
        KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_EXLM,               KC_UNDS, KC_EQL,  KC_LPRN, KC_RPRN, KC_PIPE, KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PERC,                KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_AMPR, KC_NO,
                                 QK_BOOT, KC_TRNS, KC_TRNS,              KC_ASTR, KC_AT,   KC_HASH
    ),
    /*
     * 0-9 / F1-F12 / func
     *
     * ┌───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┐
     * │   │ 1 │ 2 │ 3 │ 4 │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │F1 │F2 │F3 │F4 │F5 │F6 │   │F7 │F8 │F9 │F10│F11│F12│
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │TRS│BOT│   │   │   │   │
     * └───┴───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┴───┘
     */
    [2] = LAYOUT_split_3x6_3(
        KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,     KC_8,     KC_9,     KC_0,    KC_NO,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
                                   KC_NO,   KC_NO,   KC_NO,         KC_TRNS, KC_TRNS, QK_BOOT
    )
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SCLN:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(CW_TOGG):
            if (record->tap.count && record->event.pressed) {
                caps_word_on();
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}
