// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum {
    TD_CWTG,
};

// 自定义 tap dance：单击/长按 = Left Ctrl，双击 = Caps Word
void td_cwtg_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LCTL);
    } else {
        caps_word_toggle();  // 直接用函数调用，不走 register_code16
    }
}

void td_cwtg_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        wait_ms(TAP_CODE_DELAY);
        unregister_code16(KC_LCTL);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_CWTG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_cwtg_finished, td_cwtg_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE (Norman)
     */
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,      KC_Q, KC_W, KC_D,  KC_F,   KC_K,    /* */ KC_J,    KC_U,   KC_R,    KC_L,   KC_SCLN, KC_BSLS,
        TD(TD_CWTG), KC_A, KC_S, KC_E,  KC_T,   KC_G,    /* */ KC_Y,    KC_N,   KC_I,    KC_O,   KC_H,    KC_QUOT,
        KC_LSFT,     KC_Z, KC_X, KC_C,  KC_V,   KC_B,    /* */ KC_P,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_GRV,
                                 MO(3), KC_SPC, KC_LALT, /* */ KC_LGUI, KC_ENT, MO(4)
    ),
    /*
     * BASE (Colemak-Mod-V)
     */
    [1] = LAYOUT_split_3x6_3(
        KC_ESC,      KC_Q, KC_W, KC_D,  KC_F,   KC_P,    /* */ KC_Y,    KC_U,   KC_J,    KC_K,   KC_SCLN, KC_BSLS,
        TD(TD_CWTG), KC_A, KC_S, KC_R,  KC_T,   KC_G,    /* */ KC_H,    KC_N,   KC_E,    KC_O,   KC_I,    KC_QUOT,
        KC_LSFT,     KC_Z, KC_X, KC_C,  KC_V,   KC_B,    /* */ KC_L,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_GRV,
                                 MO(3), KC_SPC, KC_LALT, /* */ KC_LGUI, KC_ENT, MO(4)
    ),
    /*
     * GAME (QWERTY)
     */
    [2] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W, KC_E,   KC_R,   KC_T,    /* */ KC_Y,  KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_LCTL, KC_A, KC_S, KC_D,   KC_F,   KC_G,    /* */ KC_H,  KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C,   KC_V,   KC_B,    /* */ KC_N,  KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                             KC_TAB, KC_SPC, KC_LALT, /* */ TO(0), KC_ENT, KC_BSPC
    ),
    /*
     * SYM
     */
    [3] = LAYOUT_split_3x6_3(
        KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), KC_AMPR, /* */ KC_PLUS, KC_UNDS, KC_LBRC, KC_RBRC, KC_COLN, KC_PIPE,
        KC_TRNS, OS_LGUI,    OS_LCTL,    OS_LSFT,    OS_LALT,    KC_PERC, /* */ KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_EXLM, KC_DQUO,
        KC_TRNS, KC_NO,      KC_NO,      KC_AT,      KC_HASH,    KC_ASTR, /* */ KC_CIRC, KC_DLR,  KC_LCBR, KC_RCBR, KC_QUES, KC_TILD,
                                         KC_TRNS,    KC_TRNS,    QK_BOOT, /* */ KC_TRNS, KC_TRNS, MO(5)
    ),
    /*
     * FUNC
     */
    [4] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,        /* */ KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_NO,  LCA(KC_DEL),
        KC_TRNS, OS_LGUI, OS_LCTL, OS_LSFT, OS_LALT,      KC_NO,        /* */ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END, KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   MS_WHLU,      MS_WHLD,      /* */ MS_LEFT, MS_RGHT, KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                   MO(5),   LALT(KC_TAB), LCTL(KC_TAB), /* */ KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /*
     * NUM
     */
    [5] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2, KC_F3, KC_F4,   KC_F5,   KC_F6,   /* */ KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_1,  KC_2,  KC_3,    KC_4,    KC_5,    /* */ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        TO(1),   TO(2), KC_NO, KC_NO,   KC_NO,   KC_EQL,  /* */ KC_MINS, KC_PLUS, KC_COMM, KC_DOT,  KC_SLSH, TO(0),
                               KC_TRNS, KC_TRNS, KC_TRNS, /* */ KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        // Also suppress release events for OS keys, since we handle
        // everything via add_oneshot_mods() on press.
        switch (keycode) {
            case OS_LGUI:
            case OS_LCTL:
            case OS_LSFT:
            case OS_LALT:
                return false;
        }
        return true;
    }

    switch (keycode) {
        case OS_LGUI:
            add_oneshot_mods(MOD_LGUI);
            return false;
        case OS_LCTL:
            add_oneshot_mods(MOD_LCTL);
            return false;
        case OS_LSFT:
            add_oneshot_mods(MOD_LSFT);
            return false;
        case OS_LALT:
            add_oneshot_mods(MOD_LALT);
            return false;
    }

    return true;
}

const uint16_t PROGMEM combo_del[] = {KC_SCLN, KC_BSLS, COMBO_END};

const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_bspc2[] = {KC_K, KC_O, COMBO_END};

const uint16_t PROGMEM combo_plus[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM combo_plus2[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_unds[] = {KC_U, KC_R, COMBO_END};
const uint16_t PROGMEM combo_unds2[] = {KC_U, KC_N, COMBO_END};
const uint16_t PROGMEM combo_mins[] = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM combo_mins2[] = {KC_H, KC_L, COMBO_END};
const uint16_t PROGMEM combo_eql[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM combo_eql2[] = {KC_N, KC_M, COMBO_END};


combo_t key_combos[] = {
    COMBO(combo_del, KC_DEL),

    COMBO(combo_esc, KC_ESC),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_bspc2, KC_BSPC),

    COMBO(combo_plus, KC_PLUS),
    COMBO(combo_plus2, KC_PLUS),
    COMBO(combo_unds, KC_UNDS),
    COMBO(combo_unds2, KC_UNDS),
    COMBO(combo_mins, KC_MINS),
    COMBO(combo_mins2, KC_MINS),
    COMBO(combo_eql, KC_EQL),
    COMBO(combo_eql2, KC_EQL),
};
