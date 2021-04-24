#include QMK_KEYBOARD_H
#include "mymacros.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VIMDOW_L:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("wh"));
        return false;
        break;
    case VIMDOW_D:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("wj"));
        return false;
        break;
    case VIMDOW_U:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("wk"));
        return false;
        break;
    case VIMDOW_R:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("wl"));
        return false;
        break;
    case VIMEDIT:
        if (record->event.pressed)
            SEND_STRING(SS_TAP(X_ESC)":e ~/");
        return false;
        break;
    case VIMEXEC:
        if (record->event.pressed)
            SEND_STRING(SS_LALT("!"));
        return false;
        break;
    }
    return true;
};
/* enum custom_keycoedes { */
/*   CTLALTD = SAFE_RANGE, */
/*   VIMSAVE, */
/*   VIMWQ */
/* }; */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   if(record->event.pressed) { */
/*     switch(keycode) { */
/*       case CTLALTD: */
/*         SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_DOWN(X_DELETE)SS_UP(X_DELETE)SS_UP(X_LALT)SS_UP(X_LCTRL)); */
/*         return false; */
/*       case VIMSAVE: */
/*         SEND_STRING(":w"); */
/*         return false; */
/*     } */
/*   } */
/*   return true; */
/* }; */
