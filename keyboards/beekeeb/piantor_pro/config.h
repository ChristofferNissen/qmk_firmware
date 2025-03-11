// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_USART_PIN_SWAP

#define USB_VBUS_PIN GP19

#define SPLIT_HAND_PIN GP17
#define SPLIT_HAND_PIN_LOW_IS_LEFT



#define TAPPING_TERM 175

#undef FORCE_NKRO
#define FORCE_NKRO

#define USB_POLLING_INTERVAL_MS 1

// Other settings //
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD
#define QUICK_TAP_TERM 150

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Shamelessly stolen mouse key settings from @pierrechevalier83 //

// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Hz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
// #undef to override default settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 30
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 50

#define TAPPING_TOGGLE 3

