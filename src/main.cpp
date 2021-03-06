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
// IntakeL              motor         8               
// IntakeR              motor         3               
// ArmL                 motor         13              
// ArmR                 motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "utils.h"
#include "movement.h"
#include "autonomous.h"
#include "intake.h"
#include "vex_timer.h"

using namespace vex;

vex::competition Competition;

controller::axis driveAxis() { return Controller1.Axis3; }
controller::axis turnAxis() { return Controller1.Axis1; }

controller::button activateIntake() { return Controller1.ButtonR1; }
controller::button activateOuttake() { return Controller1.ButtonL1; }

controller::button raiseRamp() { return Controller1.ButtonR2; }
controller::button lowerRamp() { return Controller1.ButtonL2; }

controller::button disableIntake() { return Controller1.ButtonA; }
controller::button disableDrive() { return Controller1.ButtonB; }

void teleop()
{
  while(true)
  {
    driveAxis().changed([](){drive(driveAxis().position());});
    turnAxis().changed([](){turn(turnAxis().position());});

    activateIntake().pressed([](){spinIntakeMotors(vex::forward);});
    activateOuttake().pressed([](){spinIntakeMotors(vex::reverse);});

    activateIntake().released(stopIntakeMotors);
    activateOuttake().released(stopIntakeMotors);

    raiseRamp().pressed([](){spinArmMotors(vex::forward);});
    lowerRamp().pressed([](){spinArmMotors(vex::reverse);});

    raiseRamp().released(stopArmMotors);
    lowerRamp().released(stopArmMotors);

    disableIntake().pressed(stopIntakeMotors);
    disableDrive().pressed(stopDrive);

    wait(0.1, seconds);
  }
}

void auton()
{
  uint32_t start = vex::timer::system();

  //Select autonomous routine to run
  runRoutine(1);

  float autonTime = (vex::timer::system() - start) / 1000;
  printTime(autonTime);
}

int main() 
{
  printDebug("Start!");

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Set drivetrain brake mode
  Drivetrain.setStopping(vex::brake);

  //Set intake motor velocities
  IntakeL.setVelocity(100.0, percent);
  IntakeR.setVelocity(100.0, percent);
  ArmL.setVelocity(30.0, percent);
  ArmR.setVelocity(30.0, percent);

  IntakeL.setStopping(vex::brake);
  IntakeR.setStopping(vex::brake);
  ArmL.setStopping(vex::hold);
  ArmR.setStopping(vex::hold);

  //Competition stuff, commented out until needed
  //Competition.autonomous(auton);
  //Competition.drivercontrol(teleop);

  //Autonomous and Teleop Controls

  printDebug("Starting autonomous!");

  auton();

  Drivetrain.stop();
  wait(500, msec);

  printDebug("Starting teleop!");

  teleop();
}
