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

void spinRampMotor(vex::directionType dir)
{
  RampMotor.spin(dir);
}

void stopRampMotor()
{
  RampMotor.stop();
}