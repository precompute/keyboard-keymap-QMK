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

/* ** Send String + Send String */
void td_ssss_f(qk_tap_dance_state_t *state, void* user_data) {
  td_ssss *data = (td_ssss*)user_data;
  if (state->pressed && timer_elapsed(state->timer) > data->mytime) {
    const char *mystr2 = data->mystring2;
    send_string(mystr2);
  } else {
    const char *mystr1 = data->mystring1;
    send_string(mystr1);
  }
}

void td_ssss_r(qk_tap_dance_state_t *state, void* user_data) {
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

/* ** Send String + Keycode */
void td_sskc_f(qk_tap_dance_state_t *state, void* user_data) {
  td_sskc *data = (td_sskc*)user_data;
  if (state->pressed && timer_elapsed(state->timer) > data->mytime) {
    tap_code16(data->keycode);
  } else {
    const char *mystr = data->mystring;
    send_string(mystr);
  }
}

void td_sskc_r(qk_tap_dance_state_t *state, void* user_data) {
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
/* ** General */
/* *** LPRN  ) -> */
  [LPRN_ARROW] = TAP_DANCE_KCSS(KC_LPRN, "<-", 120),
/* *** RPRN  ( <- */
  [RPRN_ARROW] = TAP_DANCE_KCSS(KC_RPRN, "->", 120),
/* *** = =: */
  [EQL_EQLCOL] = TAP_DANCE_KCSS(KC_EQL, "=:", 120),
/* *** Grasp capture / note */
  [GRASP_CAP_NOTE] = TAP_DANCE_SSSS(SS_LCTL(SS_LALT("c")), SS_LCTL(SS_LALT("y")), 120),
/* ** Vim */
/* *** :%s/ :s/ */
  [VIM_SR_SR_ALL] = TAP_DANCE_SSSS(SS_TAP(X_ESC)":%s/", ":s/", 120),
/* ** Other Shortcuts */
/* *** Menu Terminal */
  [MENU_TERM] = TAP_DANCE_KCSS(KC_APP, SS_LSFT(SS_LCTL("z")), 120),
/* *** Shift Sentence End */
  [SFT_END_SENT] = TAP_DANCE_SSKC(".  ", KC_LSFT, 120),
};

/* * TODO */
/* :mk */
/* C-ss C-s C-s */
/* SPC ff */
/* SPC sd SPC sp */
/* volume tap hold = repeat 3xx */
/* sym layer space = sentence end .spacespaceCAPITAL shift on hold */
/* comma space for the key next to it */
/* vsplit/c.rotate */
/* hsplit/cc.rotate */
