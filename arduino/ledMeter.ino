// INCLUDES

#include "Tlc5940.h"      // Includes the TLC library

// DECLARATIONS

//// Led declarations

const int serRange = 255;                  // Serial range starting from 0 to serRange
const int tlcRange = 4095;                 // TLC range starting from 0 to tlcRange
const int ledRow = 8;                      // Number of led rows
const int ledCol = 1;                      // Number of led/row
const int ledPins[ledRow][ledCol] = {      // Pins to assign to each row
  {0},                                     //   e.g. : each line is a row
  {1},                                     //   The first one "{0}" means that the pins "0" is assigned to the first row
  {2},
  {4},
  {7},
  {10},
  {11},
  {14}
};

//// Average

const int numReadings = 5;      // Number of readings > NUMBER TO CHANGE TO SMOOTH EVERYTHING !!!
int readings[numReadings];      // Reading from the analog input
int index = 0;                  // Index of the current reading
int total = 0;                  // Running total
int average = 0;                // Average

// SETUP LOOP

void setup() {
  Tlc.init();
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;
}

// MAIN LOOP

void loop() {
  int rowRange = (tlcRange / ledRow);                               // Get the actually range for a row ("totRange" / "nbRows")
  Tlc.clear();                                                      // Clear LED's values on TLC's
  while (Serial.available() > 0) {
    total= total - readings[index];
    readings[index] = Serial.read();
    total= total + readings[index];
    index = index + 1;
    if (index >= numReadings) {
      index = 0;
    }
    average = total / numReadings;
    int outputValue = map(average, 0, serRange, 0, tlcRange);
    for (int row = 0; row < ledRow; row++) {
      int tmpRowRange = (outputValue - (rowRange * row));
      if (tmpRowRange > rowRange) {
          tmpRowRange = rowRange;
      }
      int rowValue = map(tmpRowRange, 0, rowRange, 0, tlcRange);
      for (int col = 0; col < ledCol; col++) {
        if (tmpRowRange > 0) {
          Tlc.set(ledPins[row][col], rowValue);
        }
      }
    }
    Tlc.update();                                                    // Apply all modification on the TLS's
  }
}
