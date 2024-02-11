#include QMK_KEYBOARD_H

const uint16_t PROGMEM esc_combo[] = {LCMD_T(KC_S), LCMD_T(KC_I), COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_F, KC_Y, COMBO_END};
const uint16_t PROGMEM rec_macro1_combo[] = {KC_Z, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM rec_macro2_combo[] = {KC_Q, KC_P, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(caps_combo, CW_TOGG),
    COMBO(rec_macro1_combo, DM_REC1),
    COMBO(rec_macro2_combo, DM_REC2),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_LBRC:  // [
        case KC_RBRC:  // ]
        case KC_MINS:  // -
        case KC_EQL:   // =
        case KC_BSLS:  // \ char
        case KC_GRV:   // `
        case KC_SCLN:  // ;
        case KC_QUOT:  // '
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case ALL_T(KC_COLN):
        //     if (record->tap.count && record->event.pressed) {
        //         tap_code16(KC_COLN);
        //         return false;        // Return false to ignore further processing of key
        //     }
        //     break;
        case ALL_T(KC_COLN):
            if (record->event.pressed) {
                if (record->tap.count) {
                    // Key was tapped
                    if (get_mods() & MOD_MASK_SHIFT) {
                        // If Shift is held, unregister Shift, send semicolon, re-register Shift
                        uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
                        del_mods(shift_mods); // Temporarily unregister Shift
                        tap_code(KC_SCLN);    // Send semicolon
                        set_mods(shift_mods); // Re-register Shift
                    } else {
                        // No Shift, send colon
                        tap_code16(KC_COLN);  // Send colon
                    }
                    return false; // Skip all further processing of this key
                }
            }
            break;
        case LCMD_T(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LSFT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LCMD_T(KC_RCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LSFT_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(           // base layer
        KC_F, KC_L, KC_H, KC_V, KC_Z,
        KC_QUOTE, KC_W, KC_U, KC_O, KC_Y,

        LCMD_T(KC_S), LALT_T(KC_R), LSFT_T(KC_N), LCTL_T(KC_T), HYPR_T(KC_K),
        HYPR_T(KC_C), LCTL_T(KC_D), LSFT_T(KC_E), LALT_T(KC_A), LCMD_T(KC_I),

        KC_X, KC_J, KC_B, KC_M, KC_Q,
        KC_P, KC_G, KC_COMMA, KC_DOT, KC_SLSH,

        LT(1,KC_SPC), KC_TAB,     // N/M
        KC_ENT, LT(3,KC_BSPC)),         // F/NS
	[1] = LAYOUT_split_3x5_2(           // nav layer
        KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT,
        KC_MUTE,   DM_PLY1, DM_PLY2,RSFT_T(KC_INT5), KC_TRNS,

        KC_LCMD, KC_LALT, KC_LSFT, KC_LCTL, KC_HYPR,
        KC_APP, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT,

        KC_BRID, KC_BRIU, KC_HOME, KC_PGDN, KC_PSCR,
        KC_INS, KC_PGUP, KC_END, KC_CAPS, KC_ESC,

        KC_TRNS, KC_TRNS,
        QK_REP, LT(2,KC_DEL)),               // M
	[2] = LAYOUT_split_3x5_2(           // mouse layer
        KC_TRNS, KC_ACL1, KC_ACL0, KC_ACL2, KC_BTN3,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_LCMD, KC_LALT, KC_LSFT, KC_LCTL, KC_BTN4,
        KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,

        KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_TRNS,
        KC_TRNS, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,

        KC_BTN1, KC_BTN2,
        KC_TRNS, KC_TRNS),
	[3] = LAYOUT_split_3x5_2(           // symbols layer
        KC_7, KC_5, KC_3, KC_1, KC_9,
        KC_0, KC_2, KC_4, KC_6, KC_8,

        LCMD_T(KC_LCBR), LALT_T(KC_LBRC), LSFT_T(KC_LPRN), LCTL_T(KC_MINS), ALL_T(KC_BSLS),
        ALL_T(KC_COLN), LCTL_T(KC_EQL), LSFT_T(KC_RPRN), LALT_T(KC_RBRC), LCMD_T(KC_RCBR),

        KC_AMPR, KC_PERC, KC_HASH, KC_EXLM,KC_GRV,
        KC_TILD, KC_AT, KC_DLR, KC_CIRC , KC_ASTR,

        LT(4,KC_SPC), KC_TRNS,
        KC_TRNS, KC_TRNS),
	[4] = LAYOUT_split_3x5_2(           // F keys layer
        KC_F7, KC_F5, KC_F3, KC_F1, KC_F9,
        KC_F10, KC_F2, KC_F4, KC_F6, KC_F8,

        KC_LCMD, KC_LALT, KC_LSFT, KC_LCTL, KC_HYPR,
        KC_HYPR, KC_LCTL, KC_LSFT, KC_LALT, KC_LCMD,

        KC_TRNS,   KC_TRNS, AC_TOGG, KC_F11, TG(5),
        KC_TRNS, KC_F12,  DT_PRNT, DT_UP,  DT_DOWN,

        KC_TRNS, QK_BOOT,
        QK_BOOT, KC_TRNS),
	[5] = LAYOUT_split_3x5_2(           // numpad layer
        KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_0,    KC_4,    KC_5,    KC_6,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS,   KC_1,    KC_2,    KC_3,    TG(5),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




