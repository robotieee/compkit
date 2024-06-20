/***************************************************************
  color_sensor.h
  Created by Alexandre Hiroyuki Yamauchi, June 17, 2024.
***************************************************************/

#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <Arduino.h>

#include <cmath>

namespace compkit {

template <size_t n_color_points = 1>
class color_sensor {
 private:
  unsigned int _led_pin[3];  // {red, green, blue}
  unsigned int _sensor_pin;

  int _color_points[n_color_points][4];  // {red, green, blue, natural}
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

  void read(int &red, int &green, int &blue, int &natural) {
    int *colors[3] = {&red, &green, &blue};

    natural = analogRead(_sensor_pin);

    for (size_t i = 0; i < 3; i++) {
      digitalWrite(_led_pin[i], HIGH);
      delay(25);
      *colors[i] = analogRead(_sensor_pin);
      digitalWrite(_led_pin[i], LOW);
    }
  }

  size_t add_color_point(int red, int green, int blue, int natural) {
    if (_current_color_points < n_color_points) {
      _color_points[_current_color_points][0] = red;
      _color_points[_current_color_points][1] = green;
      _color_points[_current_color_points][2] = blue;
      _color_points[_current_color_points][3] = natural;
      _current_color_points++;
    }

    return _current_color_points - 1;
  }

  int *color_point(size_t index) { return _color_points[index]; }

  int closest_color(int &red, int &green, int &blue, int &natural) {
    int colors[3] = {red, green, blue};

    int min_diff = 99999;
    int closest_color = 0;
    for (size_t i = 0; i < _current_color_points; i++) {
      int diff = 0;
      for (size_t j = 0; j < 3; j++) {
        diff += abs(colors[j] - _color_points[i][j]);
      }

      if (diff < min_diff) {
        min_diff = diff;
        closest_color = i;
      }
    }

    return closest_color;
  }
};
}  // namespace compkit

#endif  // COLOR_SENSOR_H