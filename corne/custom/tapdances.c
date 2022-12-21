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

void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
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

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
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

/* void ql_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   ql_tap_state.state = TD_NONE; */
/* } */

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

/* /\* ** Send String + Keycode *\/ */
/* void td_sskc_f(qk_tap_dance_state_t *state, void* user_data) { */
/*   td_sskc *data = (td_sskc*)user_data; */
/*   if (state->pressed && timer_elapsed(state->timer) > data->mytime) { */
/*     tap_code16(data->keycode); */
/*   } else { */
/*     const char *mystr = data->mystring; */
/*     send_string(mystr); */
/*   } */
/* } */

/* void td_sskc_r(qk_tap_dance_state_t *state, void* user_data) { */
/*   ql_tap_state.state = TD_NONE; */
/* } */

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
/* *** Size / Rotation */
[VIMSIZE_H_CC_ROT] = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("h")), SS_LCTL(SS_LGUI(SS_RGUI("."))), 120),
[VIMSIZE_J_FLIP]   = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("j")), SS_LCTL(SS_LGUI(SS_RGUI("-"))), 120),
[VIMSIZE_K_FLOP]   = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("k")), SS_LCTL(SS_LGUI(SS_RGUI("\\"))), 120),
[VIMSIZE_L_C_ROT]  = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("l")), SS_LCTL(SS_LGUI(SS_RGUI(","))), 120),
/* *** Split / Delete Other Windows */
[VIMSPLIT_H_DEL_OTHER]   = TAP_DANCE_SSSS(SS_LCTL("ws"), SS_LGUI(SS_RGUI("'")), 120),
[VIMSPLIT_V_DEL_OTHER_V] = TAP_DANCE_SSSS(SS_LCTL("wv"), SS_LGUI(SS_RGUI("v")), 120),
/* ** Emacs */
/* *** find file / find recent */
[SPC_FF_FR] = TAP_DANCE_SSSS(" ff", " fr", 120),
/* *** search directory / search project */
[SPC_SD_SP] = TAP_DANCE_SSSS(" sd", " sp", 120),
/* *** swiper search / isearch */
[EMACS_SEARCH_ISEARCH] = TAP_DANCE_SSSS(SS_LCTL("ss"), SS_LCTL("s")"s", 120),
/* *** Normal Mode / C-g */
[EMACS_NMODE_CG] = TAP_DANCE_SSSS(SS_TAP(X_ESC), SS_LCTL("g"), 120),
/* *** comment skip / imenu */
[EMACS_COMSKIP_IMENU] = TAP_DANCE_SSSS(SS_LCTL(SS_LGUI("=")), SS_LGUI(" ")"si", 120),
/* *** comment line / selection */
[EMACS_COMMENT] = TAP_DANCE_SSSS(SS_LGUI("gcc"), SS_LGUI("gc"), 120),
/* *** toggle fold / global unfold all */
[EMACS_FOLDING_T_ALL] = TAP_DANCE_SSSS(SS_LCTL("cft"), SS_LCTL("cfs"), 120),
/* *** capture */
[EMACS_CAPTURE_PDF_C] = TAP_DANCE_SSSS(SS_LCTL("t")"P", SS_LCTL("t")"p", 120),
[EMACS_CAPTURE_CODE_C] = TAP_DANCE_SSSS(SS_LCTL("t")"C", SS_LCTL("t")"c", 120),
[EMACS_CAPTURE_EPUB_C] = TAP_DANCE_SSSS(SS_LCTL("t")"E", SS_LCTL("t")"e", 120),
/* ** Other Shortcuts */
/* *** Menu Terminal */
[MENU_TERM] = TAP_DANCE_KCSS(KC_APP, SS_LSFT(SS_LCTL("z")), 120),
/* *** Shift Sentence End */
/* Adapted from sevanteri QMK config */
/* https://github.com/sevanteri/qmk_firmware/blob/7d59eeff4ddbc09758412ed74ad22a0062312388/users/sevanteri/tap_dance_config.c */
/* [SFT_END_SENT] = TAP_DANCE_SSKC(".  ", KC_LSFT, 120), */
[SFT_END_SENT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 120),
/* *** Volume */
[VOLD_3X] = TAP_DANCE_SSSS(SS_TAP(X_VOLD), SS_TAP(X_VOLD)SS_TAP(X_VOLD)SS_TAP(X_VOLD), 120),
[VOLU_3X] = TAP_DANCE_SSSS(SS_TAP(X_VOLU), SS_TAP(X_VOLU)SS_TAP(X_VOLU)SS_TAP(X_VOLU), 120),
/* /\* *** Dynamic Macro Start / Stop *\/ */
/* [DYNMACRO_START_STOP_1] = TAP_DANCE_KCKC(DYN_REC_START1, DYN_REC_STOP, 120), */
/* [DYNMACRO_START_STOP_2] = TAP_DANCE_KCKC(DYN_REC_START2, DYN_REC_STOP, 120), */
};

/* * TODO */
/* :mk */
/* comma space for the key next to it */
