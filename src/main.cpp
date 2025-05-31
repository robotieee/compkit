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
  Serial.println(point[0]);
  Serial.println(point[1]);
  Serial.println(point[2]);
  Serial.println(point[3]);

  Serial.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

  Serial.println(point.red);
  Serial.println(point.green);
  Serial.println(point.blue);
  Serial.println(point.natural);

  Serial.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

  Serial.println(color_reader.closest_color(point));

  delay(1000);
}
