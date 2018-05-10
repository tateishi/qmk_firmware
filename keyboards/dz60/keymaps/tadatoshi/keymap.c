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

#define KC_MHKB MO(HHKB)
#define KC_MMCR MO(MACR)
#define KC_MD60 MO(DZ60)
#define KC_LNAV LT(NAVI, KC_SPC)
#define KC_CESC CTL_T(KC_ESC)

#define KC_LATB LALT(KC_TAB)
#define KC_SATB S(LALT(KC_TAB))
#define KC_SCTB S(LCTL(KC_TAB))
#define KC_LCTB LCTL(KC_TAB)

enum custom_keycodes {
    MY_CUSTOM_MACRO = SAFE_RANGE
};

#define KC_CM01 MY_CUSTOM_MACRO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer Base: ANSI mode (HHKB Layout) */
    /* ,-----------------------------------------------------------.
     * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | \ | ` |
     * |-----------------------------------------------------------|
     * | Tab | Q | W | E | R | T | Y | U | I | O | P | [ | ] |Backs|
     * |-----------------------------------------------------------|
     * | Ctrl | A | S | D | F | G | H | J | K | L | ; | ' | Enter  |
     * |-----------------------------------------------------------|
     * | LShift | Z | X | C | V | B | N | M | , | . | / |RShift|Fn1|
     * |-----------------------------------------------------------'
     * | Fn |Gui |Alt | BackSP | Fn |   Space  |Alt |Gui | FN |Ctrl|
     * `-----------------------------------------------------------'
     */
    [BASE] = KC_LAYOUT_T(
           GESC,  1  ,  2  ,  3  ,  4  ,  5  ,  6  ,  7  ,  8  ,  9  ,  0  , MINS, EQL , BSLS, GRV ,
           TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,  Y  ,  U  ,  I  ,  O  ,  P  , LBRC, RBRC, BSPC,
           CESC,  A  ,  S  ,  D  ,  F  ,  G  ,  H  ,  J  ,  K  ,  L  , SCLN, QUOT, ENT ,
           LSFT,  Z  ,  X  ,  C  ,  V  ,  B  ,  N  ,  M  , COMM, DOT , SLSH, RSFT, MHKB,
           LCTL, LGUI, LALT, BSPC, LNAV, SPC , RALT, MMCR, MD60, RCTL),


    /* Layer HHKB: HHKB mode (HHKB Fn) */
    /* ,-----------------------------------------------------------.
     * |Pwr|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   | * | / |Hom|PgU|Lef|Rig| Enter  |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   | + | - |End|PgD|Dow|      |   |
     * |-----------------------------------------------------------|
     * |    |    |    |  DEL   |    |          |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [HHKB] = KC_LAYOUT_T(
           PWR , F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 , F12 , INS , DEL ,
           CAPS, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, PSCR, SLCK, PAUS, UP  , xxxx, BSPC,
           xxxx, VOLD, VOLU, MUTE, xxxx, xxxx, PAST, PSLS, HOME, PGUP, LEFT, RGHT, PENT,
           xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, PPLS, PMNS, END , PGDN, DOWN, xxxx, xxxx,
           xxxx, xxxx, xxxx, DEL , xxxx, xxxx, xxxx, xxxx, xxxx, xxxx),


    /* Layer NAVI: NAVI mode (Center Fn) */
    /* ,-----------------------------------------------------------.
     * |ESC|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |     |MwL|McU|MwR|MwU|   |   |Hom|PgU|End|   |   |   |     |
     * |-----------------------------------------------------------|
     * | Ctrl |McL|McD|McR|MwD|   |Lef|Dwn|Up |Rig|WBK|WFD|        |
     * |-----------------------------------------------------------|
     * | LShift |Mb4|Mb3|Mb2|Mb1|Mb5|Nwn|Pwn|PgD|Ntb|Ptb|RShift|   |
     * |-----------------------------------------------------------|
     * |LCtl|Gui |Alt |  F13   |    |    F14   |Alt |Gui |App |Ctrl|
     * `-----------------------------------------------------------'
     */
    [NAVI] = KC_LAYOUT_T(
           ESC , F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 , F12 , INS , DEL ,
           xxxx, WH_L, MS_U, WH_R, WH_U, xxxx, xxxx, HOME, PGUP, END , xxxx, xxxx, xxxx, xxxx,
           ____, MS_L, MS_D, MS_R, WH_D, xxxx, LEFT, DOWN, UP  , RGHT, WBAK, WFWD, xxxx,
           ____, BTN4, BTN3, BTN2, BTN1, BTN5, LATB, SATB, PGDN, SCTB, LCTB, ____, xxxx,
           ____, ____, ____, F13 , xxxx, F14 , ____, RGUI, APP , ____),


    /* Layer DZ60: Dz60 mode (Right Fn) */
    /* ,-----------------------------------------------------------.
     * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Ins|Bsp|
     * |-----------------------------------------------------------|
     * |     |TOG|MOD|HUI|HUD|SAI|SAD|VAI|VAD|   |  |Up |   |Reset |
     * |-----------------------------------------------------------|
     * |      |   |M_P|   |   |   |   |   |Hom|PgU|Lft|Rgt|        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |DEC|TOG|INC|STP|End|PgD|Dwn|      |   |
     * |-----------------------------------------------------------'
     * |    |    |    |        |    |          |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [DZ60] = KC_LAYOUT_T(
           ESC , F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 , F12 , INS , BSPC,
           ____, RTOG, RMOD, RHUI, RHUD, RSAI, RSAD, RVAI, RVAD, ____, ____, UP  , ____, RST ,
           ____,    ____,    RM_P, ____, ____, ____, ____, ____, HOME, PGUP, LEFT, RGHT, ____,
           ____,    ____,    ____, BDEC, BTOG, BINC, BSTP, ____, END , PGDN, DOWN, ____, ____,
           ____,    ____,    ____, ____, ____, ____, ____, ____, ____, ____),


    /* Layer MACR: Macro mode (Right SUPER) */
    /* ,-----------------------------------------------------------.
     * |   |M01|M02|M03|M04|M05|M06|M07|M08|M09|M10|M11|M12|   |   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |  |   |   |      |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |
     * |-----------------------------------------------------------'
     * |    |    |    |        |    |          |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [MACR] = LAYOUT_T(
           ____, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9),M(10),M(11),M(12), ____, ____,
           ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
           ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
           ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MY_CUSTOM_MACRO:
                SEND_STRING("QMK is best thing ever!");
                return false;
        }
    }

    return true;
}
