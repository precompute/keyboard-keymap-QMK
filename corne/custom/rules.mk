# -*- eval: (outshine-mode 1); -*-s
# * Defaults
# MCU = atmega32u4
# BOOTLOADER = caterina

# * Build Options
# Build Option
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
SRC+= mymacros.c tapdances.c

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

# ** Disabled
AUDIO_ENABLE = no      # Audio output on port C6
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no  # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration(+1000)
COMMAND_ENABLE = no    # Commands for debug and configuration
CONSOLE_ENABLE = no    # Console for debug
MIDI_ENABLE = no       # MIDI controls
OLED_DRIVER_ENABLE = no
RGBLIGHT_ENABLE = no   # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no # Enable one-hand typing
UNICODE_ENABLE = no    # Unicode
VIA_ENABLE = no         # Enable VIA
