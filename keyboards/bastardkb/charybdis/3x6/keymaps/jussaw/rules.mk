# Charybdis 3x6 disables mousekeys at the keyboard level; enable them so the
# MS_WHL* keys on the game layer work (buttons alone would work via the
# pointing device, wheel keycodes require MOUSEKEY).
MOUSEKEY_ENABLE = yes

# The shared userspace (extra layer + SOCD/lock logic) pushes this Elite-C build
# just past its 28 KB flash (LTO is already on via the board's keyboard.json).
# These features are unused by this keymap, so dropping them buys back the room.
MAGIC_ENABLE = no
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no
