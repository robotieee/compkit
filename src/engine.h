/***************************************************************
  engine.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef COMPKIT_ENGINE_H
#define COMPKIT_ENGINE_H

#include <Arduino.h>
namespace compkit {
class engine {
 private:
  unsigned int _engine_forward_pin;
  unsigned int _engine_backward_pin;

 public:
  /** Constructor **/
  engine(unsigned int engine_forward_pin, unsigned int engine_backward_pin)
      : _engine_forward_pin(engine_forward_pin),
        _engine_backward_pin(engine_backward_pin) {}

  void speed(int speed) {
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

#endif  // COMPKIT_ENGINE_H