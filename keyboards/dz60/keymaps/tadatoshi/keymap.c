#include "dz60.h"

#define BASE 0
#define HHKB 1
#define NAVI 2
#define DZ60 3
#define MACR 4

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define ____ KC_TRNS
#define xxxx KC_NO

#define KEYMAP_T( \
          K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
          K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
          K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,       \
          K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \
          K400, K401,       K403, K404,       K406,       K408,       K410, K411,       K413, K414  \
) { \
        { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014 }, \
        { K100, xxxx, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114 }, \
        { K200, xxxx, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, xxxx }, \
        { K300, xxxx, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, xxxx, K313, K314 }, \
        { K400, K401, xxxx, K403, K404, xxxx, K406, xxxx, K408, xxxx, K410, K411, xxxx, K413, K414 }  \
}

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

    [BASE] = KEYMAP_T(
           F(0),    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
           KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
           KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(HHKB),
           KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, LT(NAVI,KC_SPC), KC_SPC, KC_RALT, MO(MACR), MO(DZ60),   KC_RCTL),


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

  [HHKB] = KEYMAP_T(
         KC_PWR,  KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_INS, KC_DEL,
         KC_CAPS, xxxx,    xxxx,    xxxx,    xxxx,  xxxx,  xxxx,    xxxx,    KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   xxxx,   KC_BSPC,
         xxxx,    KC_VOLD, KC_VOLU, KC_MUTE, xxxx,  xxxx,  KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
         xxxx,    xxxx,    xxxx,    xxxx,    xxxx,  xxxx,  KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, xxxx,    xxxx,
         xxxx,    xxxx,    xxxx,    xxxx,    xxxx,  xxxx,  xxxx,    xxxx,    xxxx,    xxxx),

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

  [NAVI] = KEYMAP_T(
         KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_INS, KC_DEL,
         xxxx,    KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, xxxx,  xxxx,    KC_HOME, KC_PGUP, KC_END,  xxxx,    xxxx,   xxxx,   xxxx,
         xxxx,    KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, xxxx,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_WBAK, KC_WFWD,xxxx,
         KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, xxxx,  LALT(KC_TAB), S(LALT(KC_TAB)), KC_PGDN, S(LCTL(KC_TAB)), LCTL(KC_TAB),xxxx,xxxx,
         xxxx,    xxxx,    xxxx,    xxxx,    xxxx,    xxxx,  xxxx,    xxxx,    xxxx,    xxxx),

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

    [DZ60] = KEYMAP_T(
           KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_INS, KC_BSPC,
           ____,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ____,    ____,    KC_UP,   ____,   RESET,
           ____,    ____,    RGB_M_P, ____,    ____,    ____,    ____,    ____,    KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, ____,
           ____,    ____,    ____,    BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, ____,    KC_END,  KC_PGDN, KC_DOWN, ____,   ____,
           ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____),

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
