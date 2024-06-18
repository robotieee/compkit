/***************************************************************
  engine_controller.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef ENGINE_CONTROLLER_H
#define ENGINE_CONTROLLER_H

#include <Arduino.h>
#include <engine.h>

class EngineController {
 private:
  Engine *left_engine;
  Engine *right_engine;

 public:
  /** Constructor **/
  EngineController(uint16_t left_forward_pin, uint16_t left_backward_pin,
                   uint16_t right_forward_pin, uint16_t right_backward_pin)
      : left_engine(new Engine(left_forward_pin, left_backward_pin)),
        right_engine(new Engine(right_forward_pin, right_backward_pin)) {}

  ~EngineController() {
    delete left_engine;
    delete right_engine;
  }

  void walk(int16_t left_speed, int16_t right_speed) {
    left_engine->speed(left_speed);
    right_engine->speed(right_speed);
  }
};

#endif  // ENGINE_CONTROLLER_H