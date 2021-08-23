#ifndef MYMACROS_H
#define MYMACROS_H

enum custom_keycodes {
    VIMDOW_L = SAFE_RANGE,
    VIMDOW_D,
    VIMDOW_U,
    VIMDOW_R,
    VIMBUF_P,
    VIMBUF_N,
    VIMEDIT,
    VIMEXEC,
    /* VIMSPLIT_V, */
    /* VIMSPLIT_H, */

    WM_MAX,
    WM_MIN,
    WM_MAX_H,
    WM_MAX_V,
    WM_WSPC_N,
    WM_WSPC_P,
    WM_MV_WSPC_N,
    WM_MV_WSPC_P,
    WM_TILE_T,
    WM_TILE_B,
    WM_TILE_L,
    WM_TILE_R,
    WM_TILE_TL,
    WM_TILE_TR,
    WM_TILE_BL,
    WM_TILE_BR,

    EMACS_SEXP_P,
    EMACS_GIT_HUNK_N,
    EMACS_GIT_HUNK_P,
    EMACS_SEXP_N,
    EMACS_BW_B,
    EMACS_B_D,
    EMACS_B_U,
    EMACS_BW_F,
    EMACS_VISUAL,
    EMACS_HEADING_P,
    EMACS_HEADING_N,
    EMACS_DIRED_JUMP,
    RGUI_TAB
};

#endif // MYMACROS_H
