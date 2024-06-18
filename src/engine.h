/***************************************************************
  engine.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef ENGINE_H
#define ENGINE_H

#include <Arduino.h>

class Engine {
 private:
  uint16_t engine_forward_pin;
  uint16_t engine_backward_pin;

 public:
  /** Constructor **/
  Engine(uint16_t engine_forward_pin, uint16_t engine_backward_pin)
      : engine_forward_pin(engine_forward_pin),
        engine_backward_pin(engine_backward_pin) {}

  void speed(int16_t speed) {
    if (speed > 0) {
      analogWrite(engine_forward_pin, speed);
      analogWrite(engine_backward_pin, 0);
    } else {
      analogWrite(engine_forward_pin, 0);
      analogWrite(engine_backward_pin, speed);
    }
  }
};

#endif  // ENGINE_H