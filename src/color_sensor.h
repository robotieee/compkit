/***************************************************************
  color_sensor.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef COMPKIT_COLOR_SENSOR_H
#define COMPKIT_COLOR_SENSOR_H

#include <Arduino.h>
#include <compkit_macros.h>

namespace compkit {

// color_point is a 4-element array of integers
// {red, green, blue, natural}
typedef int color_point[4];

template <size_t n_color_points = 1> class color_sensor {
private:
  unsigned int _led_pin[3]; // {red, green, blue}
  unsigned int _sensor_pin;

  color_point _color_points[n_color_points]; // {red, green, blue, natural}
                                             // natural is the sensor reading
                                             // without any led light

  size_t _current_color_points = 0;

public:
  /** Constructor **/
  color_sensor(unsigned int sensor_pin, unsigned int led_red_pin,
               unsigned int led_green_pin, unsigned int led_blue_pin)
      : _led_pin{led_red_pin, led_green_pin, led_blue_pin},
        _sensor_pin(sensor_pin) {
    pinMode(_led_pin[0], OUTPUT);
    pinMode(_led_pin[1], OUTPUT);
    pinMode(_led_pin[2], OUTPUT);
    pinMode(_sensor_pin, INPUT);
  }

  void read(color_point &point) {
    point[3] = analogRead(_sensor_pin);

    for(size_t i = 0; i < 3; i++) {
      digitalWrite(_led_pin[i], HIGH);
      delay(25);
      point[i] = analogRead(_sensor_pin);
      digitalWrite(_led_pin[i], LOW);
    }
  }

  size_t add_color_point(color_point &point) {
    if(_current_color_points < n_color_points) {
      _color_points[_current_color_points][0] = point[0];
      _color_points[_current_color_points][1] = point[1];
      _color_points[_current_color_points][2] = point[2];
      _color_points[_current_color_points][3] = point[3];
      _current_color_points++;
    }

    return _current_color_points - 1;
  }

  void get_color_point(size_t index, color_point &point) {
    point[0] = _color_points[index][0];
    point[1] = _color_points[index][1];
    point[2] = _color_points[index][2];
    point[3] = _color_points[index][3];
  }

  int color_difference(color_point &point1, color_point &point2) {
    int diff = 0;
    for(size_t i = 0; i < 3; i++) {
      diff += compkit_abs(point1[i] - point2[i]);
    }
    return diff;
  }

  int closest_color(color_point &point) {
    int min_diff      = 99999;
    int closest_color = 0;
    for(size_t i = 0; i < _current_color_points; i++) {
      int diff = 0;
      for(size_t j = 0; j < 3; j++) {
        diff += compkit_abs(point[j] - _color_points[i][j]);
      }

      if(diff < min_diff) {
        min_diff      = diff;
        closest_color = i;
      }
    }

    return closest_color;
  }
};
} // namespace compkit

#endif // COMPKIT_COLOR_SENSOR_H