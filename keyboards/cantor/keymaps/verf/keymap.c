// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE
     */
    [0] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W,         KC_D,         KC_F,         KC_K,   /* */ KC_J,    KC_U,         KC_R,         KC_L,         KC_SCLN, KC_BSLS,
        CW_TOGG, KC_A, LCTL_T(KC_S), LSFT_T(KC_E), LALT_T(KC_T), KC_G,   /* */ KC_Y,    LALT_T(KC_N), RSFT_T(KC_I), RCTL_T(KC_O), KC_H,    KC_QUOT,
        KC_LSFT, KC_Z, KC_X,         KC_C,         KC_V,         KC_B,   /* */ KC_P,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH, KC_GRV,
                                     MO(3),        LT(1,KC_SPC), KC_TAB, /* */ KC_LGUI, LT(2,KC_ENT), KC_BSPC
    ),
    /*
     * SYM
     */
    [1] = LAYOUT_split_3x6_3(
        KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), KC_AMPR, /* */ KC_PLUS, KC_UNDS, KC_LBRC, KC_RBRC, KC_COLN, KC_PIPE,
        KC_NO,   KC_EXLM,    KC_CIRC,    KC_AT,      KC_DLR,     KC_PERC, /* */ KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_NO,   KC_DQUO,
        KC_TRNS, KC_NO,      KC_NO,      KC_NO,      KC_HASH,    KC_ASTR, /* */ KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_QUES, KC_TILD,
                                         KC_NO,      KC_TRNS,    QK_BOOT, /* */ KC_TRNS, KC_ENT,  KC_TRNS
    ),
    /*
     * NUM
     */
    [2] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,  /* */ KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   /* */ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  /* */ KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                               KC_NO, KC_SPC, KC_TAB, /* */ QK_BOOT, KC_TRNS, KC_NO
    ),
    /*
     * NAV / FUNC
     */
    [3] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_NO, KC_PGUP, KC_UP,   KC_PGDN,    KC_HOME, /* */ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO, KC_DEL,
        KC_NO,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,    KC_END,  /* */ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_NO,
        KC_TRNS, KC_NO, KC_NO,   KC_NO,   LGUI(KC_V), KC_NO,   /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
                                 KC_TRNS, KC_NO,      QK_BOOT, /* */ KC_LGUI, KC_NO,   LCA(KC_DEL)
    ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}
