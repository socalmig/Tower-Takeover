//motors.hpp
//contains setup for all motors, Async data, functions for auton
#include "main.h"
using namespace okapi;
using namespace pros::c;
using namespace pros;

#ifndef MOTORS_hpp
#define MOTORS_hpp

const int l_mtr = 5;
const int r_mtr = 10;
const int lb_mtr = 1;
const int rb_mtr = 6;
const int r_tread = 15;
const int l_tread = 9;
const int l_arm = 7;
const int r_arm = 20;
const int placer = 8;
const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 17.5_in;

int autonomousMode;

auto chassis = ChassisControllerFactory::create(l_mtr, r_mtr,
  AbstractMotor::gearset::green, {WHEEL_DIAMETER, CHASSIS_WIDTH}
);

void intake_run(){
  /*
  motor_set_brake_mode(l_tread, E_MOTOR_BRAKE_HOLD);
  motor_set_brake_mode(r_tread, E_MOTOR_BRAKE_HOLD);
  */
  while (true){
    motor_move(l_tread, -127);
    motor_move(r_tread, 127);
  }
}

void intake_end(){
  /*
  motor_set_brake_mode(l_tread, E_MOTOR_BRAKE_HOLD);
  motor_set_brake_mode(r_tread, E_MOTOR_BRAKE_HOLD);
  */
  while(true){
    motor_move(l_tread, 0);
    motor_move(r_tread, 0);
  }
}

void slowForward(QLength x){
  chassis.setMaxVoltage(100);
  chassis.moveDistanceAsync(x);
  chassis.setMaxVoltage(127);
}

void score(){
  /*
  motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(placer, E_MOTOR_GEARSET_36);
  */
  motor_move_absolute(placer, 60, 100);
  while(!(motor_get_position(placer) < 65) && (motor_get_position(placer) > 55)){
    delay(2);
  }
}

void bringIn(){
  /*
  motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(placer, E_MOTOR_GEARSET_36);
  */
  motor_move_absolute(placer, -60, 100);
  while(!(motor_get_position(placer) < -65) && (motor_get_position(placer) > -55)){
    delay(2);
  }
}

void up(double x){
  /*
  motor_set_brake_mode(l_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(l_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(r_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(r_arm, E_MOTOR_GEARSET_36);
  */
  motor_move_absolute(l_arm, x, 100);
  motor_move_absolute(r_arm, -x, 100);
}

void down(double x){
  motor_move_absolute(l_arm, -x, 80);
  motor_move_absolute(r_arm, x, 80);
}

void outtake(){
  while (true){
  motor_move(l_tread, -127);
  motor_move(r_tread, 127);
}
}

#endif
