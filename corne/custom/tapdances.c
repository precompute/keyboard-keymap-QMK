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

/* * Definitions */
// Functions that control what our tap dance key does
 /* //this is a PROGMEM-aware function in c */
 /* printMsg_P(const char* str) { */
 /*     char buf[strlen_P(str)+1]; */
 /*     strcpy_P(buf, str); */
 /*     puts(buf); */
 /* } */

void tapcode_SS(qk_tap_dance_state_t *state, void *user_data, uint16_t mykeycode, const char* mystring) {
/* void tapcode_SS(uint16_t mykeycode, const char* mystring, qk_tap_dance_state_t *state, void *user_data) { */
  ql_tap_state.state = cur_dance(state);
  /* char myarr[] = *mystring; */
  /* const char *myarr = mystring; */
  /* const char *myarr = PSTR(mystring); */
  char buf[strlen_P(mystring)+1];
  strcpy_P(buf, mystring);
  switch (ql_tap_state.state) {
  case TD_SINGLE_TAP:
    tap_code16(mykeycode);
    break;
  case TD_SINGLE_HOLD:
    /* SEND_STRING(myarr); */
    /* SEND_STRING(mystring); */
    /* SEND_STRING(buf); */
    send_string_P(buf);
    /* send_string_P(PSTR(buf)); */
    /* send_string_P(PSTR(mystring)); */
    break;
  case TD_NONE:
    break;
  }
}

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
/* add a uint16_t keycode argument + a char* string argument to the function and use those in place of KC_LPRN and <-. */

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
  [LPRN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, tapcode_SS(NULL, NULL, KC_LPRN, "<-"), ql_reset, 120),
  [RPRN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, rprn_arrow_finished, ql_reset, 120)
};

/* :s :%s */
/* :mk */
/* menu C-S-z */
/* : =: */
/* C-A-c C-A-y */
