#include QMK_KEYBOARD_H
#include "tapdances.h"

/* * State and Reset */
// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted | !state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
  }
  else return TD_NONE;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
.is_press_action = true,
.state = TD_NONE
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SFT_END_SENT:
    return 85; // reduce tapping term for SFT_END_SENT
  default:
    return TAPPING_TERM;
  }
}

/* ** End Sentence + Capitalize */
void sft_end_ql_finished(tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case TD_SINGLE_TAP:
      SEND_STRING(".  ");
      set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
      break;
    case TD_SINGLE_HOLD:
      register_code(KC_LSFT);
      break;
    case TD_NONE:
      break;
  }
}

void sft_end_ql_reset(tap_dance_state_t *state, void *user_data) {
  switch (ql_tap_state.state) {
    /* case TD_SINGLE_TAP: */
    /*   unregister_code(KC_X); */
    /*   break; */
    case TD_SINGLE_TAP:
      break;
    case TD_SINGLE_HOLD:
      unregister_code(KC_LSFT);
      break;
    case TD_NONE:
      break;
  }
  ql_tap_state.state = TD_NONE;
}

/* void ql_reset(tap_dance_state_t *state, void *user_data) { */
/*   ql_tap_state.state = TD_NONE; */
/* } */

/* ** Send String + Send String */
void td_ssss_f(tap_dance_state_t *state, void* user_data) {
  td_ssss *data = (td_ssss*)user_data;
  if (state->pressed) {
    const char *mystr2 = data->mystring2;
    send_string(mystr2);
  } else {
    const char *mystr1 = data->mystring1;
    send_string(mystr1);
  }
}

void td_ssss_r(tap_dance_state_t *state, void* user_data) {
  ql_tap_state.state = TD_NONE;
}

/* ** Keycode + Send String */
void td_kcss_f(tap_dance_state_t *state, void* user_data) {
  td_kcss *data = (td_kcss*)user_data;
  if (state->pressed) {
    const char *mystr = data->mystring;
    send_string(mystr);
  } else {
    tap_code16(data->keycode);
  }
}

void td_kcss_r(tap_dance_state_t *state, void* user_data) {
  ql_tap_state.state = TD_NONE;
}

/* /\* ** Send String + Keycode *\/ */
/* void td_sskc_f(tap_dance_state_t *state, void* user_data) { */
/*   td_sskc *data = (td_sskc*)user_data; */
/*   if (state->pressed && timer_elapsed(state->timer) > data->mytime) { */
/*     tap_code16(data->keycode); */
/*   } else { */
/*     const char *mystr = data->mystring; */
/*     send_string(mystr); */
/*   } */
/* } */

/* void td_sskc_r(tap_dance_state_t *state, void* user_data) { */
/*   ql_tap_state.state = TD_NONE; */
/* } */

/* ** Keycode + Keycode */
void td_kckc_f(tap_dance_state_t *state, void* user_data) {
  td_kckc *data = (td_kckc*)user_data;
  if (state->pressed) {
    tap_code16(data->keycode2);
  } else {
    tap_code16(data->keycode1);
  }
}

void td_kckc_r(tap_dance_state_t *state, void* user_data) {
  ql_tap_state.state = TD_NONE;
}

/* * Definitions */

/* * TD Enum */
// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
/* ** General */
/* *** LPRN  ) -> */
[LPRN_ARROW] = TAP_DANCE_KCSS(KC_LPRN, "<-", TAPPING_TERM),
/* *** RPRN  ( <- */
[RPRN_ARROW] = TAP_DANCE_KCSS(KC_RPRN, "->", TAPPING_TERM),
/* *** = =: */
[EQL_EQLCOL] = TAP_DANCE_KCSS(KC_EQL, "=:", TAPPING_TERM),
/* *** Grasp capture / note */
[GRASP_CAP_NOTE] = TAP_DANCE_SSSS(SS_LCTL(SS_LALT("c")), SS_LCTL(SS_LALT("y")), TAPPING_TERM),
/* ** Vim */
/* *** :%s/ :s/ */
[VIM_SR_SR_ALL] = TAP_DANCE_SSSS(SS_TAP(X_ESC)":%s/", ":s/", TAPPING_TERM),
/* *** Size / Rotation */
[VIMSIZE_H_CC_ROT] = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("h")), SS_LCTL(SS_LGUI(SS_RGUI("."))), TAPPING_TERM),
[VIMSIZE_J_FLIP]   = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("j")), SS_LCTL(SS_LGUI(SS_RGUI("-"))), TAPPING_TERM),
[VIMSIZE_K_FLOP]   = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("k")), SS_LCTL(SS_LGUI(SS_RGUI("\\"))), TAPPING_TERM),
[VIMSIZE_L_C_ROT]  = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("l")), SS_LCTL(SS_LGUI(SS_RGUI(","))), TAPPING_TERM),
/* *** Split / Delete Other Windows */
[VIMSPLIT_H_DEL_OTHER]   = TAP_DANCE_SSSS(SS_LCTL("ws"), SS_LGUI(SS_RGUI("'")), TAPPING_TERM),
[VIMSPLIT_V_DEL_OTHER_V] = TAP_DANCE_SSSS(SS_LCTL("wv"), SS_LGUI(SS_RGUI("v")), TAPPING_TERM),
/* ** Emacs */
/* *** find file / find recent */
[SPC_FF_FR] = TAP_DANCE_SSSS(" ff", " fr", TAPPING_TERM),
/* *** search directory / search project */
[SPC_SD_SP] = TAP_DANCE_SSSS(" sd", " sp", TAPPING_TERM),
/* *** swiper search / isearch */
[EMACS_SEARCH_ISEARCH] = TAP_DANCE_SSSS(SS_LCTL("ss"), SS_LCTL("s")"s", TAPPING_TERM),
/* *** Normal Mode / C-g */
[EMACS_NMODE_CG] = TAP_DANCE_SSSS(SS_TAP(X_ESC), SS_LCTL("g"), TAPPING_TERM),
/* *** comment skip / imenu */
[EMACS_COMSKIP_IMENU] = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("=")), SS_LGUI(" ")"si", TAPPING_TERM),
/* *** comment line / selection */
[EMACS_COMMENT] = TAP_DANCE_SSSS(SS_LGUI("gcc"), SS_LGUI("gc"), TAPPING_TERM),
/* *** toggle fold / global unfold all */
[EMACS_FOLDING_T_ALL] = TAP_DANCE_SSSS(SS_LCTL("cft"), SS_LCTL("cfs"), TAPPING_TERM),
/* *** capture */
[EMACS_CAPTURE_PDF_C] = TAP_DANCE_SSSS(SS_LCTL("t")"P", SS_LCTL("t")"p", TAPPING_TERM),
[EMACS_CAPTURE_CODE_C] = TAP_DANCE_SSSS(SS_LCTL("t")"C", SS_LCTL("t")"c", TAPPING_TERM),
[EMACS_CAPTURE_EPUB_C] = TAP_DANCE_SSSS(SS_LCTL("t")"E", SS_LCTL("t")"e", TAPPING_TERM),
/* ** Other Shortcuts */
/* *** Menu Terminal */
[MENU_TERM] = TAP_DANCE_KCSS(KC_APP, SS_LSFT(SS_LCTL(SS_LGUI("z"))), TAPPING_TERM),
/* *** Emacsclient */
[F4_EMACSCLIENT] = TAP_DANCE_KCSS(KC_F4, SS_LSFT(SS_LCTL(SS_LGUI("e"))), TAPPING_TERM),
/* *** Run1 */
[F7_RUN1] = TAP_DANCE_KCSS(KC_F7, SS_LSFT(SS_LCTL(SS_LGUI("c"))), TAPPING_TERM),
/* *** Run2 */
[F8_RUN2] = TAP_DANCE_KCSS(KC_F8, SS_LSFT(SS_LCTL(SS_LGUI("x"))), TAPPING_TERM),
/* *** Xkill */
[F9_XKILL] = TAP_DANCE_KCSS(KC_F9, SS_LSFT(SS_LCTL(SS_LGUI("?"))), TAPPING_TERM),
/* *** Shift Sentence End */
/* Adapted from sevanteri QMK config */
/* https://github.com/sevanteri/qmk_firmware/blob/7d59eeff4ddbc09758412ed74ad22a0062312388/users/sevanteri/tap_dance_config.c */
/* [SFT_END_SENT] = TAP_DANCE_SSKC(".  ", KC_LSFT, 120), */
[SFT_END_SENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_end_ql_finished, sft_end_ql_reset),
/* *** Volume */
[VOLD_3X] = TAP_DANCE_SSSS(SS_TAP(X_VOLD), SS_TAP(X_VOLD)SS_TAP(X_VOLD)SS_TAP(X_VOLD), TAPPING_TERM),
[VOLU_3X] = TAP_DANCE_SSSS(SS_TAP(X_VOLU), SS_TAP(X_VOLU)SS_TAP(X_VOLU)SS_TAP(X_VOLU), TAPPING_TERM),
/* /\* *** Dynamic Macro Start / Stop *\/ */
/* [DYNMACRO_START_STOP_1] = TAP_DANCE_KCKC(DYN_REC_START1, DYN_REC_STOP, 120), */
/* [DYNMACRO_START_STOP_2] = TAP_DANCE_KCKC(DYN_REC_START2, DYN_REC_STOP, 120), */
};

/* * TODO */
/* :mk */
/* comma space for the key next to it */
