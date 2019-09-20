//
// Created by Alexander Kiryanenko on 14.09.19.
//

//////////////////////////////////////////////////////////////////
// Connections
//
// Uno:   SDA <-> A4 (SDA)
//        SCL <-> A5 (SCL)
//
// Mega:  SDA <-> 20 (SDA)
//        SCL <-> 21 (SCL)
//
// Leo:   SDA <-> 2 (SDA)
//        SCL <-> 3 (SCL)
//
//////////////////////////////////////////////////////////////////


#ifndef TTP229_H
#define TTP229_H

#include <Arduino.h>
#include <Wire.h>

#define TTP229_LSF 0x57 // Device address (the addressing without the R/W bit) -> 01010111 = 57

class TTP229 {
    uint8_t _address;
    uint16_t _keys = 0;
    uint16_t _prev_state = 0;

public:
    /// Constructor
    /// \param address I2C address of TTP229 device
    explicit TTP229(int address = TTP229_LSF) : _address(address) {}

    /// Read data from TTP229. Should call before other methods.
    /// \return States of 16 keys in bitmap representation
    uint16_t readKeys();
    /// This function don't read data from ttp229. Only return previous read data.
    /// \return States of 16 keys in bitmap representation
    uint16_t getKeys() { return _keys; }
    /// Return number of pressed key or return -1 if no one key is pressed
    /// \return Number of pressed key or -1 if no one key pressed
    int getKey();
    /// Return true if key is pressed
    /// \param key Number of key
    /// \return True if key is pressed
    bool isKeyPress(byte key);
    /// Return true if key is pressed
    /// \param key Number of key
    /// \return True if key is pressed
    bool isKeyDown(byte key);
    /// Return true if key is pressed
    /// \param key Number of key
    /// \return True if key is pressed
    bool isKeyUp(byte key);
};


#endif //TTP229_H
