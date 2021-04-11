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
  //Starting cube is already in the robot
  //Drive right
  Drivetrain.driveFor(vex::forward, 36, inches);

  //Drop off starting cube in recycling can
  spinIntakeMotors(vex::reverse, 500);

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