//
// Created by pulli on 2020-11-11.
//
#include "BitFunction.h"

ushort nthos(ushort value) {
    uchar uc1 = (value >> 8) & 0xFF;
    uchar uc2 = value & 0xFF;

    return ((uc2<<8) + uc1);
}
