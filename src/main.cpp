// Include lib:
#include <Arduino.h>
#include <compkit.h>

compkit::color_sensor<5> color_reader(13, 12, 14, 27);

void setup() {
  // Initialize serial interface
  Serial.begin(9600);
  // color_reader.add_color_point({100, 100, 100, 100});
}

void loop() {
  compkit::color_point point;
  color_reader.read(point);
  Serial.println(point[3]);
  delay(1000);
}
