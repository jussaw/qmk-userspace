#pragma once

/* Invert Ploopy drag scroll.
 * Lives here (not in keymap.c) so it reaches the keyboard's own ploopyco.c
 * translation unit — config.h is force-included into every source file for
 * this build, which is why the upstream ploopyco.h core patch is unnecessary. */
#define PLOOPY_DRAGSCROLL_INVERT
