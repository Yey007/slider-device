#include "time.hpp"
#include "Arduino.h"

uint32_t Time::baseline = 0;

Time Time::fromSeconds(double seconds)
{
  Time time;
  time.milliseconds = seconds * 1000;
  return time;
}

Time Time::fromMilliseconds(uint32_t milliseconds)
{
  Time time;
  time.milliseconds = milliseconds;
  return time;
}

Time Time::now()
{
  Time time;
  time.milliseconds = millis() - baseline;
  return time;
}

void Time::reset()
{
  baseline = millis();
}

double Time::getSeconds() const
{
  return milliseconds / 1000.0;
}

uint32_t Time::getMilliseconds() const
{
  return milliseconds;
}

double operator/(const Time &time1, const Time &time2)
{
  return time1.getMilliseconds() / (double)time2.getMilliseconds();
}

Time operator+(const Time &time1, const Time &time2)
{
  return Time::fromMilliseconds(time1.getMilliseconds() + time2.getMilliseconds());
}

Time operator-(const Time &time1, const Time &time2)
{
  if (time1 < time2)
  {
    Serial.println("Subtracting times out of order. This is not good!");
  }

  return Time::fromMilliseconds(time1.getMilliseconds() - time2.getMilliseconds());
}

bool operator<(const Time &time1, const Time &time2)
{
  return time1.getMilliseconds() < time2.getMilliseconds();
}

bool operator>(const Time &time1, const Time &time2)
{
  return time1.getMilliseconds() > time2.getMilliseconds();
}