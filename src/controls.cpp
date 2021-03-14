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
  ArmMotor.setVelocity(20, percent);
  ArmMotor.spin(vex::forward);
}

void lowerArm()
{
  ArmMotor.setVelocity(20, percent);
  ArmMotor.spin(vex::reverse);
}

void stopArm()
{
  ArmMotor.stop();
}

void openClaw()
{
  ClawMotor.setVelocity(20, percent);
  ClawMotor.spin(vex::forward);
}

void closeClaw()
{
  ClawMotor.setVelocity(20, percent);
  ClawMotor.spin(vex::reverse);
}

void stopClaw()
{
  ClawMotor.stop();
}