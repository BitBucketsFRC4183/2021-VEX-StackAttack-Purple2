#include <iostream>
#include <sstream>
#include "vex.h"

int clamp(int val, int min, int max)
{
  return val < min ? min : (val > max ? max : val);
}

int abs(int val)
{
  return val < 0 ? val * -1 : val;
}

void printDebug(std::string s)
{
  std::cout << s << std::endl;

  Brain.Screen.clearScreen();
  Brain.Screen.print(s);
}

std::string boolToString(bool b)
{
  std::ostringstream converter;
  converter << std::boolalpha << b;
  return converter.str();
}