#include "vex.h"
#include "utils.h"

void stopDrive()
{
  Drivetrain.stop();
}

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
  Drivetrain.setDriveVelocity(finalVel * 1.0, percent);
}

void setTurnVel(int vel, int min = 0, int max = 100)
{
  int finalVel = clamp(abs(vel), min, max);
  Drivetrain.setTurnVelocity(finalVel * 1.0, percent);
}

void drive(int axisPos)
{
  printDebug("Driving!");

  if(axisPos > -10 && axisPos < 10) stopDrive();
  else
  {
    setDriveVel(axisPos);
    drive(axisPos > 0 ? vex::forward : vex::reverse);
  }  
}

void turn(int axisPos)
{
  printDebug("Turning!");

  if(axisPos > -10 && axisPos < 10) stopDrive();
  else
  {
    setTurnVel(axisPos, 20);
    turn(axisPos > 0 ? vex::right : vex::left);
  }
}