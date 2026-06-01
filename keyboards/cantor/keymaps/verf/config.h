// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// === Home Row Mod Optimization ===
// Reduce tapping term from default 200ms to 150ms for faster typing
#define TAPPING_TERM 150
// Allow mod-tap to resolve to hold immediately on any other key press
#define PERMISSIVE_HOLD
// Prevent mod activation on fast repeated taps of the same key (80ms window)
#define QUICK_TAP_TERM 80
// Bilateral combination rule: only cross-hand chords activate mods;
// same-hand chords are resolved as taps (Achordion-equivalent)
#define CHORDAL_HOLD

// === Caps Word ===
// Never time out — word-breaking keys (space, enter, punctuation)
// naturally exit Caps Word; idle timeout only causes accidental exits.
#define CAPS_WORD_IDLE_TIMEOUT 0
// Pressing Shift while Caps Word is active inverts shift state
// instead of exiting. Useful for mixed-case identifiers like "DBaaS".
#define CAPS_WORD_INVERT_ON_SHIFT
