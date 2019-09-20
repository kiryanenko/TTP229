//
// Created by kiryanenko on 14.09.19.
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
        if (ttp229.isKeyPress(i)) {
            Serial.print("1 ");
        } else {
            Serial.print("0 ");
        }
    }

    int key = ttp229.getKey();
    Serial.print("Pressed key: ");
    Serial.print(key);

    Serial.print("   ");
    if (ttp229.isKeyDown(0)) {
        Serial.print("Key 0 is down");
    } else if (ttp229.isKeyUp(0)) {
        Serial.print("Key 0 is up");
    }

    Serial.println();
    delay(500);
}
