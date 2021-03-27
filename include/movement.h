#include "vex.h"

void stopDrive();

void drive(vex::directionType dir);

void turn(vex::turnType dir);

void setDriveVel(int vel, int min = 0, int max = 100);

void setTurnVel(int vel, int min = 0, int max = 100);

void drive(int axisPos);

void turn(int axisPos);