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
  spinIntakeMotors(vex::forward, 500);

  //The home is about 3 feet away from recycling can
  Drivetrain.driveFor(forward, 36, inches);
  
  //Deposit cube
  spinIntakeMotors(vex::reverse, 500);

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
  spinIntakeMotors(vex::forward, 500);

  //Turn towards home
  Drivetrain.turnFor(right, 90, degrees);

  //Drive home
  Drivetrain.driveFor(forward, isGreen ? 12 : 24, inches);

  //Drop off cube
  spinIntakeMotors(vex::reverse, 500);

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

//Strategies for Autonomous
//All strategies assume that the robot is facing right, and the robot & starting cube are perfectly aligned with the recycling can

//Strategy 1: Drive right, cross sidewalk, return home
//Completes: Get Home for Dinner, Walk the Dog
void strategy1()
{
  //Drive right
  Drivetrain.driveFor(vex::forward, 36, inches);

  //Turn to facing the sidewalk
  Drivetrain.turnFor(vex::right, 90, degrees);

  //Cross sidewalk
  Drivetrain.driveFor(vex::forward, 18, inches);

  //Turn to facing the set the table cubes
  Drivetrain.turnFor(vex::right, 90, degrees);

  //Drive close to the cubes
  Drivetrain.driveFor(vex::forward, 24, inches);

  //Turn facing home
  Drivetrain.turnFor(vex::right, 90, degrees);

  //Drive into home
  Drivetrain.driveFor(vex::forward, 24, inches);
}

//Stategy 2: Intake starting cube, drive right, drop off cube, cross sidewalk, return home (No vision involved)
//Completes: Get Home for Dinner, Take out the Recycling, Walk the Dog
void strategy2()
{
  //Intake starting cube
  spinIntakeMotors(vex::forward, 500);

  //Drive right
  Drivetrain.driveFor(vex::forward, 24, inches);

  //Drop off starting cube in recycling can
  spinIntakeMotors(vex::reverse, 500);

  //Turn to facing the sidewalk
  Drivetrain.turnFor(vex::right, 90, degrees);

  //Cross sidewalk
  Drivetrain.driveFor(vex::forward, 24 + 3, inches);

  //Turn to facing the set the table cubes
  Drivetrain.turnFor(vex::right, 90, degrees);

  //Drive close to the cubes
  Drivetrain.driveFor(vex::forward, 36, inches);

  //Turn facing home
  Drivetrain.turnFor(vex::right, 90, degrees);

  //Drive into home
  Drivetrain.driveFor(vex::forward, 24, inches);
}

//Strategy 3: Same as strategy 2, except after crossing sidewalk, pick up green cube and then return home
//Completes: Get Home for Dinner, Take out the Recycling, Walk the Dog, Set the Table
void strategy3()
{
  
}

//Holds possible strategies, all of which need to be tested
void runRoutine(int strategy)
{
  switch(strategy)
  {
    case 1: strategy1();
      break;
    case 2: strategy2();
      break;
    case 3: strategy3();
      break;
    default:
      Drivetrain.driveFor(vex::forward, 10, inches);
      wait(500, msec);
      Drivetrain.driveFor(vex::reverse, 10, inches);
      break;
  }
}