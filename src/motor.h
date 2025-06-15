/***************************************************************
  motor.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef COMPKIT_MOTOR_H
#define COMPKIT_MOTOR_H

#include <Arduino.h>
class motor {
private:
  unsigned int _motor_forward_pin;
  unsigned int _motor_backward_pin;

public:
  /** Constructor **/
  motor(unsigned int motor_forward_pin, unsigned int motor_backward_pin)
      : _motor_forward_pin(motor_forward_pin),
        _motor_backward_pin(motor_backward_pin) {}

  void speed(int speed) {
    if(speed > 0) {
      analogWrite(_motor_forward_pin, speed);
      analogWrite(_motor_backward_pin, 0);
    } else {
      analogWrite(_motor_forward_pin, 0);
      analogWrite(_motor_backward_pin, speed);
    }
  }
};

#endif // COMPKIT_MOTOR_H