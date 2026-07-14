# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A **QMK Userspace** repo (`jussaw`'s fork of the `qmk/qmk-userspace` template). It holds an external
set of keymaps that are compiled against the upstream `qmk_firmware` **without forking it**. Only
keymaps for *existing* boards live here — per commit `caa7156`, adding a brand-new keyboard is out
of scope (that would require a `qmk_firmware` fork). Everything under `keyboards/<kb>/keymaps/jussaw/`
mirrors the path it would occupy inside `qmk_firmware`.

`users/jussaw/` holds the **shared userspace** — one source of truth every keyed board references
(see the Keymap architecture section). `layouts/` is still an empty `.keep` placeholder.

## Build & compile

Requires the `qmk` CLI plus a separate `qmk_firmware` checkout (present at `~/repos/qmk_firmware`).
`user.overlay_dir` already points at this repo. If `qmk config -ro user.qmk_home` is unset the
`Makefile` errors — set it to the firmware checkout first.

- Build every target listed in `qmk.json`: `qmk userspace-compile`
- Build one board: `qmk compile -kb crkbd/rev1 -km jussaw` (or `make crkbd/rev1:jussaw`)
- Flash: append `:flash`, e.g. `make crkbd/rev1:jussaw:flash`
- The `Makefile` is a thin shim that re-invokes `make` inside `$(user.qmk_home)` with
  `QMK_USERSPACE` set to this repo.
- Build outputs (e.g. `crkbd_rev1_jussaw.hex`) land at the repo root and are **gitignored** — a
  stray `*.hex` here is a local artifact, not source.

**Build targets** live in `qmk.json` (`crkbd/rev1`, `planck/rev6`, `ploopyco/trackball_nano/rev1_001`,
`bastardkb/charybdis/3x6/elitec`). Manage them with `qmk userspace-add / -remove / -list` rather than
editing the JSON by hand. CI (`.github/workflows/build_binaries.yaml`) calls QMK's reusable workflows
to build all `qmk.json` targets on every push and publish firmware to the repo's Releases tab.

## Keymap architecture (the cross-file part worth knowing)

**crkbd is the single source of truth.** Its layout — **Colemak-DH** base with **home-row mods** in
GACS order (GUI/Alt/Ctrl/Shift via `LxyZ_T()` macros), plus `_LOWER` (symbols) / `_UPPER` (numbers /
nav / F-keys) / `_ADJUST` (media, mouse, `QK_BOOT`) / `_SETTINGS` (holds `TG_GAME`) / `_GAME` — is
shared by every keyed board through the `users/jussaw/` userspace. QMK auto-compiles `users/jussaw/`
for any keymap named `jussaw` (its `rules.mk`/`config.h` are force-included; `SRC += jussaw.c` is
explicit because this QMK version does not auto-add it). Adjust is reached by overlaying `MO(_ADJUST)`
on the opposite layer key while Lower or Upper is held (no tri-layer).

The shared pieces:

- **`users/jussaw/jussaw.h`** — the layer `enum` and every keycode alias (home-row mods, layer keys,
  Lower/Upper mod-taps). **`wrappers.h`** — the actual keymap content as per-layer, per-half **row
  macros** (`JW_DEF_L1`…`JW_GAM_R3`). Physical matrices differ, so QMK cannot share one `keymaps[]`
  array; instead each board feeds these row macros into its own `LAYOUT_*` via a
  `LAYOUT_*_wrapper(...)` indirection (forces macro expansion before the arg count is checked) and
  supplies only its own thumb/bottom row. **`jussaw.c`** — `process_record_user` (Game-layer `A`/`D`
  **SOCD** last-input-priority cleaning + momentary `KC_SCRL`/`KC_NUM` re-emit) and
  `layer_state_set_user` (stale-SOCD cleanup). **`config.h`** — shared tuning (`TAPPING_TERM`,
  `QUICK_TAP_TERM`, `PERMISSIVE_HOLD`, `TAP_CODE_DELAY 50`, fast low-accel mousekey), included before
  each board's own `config.h` so a board can `#undef`/override.

Board-local specifics (in each board's own `keymap.c`/`config.h`/`rules.mk`):

- **crkbd** is the reference (its rows are copied verbatim into `wrappers.h`); `config.h` keeps only
  `MASTER_LEFT`.
- **charybdis** has only 5 thumb keys, so it defines two local overrides: the trackball keycodes
  (`S_D_MOD`/`DPI_MOD`/`DRGSCRL`/`SNIPING`/`S_D_RMOD`/`DPI_RMOD`) replace the mouse/lock cluster on
  the Lower-left, and Backspace stays on the Default R1 edge (no room for a Bksp thumb). Its
  `config.h` raises `TAP_CODE_DELAY` to 100 and holds the `CHARYBDIS_*` DPI constants; `rules.mk`
  disables `MAGIC`/`GRAVE_ESC`/`SPACE_CADET` to fit the Elite-C's 28 KB flash.
- **planck** has no thumb cluster, so its 12-wide bottom row carries the crkbd thumb functions. Its
  upstream Muse/MIDI/encoder/dip-switch scaffolding has been **removed** (no more `SRC += muse.c`;
  `rules.mk` now just enables `MOUSEKEY`).
- **Ploopy trackball_nano keeps a dummy keymap** (`{{ KC_NO }}`) — no keys, so it is **out of scope**
  for the shared layout (it still compiles `users/jussaw/`, but those hooks are inert there). All
  behavior is host-LED-driven in `led_update_user`: scroll-lock toggles drag-scroll, num-lock cycles
  DPI, all three locks reset to bootloader — driven over the wire by the crkbd's momentary SCRL/NUM
  taps. `keymap.c` also has ADNS5050 power-down/wake hooks; drag-scroll is inverted via
  `PLOOPY_DRAGSCROLL_INVERT` in its `config.h`.

## Commit messages

Follow **Conventional Commits 1.0.0** (https://www.conventionalcommits.org/en/v1.0.0/#specification),
always **with a scope**:

```
<type>(<scope>): <description>

[optional body]

[optional footer(s)]
```

- **type** — one of `feat`, `fix`, `build`, `chore`, `ci`, `docs`, `style`, `refactor`, `perf`, `test`.
- **scope** — the area touched, in parentheses (required here). Prefer the board:
  `crkbd`, `planck`, `ploopyco`, `charybdis`. Use `users` for the shared `users/jussaw/` userspace,
  `qmk` for `qmk.json` build targets, `ci` for the workflow, `devcontainer`/`clangd`/`clang-format`
  for tooling, `repo` for cross-cutting changes.
- **description** — imperative mood, lower-case, no trailing period.
- A breaking change is marked with `!` before the colon (e.g. `feat(crkbd)!: ...`) and/or a
  `BREAKING CHANGE:` footer.

Examples: `feat(crkbd): add SOCD cleaning to game layer`, `fix(ploopyco): stop nano entering
bootloader on num lock`, `chore(qmk): register charybdis 3x6 build target`.

## Style & tooling

- **`.clang-format`** is Google-based with `IndentWidth 4` and a deliberately huge `ColumnLimit 1000`
  so keymap grids stay one row per physical row. Wrap aligned/generated tables in
  `// clang-format off` … `// clang-format on` (see `charybdis/.../keymap.c`).
- **`.clangd`** strips AVR/ARM-specific flags so clangd can parse the sources; `compile_commands.json`
  and `.cache/` are gitignored.
- **`.editorconfig`**: 4-space default; tabs + LF for `*.mk` and `Makefile`.
- A **dev container** (`ghcr.io/qmk/qmk_cli`) provisions the `qmk` CLI and clones `qmk_firmware` into
  `/workspaces` via `.devcontainer/setup.sh`.
