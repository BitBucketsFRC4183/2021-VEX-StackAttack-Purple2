#include "vex.h"

void spinIntakeMotors(vex::directionType dir)
{
  IntakeL.spin(dir);
  IntakeR.spin(dir == vex::forward ? vex::reverse : vex::forward);
}

void stopIntakeMotors()
{
  IntakeL.stop();
  IntakeR.stop();
}

void intake()
{
  spinIntakeMotors(vex::forward);
}

void outtake()
{
  spinIntakeMotors(vex::reverse);
}

