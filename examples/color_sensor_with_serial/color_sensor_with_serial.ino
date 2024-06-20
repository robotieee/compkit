#include <Arduino.h>
#include <compkit.h>

compkit::color_sensor<5> color_reader(13, 12, 14, 27);

void menu(String incomingString) {
  Serial.print("Received: ");
  Serial.println(incomingString);

  if (incomingString == "t" || incomingString == "test") {
    Serial.println("Function 'test' recognized!");
    Serial.println("Hello World!");
    for (int i = 0; i < 3; i++) {
      analogWrite(13, 1023);
      delay(50);
      analogWrite(13, 0);
      delay(50);
    }
    Serial.println("Function 'test' ended!");
  } else if (incomingString == "c" || incomingString == "addc") {
    Serial.println("Function 'add color point' recognized!");
    int red, green, blue, natural;
    color_reader.read(red, green, blue, natural);

    Serial.print("Red: ");
    Serial.print(red);
    Serial.print(" | Green: ");
    Serial.print(green);
    Serial.print(" | Blue: ");
    Serial.print(blue);
    Serial.print(" | Natural: ");
    Serial.println(natural);

    int count = color_reader.add_color_point(red, green, blue, natural);
    if (count >= 4) {
      Serial.println("Max Color Points Reached!");
      incomingString == "q";
    }

    Serial.println("Function 'add color point' ended!");
  } else if (incomingString == "q" || incomingString == "quit") {
    Serial.println("Function 'quit' recognized!");
    Serial.println("Quitting the calibration program...");
  }

  else {
    Serial.println("Unknown function!");
  }
  Serial.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}

void setup() {
  Serial.begin(115200);

  String incomingString = "";

  while (incomingString != "quit" && incomingString != "q") {
    if (Serial.available() > 0) {
      incomingString = Serial.readStringUntil('\n');

      menu(incomingString);
    }
  }
}

void loop() {
  int red, green, blue, natural;
  color_reader.read(red, green, blue, natural);
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" | Green: ");
  Serial.print(green);
  Serial.print(" | Blue: ");
  Serial.print(blue);
  Serial.print(" | Natural: ");
  Serial.print(natural);

  int color = color_reader.closest_color(red, green, blue, natural);

  if (color == 0) {
    Serial.println(" | Color: Red");
  } else if (color == 1) {
    Serial.println(" | Color: Green");
  } else if (color == 2) {
    Serial.println(" | Color: Blue");
  } else if (color == 3) {
    Serial.println(" | Color: Yellow");
  } else {
    Serial.println(" | Color: White");
  }

  delay(200);
}
