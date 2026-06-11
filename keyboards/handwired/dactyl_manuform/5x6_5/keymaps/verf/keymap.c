// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0
// Ported from Cantor layout to Dactyl Manuform 5x6_5

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE
     */
    [0] = LAYOUT_5x6_5(
        KC_ESC,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    /* */ KC_6,    KC_7,         KC_8,          KC_9,         KC_0,            KC_DEL,
        KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,    /* */ KC_Y,    KC_U,         KC_I,          KC_O,         KC_P,            KC_BSLS,
        CW_TOGG, LGUI_T(KC_A), LCTL_T(KC_S), LSFT_T(KC_D), LALT_T(KC_F), KC_G,    /* */ KC_H,    LALT_T(KC_J), RSFT_T(KC_K),  RCTL_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,    /* */ KC_N,    KC_M,         KC_COMM,       KC_DOT,       KC_SLSH,         KC_GRV,
                 KC_NO,        KC_NO,        LT(3,KC_SPC), KC_NO,        KC_LGUI, /* */ KC_RGUI, KC_NO,        LT(4,KC_BSPC), KC_NO,        KC_NO,
                                                           MO(1),        KC_NO,   /* */ KC_NO,   LT(2,KC_ENT)
    ),
    /*
     * SYM
     */
    [1] = LAYOUT_5x6_5(
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), KC_NO,   /* */ KC_PLUS, KC_UNDS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
        KC_TRNS, KC_EXLM,    KC_CIRC,    KC_AT,      KC_DLR,     KC_PERC, /* */ KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_PIPE, KC_DQUO,
        KC_TRNS, KC_NO,      KC_NO,      KC_AMPR,    KC_HASH,    KC_ASTR, /* */ KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_QUES, KC_NO,
                 KC_NO,      KC_NO,      KC_TRNS,    KC_TRNS,    QK_BOOT, /* */ KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_TILD,
                                                     KC_TRNS,    KC_TRNS, /* */ KC_TRNS, KC_TRNS
    ),
    /*
     * NUM
     */
    [2] = LAYOUT_5x6_5(
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,
        KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5,   KC_F6,   /* */ KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12,
        KC_NO, KC_1,  KC_2,  KC_3,    KC_4,    KC_5,    /* */ KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   /* */ KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,KC_NO,  KC_NO,
               KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, /* */ QK_BOOT, KC_TRNS, KC_TRNS, KC_NO,  KC_NO,
                                      KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS
    ),
    /*
     * NAV
     */
    [3] = LAYOUT_5x6_5(
        KC_TRNS, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_TRNS, KC_NO,      KC_PGUP,    KC_UP,      KC_PGDN,    KC_HOME, /* */ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO, KC_NO,
        KC_TRNS, LCTL(KC_A), KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_END,  /* */ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_NO,
        KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,   /* */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
                 KC_NO,      KC_NO,      KC_TRNS,    KC_TRNS,    KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
                                                   KC_TRNS,    KC_TRNS, /* */ KC_TRNS, KC_TRNS
    ),
    /*
     * FUN
     */
    [4] = LAYOUT_5x6_5(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   /* */ KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,
        KC_TRNS, KC_MUTE, KC_NO,   MS_WHLU, KC_NO,   KC_NO,   /* */ KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,
        KC_TRNS, KC_NO,   MS_WHLL, MS_WHLD, MS_WHLR, KC_NO,   /* */ MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_NO, KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   /* */ KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,
                 DT_UP,   DT_DOWN, MS_BTN1, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS,  DT_PRNT, KC_NO,
                                            MS_BTN2, KC_TRNS, /* */ KC_TRNS, KC_TRNS
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
        case KC_SPC:
        case KC_BSPC:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}



const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
combo_t key_combos[] = {
    COMBO(qw_combo, KC_ESC),
};
