#include QMK_KEYBOARD_H
#include "mycombos.h"

/* * Definitions */
const uint16_t PROGMEM esc_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM launcher_combo[] = {KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM terminal_combo[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
[COMM_DOT_ESC] = COMBO_ACTION(esc_combo),
[TAB_Q_LAUNCHER] = COMBO_ACTION(launcher_combo),
[Q_W_TERMINAL] = COMBO_ACTION(terminal_combo),
};

/* * tap */
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
  case COMM_DOT_ESC:
    if (pressed) tap_code16(KC_ESC);
    break;
  case TAB_Q_LAUNCHER:
    if (pressed) tap_code16(LCTL(LSFT(LGUI(KC_X))));
    break;
  case Q_W_TERMINAL:
    if (pressed) tap_code16(LCTL(LSFT(LGUI(KC_Z))));
    break;
  }
}
