#pragma once
#define VIAL_KEYBOARD_UID {0x25, 0xAF, 0x45, 0xDA, 0x52, 0xE7, 0x36, 0xF9}

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.

#undef PRODUCT
#define PRODUCT "Awesome Hotreus62 Keyboard"

#define USB_POLLING_INTERVAL_MS 1

// Prevent normal rollover on alphas from accidentally triggering mods.
///#define IGNORE_MOD_TAP_INTERRUPT

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#undef TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

// Other settings //
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Other settings //
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

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
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100

#define TAPPING_TOGGLE 3
