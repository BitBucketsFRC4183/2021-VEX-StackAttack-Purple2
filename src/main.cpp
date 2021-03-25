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
// Drivetrain           drivetrain    1, 10           
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// Vision               vision        15              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "utils.h"
#include "movement.h"
#include "autonomous.h"

using namespace vex;

controller::axis driveAxis() { return Controller1.Axis3; }
controller::axis turnAxis() { return Controller1.Axis1; }

controller::button clawOpen() { return Controller1.ButtonR1; }
controller::button clawClose() { return Controller1.ButtonR2; }

controller::button armUp() { return Controller1.ButtonL1; }
controller::button armDown() { return Controller1.ButtonL2; }

void teleopDrive()
{
  int pos = driveAxis().position();
  if(pos < -10 || pos > 10) drive(pos);
  else Drivetrain.stop();
}

void teleopTurn()
{
  int pos = turnAxis().position();
  if(pos < -10 || pos > 10) turn(pos);
  else Drivetrain.stop();
}

void teleop()
{
  while(true)
  {
    driveAxis().changed(teleopDrive);
    turnAxis().changed(teleopTurn);

    wait(0.1, seconds);
  }
}

void auton()
{
  getHomeForDinner();

  printDebug(boolToString(findGreenCube()));
}

int main() 
{
  printDebug("Start!");

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Drivetrain.setStopping(brake);
  ClawMotor.setStopping(hold);
  ArmMotor.setStopping(hold);

  //Autonomous and Teleop Controls

  printDebug("Starting autonomous!");

  auton();

  Drivetrain.stop();
  wait(500, msec);

  printDebug("Starting teleop!");

  teleop();
}
