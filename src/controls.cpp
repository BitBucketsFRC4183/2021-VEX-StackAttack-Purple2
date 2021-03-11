#include "vex.h"
#include "global.h"

using namespace vex;

void drive(directionType dir)
{
  Drivetrain.drive(dir);
}

void drive(int axisPos)
{
  Drivetrain.setDriveVelocity(clamp(abs(axisPos), 20, 100), percent);
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}

void turn(turnType dir)
{
  Drivetrain.turn(dir);
}

void turn(int axisPos)
{
  Drivetrain.setTurnVelocity(clamp(abs(axisPos), 20, 100), percent);
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}