#include "vex.h"
#include "utils.h"
#include <iostream>

void drive(vex::directionType dir)
{
  Drivetrain.drive(dir);
}

void turn(vex::turnType dir)
{
  Drivetrain.turn(dir);
}

void setDriveVel(int vel, int min = 0, int max = 100)
{
  int finalVel = clamp(abs(vel), min, max);
  Drivetrain.setDriveVelocity(finalVel, percent);
}

void setTurnVel(int vel, int min = 0, int max = 100)
{
  int finalVel = clamp(abs(vel), min, max);
  Drivetrain.setTurnVelocity(finalVel, percent);
}

void drive(int axisPos)
{
  std::cout << "Driving!" << std::endl;
  setDriveVel(axisPos);
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}

void turn(int axisPos)
{
  std::cout << "Turning!" << std::endl;
  setTurnVel(axisPos);
  turn(axisPos > 0 ? vex::right : vex::left);
}