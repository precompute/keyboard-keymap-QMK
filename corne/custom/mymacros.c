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
/* ** Search Replace */
    case VIM_SR:
        if (record->event.pressed)
            SEND_STRING(SS_TAP(X_ESC)":s/");
        return false;
        break;
    case VIM_SR_ALL:
        if (record->event.pressed)
            SEND_STRING(SS_TAP(X_ESC)":%s/");
        return false;
        break;
/* * Window Manager */
/* ** Size */
    case WM_MAX:
        if (record->event.pressed)
            tap_code16(LGUI(KC_UP));
        return false;
        break;
    case WM_MIN:
        if (record->event.pressed)
            tap_code16(LGUI(KC_DOWN));
        return false;
        break;
    case WM_MAX_H:
        if (record->event.pressed)
            tap_code16(LGUI(KC_LEFT));
        return false;
        break;
    case WM_MAX_V:
        if (record->event.pressed)
            tap_code16(LGUI(KC_RGHT));
        return false;
        break;
/* ** Workspace */
    case WM_WSPC_N:
        if (record->event.pressed)
            tap_code16(LCTL(RGUI(KC_L)));
        return false;
        break;
    case WM_WSPC_P:
        if (record->event.pressed)
            tap_code16(LCTL(RGUI(KC_H)));
        return false;
        break;
    case WM_MV_WSPC_N:
        if (record->event.pressed)
            tap_code16(LCTL(RGUI(KC_END)));
        return false;
        break;
    case WM_MV_WSPC_P:
        if (record->event.pressed)
            tap_code16(LCTL(RGUI(KC_HOME)));
        return false;
        break;
/* ** Tiling */
    case WM_TILE_T:
        if (record->event.pressed)
            tap_code16(LALT(LGUI(KC_UP)));
        return false;
        break;
    case WM_TILE_B:
        if (record->event.pressed)
            tap_code16(LALT(LGUI(KC_DOWN)));
        return false;
        break;
    case WM_TILE_L:
        if (record->event.pressed)
            tap_code16(LALT(LGUI(KC_LEFT)));
        return false;
        break;
    case WM_TILE_R:
        if (record->event.pressed)
            tap_code16(LALT(LGUI(KC_RGHT)));
        return false;
        break;
    case WM_TILE_TL:
        if (record->event.pressed)
            tap_code16(LCTL(LGUI(KC_UP)));
        return false;
        break;
    case WM_TILE_TR:
        if (record->event.pressed)
            tap_code16(LCTL(LGUI(KC_RGHT)));
        return false;
        break;
    case WM_TILE_BL:
        if (record->event.pressed)
            tap_code16(LCTL(LGUI(KC_LEFT)));
        return false;
        break;
    case WM_TILE_BR:
        if (record->event.pressed)
            tap_code16(LCTL(LGUI(KC_DOWN)));
        return false;
        break;
    }
    return true;
};
