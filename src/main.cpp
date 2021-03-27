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
// Vision               vision        15              
// IntakeL              motor         21              
// IntakeR              motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "utils.h"
#include "movement.h"
#include "autonomous.h"
#include "intake.h"

using namespace vex;

controller::axis driveAxis() { return Controller1.Axis3; }
controller::axis turnAxis() { return Controller1.Axis1; }

controller::button activateIntake() { return Controller1.ButtonR1; }
controller::button activateOuttake() { return Controller1.ButtonL1; }

controller::button disableIntake() { return Controller1.ButtonA; }
controller::button disableDrive() { return Controller1.ButtonB; }

void teleopDrive()
{
  int pos = driveAxis().position();
  if(pos < -10 || pos > 10) drive(pos);
  else stopDrive();
}

void teleopTurn()
{
  int pos = turnAxis().position();
  if(pos < -10 || pos > 10) turn(pos);
  else stopDrive();
}

void teleop()
{
  while(true)
  {
    driveAxis().changed(teleopDrive);
    turnAxis().changed(teleopTurn);

    activateIntake().pressed(intake);
    activateOuttake().pressed(outtake);

    activateIntake().released(stopIntakeMotors);
    activateOuttake().released(stopIntakeMotors);

    disableIntake().pressed(stopIntakeMotors);
    disableDrive().pressed(stopDrive);

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

  //Set drivetrain brake mode
  Drivetrain.setStopping(brake);

  //Set intake motor velocities
  IntakeL.setVelocity(100, percent);
  IntakeR.setVelocity(100, percent);

  //Autonomous and Teleop Controls

  printDebug("Starting autonomous!");

  auton();

  Drivetrain.stop();
  wait(500, msec);

  printDebug("Starting teleop!");

  teleop();
}
