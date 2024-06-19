/***************************************************************
  engine.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef ENGINE_H
#define ENGINE_H

#include <Arduino.h>
namespace compkit {
class engine {
 private:
  uint16_t _engine_forward_pin;
  uint16_t _engine_backward_pin;

 public:
  /** Constructor **/
  engine(uint16_t engine_forward_pin, uint16_t engine_backward_pin)
      : _engine_forward_pin(engine_forward_pin),
        _engine_backward_pin(engine_backward_pin) {}

  void speed(int16_t speed) {
    if (speed > 0) {
      analogWrite(_engine_forward_pin, speed);
      analogWrite(_engine_backward_pin, 0);
    } else {
      analogWrite(_engine_forward_pin, 0);
      analogWrite(_engine_backward_pin, speed);
    }
  }
};
}  // namespace compkit

#endif  // ENGINE_H