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
// Drivetrain           drivetrain    10, 1           
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "global.h"
#include "controls.h"

using namespace vex;

controller::axis driveAxis, turnAxis;
controller::button clawOpen, clawClose, armUp, armDown;

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

  clawOpen = Controller1.ButtonR1;
  clawClose = Controller1.ButtonR2;

  armUp = Controller1.ButtonL1;
  armDown = Controller1.ButtonL2;

  //Comment to disable auton
  //auton();

  //Comment to disable teleop (while loop teleop)
  //while(true) teleop(); 

  //Callback-based teleop
  while(true)
  {
    driveAxis.changed(teleopDrive);
    turnAxis.changed(teleopTurn);

    clawOpen.pressed(openClaw);
    clawClose.pressed(closeClaw);

    clawOpen.released(stopClaw);
    clawClose.released(stopClaw);

    armUp.pressed(raiseArm);
    armDown.pressed(lowerArm);

    armUp.released(stopArm);
    armDown.released(stopArm);
  }
}
