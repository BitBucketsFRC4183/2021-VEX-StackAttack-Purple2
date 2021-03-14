#include "vex.h"
#include "global.h"

using namespace vex;

void drive(int axisPos)
{
  Drivetrain.setDriveVelocity(clamp(abs(axisPos), 20, 100), percent);
  Drivetrain.drive(axisPos > 0 ? vex::forward : vex::reverse);
}

void turn(int axisPos)
{
  Drivetrain.setTurnVelocity(clamp(abs(axisPos), 20, 100), percent);
  Drivetrain.turn(axisPos > 0 ? vex::left : vex::right);
}

void raiseArm()
{
  ArmMotor.spin(vex::forward);
}

void lowerArm()
{
  ArmMotor.spin(vex::reverse);
}

void stopArm()
{
  ArmMotor.stop();
}

void openClaw()
{
  ClawMotor.spin(vex::forward);
}

void closeClaw()
{
  ClawMotor.spin(vex::reverse);
}

void stopClaw()
{
  ClawMotor.stop();
}