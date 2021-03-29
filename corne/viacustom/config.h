#pragma once

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */
#define SPLIT_USB_DETECT
#define MASTER_LEFT
/* #define MASTER_RIGHT */
// #define EE_HANDS

#define USE_SERIAL_PD2
