// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0
// Ported from Cantor layout to Dactyl Manuform 5x6_5

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_5x6_5(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
             '*', '*', '*', '*', '*',  '*', '*', '*', '*', '*',
                            '*', '*',  '*', '*'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE
     */
    [0] = LAYOUT_5x6_5(
        KC_NO,           KC_1,    KC_2,         KC_3,         KC_4,          KC_5,  /* */  KC_6,  KC_7,         KC_8,         KC_9,         KC_0,   KC_DEL,
        KC_ESC,          KC_Q,    KC_W,         KC_E,         KC_R,          KC_T,  /* */  KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,   KC_BSLS,
        LCTL_T(CW_TOGG), KC_A,    LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F),  KC_G,  /* */  KC_H,  RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), KC_SCLN, KC_QUOT,
        KC_LSFT,         KC_Z,    KC_X,         KC_C,         KC_V,          KC_B,  /* */  KC_N,  KC_M,         KC_COMM,      KC_DOT,       KC_SLSH, KC_GRV,
                         KC_LGUI, KC_LALT,      KC_SPC,       KC_NO,         KC_NO, /* */  KC_NO, KC_NO,        KC_BSPC,      KC_NO,        KC_NO,
                                                       LT(1,KC_TAB), LT(3,KC_F13), /* */  LT(4,KC_EQL), LT(2,KC_ENT)
    ),
    /*
     * SYM
     */
    [1] = LAYOUT_5x6_5(
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), KC_NO,   /* */ KC_PLUS, KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_BSLS,
        KC_NO,   KC_EXLM,    KC_AT,      KC_CIRC,    KC_DLR,     KC_PERC, /* */ KC_MINS, KC_COLN, KC_LPRN, KC_RPRN, KC_DQUO, KC_PIPE,
        KC_NO,   KC_NO,      KC_NO,      KC_AMPR,    KC_HASH,    KC_ASTR, /* */ KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_QUES, KC_NO,
                 KC_NO,      KC_NO,      QK_BOOT,    QK_BOOT,    QK_BOOT, /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                     KC_TRNS,    KC_TRNS, /* */ KC_TRNS, KC_TRNS
    ),
    /*
     * NUM
     */
    [2] = LAYOUT_5x6_5(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, /* */ KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,
        KC_NO, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  /* */ KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,
               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* */ QK_BOOT, QK_BOOT, QK_BOOT, KC_NO,  KC_NO,
                                    KC_NO, KC_NO, /* */ QK_BOOT, KC_TRNS
    ),
    /*
     * NAV
     */
    [3] = LAYOUT_5x6_5(
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_PGUP, KC_UP,   KC_PGDN, KC_NO,   /* */ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO, KC_NO,
        KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   /* */ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_HOME, KC_END,  /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
               KC_NO, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
                                        KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS
    ),
    /*
     * FUN
     */
    [4] = LAYOUT_5x6_5(
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, /* */   KC_NO,    KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, /* */   KC_NO,    KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, /* */   KC_NO,    KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, /* */   KC_NO,    KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO,
               KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, /* */ KC_TRNS,  KC_TRNS, KC_TRNS,  KC_NO,  KC_NO,
                                      KC_TRNS, KC_TRNS, /* */ KC_TRNS,  KC_TRNS
    ),
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
        case KC_F13:
            if (record->event.pressed) {
                register_code16(KC_UNDS);
            } else {
                unregister_code16(KC_UNDS);
            }
            return false;
        default:
            return true;

    }
}
