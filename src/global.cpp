#include "vex.h"

using namespace vex;

void drive(directionType dir)
{
  Drivetrain.drive(dir);
}

void drive(int axisPos)
{
  Drivetrain.setDriveVelocity(axisPos < 0 ? axisPos * -1 : axisPos, percent);
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}

void turn(turnType dir)
{
  Drivetrain.turn(dir);
}

void turn(int axisPos)
{
  Drivetrain.setTurnVelocity(axisPos < 0 ? axisPos * -1 : axisPos, percent);
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}