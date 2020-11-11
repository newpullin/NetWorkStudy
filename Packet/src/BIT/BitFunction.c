//
// Created by pulli on 2020-11-11.
//
#include "BitFunction.h"

ushort nthos(ushort value) {
    uchar uc1 = (value >> 8) & 0xFF;
    uchar uc2 = value & 0xFF;

    return ((uc2<<8) + uc1);
}

uint nthos_i(uint value) {
    uchar uc1 = (value >> 24) & 0xFF;
    uchar uc2 = (value >> 16) & 0xFF;
    uchar uc3 = (value >> 8) & 0xFF;
    uchar uc4 = value & 0xFF;

    return ( (uc4<<24) + (uc3<<16) + (uc2<<8) + uc1);
}
