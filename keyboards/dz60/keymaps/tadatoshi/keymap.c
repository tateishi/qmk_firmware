#include "dz60.h"

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

#define KC_SESC F(0)
#define KC_MHKB MO(HHKB)
#define KC_MMCR MO(MACR)
#define KC_MD60 MO(DZ60)
#define KC_LNAV LT(NAVI, KC_SPC)

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

// Used to create a keymap using only KC_ prefixed keys
#define KC_KEYMAP_T( \
             K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
             K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
             K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, \
             K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \
             K400, K401,       K403, K404,       K406,       K408,       K410, K411,       K413, K414 \
    ) \
    KEYMAP_T( \
             KC_##K000, KC_##K001, KC_##K002, KC_##K003, KC_##K004, KC_##K005, KC_##K006, KC_##K007, KC_##K008, KC_##K009, KC_##K010, KC_##K011, KC_##K012, KC_##K013, KC_##K014, \
             KC_##K100,       KC_##K102, KC_##K103, KC_##K104, KC_##K105, KC_##K106, KC_##K107, KC_##K108, KC_##K109, KC_##K110, KC_##K111, KC_##K112, KC_##K113, KC_##K114, \
             KC_##K200,       KC_##K202, KC_##K203, KC_##K204, KC_##K205, KC_##K206, KC_##K207, KC_##K208, KC_##K209, KC_##K210, KC_##K211, KC_##K212, KC_##K213, \
             KC_##K300,       KC_##K302, KC_##K303, KC_##K304, KC_##K305, KC_##K306, KC_##K307, KC_##K308, KC_##K309, KC_##K310, KC_##K311,       KC_##K313, KC_##K314, \
             KC_##K400, KC_##K401,       KC_##K403, KC_##K404,       KC_##K406,       KC_##K408,       KC_##K410, KC_##K411,       KC_##K413, KC_##K414 \
              )

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
