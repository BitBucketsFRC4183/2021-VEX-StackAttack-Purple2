#include "vex.h"
#include "utils.h"
#include "intake.h"

bool findObject(vision::signature s)
{
  Vision.takeSnapshot(s);
  return Vision.objectCount > 0;
}

bool findGreenCube()
{
  return false;
  //return findObject(Vision__GREEN_CUBE);
}

bool findPurpleCube()
{
  return false;
  //return findObject(Vision__PURPLE_CUBE);
}

bool findOrangeCube()
{
  return false;
  //return findObject(Vision__ORANGE_CUBE);
}

void getHomeForDinner()
{
  printDebug("Auto: Task Get Home for Dinner starting!");

  //Drive out of home
  Drivetrain.driveFor(forward, 12, inches);

  //Drive back into home
  Drivetrain.driveFor(reverse, 12, inches);
  
  printDebug("Auto: Task Get Home for Dinner complete!");
}

//Assumes robot is facing right
void takeOutTheRecycling()
{
  printDebug("Auto: Task Take Out Recycling starting!");

  //Intake cube
  spinIntakeMotors(vex::forward);

  wait(500, msec);

  //The home is about 3 feet away from recycling can
  Drivetrain.driveFor(forward, 36, inches);
  
  //Deposit cube
  spinIntakeMotors(vex::reverse);

  printDebug("Auto: Task Take Out Recycling complete!");
}

//Assumes robot is facing downwards
void setTheTable()
{
  printDebug("Auto: Task Set the Table starting!");

  //First cube is about 1 foot away from home
  Drivetrain.driveFor(forward, 12, inches);

  //Orient to be facing cube
  Drivetrain.turnFor(right, 90, degrees);

  bool isGreen = findGreenCube();

  //If its not green, move to next cube
  if(!isGreen)
  {
    //Reorient to be facing downwards
    Drivetrain.turnFor(left, 90, degrees);

    //Drive to next cube
    Drivetrain.driveFor(forward, 12, inches);

    //Orient to facing cube
    Drivetrain.turnFor(right, 90, degrees);
  }

  //Intake
  spinIntakeMotors(vex::forward);

  //Turn towards home
  Drivetrain.turnFor(right, 90, degrees);

  //Drive home
  Drivetrain.driveFor(forward, isGreen ? 12 : 24, inches);

  printDebug("Auto: Task Set the Table complete!");
}

//Assumes robot is facing downwards
void walkTheDog()
{
  printDebug("Auto: Task Walk the Dog complete!");

  //Drive down to about halfway
  Drivetrain.driveFor(forward, 12 + 6, inches);

  //Turn towards sidewalk
  Drivetrain.turnFor(left, 90, degrees);

  //Drive to sidewalk
  Drivetrain.driveFor(forward, 36, inches);

  //Turn facing up
  Drivetrain.turnFor(left, 90, degrees);

  //Cross sidewalk
  Drivetrain.driveFor(forward, 24, inches);

  //Turn facing home
  Drivetrain.turnFor(left, 90, degrees);

  //Drive home
  Drivetrain.driveFor(forward, 36, inches);

  printDebug("Auto: Task Walk the Dog complete!");
}