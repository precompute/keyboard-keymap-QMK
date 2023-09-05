# * Defaults
# MCU = atmega32u4
# BOOTLOADER = caterina

# * Build Options
# Build Option
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
SRC+= mymacros.c tapdances.c myunicode.c

# https://github.com/qmk/qmk_firmware/issues/21137
# This will auto-include the specified file in the introspection preamble so that it makes them available to the introspection functions.
# If you're already specifying it in a SRC += <my_combos_file>.c elsewhere, then it'll need to be removed from the SRC line.
INTROSPECTION_KEYMAP_C= mycombos.c

# ** Enabled
CFLAGS += -flto
EXTRAFLAGS += -flto
EXTRAKEY_ENABLE = yes    # Audio control and System control(+450)
LTO_ENABLE = yes         # This enables Link Time Optimization.This can save a good chunk of space(several KB for me), but the macro and function... functions cause it to error out.
MOUSEKEY_ENABLE = yes    # Mouse keys
NKRO_ENABLE = yes        # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
TAP_DANCE_ENABLE = yes
# SPLIT_KEYBOARD = yes
# SPLIT_TRANSPORT = mirror # for when Split Mirroring drops, it will maintain mirroring functionality
# Unicode, ascending size
# UNICODE_ENABLE = yes     # Unicode
UNICODEMAP_ENABLE = yes     # Unicode
# UCIS_ENABLE = yes     # Unicode
COMBO_ENABLE = yes

# > The firmware size is approaching the maximum - 27712/28672 (96%, 960 bytes free)
# > The firmware size is fine - 26968/28672 (94%, 1704 bytes free)
# > The firmware size is fine - 26474/28672 (92%, 2198 bytes free)
# > The firmware size is fine - 26714/28672 (93%, 1958 bytes free)
# [23-09-05 12:45:42] Sad!
# DYNAMIC_MACRO_ENABLE = yes # Dynamic Macros, recording, playback

# ** Disabled
AUDIO_ENABLE = no      # Audio output on port C6
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no  # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration(+1000)
MAGIC_ENABLE = no      # MAGIC actions (BOOTMAGIC without the boot)
KEY_OVERRIDE_ENABLE = no
COMMAND_ENABLE = no    # Commands for debug and configuration
CONSOLE_ENABLE = no    # Console for debug
MIDI_ENABLE = no       # MIDI controls
OLED_DRIVER_ENABLE = no
RAW_ENABLE = no
RGBLIGHT_ENABLE = no   # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no # Enable one-hand typing
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes

# UNICODE_ENABLE = no    # Unicode
VIA_ENABLE = no         # Enable VIA
VIRTSER_ENABLE = no
RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no

# To reduce firmware size, see:
# https://docs.qmk.fm/#/squeezing_avr
