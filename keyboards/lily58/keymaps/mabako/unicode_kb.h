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
    E_GRAVE_UC,
    E_GRAVE_LC,
    E_ACUTE_UC,
    E_ACUTE_LC,
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
    [E_GRAVE_UC] = 0x00C8,
    [E_GRAVE_LC] = 0x00E8,
    [E_ACUTE_UC] = 0x00C9,
    [E_ACUTE_LC] = 0x00E9,
};

enum unicode_keys {
    KC_AE = XP(AE_LC, AE_UC),
    KC_OE = XP(OE_LC, OE_UC),
    KC_UE = XP(UE_LC, UE_UC),
    KC_SS = XP(SS_LC, SS_UC),
    KC_EUR = X(EUR),
    KC_EGRV = XP(E_GRAVE_LC, E_GRAVE_UC),
    KC_EACT = XP(E_ACUTE_LC, E_ACUTE_UC),
};
