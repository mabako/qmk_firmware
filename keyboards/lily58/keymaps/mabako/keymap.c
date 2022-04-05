#include QMK_KEYBOARD_H
#include "unicode.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _UMLAUT,
};

enum custom_keycodes {
  C_SHRUG = SAFE_RANGE,
  C_TFLIP,
  C_TPUT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|UMLAUT|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RSFT_T(KC_QUOT),
  KC_LCTRL, KC_Y,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RCTL_T(KC_EQUAL),
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, MO(_UMLAUT)
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      | BOOT |                    | INS  | DEL  | HOME | END  |PgDown| PgUp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______,        _______, _______, _______, _______, QK_BOOT,                   KC_INS,  KC_DEL,  KC_HOME, KC_END,  KC_PGDN, KC_PGUP,
  KC_F1,          KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  LSFT_T(KC_GRV), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, RSFT_T(KC_TILD),
  KC_LCTRL,       _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, RCTL_T(KC_PIPE),
                                    _______, _______, _______, _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | BOOT |      |MPlay |MNext |Print |Pause |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______,       _______, _______, _______, _______, _______,                     QK_BOOT, _______, KC_MPLY, KC_MNXT, KC_PSCR, KC_PAUS,
  KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  LSFT_T(KC_F1), KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_RSFT,
  LCTL_T(KC_F7), KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, RCTL_T(KC_BSLS),
                                   _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* UMLAUT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |   È  |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   €  |      |      |                    |TFlip |   Ü  |      |   Ö  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Ä  |   ß  |   É  |      |      |-------.    ,-------| TPut |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|Shrug |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_UMLAUT] = LAYOUT(
  _______, _______, _______, KC_EGRV, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_EUR , _______, _______,                   C_TFLIP, KC_UE  , _______, KC_OE  , _______, _______,
  _______, KC_AE  , KC_SS  , KC_EACT, _______, _______,                   C_TPUT,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, C_SHRUG, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
)};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_left())
    return OLED_ROTATION_270;
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (!is_keyboard_left()) {

    oled_set_cursor(0, 4);
    oled_write_ln(read_keylog(), false);
    oled_set_cursor(0, 12);
    oled_write_ln(read_keylogs(), false);


    oled_set_cursor(0, 0);
    switch (get_highest_layer(layer_state)) {
      case _QWERTY:
        oled_write_ln_P(PSTR(" ooo "), false);
        break;
      case _RAISE:
        oled_write_ln_P(PSTR("RAISE"), false);
        break;
      case _LOWER:
        oled_write_ln_P(PSTR("LOWER"), false);
        break;
      case _ADJUST:
        oled_write_ln_P(PSTR("ADJST"), false);
        break;
      case _UMLAUT:
        oled_write_ln_P(PSTR("UMLAU"), false);
        break;
      default:
        oled_write_ln_P(PSTR("?????"), false);
    }
  } else {
    static const char PROGMEM logo[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x40, 0x00, 0x00, 0xc0, 0xe0,
      0xc0, 0xe0, 0x20, 0x38, 0x30, 0x38, 0x38, 0x38, 0x0c, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x18, 0xd0, 0xf0, 0xfc, 0x3b, 0x0f, 0x0f, 0x07, 0x03, 0x03, 0x03, 0x03,
      0x03, 0x03, 0x06, 0x06, 0x0e, 0x0c, 0x3c, 0xfe, 0xfe, 0xe4, 0x03, 0x00, 0x80, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x10, 0x30, 0x79, 0xff, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0x7f, 0x70, 0x30, 0x10, 0x0c, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x07, 0x07, 0x0e, 0x1e, 0x1c, 0x1c, 0x1c, 0x1c,
      0x0c, 0x0c, 0x0c, 0x1e, 0x1e, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(logo, sizeof(logo));
    // wpm counter
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(1, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case RCTL_T(KC_PIPE):
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_PIPE);
        return false;
      }
      break;
    case C_SHRUG:
      if (record->event.pressed) {
        send_unicode_string("¯\\_(ツ)_/¯");
      }
      return false;
    case C_TFLIP:
      if (record->event.pressed) {
        send_unicode_string("(┛°□°)┛ヘ┻━┻");
      }
      return false;
    case C_TPUT:
      if (record->event.pressed) {
        send_unicode_string("┬──┬ \u30CE( ゜-゜\u30CE)");
      }
      return false;
  }

  return true;
}

const key_override_t undo_override = ko_make_basic(MOD_MASK_CTRL, KC_Y, C(KC_Z));
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t **key_overrides = (const key_override_t *[]){
    &undo_override,
    &delete_key_override,
    NULL
};
