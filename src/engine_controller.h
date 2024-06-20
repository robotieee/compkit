/***************************************************************
  engine_controller.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef ENGINE_CONTROLLER_H
#define ENGINE_CONTROLLER_H

#include <Arduino.h>
#include <engine.h>

namespace compkit {
class engine_controller {
 private:
  engine *_left_engine;
  engine *_right_engine;

 public:
  /** Constructor **/
  engine_controller(unsigned int left_forward_pin,
                    unsigned int left_backward_pin,
                    unsigned int right_forward_pin,
                    unsigned int right_backward_pin)
      : _left_engine(new engine(left_forward_pin, left_backward_pin)),
        _right_engine(new engine(right_forward_pin, right_backward_pin)) {}

  ~engine_controller() {
    delete _left_engine;
    delete _right_engine;
  }

  void walk(int left_speed, int right_speed) {
    _left_engine->speed(left_speed);
    _right_engine->speed(right_speed);
  }
};
}  // namespace compkit

#endif  // ENGINE_CONTROLLER_H