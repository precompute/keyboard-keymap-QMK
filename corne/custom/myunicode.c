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

[EMOJI00] = 0X1F60B, //😋
[EMOJI01] = 0x1f61b, //😛
[EMOJI02] = 0x1f61c, //😜
[EMOJI03] = 0x1f92d, //🤭
[EMOJI04] = 0x1f928, //🤨
[EMOJI05] = 0x1f610, //😐
[EMOJI06] = 0x1f611, //😑
[EMOJI07] = 0x1f636, //😶
[EMOJI08] = 0x1f920, //🤠
[EMOJI09] = 0x1f973, //🥳
[EMOJI10] = 0x1f44b, //👋
[EMOJI11] = 0x1f44d, //👍
[EMOJI12] = 0x1f605, //😅
[EMOJI13] = 0x1f600, //😀
[EMOJI14] = 0x1f604, //😄
[EMOJI15] = 0x1f606, //😆
[EMOJI16] = 0x1f602, //😂
[EMOJI17] = 0x1f642, //🙂
[EMOJI18] = 0x1f643, //🙃
[EMOJI19] = 0x1f609, //😉
[EMOJI20] = 0x1f60a, //😊
[EMOJI21] = 0x1f607, //😇
[EMOJI22] = 0x1f923, //🤣
[EMOJI23] = 0x1f44a, //👊
[EMOJI24] = 0x1f60e, //😎
[EMOJI25] = 0x1f641, //🙁
[EMOJI26] = 0x1f623, //😣
[EMOJI27] = 0x1f62b, //😫
[EMOJI28] = 0x1f480, //💀
[EMOJI29] = 0x2620,  //☠
[EMOJI30] = 0x1f620, //😠
[EMOJI31] = 0x1f4af, //💯
[EMOJI32] = 0x1f4a2, //💢
[EMOJI33] = 0x1f44e, //👎
[EMOJI34] = 0x1f440, //👀
[EMOJI35] = 0x1f4a5, //💥
[EMOJI36] = 0x1f47b, //👻
[EMOJI37] = 0x1f916, //🤖
[EMOJI38] = 0x1f937, //🤷
[EMOJI39] = 0x1f340, //🍀
};

/* Character	Unicode Character Number (Decimal)	Unicode Character (Hexadecimal ) */
/* ß	0223	00DF eszett */
/* ä	0228	00E4 */
/* ö	0246	00F6 */
/* ü	0252	00FC */
/* Ä	0196	00C4 */
/* Ö	0214	00D6 */
/* Ü	0220	00DC */

/* 😋😛😜🤭🤨😐😑😶🤠🥳👋👍 */
/* 😅😀😄😆😂🙂🙃😉😊😇🤣👊 */
/* 😎🙁😣😫💀☠😠💯💢💥👀👎 */
/* 👻🤖🤷🍀 */
