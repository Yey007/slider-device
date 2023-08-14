#include "distance.hpp"
#include "motor_config.hpp"

Distance Distance::fromCentimeters(double centimeters)
{
  Distance distance;
  distance.millimeters = centimeters * 10;
  return distance;
}

Distance Distance::fromMillimeters(uint32_t millimeters)
{
  Distance distance;
  distance.millimeters = millimeters;
  return distance;
}

Distance Distance::fromMotorTicks(uint32_t ticks)
{
  Distance distance;
  distance.millimeters = MM_PER_STEP * ticks;
  return distance;
}

double Distance::getCentimeters() const
{
  return millimeters / 10.0;
}

uint32_t Distance::getMillimeters() const
{
  return millimeters;
}

uint32_t Distance::getMotorTicks() const
{
  return millimeters / MM_PER_STEP;
}

Distance operator*(const Distance &distance, double scalar)
{
  return Distance::fromMillimeters(distance.getMillimeters() * scalar);
}

Distance operator*(double scalar, const Distance &distance)
{
  return distance * scalar;
}

Distance operator+(const Distance &distance1, const Distance &distance2)
{
  return Distance::fromMillimeters(distance1.getMillimeters() + distance2.getMillimeters());
}