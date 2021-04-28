/* -*- eval: (outshine-mode 1); -*- */
#include QMK_KEYBOARD_H
#include "tapdances.h"
#include <stdint.h>

#include "progmem.h"
#include "send_string_keycodes.h"

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

void tap_release(qk_tap_dance_state_t *state, void* user_data) {
    // immediately finish TD on first release.
    state->finished = true;
}

void td_kcss_f(qk_tap_dance_state_t *state, void* user_data) {
  td_kcss *data = (td_kcss*)user_data;
  /* if (data->held) { */
  if (state->pressed && timer_elapsed(state->timer) > data->mytime) {
    data->held = false;
    /* SEND_STRING(data->mystring); */
    send_string_P(data->mystring);
  } else {
    tap_code16(data->keycode);
  }
}

void td_kcss_r(qk_tap_dance_state_t *state, void* user_data) {
  ql_tap_state.state = TD_NONE;
}

/* * Definitions */

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
  /* [LPRN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lprn_arrow_finished, ql_reset, 120), */
  [LPRN_ARROW] = TAP_DANCE_KCSS(KC_LPRN, "<-", 120),
  /* [LPRN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, tapcode_SS(0, 0, KC_LPRN, "<-"), ql_reset, 120), */
  [RPRN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, rprn_arrow_finished, ql_reset, 120)
};

/* :s :%s */
/* :mk */
/* menu C-S-z */
/* : =: */
/* C-A-c C-A-y */
/* volume tap hold = repeat 3xx */
/* sym layer space = sentence end .spacespaceCAPITAL shift on hold */
/* comma space for the key next to it */
