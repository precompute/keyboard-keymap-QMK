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
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

typedef struct {
  const char* mystring1;
  const char* mystring2;
  uint16_t mytime;
} td_ssss;
void td_ssss_f(qk_tap_dance_state_t *state, void *user_data);
void td_ssss_r(qk_tap_dance_state_t *state, void *user_data);
#define TAP_DANCE_SSSS(_mystring1, _mystring2, _mytime) { \
  .fn = {NULL, td_ssss_f, td_ssss_r}, \
  .user_data = (void*)&((td_ssss){.mystring1=_mystring1, .mystring2=_mystring2, .mytime=_mytime,}) \
}

typedef struct {
  uint16_t keycode;
  const char* mystring;
  uint16_t mytime;
} td_kcss;
void td_kcss_f(qk_tap_dance_state_t *state, void *user_data);
void td_kcss_r(qk_tap_dance_state_t *state, void *user_data);
#define TAP_DANCE_KCSS(_keycode, _mystring, _mytime) { \
  .fn = {NULL, td_kcss_f, td_kcss_r}, \
  .user_data = (void*)&((td_kcss){.keycode=_keycode, .mystring=_mystring, .mytime=_mytime,}) \
}

/* typedef struct { */
/*   const char* mystring; */
/*   uint16_t keycode; */
/*   uint16_t mytime; */
/* } td_sskc; */
/* void td_sskc_f(qk_tap_dance_state_t *state, void *user_data); */
/* void td_sskc_r(qk_tap_dance_state_t *state, void *user_data); */
/* #define TAP_DANCE_SSKC(_mystring, _keycode, _mytime) { \ */
/*   .fn = {NULL, td_sskc_f, td_sskc_r}, \ */
/*   .user_data = (void*)&((td_sskc){.mystring=_mystring, .keycode=_keycode, .mytime=_mytime,}) \ */
/* } */

typedef struct {
  uint16_t keycode1;
  uint16_t keycode2;
  uint16_t mytime;
} td_kckc;
void td_kckc_f(qk_tap_dance_state_t *state, void *user_data);
void td_kckc_r(qk_tap_dance_state_t *state, void *user_data);
#define TAP_DANCE_KCKC(_keycode1, _keycode2, _mytime) { \
  .fn = {NULL, td_kckc_f, td_kckc_r}, \
  .user_data = (void*)&((td_kckc){.keycode1=_keycode1, .keycode2=_keycode2, .mytime=_mytime,}) \
}
#endif // TAPDANCES_H
