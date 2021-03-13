/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Sajo                                             */
/*    Created:      Wed Mar 10 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "global.h"
#include "controls.h"

using namespace vex;

controller::axis driveAxis, turnAxis;


void teleopDrive()
{
  int pos = driveAxis.position();
  if(pos != 0) drive(pos);
  else Drivetrain.stop();
}

void teleopTurn()
{
  int pos = turnAxis.position();
  if(pos != 0) turn(pos);
}

void teleop()
{
  if(driveAxis.position() != 0)
  {
    drive(driveAxis.position());
  }
  else Drivetrain.stop();

  if(turnAxis.position() != 0)
  {
    turn(turnAxis.position());
  }

  waitUntil(!Drivetrain.isMoving());
}

void auton()
{

}

int main() 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Init axis/button variables
  driveAxis = Controller1.Axis3;
  turnAxis = Controller1.Axis1;

  //Comment to disable auton
  //auton();

  //Comment to disable teleop (while loop teleop)
  //while(true) teleop(); 

  //Callback-based teleop
  driveAxis.changed(teleopDrive);
  turnAxis.changed(teleopTurn);
}
