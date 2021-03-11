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

using namespace vex;

void drive(directionType dir)
{
  Drivetrain.drive(dir);
}

void drive(int axisPos)
{
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}

void turn(turnType dir)
{
  Drivetrain.turn(dir);
}

void turn(int axisPos)
{
  drive(axisPos > 0 ? vex::forward : vex::reverse);
}

int main() 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Drivetrain.setDriveVelocity(50, percent);
  drive(forward);  
}
