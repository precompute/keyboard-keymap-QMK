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
  LEFTBR_ARROW, // Our custom tap dance key; add any other tap dance keys to this enum
  RIGHTBR_ARROW,
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);
#endif // TAPDANCES_H
