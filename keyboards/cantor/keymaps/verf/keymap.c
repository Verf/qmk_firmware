// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum custom_keycodes {
    MY_CTL  = SAFE_RANGE,   // 替代 OS_LCTL，直接激活 oneshot
    MY_SFT,                 // 替代 OS_LSFT
    MY_ALT,                 // 替代 OS_LALT
    MY_GUI,                 // 替代 OS_LGUI
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_CTL:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_LCTL);
            }
            return false;
        case MY_SFT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_LSFT);
            }
            return false;
        case MY_ALT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_LALT);
            }
            return false;
        case MY_GUI:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_LGUI);
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE
     */
    [0] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W, KC_D,  KC_F,         KC_K,   /* */ KC_J,  KC_U,         KC_R,    KC_L,   KC_SCLN, KC_BSLS,
        CW_TOGG, KC_A, KC_S, KC_E,  KC_T,         KC_G,   /* */ KC_Y,  KC_N,         KC_I,    KC_O,   KC_H,    KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C,  KC_V,         KC_B,   /* */ KC_P,  KC_M,         KC_COMM, KC_DOT, KC_SLSH, KC_GRV,
                             KC_NO, LT(1,KC_SPC), KC_TAB, /* */ KC_NO, LT(2,KC_ENT), KC_BSPC
    ),
    /*
     * SYM
     */
    [1] = LAYOUT_split_3x6_3(
        KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), KC_AMPR, /* */ KC_PLUS, KC_UNDS, KC_LBRC, KC_RBRC, KC_COLN, KC_PIPE,
        KC_LGUI, MY_GUI,     MY_CTL,     MY_SFT,     MY_ALT,     KC_PERC, /* */ KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_AMPR, KC_DQUO,
        KC_TRNS, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_ASTR, /* */ KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_QUES, KC_TILD,
                                         KC_TRNS,    KC_TRNS,    QK_BOOT, /* */ KC_TRNS, MO(3),   KC_TRNS
    ),
    /*
     * NUM
     */
    [2] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_1,   KC_2,   KC_3,    KC_4,   KC_5,    /* */ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_DEL,
        KC_LGUI, MY_GUI, MY_CTL, MY_SFT,  MY_ALT, KC_ASTR, /* */ KC_MINS, KC_EQL,  KC_PLUS, KC_SLSH, KC_NO,  KC_NO,
        KC_F1,   KC_F2,  KC_F3,  KC_F4,   KC_F5,  KC_F6,   /* */ KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
                                 KC_TRNS, MO(3),  KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /*
     * NAV / FUNC
     */
    [3] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   /* */ KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_NO, LCA(KC_DEL),
        KC_NO, MY_GUI,  MY_CTL,  MY_SFT,  MY_ALT,  KC_NO,   /* */ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_NO,
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
