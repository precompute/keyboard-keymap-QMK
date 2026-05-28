#include QMK_KEYBOARD_H
#include "mymacros.h"

bool is_rgui_tab_active = false;
uint16_t rgui_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
/* * Vim Window Movement */
        case VIMDOW_L:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(SS_LCTL("wh")));
            return false;
            break;
        case VIMDOW_D:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(SS_LCTL("wj")));
            return false;
            break;
        case VIMDOW_U:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(SS_LCTL("wk")));
            return false;
            break;
        case VIMDOW_R:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(SS_LCTL("wl")));
            return false;
            break;
/* * Emacs Movement */
        /* case EMACS_BW_B: */
        /*     if (record->event.pressed) */
        /*         SEND_STRING(SS_LGUI("B")); */
        /*     return false; */
        /*     break; */
        /* case EMACS_B_D: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(RGUI(KC_J))); */
        /*     return false; */
        /*     break; */
        /* case EMACS_B_U: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(RGUI(KC_K))); */
        /*     return false; */
        /*     break; */
        /* case EMACS_BW_F: */
        /*     if (record->event.pressed) */
        /*         SEND_STRING(SS_LGUI("W")); */
        /*     return false; */
        /*     break; */
        /* case EMACS_SEXP_P: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LALT(KC_B))); */
        /*     return false; */
        /*     break; */
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
        /* case EMACS_SEXP_N: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LALT(KC_F))); */
        /*     return false; */
        /*     break; */
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
        /* case EMACS_DIRED_JUMP: */
        /*     if (record->event.pressed) */
        /*         SEND_STRING(SS_LGUI(" ")"oo"); */
        /*     return false; */
        /*     break; */
        /* case EMACS_FDEFBEG_N: */
        /*     if (record->event.pressed) */
        /*         SEND_STRING(SS_RGUI("]")"m"); */
        /*     return false; */
        /*     break; */
        /* case EMACS_FDEFBEG_P: */
        /*     if (record->event.pressed) */
        /*         SEND_STRING(SS_RGUI("[")"m"); */
        /*     return false; */
        /*     break; */
        /* case EMACS_FDEFEND_N: */
        /*     if (record->event.pressed) */
        /*         SEND_STRING(SS_RGUI("]")"M"); */
        /*     return false; */
        /*     break; */
        /* case EMACS_FDEFEND_P: */
        /*     if (record->event.pressed) */
        /*         SEND_STRING(SS_RGUI("[")"M"); */
        /*     return false; */
        /*     break; */
        case EMACS_WIND_C:
            if (record->event.pressed)
                SEND_STRING(SS_LGUI(" ")"!R");
            return false;
            break;
        case EMACS_FRAME_P:
            if (record->event.pressed)
                SEND_STRING(SS_RGUI("w")"<");
            return false;
            break;
        case EMACS_FRAME_N:
            if (record->event.pressed)
                SEND_STRING(SS_RGUI("w")">");
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
/* /\* ** Edit *\/ */
/*         case VIMEDIT: */
/*             if (record->event.pressed) */
/*                 SEND_STRING(SS_TAP(X_ESC)":e ~/"); */
/*             return false; */
/*             break; */
/* ** Exec */
/*         case VIMEXEC: */
/*             if (record->event.pressed) */
/*                 SEND_STRING(SS_LALT("!")); */
/*             return false; */
/*             break; */
/* ** Visual */
        /* case EMACS_VISUAL: */
        /*     if (record->event.pressed) */
        /*         SEND_STRING(SS_LGUI("V")); */
        /*     return false; */
        /*     break; */
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
                tap_code16(LCTL(LGUI(RGUI(KC_UP))));
            return false;
            break;
        case WM_MIN:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_DOWN))));
            return false;
            break;
        /* case WM_MAX_H: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LGUI(KC_LEFT)); */
        /*     return false; */
        /*     break; */
        /* case WM_MAX_V: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LGUI(KC_RGHT)); */
        /*     return false; */
        /*     break; */
/* ** Workspace */
        case WM_WSPC_N:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_RIGHT))));
            return false;
            break;
        case WM_WSPC_P:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_LEFT))));
            return false;
            break;
        case WM_MV_WSPC_N:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_END))));
            return false;
            break;
        case WM_MV_WSPC_P:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_HOME))));
            return false;
            break;
/* ** Tiling */
        case WM_TILE_T:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_U))));
            return false;
            break;
        case WM_TILE_B:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_COMM))));
            return false;
            break;
        case WM_TILE_L:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_N))));
            return false;
            break;
        case WM_TILE_R:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_I))));
            return false;
            break;
        case WM_TILE_TL:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_L))));
            return false;
            break;
        case WM_TILE_TR:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_Y))));
            return false;
            break;
        case WM_TILE_BL:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_H))));
            return false;
            break;
        case WM_TILE_BR:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_DOT))));
            return false;
            break;
        case WM_FILL_H:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_SCLN))));
            return false;
            break;
        case WM_FILL_V:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_O))));
            return false;
            break;
        case WM_TILE_C:
            if (record->event.pressed)
                tap_code16(LGUI(LCTL(RGUI(KC_E))));
            return false;
            break;
        /* case WM_W_INC: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(KC_P)))); */
        /*     return false; */
        /*     break; */
        /* case WM_S_INC: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(KC_W)))); */
        /*     return false; */
        /*     break; */
        /* case WM_N_INC: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(KC_F)))); */
        /*     return false; */
        /*     break; */
        /* case WM_E_INC: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(KC_Q)))); */
        /*     return false; */
        /*     break; */
        /* case WM_W_DEC: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(KC_T)))); */
        /*     return false; */
        /*     break; */
        /* case WM_S_DEC: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(KC_R)))); */
        /*     return false; */
        /*     break; */
        /* case WM_N_DEC: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(KC_S)))); */
        /*     return false; */
        /*     break; */
        /* case WM_E_DEC: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(KC_A)))); */
        /*     return false; */
        /*     break; */
/* ** Grid */
        /* case WM_TILE_01: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_Q))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_02: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_W))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_03: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_F))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_04: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_P))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_05: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_B))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_06: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_J))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_07: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_A))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_08: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_R))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_09: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_S))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_10: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_T))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_11: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_G))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_12: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_M))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_13: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_Z))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_14: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_X))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_15: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_C))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_16: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_D))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_17: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_V))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_18: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_K))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_GROW_L: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_L))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_GROW_D: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_Y))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_GROW_U: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_U))))); */
        /*     return false; */
        /*     break; */
        /* case WM_TILE_GROW_R: */
        /*     if (record->event.pressed) */
        /*         tap_code16(LCTL(LSFT(LGUI(LALT(KC_SCLN))))); */
        /*     return false; */
        /*     break; */
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

        case WM_TILE_31_1:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_Q))));
            return false;
            break;

        case WM_TILE_31_2:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_A))));
            return false;
            break;

        case WM_TILE_31_3:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_Z))));
            return false;
            break;

        case WM_TILE_32_11:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_W))));
            return false;
            break;

        case WM_TILE_32_12:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_F))));
            return false;
            break;

        case WM_TILE_32_21:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_R))));
            return false;
            break;

        case WM_TILE_32_22:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_S))));
            return false;
            break;

        case WM_TILE_32_31:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_X))));
            return false;
            break;

        case WM_TILE_32_32:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_C))));
            return false;
            break;

        case WM_TILE_33_11:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_P))));
            return false;
            break;

        case WM_TILE_33_12:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_B))));
            return false;
            break;

        case WM_TILE_33_13:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_J))));
            return false;
            break;

        case WM_TILE_33_21:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_T))));
            return false;
            break;

        case WM_TILE_33_22:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_G))));
            return false;
            break;

        case WM_TILE_33_23:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_M))));
            return false;
            break;

        case WM_TILE_33_31:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_D))));
            return false;
            break;

        case WM_TILE_33_32:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_V))));
            return false;
            break;

        case WM_TILE_33_33:
            if (record->event.pressed)
                tap_code16(LCTL(LGUI(RGUI(KC_K))));
            return false;
            break;

        case WM_AUTOTILE_21:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_0))));
          return false;
          break;

        case WM_AUTOTILE_12:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_1))));
          return false;
          break;

        case WM_AUTOTILE_22:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_2))));
          return false;
          break;

        case WM_AUTOTILE_31:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_3))));
          return false;
          break;

        case WM_AUTOTILE_13:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_4))));
          return false;
          break;

        case WM_AUTOTILE_32:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_5))));
          return false;
          break;

        case WM_AUTOTILE_23:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_6))));
          return false;
          break;

        case WM_AUTOTILE_33:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_7))));
          return false;
          break;

        case WM_AUTOTILE_AUTO:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_8))));
          return false;
          break;

        case WM_EXTEND_0:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_MINS))));
          return false;
          break;

        case WM_EXTEND_1:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_EQL))));
          return false;
          break;

        case WM_EXTEND_2:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_LBRC))));
          return false;
          break;

        case WM_EXTEND_3:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_RBRC))));
          return false;
          break;

        case WM_EXTEND_4:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_9))));
          return false;
          break;

        /* case WM_SCALE_0: */
        /*   if (record->event.pressed) */
        /*     tap_code16(LCTL(LGUI(RGUI(KC_BSLS)))); */
        /*   return false; */
        /*   break; */

        /* case WM_SCALE_1: */
        /*   if (record->event.pressed) */
        /*     tap_code16(LCTL(LGUI(RGUI(KC_QUOT)))); */
        /*   return false; */
        /*   break; */

        /* case WM_SCALE_2: */
        /*   if (record->event.pressed) */
        /*     tap_code16(LCTL(LGUI(RGUI(KC_GRV)))); */
        /*   return false; */
        /*   break; */

        /* case WM_SCALE_3: */
        /*   if (record->event.pressed) */
        /*     tap_code16(LCTL(LGUI(RGUI(KC_SLSH)))); */
        /*   return false; */
        /*   break; */

        case WM_MOVE_0:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_F1))));
          return false;
          break;

        case WM_MOVE_1:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_F2))));
          return false;
          break;

        case WM_MOVE_2:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_F3))));
          return false;
          break;

        case WM_MOVE_3:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_F4))));
          return false;
          break;

        case WM_SWAP_0:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_F5))));
          return false;
          break;

        case WM_SWAP_1:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_F6))));
          return false;
          break;

        case WM_SWAP_2:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_PGUP))));
          return false;
          break;

        case WM_SWAP_3:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_PGDN))));
          return false;
          break;

        case WM_UNDO:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_UNDO))));
          return false;
          break;

        case WM_REDO:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(RGUI(KC_AGIN))));
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

/* ** Xmodmap */
        case XMODMAPRESET:
            if (record->event.pressed)
                tap_code16(LSFT(LCTL(LGUI(KC_B))));
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
