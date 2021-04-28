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
  [LPRN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, tapcode_SS(0, 0, KC_LPRN, "<-"), ql_reset, 120),
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

/* precondition */
/*  —  */
/* Today at 2:50 AM */
/* you'll need to package your two arguments in some sort of struct and pass it onto the user_data argument */
/* for example: */

/* void sentence_end(qk_tap_dance_state_t *state, void *user_data) { */
/*     uint16_t tap_keycode = ((int16_t)((size_t)user_data)); */
/*     switch (state->count) { */

/*         // Double tapping TD_DOT produces */
/*         // ". <one-shot-shift>" i.e. dot, space and capitalize next letter. */
/*         // This helps to quickly end a sentence and begin another one */
/*         // without having to hit shift. */
/*         case 2: */
/*             /\* Check that Shift is inactive *\/ */
/*             if (!(get_mods() & MOD_MASK_SHIFT)) { */
/*                 tap_code(KC_SPC); */
/*                 /\* Internal code of OSM(MOD_LSFT) *\/ */
/*                 add_oneshot_mods(MOD_BIT(KC_LSHIFT)); */

/*             } else { */
/*                 // send ">" (KC_DOT + shift → ">") */
/*                 tap_code16(tap_keycode); */
/*             } */
/*             break; */

/*             // Since `sentence_end` is called on each tap */
/*             // and not at the end of the tapping term, */
/*             // the third tap needs to cancel the effects */
/*             // of the double tap in order to get the expected */
/*             // three dots ellipsis. */
/*         case 3: */
/*             // remove the added space of the double tap case */
/*             tap_code(KC_BSPC); */
/*             // replace the space with a second dot */
/*             tap_code16(tap_keycode); */
/*             // tap the third dot */
/*             tap_code16(tap_keycode); */
/*             break; */

/*             // send KC_DOT on every normal tap of TD_DOT */
/*         default: */
/*             tap_code16(tap_keycode); */
/*     } */
/* }; */

/* [TD_SEEND_QUES] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end, NULL, NULL, KC_QUES) */

/* although I'm not sure how to pass in a structure with two variables in the user_data argument */
/* https://github.com/sevanteri/qmk_firmware/blob/7d59eeff4ddbc09758412ed74ad22a0062312388/users/sevanteri/tap_dance_config.c this may be useful */
