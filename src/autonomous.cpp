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

bool findObject(vision::signature s)
{
  Vision.takeSnapshot(s);
  return Vision.objectCount > 0;
}

bool findGreenCube()
{
  return findObject(Vision__GREEN_CUBE);
}

bool findPurpleCube()
{
  return findObject(Vision__PURPLE_CUBE);
}

bool findOrangeCube()
{
  return findObject(Vision__ORANGE_CUBE);
}