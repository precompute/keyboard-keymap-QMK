#ifndef MYCOMBOS_H
#define MYCOMBOS_H
#include QMK_KEYBOARD_H
/* #include "quantum.h" */

enum combos {
PERIOD_COMMA_ESC,
};

const uint16_t PROGMEM period_comma_esc_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [PERIOD_COMMA_ESC] = COMBO(period_comma_esc_combo,  KC_ESC),
};

#endif // MYCOMBOS_H
