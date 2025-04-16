
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
  #include <stdio.h>

  #include QMK_KEYBOARD_H

  enum sofle_layers {
      _DEFAULTS = 0,
      _QWERTY = 0,
      _LOWER,
      _RAISE,
      _ADJUST,
  };

  enum custom_keycodes {
      KC_QWERTY = SAFE_RANGE,
      KC_LOWER,
      KC_RAISE,
      KC_ADJUST,
      KC_D_MUTE
  };

  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY */
      [_QWERTY] = LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,KC_8, KC_9, KC_0, KC_MINS,
      KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, RGB_TOG, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
      KC_LCTL, KC_LGUI, KC_SPC, KC_LOWER, KC_TAB, KC_ENT, KC_RAISE, KC_BSPC, KC_LALT ,KC_BSPC
    ),
    /* LOWER */
    [_LOWER] = LAYOUT(
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
      KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_LBRC), LSFT(KC_RBRC),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /* RAISE */
    [_RAISE] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,KC_TRNS,
      KC_TRNS, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /* ADJUST */
      [_ADJUST] = LAYOUT(
      HF_RST, EE_CLR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT,KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    };

    #ifdef OLED_ENABLE
    /** https://javl.github.io/image2cpp/ plain vert 1 bit */
    static void render_logo(void) {
        static const char PROGMEM qmk_logo[] = {
    // 'sumo-logo', 128x32px
    0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xb0, 0x48, 0xb4, 0xba, 0xba, 0xba, 0x44, 0x74,
    0xe8, 0xe8, 0xd0, 0xa0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x41, 0x02, 0x04, 0x18, 0x25, 0xc2, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0,
    0x80, 0x00, 0x08, 0x18, 0x28, 0x48, 0x88, 0x09, 0x08, 0x08, 0x08, 0x88, 0x08, 0x08, 0x48, 0x88,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x48, 0x48, 0x48, 0x08, 0x08, 0x08, 0xe8, 0x08, 0x08,
    0x08, 0xc8, 0x08, 0x08, 0x08, 0x48, 0x88, 0x88, 0x08, 0xc8, 0x08, 0x08, 0x08, 0x48, 0x88, 0x08,
    0x08, 0x88, 0x08, 0x08, 0x08, 0x88, 0x88, 0x8a, 0x88, 0x88, 0x88, 0x88, 0x08, 0x08, 0x08, 0x88,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x48, 0x88, 0x88, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0xe0, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x15, 0xc2, 0xf9, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x3f, 0xff,
    0xf6, 0xfe, 0xfd, 0xfb, 0xf7, 0x6e, 0x19, 0x06, 0x88, 0x08, 0xc8, 0xe8, 0xec, 0xec, 0x28, 0xd0,
    0x10, 0xe0, 0x00, 0x00, 0x00, 0x01, 0x02, 0x46, 0x7f, 0xdf, 0x8e, 0x04, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x80, 0xc0, 0xa0, 0x90, 0x88, 0x85, 0x82, 0x80, 0x80, 0x80, 0x83, 0x84, 0x84, 0x88,
    0x8f, 0x81, 0x80, 0x80, 0x81, 0x82, 0x84, 0x84, 0x89, 0x89, 0x80, 0x80, 0x80, 0x8f, 0x80, 0x80,
    0x80, 0x87, 0x80, 0x80, 0x80, 0x86, 0x88, 0x88, 0x89, 0x87, 0x81, 0x80, 0x80, 0x80, 0x89, 0x86,
    0x82, 0x85, 0x84, 0x88, 0x80, 0x80, 0x80, 0x80, 0x86, 0x81, 0x80, 0x80, 0x80, 0x84, 0x84, 0x84,
    0x87, 0x84, 0x88, 0x88, 0x80, 0x90, 0x88, 0x88, 0x89, 0x85, 0x81, 0x98, 0x80, 0x40, 0x3f, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x50, 0x87, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xf9, 0xfe,
    0xee, 0xff, 0x7e, 0xbf, 0xdf, 0xec, 0x30, 0xc0, 0x23, 0x20, 0x27, 0x2c, 0x6d, 0x6e, 0x29, 0x17,
    0x10, 0x0f, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x40, 0x3b, 0xff, 0xfe, 0x3c, 0x1c, 0x18,
    0x00, 0x00, 0xf0, 0x0c, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x02, 0x0c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x1a, 0x25, 0x5b, 0xbb, 0xbb, 0xbb, 0x45, 0x5d,
    0x2e, 0x2e, 0x17, 0x0b, 0x05, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x40, 0x08, 0x00, 0x10, 0x20, 0xc0, 0x30, 0x08, 0x04, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x06, 0x08, 0x10, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10,
    0x08, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0xa8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x88, 0x20, 0x20, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
    }

    static void render_layer_base(void) {
        static const char PROGMEM qmk_logo[] = {
    // 'sumo-default', 128x32px
    0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xb0, 0x48, 0xb4, 0xba, 0xba, 0xba, 0x44, 0x74,
    0xe8, 0xe8, 0xd0, 0xa0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, 0x9d, 0xff, 0x7f, 0x1e, 0x0e, 0x0c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x60, 0x10, 0x08, 0x44, 0x04, 0x02, 0x02, 0x12, 0x2a, 0x92, 0xc4, 0x84, 0x08, 0x90,
    0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x15, 0xc2, 0xf9, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x3f, 0xff,
    0xee, 0xfe, 0xfd, 0xfb, 0xf7, 0x6e, 0x19, 0x06, 0x88, 0x08, 0xc8, 0x68, 0x6c, 0xec, 0x28, 0xd0,
    0x10, 0xe0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x18, 0x04, 0x02, 0x01, 0x06, 0x18, 0xa0, 0xc0, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x31, 0x4e, 0x80, 0x4c, 0x12, 0x12, 0x0c, 0x00, 0x82, 0x80, 0x11, 0x00, 0x88, 0x41,
    0x32, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x50, 0x87, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xf9, 0xfe,
    0xde, 0xff, 0x7e, 0xbf, 0xdf, 0xec, 0x30, 0xc0, 0x23, 0x20, 0x27, 0x2e, 0x6f, 0x6e, 0x29, 0x17,
    0x10, 0x0f, 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x20, 0x40, 0x80, 0x44, 0x22, 0x1b, 0x0f, 0x07,
    0x03, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x80, 0x00, 0xc0, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x82, 0x02, 0x01, 0x01, 0x00, 0xc0,
    0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc1, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x1a, 0x25, 0x5b, 0xbb, 0xbb, 0xbb, 0x45, 0x5d,
    0x2e, 0x2e, 0x17, 0x0b, 0x05, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x04, 0x8d, 0xff, 0xbe, 0x1c, 0x08, 0x00,
    0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x0d, 0x03,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x0a, 0x12, 0x12, 0x02, 0x02, 0x02, 0x00, 0x00, 0x01,
    0x02, 0x02, 0x03, 0x0f, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x08, 0x0f,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x0f, 0x00, 0x1b, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
    }
    static void render_layer_raised(void) {
        static const char PROGMEM qmk_logo[] = {
    // 'sumo-level-01', 128x32px
    0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0x40,
    0x80, 0x80, 0x40, 0xa0, 0xd0, 0xe8, 0xe8, 0xf4, 0xf4, 0xfa, 0x7a, 0xba, 0xba, 0xba, 0x7a, 0x84,
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, 0x9d, 0xff, 0x7f, 0x1e, 0x0e, 0x0c,
    0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x00, 0x60, 0xa0, 0x40, 0x40, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x60, 0x10, 0x08, 0x44, 0x04, 0x02, 0x02, 0x12, 0x2a, 0x92, 0xc4, 0x84, 0x08, 0x90,
    0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x15, 0xc2, 0xf9, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x3f, 0xff,
    0xee, 0xfe, 0xfd, 0xfa, 0xf5, 0x6f, 0x1f, 0x87, 0x49, 0x0e, 0xc9, 0x68, 0x6c, 0xec, 0x29, 0xd0,
    0x10, 0xe0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x18, 0x04, 0x02, 0x01, 0x06, 0x18, 0xa0, 0xc0, 0x80,
    0x00, 0x07, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x05, 0x35, 0x28, 0x10, 0x10, 0x08, 0x08, 0x05,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x31, 0x4e, 0x80, 0x4c, 0x12, 0x12, 0x0c, 0x00, 0x82, 0x80, 0x11, 0x00, 0x88, 0x41,
    0x32, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x50, 0x87, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xf9, 0xfe,
    0xde, 0xff, 0x7e, 0xbf, 0xdf, 0xec, 0x30, 0xc1, 0x22, 0x20, 0x27, 0x2e, 0x6f, 0x6e, 0x29, 0x17,
    0x10, 0x0f, 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x20, 0x40, 0x80, 0x44, 0x22, 0x1b, 0x0f, 0x07,
    0x03, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x60, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x01, 0x02, 0x02, 0x03, 0x02, 0x02, 0x01, 0xc1, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x41, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x1a, 0x25, 0x5b, 0xbb, 0xbb, 0xbb, 0x45, 0x5d,
    0x2e, 0x2e, 0x17, 0x0b, 0x05, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x04, 0x8d, 0xff, 0xbe, 0x1c, 0x08, 0x00,
    0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07,
    0x37, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x1a,
    0x06, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x0a, 0x12, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1e, 0x01, 0x09, 0x09, 0x1f, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x02, 0x03, 0x1e, 0x02, 0x0f, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
    }
    static void render_layer_lower(void) {
        static const char PROGMEM qmk_logo[] = {
    // 'sumo-level-02', 128x32px
    0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xb0, 0x48, 0xb4, 0xba, 0xba, 0xba, 0x44, 0x74,
    0xe8, 0xe8, 0xd0, 0xa0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, 0x9d, 0xff, 0x7f, 0x1e, 0x0e, 0x0c,
    0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe1, 0x60, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x60, 0x10, 0x08, 0x44, 0x04, 0x02, 0x02, 0x12, 0x2a, 0x92, 0xc4, 0x84, 0x08, 0x90,
    0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x15, 0xc2, 0xf9, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x3f, 0xff,
    0xee, 0xfe, 0xfd, 0xfb, 0xf7, 0x6e, 0x19, 0x06, 0x88, 0x08, 0xc8, 0x68, 0x6c, 0xec, 0x28, 0xd0,
    0x10, 0xe0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x18, 0x04, 0x02, 0x01, 0x06, 0x18, 0xa0, 0xc0, 0x80,
    0x00, 0x02, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x37, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x31, 0x4e, 0x80, 0x4c, 0x12, 0x12, 0x0c, 0x00, 0x82, 0x80, 0x11, 0x00, 0x88, 0x41,
    0x32, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x50, 0x87, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xf9, 0xfe,
    0xde, 0xff, 0x7e, 0xbf, 0x5f, 0xec, 0xf0, 0xc2, 0x25, 0xe0, 0x27, 0x2e, 0x6f, 0x6e, 0x29, 0x17,
    0x10, 0x0f, 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x20, 0x40, 0x80, 0x44, 0x22, 0x1b, 0x0f, 0x07,
    0x03, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0xa0, 0x60,
    0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x01, 0x02, 0x02, 0x03, 0x02, 0x02, 0x01, 0xc1, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x41, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x05, 0x0b, 0x0b, 0x0b, 0x0b, 0x05, 0x05,
    0x02, 0x02, 0x05, 0x0a, 0x17, 0x2f, 0x2f, 0x5f, 0x5f, 0xbe, 0xbd, 0xba, 0xba, 0xba, 0xbd, 0x42,
    0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x04, 0x8d, 0xff, 0xbe, 0x1c, 0x08, 0x00,
    0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x05, 0x08, 0x08, 0x10, 0x10, 0x28, 0x35,
    0x05, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x1a,
    0x06, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x0a, 0x12, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1e, 0x01, 0x09, 0x09, 0x1f, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x02, 0x03, 0x1e, 0x02, 0x0f, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
    }
    static void render_layer_adjust(void) {
        static const char PROGMEM qmk_logo[] = {
    // 'sumo-system', 128x32px
    0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0x40,
    0x80, 0x80, 0x40, 0xa0, 0xd0, 0xe8, 0xe8, 0xf4, 0xf4, 0xfa, 0x7a, 0xba, 0xba, 0xba, 0x7a, 0x84,
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x20, 0x9d, 0xff, 0x7f, 0x1e, 0x0e, 0x0c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0x80, 0xc0, 0xe0,
    0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x60, 0x10, 0x08, 0x44, 0x04, 0x02, 0x02, 0x12, 0x2a, 0x92, 0xc4, 0x84, 0x08, 0x90,
    0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x15, 0xc2, 0xf9, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xc7, 0x3f, 0xff,
    0xee, 0xfe, 0xfd, 0xfa, 0xf5, 0x6f, 0x1f, 0x87, 0x49, 0x0e, 0xc9, 0x68, 0x6c, 0xec, 0x29, 0xd0,
    0x10, 0xe0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x18, 0x04, 0x02, 0x01, 0x06, 0x18, 0xa0, 0xc0, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0xf7, 0xf7, 0x87, 0xe3, 0xf1,
    0xf7, 0x77, 0x77, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x31, 0x4e, 0x80, 0x4c, 0x12, 0x12, 0x0c, 0x00, 0x82, 0x80, 0x11, 0x00, 0x88, 0x41,
    0x32, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x50, 0x87, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xf9, 0xfe,
    0xde, 0xff, 0x7e, 0xbf, 0x5f, 0xec, 0xf0, 0xc3, 0x24, 0xe0, 0x27, 0x2e, 0x6f, 0x6e, 0x29, 0x17,
    0x10, 0x0f, 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x20, 0x40, 0x80, 0x44, 0x22, 0x1b, 0x0f, 0x07,
    0x03, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe1, 0xe3, 0xef, 0x8f, 0xcf, 0xef,
    0xee, 0xee, 0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x00, 0xc0, 0x00, 0x81, 0x01, 0x02, 0x02, 0x23, 0x42, 0x82, 0x01, 0x01, 0x00, 0xc0,
    0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc1, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x09, 0x0a, 0x05, 0x0b, 0x0b, 0x0b, 0x0b, 0x05, 0x05,
    0x02, 0x02, 0x05, 0x0a, 0x17, 0x2f, 0x2f, 0x5f, 0x5f, 0xbe, 0xbd, 0xba, 0xba, 0xba, 0xbd, 0x42,
    0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x04, 0x8d, 0xff, 0xbe, 0x1c, 0x08, 0x00,
    0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01,
    0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x08, 0x08, 0x04, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x02, 0x0f, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x01, 0x02, 0x02, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x11, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
    }
    /**
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master()) {
           return OLED_ROTATION_270;
        }
        return rotation;
    }
    */

    bool oled_task_user(void) {
        if (is_keyboard_master()) {
            switch (get_highest_layer(layer_state)) {
                case _RAISE:
                    render_layer_raised();
                    break;
                case _LOWER:
                    render_layer_lower();
                    break;
                case _ADJUST:
                    render_layer_adjust();
                    break;
                default:
                    render_layer_base();
            }
        } else {
            switch (get_highest_layer(layer_state)) {
                default:
                    render_logo();
            }
        }
        return false;
    }

  #endif

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch (keycode) {
          case KC_LOWER:
              if (record->event.pressed) {
                  layer_on(_LOWER);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              } else {
                  layer_off(_LOWER);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              }
              return false;
          case KC_RAISE:
              if (record->event.pressed) {
                  layer_on(_RAISE);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              } else {
                  layer_off(_RAISE);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              }
              return false;
          case KC_ADJUST:
              if (record->event.pressed) {
                  layer_on(_ADJUST);
              } else {
                  layer_off(_ADJUST);
              }
              return false;
          case KC_D_MUTE:
              if (record->event.pressed) {
                  register_mods(mod_config(MOD_MEH));
                  register_code(KC_UP);
              } else {
                  unregister_mods(mod_config(MOD_MEH));
                  unregister_code(KC_UP);
              }
      }
      return true;
  }

  #ifdef ENCODER_ENABLE

  bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
	} else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
  }

  #endif
