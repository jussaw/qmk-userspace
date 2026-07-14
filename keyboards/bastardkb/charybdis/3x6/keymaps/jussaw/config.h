/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Mod Tap — override the shared default (users/jussaw/config.h sets 50). */
#undef TAP_CODE_DELAY
#define TAP_CODE_DELAY 100

/* Trackball Settings
 * Live here (not in keymap.c) so they reach the keyboard's own charybdis.c
 * translation unit — config.h is force-included into every source file for
 * this build. */
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 400
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200
#define CHARYBDIS_MINIMUM_SNIPING_DPI 200
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100