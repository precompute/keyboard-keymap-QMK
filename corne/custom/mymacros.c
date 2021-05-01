/* -*- eval: (outshine-mode 1); -*- */
#include QMK_KEYBOARD_H
#include "mymacros.h"

bool is_rgui_tab_active = false;
uint16_t rgui_tab_timer = 0;

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
/* ** Super-Tab */
/* adapted from */
/* https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros#super-alt-tab */
    case RGUI_TAB:
      if (record->event.pressed) {
        if (!is_rgui_tab_active) {
          is_rgui_tab_active = true;
          register_code(KC_RGUI);
        }
        rgui_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    }
    return true;
};

/* ** Super-Tab matrix scan */
void matrix_scan_user(void) {
  if (is_rgui_tab_active) {
    if (timer_elapsed(rgui_tab_timer) > 400) {
      unregister_code(KC_RGUI);
      is_rgui_tab_active = false;
    }
  }
}
