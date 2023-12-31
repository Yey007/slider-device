#pragma once
#include <stdint.h>

struct Time
{
public:
  static Time fromSeconds(float seconds);
  static Time fromMilliseconds(uint32_t milliseconds);
  static Time now();
  static void reset();

  float getSeconds() const;
  uint32_t getMilliseconds() const;

private:
  uint32_t milliseconds;
  static uint32_t baseline;
};

float operator/(const Time &time1, const Time &time2);
Time operator+(const Time &time1, const Time &time2);
Time operator-(const Time &time1, const Time &time2);
bool operator<(const Time &time1, const Time &time2);
bool operator>(const Time &time1, const Time &time2);
