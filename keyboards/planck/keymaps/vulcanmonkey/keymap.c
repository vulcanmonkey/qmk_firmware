/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  EMOJI,
  ONE_UP,
  ZELDA,
  COIN,
  SONIC,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | ENTR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Del  |Lower |    Space    |Raise | SHFT | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT ,
  KC_LCTL, KC_LALT, KC_LGUI, KC_DEL,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |Pg Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  | Home |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_PGUP, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_HOME, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   (  |   {  |   }  |   )  |   ?  |  _   |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   \  |   [  |   ]  |   /  |   |  |      |      |      | Home |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_TAB,  KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, S(KC_SLSH), S(KC_MINS), KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX,
  _______, KC_BSLS, KC_LBRC, KC_RBRC, KC_SLSH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      | R_TOG| R_MOD| R_HUI| R_HUD| R_SAI| R_SAD| R_VAI| R_VAD| Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  1UP |SONIC |Aud on|Audoff|AGnorm|AGswap|QWERTY|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | ZLDA | COIN |Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
  _______, RESET,  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
  _______, ONE_UP,  SONIC,   AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
  _______, ZELDA,   COIN,    MU_ON,   MU_OFF,  _______, _______, TERM_ON, TERM_OFF, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float one_up_song[][2] = SONG(ONE_UP_SOUND);
  float zelda_song [][2] = SONG(ZELDA_PUZZLE);
  float sonic_song [][2] = SONG(SONIC_RING);
  float coin_song [][2] = SONG(COIN_SOUND);
  float windows_song [][2] = SONG(IN_LIKE_FLINT);
  float mac_song [][2] = SONG(GUITAR_SOUND);
  float linux_song [][2] = SONG(DOE_A_DEER);
#endif

void unicode_input_start()
{
  uint8_t input = get_unicode_input_mode();
  switch(input) {
  case UC_OSX:
    SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_SPACE))));
    register_code(KC_LALT);
    break;
  case UC_LNX:
    register_code(KC_LCTL);
    register_code(KC_LSFT);
    register_code(KC_U);
    unregister_code(KC_U);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
    break;
  case UC_WIN:
    register_code(KC_LALT);
    register_code(KC_PPLS);
    unregister_code(KC_PPLS);
    break;
  case UC_WINC:
    register_code(KC_RALT);
    unregister_code(KC_RALT);
    register_code(KC_U);
    unregister_code(KC_U);
  }
  wait_ms(UNICODE_TYPE_DELAY);
}

void unicode_input_finish()
{
  uint8_t input = get_unicode_input_mode();
  switch(input) {
    case UC_OSX:
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_SPACE))));
    case UC_WIN:
      unregister_code(KC_LALT);
      break;
    case UC_LNX:
      register_code(KC_SPC);
      unregister_code(KC_SPC);
      break;
    case UC_WINC:
      // A bit of a hack for now to get WinCompose to essentially know that the key sequence is done
      register_code(KC_SPC);
      unregister_code(KC_SPC);
      register_code(KC_BSPC);
      unregister_code(KC_BSPC);
      break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case QWERTY:
      if(record->event.pressed)
      {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case SONIC:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(sonic_song);
        #endif
      }
      return false;
      break;
    case ONE_UP:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(one_up_song);
        #endif
      }
      return false;
      break;
    case ZELDA:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(zelda_song);
        #endif
      }
      return false;
      break;
    case COIN:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(coin_song);
        #endif
      }
      return false;
      break;
  }
  return true;
}
