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
/* * Emacs Movement */
        case EMACS_BW_B:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI("B"));
            return false;
            break;
        case EMACS_B_D:
            if (record->event.pressed)
                tap_code16(LCTL(RGUI(KC_J)));
            return false;
            break;
        case EMACS_B_U:
            if (record->event.pressed)
                tap_code16(LCTL(RGUI(KC_K)));
            return false;
            break;
        case EMACS_BW_F:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI("W"));
            return false;
            break;
        case EMACS_SEXP_P:
            if (record->event.pressed)
                tap_code16(LCTL(LALT(KC_B)));
            return false;
            break;
        case EMACS_GIT_HUNK_N:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(" ")"g]");
            return false;
            break;
        case EMACS_GIT_HUNK_P:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(" ")"g[");
            return false;
            break;
        case EMACS_SEXP_N:
            if (record->event.pressed)
                tap_code16(LCTL(LALT(KC_F)));
            return false;
            break;
        case EMACS_HEADING_P:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI("["));
            return false;
            break;
        case EMACS_HEADING_N:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI("]"));
            return false;
            break;
        case EMACS_DIRED_JUMP:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(" ")"oo");
            return false;
            break;
        case EMACS_FDEFBEG_N:
            if (record->event.pressed)
                SEND_STRING(SS_RGUI("]")"m");
            return false;
            break;
        case EMACS_FDEFBEG_P:
            if (record->event.pressed)
                SEND_STRING(SS_RGUI("[")"m");
            return false;
            break;
        case EMACS_FDEFEND_N:
            if (record->event.pressed)
                SEND_STRING(SS_RGUI("]")"M");
            return false;
            break;
        case EMACS_FDEFEND_P:
            if (record->event.pressed)
                SEND_STRING(SS_RGUI("[")"M");
            return false;
            break;
        case EMACS_WIND_C:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(" ")"!R");
            return false;
            break;
/* * Vim Movement */
/* ** Buffer */
        case VIMBUF_P:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(" ")"bp");
            return false;
            break;
        case VIMBUF_N:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(" ")"bn");
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
/* ** Visual */
        case EMACS_VISUAL:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI("V"));
            return false;
            break;
/* ** Split */
            /* case VIMSPLIT_H: */
            /*     if (record->event.pressed) */
            /*         SEND_STRING(SS_LCTL("ws")); */
            /*     return false; */
            /*     break; */
            /* case VIMSPLIT_V: */
            /*     if (record->event.pressed) */
            /*         SEND_STRING(SS_LCTL("wv")); */
            /*     return false; */
            /*     break; */
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
        case WM_FILL_H:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(KC_PGDN)));
            return false;
            break;
        case WM_FILL_V:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(KC_PGUP)));
            return false;
            break;
        case WM_TILE_C:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(KC_END)));
            return false;
            break;
        case WM_W_INC:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(KC_P))));
            return false;
            break;
        case WM_S_INC:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(KC_W))));
            return false;
            break;
        case WM_N_INC:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(KC_F))));
            return false;
            break;
        case WM_E_INC:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(KC_Q))));
            return false;
            break;
        case WM_W_DEC:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(KC_T))));
            return false;
            break;
        case WM_S_DEC:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(KC_R))));
            return false;
            break;
        case WM_N_DEC:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(KC_S))));
            return false;
            break;
        case WM_E_DEC:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(KC_A))));
            return false;
            break;
/* ** Grid */
        case WM_TILE_01:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_Q)))));
            return false;
            break;
        case WM_TILE_02:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_W)))));
            return false;
            break;
        case WM_TILE_03:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_F)))));
            return false;
            break;
        case WM_TILE_04:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_P)))));
            return false;
            break;
        case WM_TILE_05:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_B)))));
            return false;
            break;
        case WM_TILE_06:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_J)))));
            return false;
            break;
        case WM_TILE_07:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_A)))));
            return false;
            break;
        case WM_TILE_08:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_R)))));
            return false;
            break;
        case WM_TILE_09:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_S)))));
            return false;
            break;
        case WM_TILE_10:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_T)))));
            return false;
            break;
        case WM_TILE_11:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_G)))));
            return false;
            break;
        case WM_TILE_12:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_M)))));
            return false;
            break;
        case WM_TILE_13:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_Z)))));
            return false;
            break;
        case WM_TILE_14:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_X)))));
            return false;
            break;
        case WM_TILE_15:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_C)))));
            return false;
            break;
        case WM_TILE_16:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_D)))));
            return false;
            break;
        case WM_TILE_17:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_V)))));
            return false;
            break;
        case WM_TILE_18:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_K)))));
            return false;
            break;

        case WM_TILE_GROW_L:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_L)))));
            return false;
            break;
        case WM_TILE_GROW_D:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_Y)))));
            return false;
            break;
        case WM_TILE_GROW_U:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_U)))));
            return false;
            break;
        case WM_TILE_GROW_R:
            if (record->event.pressed)
                tap_code16(LCTL(LSFT(LGUI(LALT(KC_SCLN)))));
            return false;
            break;
        case RGUI_TAB_QUICK:
            if (record->event.pressed)
                tap_code16(RGUI(KC_TAB));
            return false;
            break;
        case RGUI_TAB_R_QUICK:
            if (record->event.pressed)
                tap_code16(LSFT(RGUI(KC_TAB)));
            return false;
            break;
/* ** Snippets */
        case ORG_SRC_BLOCK:
            if (record->event.pressed)
                SEND_STRING("#+BEGIN_SRC"SS_TAP(X_ENT)SS_TAP(X_ENT)"#+END_SRC"SS_TAP(X_UP));
            return false;
            break;
        case ORG_QUOTE_BLOCK:
            if (record->event.pressed)
                SEND_STRING("#+BEGIN_QUOTE"SS_TAP(X_ENT)SS_TAP(X_ENT)"#+END_QUOTE"SS_TAP(X_UP));
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
        if (timer_elapsed(rgui_tab_timer) > 350) {
            unregister_code(KC_RGUI);
            is_rgui_tab_active = false;
        }
    }
}
