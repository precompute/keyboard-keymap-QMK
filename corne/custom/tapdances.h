#ifndef TAPDANCES_H
#define TAPDANCES_H
// Define a type for as many tap dance states as you need
typedef enum {
TD_NONE,
/* TD_UNKNOWN, */
TD_SINGLE_TAP,
TD_SINGLE_HOLD,
/* TD_DOUBLE_TAP */
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

enum {
LPRN_ARROW, // Our custom tap dance key; add any other tap dance keys to this enum
RPRN_ARROW,
VIM_SR_SR_ALL,
MENU_TERM,
EQL_EQLCOL,
GRASP_CAP_NOTE,
SFT_END_SENT,
F4_EMACSCLIENT,
F7_RUN1,
F8_RUN2,
F9_XKILL,

VIMSIZE_H_CC_ROT,
VIMSIZE_J_FLIP,
VIMSIZE_K_FLOP,
VIMSIZE_L_C_ROT,

VIMSPLIT_H_DEL_OTHER,
VIMSPLIT_V_DEL_OTHER_V,

VOLD_3X,
VOLU_3X,

SPC_FF_FR,
SPC_SD_SP,
EMACS_SEARCH_ISEARCH,
EMACS_NMODE_CG,
EMACS_COMSKIP_IMENU,
EMACS_COMMENT,
EMACS_FOLDING_T_ALL,
EMACS_CAPTURE_PDF_C,
EMACS_CAPTURE_CODE_C,
EMACS_CAPTURE_EPUB_C,

/* DYNMACRO_START_STOP_1, */
/* DYNMACRO_START_STOP_2, */
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

typedef struct {
  const char* mystring1;
  const char* mystring2;
  uint16_t mytime;
} td_ssss;
void td_ssss_f(tap_dance_state_t *state, void *user_data);
void td_ssss_r(tap_dance_state_t *state, void *user_data);
#define TAP_DANCE_SSSS(_mystring1, _mystring2, _mytime) {               \
    .fn = {NULL, td_ssss_f, td_ssss_r},                                 \
      .user_data = (void*)&((td_ssss){.mystring1=_mystring1, .mystring2=_mystring2, .mytime=_mytime,}) \
      }

typedef struct {
  uint16_t keycode;
  const char* mystring;
  uint16_t mytime;
} td_kcss;
void td_kcss_f(tap_dance_state_t *state, void *user_data);
void td_kcss_r(tap_dance_state_t *state, void *user_data);
#define TAP_DANCE_KCSS(_keycode, _mystring, _mytime) {                  \
    .fn = {NULL, td_kcss_f, td_kcss_r},                                 \
      .user_data = (void*)&((td_kcss){.keycode=_keycode, .mystring=_mystring, .mytime=_mytime,}) \
      }

/* typedef struct { */
/*   const char* mystring; */
/*   uint16_t keycode; */
/*   uint16_t mytime; */
/* } td_sskc; */
/* void td_sskc_f(tap_dance_state_t *state, void *user_data); */
/* void td_sskc_r(tap_dance_state_t *state, void *user_data); */
/* #define TAP_DANCE_SSKC(_mystring, _keycode, _mytime) { \ */
/*   .fn = {NULL, td_sskc_f, td_sskc_r}, \ */
/*   .user_data = (void*)&((td_sskc){.mystring=_mystring, .keycode=_keycode, .mytime=_mytime,}) \ */
/* } */

typedef struct {
  uint16_t keycode1;
  uint16_t keycode2;
  uint16_t mytime;
} td_kckc;
void td_kckc_f(tap_dance_state_t *state, void *user_data);
void td_kckc_r(tap_dance_state_t *state, void *user_data);
#define TAP_DANCE_KCKC(_keycode1, _keycode2, _mytime) {                 \
    .fn = {NULL, td_kckc_f, td_kckc_r},                                 \
      .user_data = (void*)&((td_kckc){.keycode1=_keycode1, .keycode2=_keycode2, .mytime=_mytime,}) \
      }
#endif // TAPDANCES_H
