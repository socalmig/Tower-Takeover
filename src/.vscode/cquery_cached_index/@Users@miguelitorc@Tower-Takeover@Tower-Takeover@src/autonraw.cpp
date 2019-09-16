//autonraw.cpp
//contains each auton
#include "main.h"
#include "motors.hpp"

using namespace okapi;
using namespace pros::c;
using namespace pros;

#ifndef AUTONRAW_cpp
#define AUTONRAW_cpp

void red_auton_bottom1() {

  motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(placer, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(l_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(l_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(r_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(r_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(l_tread, E_MOTOR_BRAKE_HOLD);
  motor_set_brake_mode(r_tread, E_MOTOR_BRAKE_HOLD);

  score(); //extends placer to put out treads
  delay(20);
  bringIn(); //brings placer back in
  delay(20);
  chassis.moveDistanceAsync(6.916_ft); //move forward to foam line
  delay(20);
  chassis.moveDistanceAsync(-0.583_ft); //returns to 6.666 ft
  delay(50);
  chassis.turnAngleAsync(90);
  delay(20);
  chassis.moveDistanceAsync(-0.25_ft); //resets position
  delay(20);
  chassis.moveDistanceAsync(1_ft); //pulls up to cubes
  intake_run(); //starts treads
  delay(20);
  slowForward(2_ft); //moves slowly at voltage of 100
  delay(20);
  intake_end();
  delay(20);
  chassis.moveDistanceAsync(-4.3_ft); //bumps against edge
  delay(20);
  chassis.moveDistanceAsync(0.3_ft); //backs from edge
  delay(20);
  chassis.turnAngleAsync(-90); //faces towards bottom left corner
  delay(20);
  chassis.moveDistanceAsync(1_ft); //moves toward goal
  delay(20);
  score(); //places cubes
  delay(20);
  chassis.moveDistanceAsync(-0.5_ft); //pulls back from cubes
  delay(20);
  bringIn(); //brings cube scorer in
  delay(20);
  chassis.turnAngleAsync(60); //turns towards center bottom green cube
  delay(20);
  chassis.moveDistanceAsync(55_in); //moves to green cube
  delay(20);
  intake_run(); //intakes cube
  delay(50);
  chassis.moveDistanceAsync(-27_in); //moves back grom cube 90 deg from red cup
  delay(20);
  chassis.turnAngleAsync(-90); //turns to cup
  delay(20);
  up(3); //lifts lift to cup height
  delay(20);
  chassis.moveDistanceAsync(10_in); //moves to cup
  delay(20);
  slowForward(5_in); //moves last 5 in to cup slowly
  delay(40);
  outtake(); //outtakes cube into cup
  delay(75);
  intake_end(); //stops lift
  delay(20);
  chassis.moveDistanceAsync(-0.5_ft);
  delay(2);
}

void red_auton_top1(){}

void blue_auton_bottom1(){}

void blue_auton_top1(){}

#endif
