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
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

void tap_release(qk_tap_dance_state_t* state, void* user_data);
typedef struct {
  uint16_t keycode;
  const char* mystring;
  uint16_t mytime;
  /* bool held; */
} td_kcss;
void td_kcss_f(qk_tap_dance_state_t *state, void *user_data);
void td_kcss_r(qk_tap_dance_state_t *state, void *user_data);
#define TAP_DANCE_KCSS(_keycode, _mystring, _mytime) { \
  .fn = {NULL, td_kcss_f, td_kcss_r}, \
  .user_data = (void*)&((td_kcss){.keycode=_keycode, .mystring=_mystring, .mytime=_mytime,}) \
}




#endif // TAPDANCES_H
