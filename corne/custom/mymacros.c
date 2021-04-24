/* -*- eval: (outshine-mode 1); -*- */
#include QMK_KEYBOARD_H
#include "mymacros.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
/* * Vim Window Movement */
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
/* * Vim Misc */
/* ** Edit */
    case VIMEDIT:
        if (record->event.pressed)
            SEND_STRING(SS_TAP(X_ESC)":e ~/");
        return false;
        break;
/* ** Exec */
    case VIMEXEC:
        if (record->event.pressed)
            SEND_STRING(SS_LALT("!"));
        return false;
        break;
/* ** Split */
    case VIMSPLIT_H:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("ws"));
        return false;
        break;
    case VIMSPLIT_V:
        if (record->event.pressed)
            SEND_STRING(SS_LCTL("wv"));
        return false;
        break;
    }
    return true;
};
