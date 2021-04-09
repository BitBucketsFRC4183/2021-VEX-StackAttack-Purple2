#include "vex.h"

void stopIntakeMotors()
{
  IntakeL.stop();
  IntakeR.stop();
}

void spinIntakeMotors(vex::directionType dir)
{
  IntakeL.spin(dir);
  IntakeR.spin(dir == vex::forward ? vex::reverse : vex::forward);
}

void spinIntakeMotors(vex::directionType dir, int pause)
{
  spinIntakeMotors(dir);
  wait(pause, msec);
  stopIntakeMotors();
}

void spinRampMotors(vex::directionType dir)
{
  ArmL.spin(dir);
  ArmR.spin(dir == vex::forward ? vex::reverse : vex::forward);
}

void stopRampMotor()
{
  ArmL.stop();
  ArmR.stop();
}