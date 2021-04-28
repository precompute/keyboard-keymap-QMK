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

/* ** Keycode + Send String */
void td_kcss_f(qk_tap_dance_state_t *state, void* user_data) {
  td_kcss *data = (td_kcss*)user_data;
  if (state->pressed && timer_elapsed(state->timer) > data->mytime) {
    const char *mystr = data->mystring;
    send_string(mystr);
  } else {
    tap_code16(data->keycode);
  }
}

void td_kcss_r(qk_tap_dance_state_t *state, void* user_data) {
  ql_tap_state.state = TD_NONE;
}

/* ** Keycode + Keycode */
void td_kckc_f(qk_tap_dance_state_t *state, void* user_data) {
  td_kckc *data = (td_kckc*)user_data;
  if (state->pressed && timer_elapsed(state->timer) > data->mytime) {
    tap_code16(data->keycode2);
  } else {
    tap_code16(data->keycode1);
  }
}

void td_kckc_r(qk_tap_dance_state_t *state, void* user_data) {
  ql_tap_state.state = TD_NONE;
}

/* * Definitions */

/* * TD Enum */
// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
/* ** LPRN  ) -> */
  [LPRN_ARROW] = TAP_DANCE_KCSS(KC_LPRN, "<-", 120),
/* ** RPRN  ( <- */
  [LPRN_ARROW] = TAP_DANCE_KCSS(KC_RPRN, "->", 120),
};

/* * TODO */
/* :s :%s */
/* :mk */
/* menu C-S-z */
/* : =: */
/* C-A-c C-A-y */
/* volume tap hold = repeat 3xx */
/* sym layer space = sentence end .spacespaceCAPITAL shift on hold */
/* comma space for the key next to it */
/* vsplit/c.rotate */
/* hsplit/cc.rotate */
