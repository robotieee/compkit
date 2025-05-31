#include <unity.h>

void setUp(void) {} // before test

void tearDown(void) {} // after test

void test_PlaceholderDeleteMeIsUseless(void) {
  TEST_ASSERT_EQUAL(1, 1);
}

void process() {
  UNITY_BEGIN();

  RUN_TEST(test_PlaceholderDeleteMeIsUseless);

  UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  process();
}

void loop() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}

#else

int main(int argc, char** argv) {
  process();
  return 0;
}

#endif