//
// Created by kiryanenko on 14.09.19.
//

#include "TTP229.h"


byte reverseBits(byte number) {
    number = (number & 0x55) << 1 | (number & 0xAA) >> 1;
    number = (number & 0x33) << 2 | (number & 0xCC) >> 2;
    number = (number & 0x0F) << 4 | (number & 0xF0) >> 4;

    return number;
}


uint16_t TTP229::readKeys() {
    _keys = 0;
    Wire.requestFrom(_address, 2);
    byte *buffer = (byte*) &_keys;
    byte i = 0;
    while(Wire.available()) {       // slave may send less than requested
        byte data = Wire.read();
        buffer[i] = reverseBits(data);
        ++i;
    }
    return _keys;
}

int TTP229::getKey() {
    int i = 0;
    for (uint16_t mask = 0x0001; mask; mask <<= 1) {
        if (mask & _keys) {
            return i;
        }
        ++i;
    }
    return -1;
}

bool TTP229::isKeyPressed(byte key) {
    return bitRead(_keys, key);
}
