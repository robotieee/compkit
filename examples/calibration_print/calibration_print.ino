#include <compkit.h>

color_sensor<0> sensorCor(A0, 2, 3, 4);

void setup() { Serial.begin(9600); }

void loop() {
  color_point leituraCor;
  sensorCor.read(leituraCor);
  println_color(leituraCor);
  delay(100);
}