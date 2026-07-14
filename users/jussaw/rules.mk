# Shared behavior for every `jussaw` keymap. This QMK version does not add the
# userspace <name>.c to SRC automatically, so do it explicitly here. VPATH
# already covers users/jussaw, so no path is needed.
SRC += jussaw.c
