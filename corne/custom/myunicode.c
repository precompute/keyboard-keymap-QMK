/* -*- eval: (outshine-mode 1); -*- */
#include QMK_KEYBOARD_H
#include "myunicode.h"

const uint32_t PROGMEM unicode_map[] = {
[ESZETT]   = 0x00DF, //ß
[AUMLAUT]  = 0x00E4, //ä
[OUMLAUT]  = 0x00F6, //ö
[UUMLAUT]  = 0x00FC, //ü
[AUMLAUTC] = 0x00C4, //Ä
[OUMLAUTC] = 0x00D6, //Ö
[UUMLAUTC] = 0x00DC, //Ü
[AIGU]     = 0x00E9, //é
};

/* Character	Unicode Character Number (Decimal)	Unicode Character (Hexadecimal ) */
/* ß	0223	00DF eszett */
/* ä	0228	00E4 */
/* ö	0246	00F6 */
/* ü	0252	00FC */
/* Ä	0196	00C4 */
/* Ö	0214	00D6 */
/* Ü	0220	00DC */
