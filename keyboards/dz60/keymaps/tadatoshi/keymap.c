#include "dz60.h"
#include "tadatoshi.h"

#define BASE 0
#define HHKB 1
#define NAVI 2
#define DZ60 3
#define MACR 4

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define ____ KC_TRNS
#define xxxx KC_NO

#define KC_____ KC_TRNS
#define KC_xxxx KC_NO

#define KC_RST  RESET

#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_RM_P RGB_M_P

#define KC_BDEC BL_DEC
#define KC_BTOG BL_TOGG
#define KC_BINC BL_INC
#define KC_BSTP BL_STEP

#define KC_SESC F(0)
#define KC_MHKB MO(HHKB)
#define KC_MMCR MO(MACR)
#define KC_MD60 MO(DZ60)
#define KC_LNAV LT(NAVI, KC_SPC)

#define KC_LATB LALT(KC_TAB)
#define KC_SATB S(LALT(KC_TAB))
#define KC_SCTB S(LCTL(KC_TAB))
#define KC_LCTB LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Bspc |
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |
     * |-----------------------------------------------------------|
     * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|RShift|Fn1|
     * |-----------------------------------------------------------'
     * |FN  |Gui |Alt  |BackSP |FN |Space      |Alt |Gui |FN  |CTRL|
     * `-----------------------------------------------------------'
     */
    [BASE] = KC_KEYMAP_T(
           SESC,  1  ,  2  ,  3  ,  4  ,  5  ,  6  ,  7  ,  8  ,  9  ,  0  , MINS, EQL , BSLS, GRV ,
           TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,  Y  ,  U  ,  I  ,  O  ,  P  , LBRC, RBRC, BSPC,
           LCTL,  A  ,  S  ,  D  ,  F  ,  G  ,  H  ,  J  ,  K  ,  L  , SCLN, QUOT, ENT ,
           LSFT,  Z  ,  X  ,  C  ,  V  ,  B  ,  N  ,  M  , COMM, DOT , SLSH, RSFT, MHKB,
           LCTL, LGUI, LALT, BSPC, LNAV, SPC , RALT, MMCR, MD60, RCTL),

    /* Layer HHKB: HHKB mode (HHKB Fn) */
    /* ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus| Up|   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig| Enter  |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
     * |-----------------------------------------------------------|
     * |    |    |     |       |   |           |    |    |    |    |
     * `-----------------------------------------------------------'
     */

  [HHKB] = KC_KEYMAP_T(
         PWR , F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 , F12 , INS , DEL ,
         CAPS, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, PSCR, SLCK, PAUS, UP  , xxxx, BSPC,
         xxxx, VOLD, VOLU, MUTE, xxxx, xxxx, PAST, PSLS, HOME, PGUP, LEFT, RGHT, PENT,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, PPLS, PMNS, END , PGDN, DOWN, xxxx, xxxx,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx),

    /* Layer NAVI: NAVI mode (Center Fn) */
    /* ,-----------------------------------------------------------.
     * |ESC| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |     |MwL|McU|MwR|MwU|   |   |Hom|PgU|End|   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |McL|McD|McR|MwD|   |Lef|Dwn| Up|Rig|WBK|WFD|        |
     * |-----------------------------------------------------------|
     * |     Mb5|Mb4|Mb3|Mb2|Mb1|   |Nwn|Pwn|PgD|Ntb|Ptb|      |   |
     * |-----------------------------------------------------------|
     * |    |    |     |       |   |           |    |    |    |    |
     * `-----------------------------------------------------------'
     */

  [NAVI] = KC_KEYMAP_T(
         ESC , F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 , F12 , INS , DEL ,
         xxxx, WH_L, MS_U, WH_R, WH_U, xxxx, xxxx, HOME, PGUP, END , xxxx, xxxx, xxxx, xxxx,
         xxxx, MS_L, MS_D, MS_R, WH_D, xxxx, LEFT, DOWN, UP  , RGHT, WBAK, WFWD, xxxx,
         BTN5, BTN4, BTN3, BTN2, BTN1, xxxx, LATB, SATB, PGDN, SCTB, LCTB, xxxx, xxxx,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx),

    /* ,-----------------------------------------------------------.
     * |  `| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Bsp|
     * |-----------------------------------------------------------|
     * |     |TOG|MOD|HUI|HUD|SAI|SAD|VAI|VAD|   |  | Up|   | RST  |
     * |-----------------------------------------------------------|
     * |      |   |M_P|   |   |   |   |   |Hom|PgU|Lft|Rgt|        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |DEC|TOG|INC|STP|End|PgD|Dwn|      |   |
     * |-----------------------------------------------------------'
     * |    |    |     |       |   |           |    |    |    |    |
     * `-----------------------------------------------------------'
     */

    [DZ60] = KC_KEYMAP_T(
           ESC , F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 , F12 , INS , BSPC,
           ____, RTOG, RMOD, RHUI, RHUD, RSAI, RSAD, RVAI, RVAD, ____, ____, UP  , ____, RST ,
           ____,    ____,    RM_P, ____, ____, ____, ____, ____, HOME, PGUP, LEFT, RGHT, ____,
           ____,    ____,    ____, BDEC, BTOG, BINC, BSTP, ____, END , PGDN, DOWN, ____, ____,
           ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____),

    /* ,-----------------------------------------------------------.
     * |   |M01|M02|M03|M04|M05|M06|M07|M08|M09|M10|M11|M12|   |   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |  |   |   |      |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * |-----------------------------------------------------------'
     * |    |    |     |       |   |           |    |    |    |    |
     * `-----------------------------------------------------------'
     */

    [MACR] = KEYMAP_T(
           ____, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), ____, ____,
           ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,  ____,  ____,  ____,
           ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,  ____,  ____,
           ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,  ____,  ____,
           ____, ____, ____, ____, ____, ____, ____, ____, ____, ____),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    static uint8_t shift_esc_shift_mask;
    switch (id) {
    case SHIFT_ESC:
        shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
        if (record->event.pressed) {
            if (shift_esc_shift_mask) {
                add_key(KC_GRV);
                send_keyboard_report();
            } else {
                add_key(KC_ESC);
                send_keyboard_report();
            }
        } else {
            if (shift_esc_shift_mask) {
                del_key(KC_GRV);
                send_keyboard_report();
            } else {
                del_key(KC_ESC);
                send_keyboard_report();
            }
        }
        break;
    }
}
