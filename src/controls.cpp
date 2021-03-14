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

void moveArm(int flag)
{
  if(flag == 0) ArmMotor.stop();

  ArmMotor.setVelocity(20, percent);
  ArmMotor.spin(flag > 0 ? vex::forward : vex::reverse);
}

void moveClaw(int flag)
{
  if(flag == 0) ClawMotor.stop();

  ClawMotor.setVelocity(20, percent);
  ClawMotor.spin(flag > 0 ? vex::forward : vex::reverse);
}

void raiseArm() { moveArm(1); }

void lowerArm() { moveArm(-1); }

void stopArm() { moveArm(0); }

void openClaw() { moveClaw(1); }

void closeClaw() { moveClaw(-1); }

void stopClaw() { moveClaw(0); }