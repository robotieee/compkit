/***************************************************************
  motor_controller.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef COMPKIT_MOTOR_CONTROLLER_H
#define COMPKIT_MOTOR_CONTROLLER_H

#include <Arduino.h>
#include <motor.h>

class motor_controller {
private:
  motor *_left_motor;
  motor *_right_motor;

public:
  /** Constructor **/
  motor_controller(unsigned int left_forward_pin,
                   unsigned int left_backward_pin,
                   unsigned int right_forward_pin,
                   unsigned int right_backward_pin)
      : _left_motor(new motor(left_forward_pin, left_backward_pin)),
        _right_motor(new motor(right_forward_pin, right_backward_pin)) {}

  ~motor_controller() {
    delete _left_motor;
    delete _right_motor;
  }

  void walk(int left_speed, int right_speed) {
    _left_motor->speed(left_speed);
    _right_motor->speed(right_speed);
  }
};

#endif // COMPKIT_MOTOR_CONTROLLER_H