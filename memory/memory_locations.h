#ifndef MEMORY_LOCATIONS_H
#define MEMORY_LOCATIONS_H

enum ReservedLocations
{
    RESTART_00 = 0x0,
    RESTART_08 = 0x08,
    RESTART_10 = 0x10,
    RESTART_18 = 0x18,
    RESTART_20 = 0x20,
    RESTART_28 = 0x28,
    RESTART_30 = 0x30,
    RESTART_38 = 0x38,
    VERT_BLANK_INTERRUPT = 0x40,
    LCDC_STATUS_INTERRUPT = 0x48,
    TIMER_OVERFLOW_INTERRUPT = 0x50,
    SERIAL_TRANSFER_COMPLETION_INTERRUPT = 0x58,
    HI_TO_LO_INTERRUPT = 0x60,
};

#endif
