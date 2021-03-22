#include "vex.h"
#include "utils.h"

void getHomeForDinner()
{
  printDebug("Auto: Moving forward!");

  Drivetrain.driveFor(forward, 12, inches);

  printDebug("Auto: Moving backward into home!");

  Drivetrain.driveFor(reverse, 12, inches);
  
  printDebug("Auto: Task Get Home for Dinner complete!");
}