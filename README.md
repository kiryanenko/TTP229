TTP229 Arduino Library
============================================

An Arduino library for TTP229 module for controlling a 16 capacitive touch keys. 

Tested with the Robotdyn 16 Keys I2C Capacitive Touch TTP229 Module Robotdyn Capacitive Touch Disk Pad.


## Connection

- Uno:   
    - SDA <-> A4 (SDA)
    - SCL <-> A5 (SCL)

- Mega:  
    - SDA <-> 20 (SDA)
    - SCL <-> 21 (SCL)

- Leo:
    - SDA <-> 2 (SDA)
    - SCL <-> 3 (SCL)


## Methods:

- `uint16_t readKeys()` - Read data from TTP229 and return states of 16 keys 
  in bitmap representation. This method should call before other methods.

- `int getKey()` - Return number of pressed key or return `-1` if no one key is pressed.

- `bool isKeyPressed(byte key)` - Return true if key is pressed.


## Example

```cpp
#include <Wire.h>
#include <TTP229.h>

TTP229 ttp229;

void setup()
{
    Wire.begin();
    Serial.begin(9600);
}

void loop()
{
    ttp229.readKeys();

    Serial.print("Key states: ");
    for (int i = 0; i < 16; ++i) {
        if (ttp229.isKeyPressed(i)) {
            Serial.print("1 ");
        } else {
            Serial.print("0 ");
        }
    }

    int key = ttp229.getKey();
    Serial.print("Pressed key: ");
    Serial.println(key);

    delay(500);
}
```
 
 
 # License
 Copyright (c) 2019 Alexander Kiryanenko. Licensed under the MIT license.