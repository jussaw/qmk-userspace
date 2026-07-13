# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A **QMK Userspace** repo (`jussaw`'s fork of the `qmk/qmk-userspace` template). It holds an external
set of keymaps that are compiled against the upstream `qmk_firmware` **without forking it**. Only
keymaps for *existing* boards live here — per commit `caa7156`, adding a brand-new keyboard is out
of scope (that would require a `qmk_firmware` fork). Everything under `keyboards/<kb>/keymaps/jussaw/`
mirrors the path it would occupy inside `qmk_firmware`.

`users/` and `layouts/` are empty `.keep` placeholders — there is **no shared userspace C code**; each
board's `keymap.c` is fully standalone.

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

All four `jussaw` keymaps share a layer scheme — **base + Lower (symbols) + Upper/Raise (numbers /
nav / F-keys) + Adjust (media, mouse, `QK_BOOT`) + Game** — where Adjust is reached by holding Lower
and Upper together. Beyond that, they diverge in ways that matter:

- **crkbd is the flagship and the most customized.** Its base (`_DEFAULT`) is **Colemak-DH**, not
  QWERTY, with **home-row mods** in GACS order (GUI/Alt/Ctrl/Shift via `LxyZ_T()` macros). It adds a
  `_MAC` / `_UPPER_MAC` pair that swaps GUI↔Ctrl for macOS, and a `_SETTINGS` layer that switches the
  persistent default layer via `TO()` / `DF()` / `TG()`.
- **planck and charybdis base layers are plain QWERTY** (`enum _QWERTY`) with no home-row mods — do
  not assume the crkbd conventions carry over.
- **crkbd `process_record_user`** does two non-obvious things: (1) re-emits `KC_SCRL` / `KC_NUM` as
  taps so those locks behave *momentarily*, and (2) in the Game layer implements **SOCD** (last-input-
  priority) cleaning for the `A`/`D` keys.
- **Ploopy trackball_nano has a dummy keymap** (`{{ KC_NO }}`) — it has no keys. All behavior is
  host-LED-driven in `led_update_user`: the scroll-lock LED toggles drag-scroll, num-lock cycles DPI,
  and all three locks together reset to bootloader. This is why the crkbd's momentary SCRL/NUM taps
  above exist — they drive this trackball. `keymap.c` also has ADNS5050 power-down/wake hooks;
  drag-scroll is inverted via `PLOOPY_DRAGSCROLL_INVERT` in `config.h`.
- **charybdis** keeps trackball DPI/sniping constants at the top of `keymap.c` and uses
  `S_D_MOD` / `DPI_MOD` / `DRGSCRL` / `SNIPING` keycodes on its Lower layer.
- **planck `keymap.c`** still carries the upstream default's Muse/MIDI/encoder/dip-switch boilerplate
  (hence `SRC += muse.c` in its `rules.mk`); treat it as inherited scaffolding, not bespoke design.

Per-keymap `config.h` holds the tuning (tapping term, `PERMISSIVE_HOLD_PER_KEY`, `MASTER_LEFT`, fast
low-accel mousekey settings); per-keymap `rules.mk` toggles hardware features (crkbd disables OLED/RGB,
enables MOUSEKEY, sets `atmel-dfu`).

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
  `crkbd`, `planck`, `ploopyco`, `charybdis`. Use `qmk` for `qmk.json` build targets, `ci` for the
  workflow, `devcontainer`/`clangd`/`clang-format` for tooling, `repo` for cross-cutting changes.
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
