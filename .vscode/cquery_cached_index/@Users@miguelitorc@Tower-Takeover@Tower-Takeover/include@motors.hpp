//motors.hpp
//contains setup for all motors, Async data, functions for auton
#include "main.h"
using namespace okapi;
using namespace pros::c;
using namespace pros;

#ifndef MOTORS_hpp
#define MOTORS_hpp

const int l_mtr = 10; //
const int r_mtr = 1; //
const int r_tread = 11; //
const int l_tread = 20; //
const int l_arm = 19; //
const int r_arm = 12; //
const int placer = 8; //
const int strafe = 18;
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
    motor_move(l_tread, -127);
    motor_move(r_tread, 127);
}

void intake_end(){
  /*
  motor_set_brake_mode(l_tread, E_MOTOR_BRAKE_HOLD);
  motor_set_brake_mode(r_tread, E_MOTOR_BRAKE_HOLD);
  */
    motor_move(l_tread, 0);
    motor_move(r_tread, 0);
}

void slowForward(QLength x){
  chassis.setMaxVoltage(100);
  chassis.moveDistanceAsync(x);
  chassis.waitUntilSettled();
  chassis.setMaxVoltage(127);
}

void score(){
  /*
  motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(placer, E_MOTOR_GEARSET_36);
  */
  motor_move_absolute(placer, 60, 100);
  //while(!(motor_get_position(placer) < 65) && (motor_get_position(placer) > 55)){
  //  delay(2);
  //}
}

void bringIn(){
  /*
  motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(placer, E_MOTOR_GEARSET_36);
  */
  motor_move_absolute(placer, -60, 100);
  //while(!(motor_get_position(placer) < -65) && (motor_get_position(placer) > -55)){
    //delay(2);
  //}
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
  motor_move(l_tread, -127);
  motor_move(r_tread, 127);
}
void intake_timed(double x){
  intake_run();
  delay(x);
  intake_end();
}

void forward_set(double speed, QLength x){
  chassis.setMaxVelocity(speed);
  chassis.moveDistance(x);
  chassis.waitUntilSettled();
  chassis.setMaxVelocity(100);
}

void forward(QLength x){
  chassis.moveDistanceAsync(x);
  chassis.waitUntilSettled();
}

void up_speed(double position, double speed){
  double posplusfive = position+5;
  double posminusfive = position-5;
  motor_move_absolute(l_arm, position, speed);
  while (!((motor_get_position(l_arm) < posplusfive) && (motor_get_position(l_arm) > posminusfive))) {
    delay(2);
  }
  motor_move_absolute(r_arm, -position, speed);
  while (!((motor_get_position(r_arm) < -posplusfive) && (motor_get_position(r_arm) > -posminusfive))) {
    delay(2);
  }
}

void down_speed(double position, double speed){
  double posplusfive = position+5;
  double posminusfive = position-5;
  motor_move_absolute(l_arm, -position, speed);
  while (!((motor_get_position(l_arm) < -posplusfive) && (motor_get_position(l_arm) > -posminusfive))) {
    delay(2);
  }
  motor_move_absolute(r_arm, position, speed);
  while (!((motor_get_position(r_arm) < posplusfive) && (motor_get_position(r_arm) > posminusfive))) {
    delay(2);
  }
}

void directionMove(double x){
  motor_move_absolute(strafe, x, 100);
}

#endif
