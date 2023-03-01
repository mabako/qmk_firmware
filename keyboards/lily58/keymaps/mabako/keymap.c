#include QMK_KEYBOARD_H
#include <string.h>
#include "raw_hid.h"
#include "transactions.h"
#include "unicode_kb.h"

#define RAW_EPSIZE 32

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
  C_TRIG,

  C_ULGHT,
  C_DLGHT,
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
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Y,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQUAL,
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
  LSFT_T(KC_GRV), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  KC_LCTL,        _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
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
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______,       _______, _______, _______, _______, _______,                     QK_BOOT, _______, KC_MPLY, KC_MNXT, KC_PSCR, KC_PAUS,
  KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  LSFT_T(KC_F1), KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
  LCTL_T(KC_F7), KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   C_ULGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C_DLGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* UMLAUT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |   È  |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   €  |      |      |                    |TFlip |   Ü  |      |   Ö  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Ä  |   ß  |   É  |      |      |-------.    ,-------| TPut |      |      | TRig |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|Shrug |      |      |      |   \  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_UMLAUT] = LAYOUT(
  _______, _______, _______, KC_EGRV, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_EUR , _______, _______,                   C_TFLIP, KC_UE  , _______, KC_OE  , _______, _______,
  _______, KC_AE  , KC_SS  , KC_EACT, _______, _______,                   C_TPUT,  _______, _______, C_TRIG,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, C_SHRUG, _______, _______, _______, KC_BSLS, KC_PIPE,
                             _______, _______, _______, _______, _______, _______, _______, _______
)};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint32_t clock_timer = 0;
bool clock_set = false;

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_left())
    return OLED_ROTATION_270;
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
// const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);
void send_hid_command(uint8_t command);

bool oled_task_user(void) {
  if (!is_keyboard_left()) {
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

    oled_set_cursor(0, 4);
    oled_write_ln(read_keylog(), false);
    oled_set_cursor(0, 9);
    oled_write(read_keylogs(), false);

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

    // clock
    if (clock_set) {
      uint32_t diff = TIMER_DIFF_32(timer_read32(), clock_timer) / 60000;
      uint32_t hours = (diff / 60) % 24;
      uint32_t minutes = diff % 60;

      char time_str[6];
      time_str[2] = '\0';
      time_str[1] = '0' + minutes % 10;
      time_str[0] = '0' + minutes / 10;
      oled_set_cursor(3, 10);
      oled_write(time_str, false);
      
      time_str[1] = '0' + hours % 10;
      time_str[0] = '0' + hours / 10;
      oled_set_cursor(1, 9);
      oled_write(time_str, false);
    }
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
    case C_TRIG:
      if (record->event.pressed) {
        send_unicode_string("→");
      }
      return false;
    case C_ULGHT:
      if (record->event.pressed) {
        send_hid_command(0x01);
      }
      return false;
    case C_DLGHT:
      if (record->event.pressed) {
        send_hid_command(0x02);
      }
      return false;
  }

  return true;
}

void clock_set_handler(uint8_t request_size, const void* request, uint8_t response_size, void* response) {
  clock_timer = timer_read32() - *(uint32_t*)request;
  clock_set = true;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (data[0] != 0xC3) {
    return;
  }

  uint8_t response[RAW_EPSIZE];
  memset(response, 0, RAW_EPSIZE);

  if(data[1] == 0x01) {
    uint32_t ms_since_midnight = (((uint32_t)data[5] << 24) | ((uint32_t)data[4] << 16) | ((uint32_t)data[3] << 8) | (uint32_t)data[2]);
    //memcpy(&ms_since_midnight, &data[2], sizeof(ms_since_midnight));

    if (is_keyboard_left()) {
      clock_set_handler(sizeof(ms_since_midnight), (void*)&ms_since_midnight, 0, NULL);
    } else {
      clock_timer = ms_since_midnight;
      clock_set = true;
    }

    response[0] = 0xC4;
    response[1] = 0x01;
  }
  
  raw_hid_send(response, RAW_EPSIZE);
}

void send_hid_command(uint8_t command) {
  uint8_t response[RAW_EPSIZE];
  memset(response, 0, RAW_EPSIZE);
  response[0] = 0xC5;
  response[1] = command;

  raw_hid_send(response, RAW_EPSIZE);
}

void keyboard_post_init_user(void) {
  transaction_register_rpc(USER_SET_CLOCK, clock_set_handler);
}

void housekeeping_task_user(void) {
  if (is_keyboard_master() && !is_keyboard_left()) {
    if (clock_set) {
      if (transaction_rpc_send(USER_SET_CLOCK, sizeof(clock_timer), &clock_timer)) {
        clock_set = false;
      }
    }
  }
}

const key_override_t undo_override = ko_make_basic(MOD_MASK_CTRL, KC_Y, C(KC_Z));
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
//const key_override_t rdp_home = ko_make_basic(MOD_MASK_CAG, KC_8, LCA(KC_HOME));
//const key_override_t rdp_end = ko_make_basic(MOD_MASK_CAG, KC_9, LCA(KC_END));
const key_override_t **key_overrides = (const key_override_t *[]){
  &undo_override,
  &delete_key_override,
  //&rdp_home,
  //&rdp_end,
  NULL
};
