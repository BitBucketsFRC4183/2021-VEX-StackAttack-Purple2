#include "vex.h"
#include <iostream>

void getHomeForDinner()
{
  std::cout << "Auto: Moving forward!" << std::endl;
  Drivetrain.driveFor(forward, 12, inches);
  std::cout << "Auto: Moving backward into home!" << std::endl;
  Drivetrain.driveFor(reverse, 12, inches);
  std::cout << "Auto: Task Get Home for Dinner complete!" << std::endl;
}