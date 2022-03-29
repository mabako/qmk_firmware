#pragma once
#include "quantum.h"

enum unicode_names {
    AE_UC,
    AE_LC,
    OE_UC,
    OE_LC,
    UE_UC,
    UE_LC,
    SS_UC,
    SS_LC,
    EUR,
};

const uint32_t PROGMEM unicode_map[] = {
    [AE_UC] = 0x00C4,
    [AE_LC] = 0x00E4,
    [OE_UC] = 0x00D6,
    [OE_LC] = 0x00F6,
    [UE_UC] = 0x00DC,
    [UE_LC] = 0x00FC,
    [SS_UC] = 0x1E9E,
    [SS_LC] = 0x00DF,
    [EUR] = 0x20AC,
};

enum unicode_keys {
    KC_AE = XP(AE_LC, AE_UC),
    KC_OE = XP(OE_LC, OE_UC),
    KC_UE = XP(UE_LC, UE_UC),
    KC_SS = XP(SS_LC, SS_UC),
    KC_EUR = X(EUR),
};
