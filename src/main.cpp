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

using namespace vex;

controller::axis driveAxis = Controller1.Axis3;
controller::axis turnAxis = Controller1.Axis1;

controller::button clawOpen = Controller1.ButtonR1;
controller::button clawClose = Controller1.ButtonR2;

controller::button armUp = Controller1.ButtonL1;
controller::button armDown = Controller1.ButtonL2;

int clamp(int val, int min, int max)
{
  return val < min ? min : (val > max ? max : val);
}

int abs(int val)
{
  return val < 0 ? val * -1 : val;
}

void drive(int axisPos)
{
  Brain.Screen.print("Driving forwards/backwards!");
  Drivetrain.setDriveVelocity(clamp(abs(axisPos), 20, 100), percent);
  Drivetrain.drive(axisPos > 0 ? vex::forward : vex::reverse);
}

void turn(int axisPos)
{
  Brain.Screen.print("Turning left/right!");
  Drivetrain.setTurnVelocity(clamp(abs(axisPos), 20, 100), percent);
  Drivetrain.turn(axisPos > 0 ? vex::left : vex::right);
}

void moveArm(int flag)
{
  Brain.Screen.print("Moving arm!");
  if(flag == 0) ArmMotor.stop();

  ArmMotor.setVelocity(20, percent);
  ArmMotor.spin(flag > 0 ? vex::forward : vex::reverse);
}

void moveClaw(int flag)
{
  Brain.Screen.print("Moving claw!");
  if(flag == 0) ClawMotor.stop();

  ClawMotor.setVelocity(20, percent);
  ClawMotor.spin(flag > 0 ? vex::forward : vex::reverse);
}

void raiseArm() { moveArm(1); }

void lowerArm() { moveArm(-1); }

void stopArm() { moveArm(0); }

void openClaw() { moveClaw(1); }

void closeClaw() { moveClaw(-1); }

void stopClaw() { moveClaw(0); }

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

int main() 
{
  Brain.Screen.print("Start!");

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Screen.print("Init complete!");

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
