#include "vex.h"

using namespace vex;

void drive(directionType dir)
{
  Drivetrain.drive(dir);
}

void drive(int axisPos)
{
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}

void turn(turnType dir)
{
  Drivetrain.turn(dir);
}

void turn(int axisPos)
{
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}