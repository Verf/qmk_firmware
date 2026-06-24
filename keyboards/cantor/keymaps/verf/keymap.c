// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum custom_keycodes {
    MY_MO1 = SAFE_RANGE,  // 替代 MO(1)，绕过 tap-hold 机制
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_MO1:
            if (record->event.pressed) {
                layer_on(1);
            } else {
                layer_off(1);
            }
            return false;  // 阻止 QMK 对 keycode 的默认处理
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE
     */
    [0] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W, KC_D,   KC_F,   KC_K,   /* */ KC_J,    KC_U,   KC_R,   KC_L,    KC_SCLN, KC_BSLS,
        CW_TOGG, KC_A, KC_S, KC_E,   KC_T,   KC_G,   /* */ KC_Y,    KC_N,   KC_I,   KC_O,    KC_H,    KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C,   KC_V,   KC_B,   /* */ KC_P,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_GRV,
                             MY_MO1, KC_SPC, KC_TAB, /* */ KC_BSPC, KC_ENT, MO(2)
    ),
    /*
     * SYM
     */
    [1] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_AMPR, /* */ KC_PLUS, KC_UNDS, KC_LBRC, KC_RBRC, KC_COLN, KC_PIPE,
        KC_LGUI, OS_LGUI, OS_LCTL, OS_LSFT, OS_LALT, KC_PERC, /* */ KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_AMPR, KC_DQUO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ASTR, /* */ KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_QUES, KC_TILD,
                                   KC_TRNS, KC_TRNS, QK_BOOT, /* */ KC_TRNS, KC_TRNS, MO(3)
    ),
    /*
     * NUM
     */
    [2] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   /* */ KC_PEQL, KC_P7,   KC_P8, KC_P9, KC_PMNS, KC_DEL,
        KC_LGUI, OS_LGUI, OS_LCTL, OS_LSFT, OS_LALT, KC_NO,   /* */ KC_PDOT, KC_P4,   KC_P5, KC_P6, KC_PPLS, KC_NO,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  /* */ KC_P0,   KC_P1,   KC_P2, KC_P3, KC_PSLS, KC_NO,
                                   MO(3),   KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /*
     * NAV / FUNC
     */
    [3] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   /* */ KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_NO, LCA(KC_DEL),
        KC_NO, OS_LGUI, OS_LCTL, OS_LSFT, OS_LALT, KC_NO,   /* */ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   /* */ MS_LEFT, MS_RGHT, KC_NO,   KC_NO,   KC_NO, KC_NO,
                                 KC_TRNS, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM combo1[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_SCLN, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo1, KC_ESC),
    COMBO(combo2, KC_TAB),
    COMBO(combo3, KC_DEL),
    COMBO(combo4, KC_BSPC),
};
