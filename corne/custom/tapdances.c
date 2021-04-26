/* -*- eval: (outshine-mode 1); -*- */
#include QMK_KEYBOARD_H
#include "tapdances.h"

/* * State and Reset */
// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
  }
  else return TD_NONE;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = TD_NONE;
}

/* * Definitions */
// Functions that control what our tap dance key does
/* ** LPRN  ) -> */
void lprn_arrow_finished(qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
  case TD_SINGLE_TAP:
    tap_code16(KC_LPRN);
    break;
  case TD_SINGLE_HOLD:
    SEND_STRING("<-");
    break;
  case TD_NONE:
    break;
  }
}

/* ** RPRN  ( <- */
void rprn_arrow_finished(qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
  case TD_SINGLE_TAP:
    tap_code16(KC_RPRN);
    break;
  case TD_SINGLE_HOLD:
    SEND_STRING("->");
    break;
  case TD_NONE:
    break;
  }
}

/* * TD Enum */
// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [LPRN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lprn_arrow_finished, ql_reset, 200),
  [RPRN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, rprn_arrow_finished, ql_reset, 200)
};
