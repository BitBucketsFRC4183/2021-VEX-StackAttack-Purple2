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
#include "utils.h"
#include "autonomous.h"
#include <iostream>

using namespace vex;

controller::axis driveAxis() { return Controller1.Axis3; }
controller::axis turnAxis() { return Controller1.Axis1; }

controller::button clawOpen() { return Controller1.ButtonR1; }
controller::button clawClose() { return Controller1.ButtonR2; }

controller::button armUp() { return Controller1.ButtonL1; }
controller::button armDown() { return Controller1.ButtonL2; }

void drive(int axisPos)
{
  std::cout << "Driving!" << std::endl;
  Drivetrain.setDriveVelocity(clamp(abs(axisPos), 20, 100), percent);
  Drivetrain.drive(axisPos > 0 ? vex::forward : vex::reverse);
}

void turn(int axisPos)
{
  std::cout << "Turning!" << std::endl;
  Drivetrain.setTurnVelocity(clamp(abs(axisPos), 20, 100), percent);
  Drivetrain.turn(axisPos > 0 ? vex::right : vex::left);
}

void teleopDrive()
{
  int pos = driveAxis().position();
  if(pos != 0) drive(pos);
  else Drivetrain.stop();
}

void teleopTurn()
{
  int pos = turnAxis().position();
  if(pos < -30 || pos > 30) turn(pos);
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
}

int main() 
{
  std::cout << "Start!" << std::endl;

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Drivetrain.setStopping(brake);
  ClawMotor.setStopping(hold);
  ArmMotor.setStopping(hold);

  //Autonomous and Teleop Controls

  std::cout << "Starting autonomous!" << std::endl;

  auton();

  Drivetrain.stop();
  wait(500, msec);

  std::cout << "Starting teleop!" << std::endl;

  teleop();
}
