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
  intake_run(); //starts intake
  forward(2.5_ft); //moves forward 2.5 ft collecting cubes
  forward(-2_ft); //moves back 2 ft
  chassis.turnAngleAsync(-128); //turns 128 deg facing goal
  forward(3_in); //moves forward towards goal
  score(); //scores stack
  delay(50);
  slowForward(-3_in); //moves back slowly
  bringIn(); //brings placer in
  chassis.turnAngleAsync(38); //turns 38 deg to face south
  forward(-10_in); //moves back 10 in
  chassis.turnAngleAsync(90); //turns towards orange cube west against post
  intake_run(); //starts intake
  forward(3_ft); //moves forward 3 ft to collect orange cube
  delay(75);
  intake_end(); //stops intake
  forward(-1_ft); //moves backwards 1 ft to be next to green cube at 2,3 from bottom left corner
  chassis.turnAngleAsync(90); //turns to face green cube
  intake_run(); //starts intake
  forward(2_in); //grabs green cube
  delay(75);
  intake_end(); //stops intake
  forward(-2_in); //moves backwards towards center of tile
  chassis.turnAngleAsync(-90); //turns to face west
  forward(-10_in); //moves backwards to line up with red cup
  chassis.turnAngleAsync(-90); //turns to face red cup
  up(3); //lift goes up height of 3 cubes
  forward(1.5_ft); //moves forward to red cup
  outtake(); //outtakes green cube
  delay(75);
  intake_end(); //stops intake
  slowForward(-0.2_ft); //moves backwards towards center of tile again
  down(3); //lift goes down
  forward(-1.3_ft); //goes to center of tile
  chassis.turnAngleAsync(90); //turns to face bottom center cup
  forward(1.5_ft); //moves forwards to cup
  up(3); //moves lift up 3 cubes
  slowForward(0.4_ft); //moves forward towards cup
  outtake(); //outtakes orange cube
  delay(75);
  intake_end(); //stops intake
  slowForward(-0.4_ft); //moves back from cup slowly
  down(3); //lift goes down
  delay(2);
}

void red_auton_top1(){

  motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(placer, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(l_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(l_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(r_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(r_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(l_tread, E_MOTOR_BRAKE_HOLD);
  motor_set_brake_mode(r_tread, E_MOTOR_BRAKE_HOLD);

  score(); //sets robot up
  delay(75);
  bringIn(); //brings placer back in
  intake_run(); //starts intake
  forward(1_ft); //moves forward 1 ft to collect orange cube
  intake_end(); //stops intake
  up(3); //moves up
  forward(1_ft); //moves forward 1 ft towards stack
  intake_run(); //starts intake
  down_speed(3,50); //moves down on stack at 50 speed
  delay(75);
  intake_end(); //stops intake
  forward(-2.2_ft); //moves backwards against wall
  delay(50);
  forward(0.2_ft); //moves forward slightly from wall
  chassis.turnAngleAsync(90); //turns to face goal
  forward(2.5_ft); //moves to goal
  score(); //scores stack
  delay(50);
  slowForward(-0.5_ft); //moves backwards slowly
  bringIn(); //brings in placer
  chassis.turnAngleAsync(-90); //turns to face orange cube to right
  intake_run(); //starts intake
  forward(1_ft); //moves forward towards cube
  delay(75);
  intake_end(); //stops intake
  chassis.turnAngleAsync(-90); //turns to face goal on directly below
  forward(3_ft); //moves towards goal
  up(3); //moves lift up 3 cubes
  slowForward(0.5_ft); //moves slowly towards goal
  outtake(); //outtakes orange cube
  delay(75);
  slowForward(-0.5_ft); //backs slowly away from cup
  down(3); //moves lift down
  delay(2);
}

void blue_auton_top1(){

    motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
    motor_set_gearing(placer, E_MOTOR_GEARSET_36);
    motor_set_brake_mode(l_arm, E_MOTOR_BRAKE_HOLD);
    motor_set_gearing(l_arm, E_MOTOR_GEARSET_36);
    motor_set_brake_mode(r_arm, E_MOTOR_BRAKE_HOLD);
    motor_set_gearing(r_arm, E_MOTOR_GEARSET_36);
    motor_set_brake_mode(l_tread, E_MOTOR_BRAKE_HOLD);
    motor_set_brake_mode(r_tread, E_MOTOR_BRAKE_HOLD);

    score(); //sets robot up
    delay(75);
    bringIn(); //brings placer back in
    intake_run(); //starts intake
    forward(1_ft); //moves forward 1 ft to collect green cube
    intake_end(); //stops intake
    up(3); //moves up
    forward(1_ft); //moves forward 1 ft towards stack
    intake_run(); //starts intake
    down_speed(3,50); //moves down on stack at 50 speed
    delay(75);
    intake_end(); //stops intake
    forward(-2.2_ft); //moves backwards against wall
    delay(50);
    forward(0.2_ft); //moves forward slightly from wall
    chassis.turnAngleAsync(-90); //turns to face goal
    forward(2.5_ft); //moves to goal
    score(); //scores stack
    delay(50);
    slowForward(-0.5_ft); //moves backwards slowly
    bringIn(); //brings in placer
    chassis.turnAngleAsync(90); //turns to face green cube to left
    intake_run(); //starts intake
    forward(1_ft); //moves forward towards cube
    delay(75);
    intake_end(); //stops intake
    chassis.turnAngleAsync(90); //turns to face goal on directly below
    forward(3_ft); //moves towards goal
    up(3); //moves lift up 3 cubes
    slowForward(0.5_ft); //moves slowly towards goal
    outtake(); //outtakes green cube
    delay(75);
    slowForward(-0.5_ft); //backs slowly away from cup
    down(3); //moves lift down
    delay(2);
}

void blue_auton_bottom1(){

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
    intake_run(); //starts intake
    forward(2.5_ft); //moves forward 2.5 ft collecting cubes
    forward(-2_ft); //moves back 2 ft
    chassis.turnAngleAsync(128); //turns 128 deg facing goal
    forward(3_in); //moves forward towards goal
    score(); //scores stack
    delay(50);
    slowForward(-3_in); //moves back slowly
    bringIn(); //brings placer in
    chassis.turnAngleAsync(-38); //turns 38 deg to face south
    forward(-10_in); //moves back 10 in
    chassis.turnAngleAsync(-90); //turns towards green cube east against post
    intake_run(); //starts intake
    forward(3_ft); //moves forward 3 ft to collect green cube
    delay(75);
    intake_end(); //stops intake
    forward(-1_ft); //moves backwards 1 ft to be next to green cube at 2,3 from bottom left corner
    chassis.turnAngleAsync(-90); //turns to face orange cube
    intake_run(); //starts intake
    forward(2_in); //grabs orange cube
    delay(75);
    intake_end(); //stops intake
    forward(-2_in); //moves backwards towards center of tile
    chassis.turnAngleAsync(90); //turns to face east
    forward(-10_in); //moves backwards to line up with blue cup
    chassis.turnAngleAsync(90); //turns to face blue cup
    up(3); //lift goes up height of 3 cubes
    forward(1.5_ft); //moves forward to red cup
    outtake(); //outtakes orange cube
    delay(75);
    intake_end(); //stops intake
    slowForward(-0.2_ft); //moves backwards towards center of tile again
    down(3); //lift goes down
    forward(-1.3_ft); //goes to center of tile
    chassis.turnAngleAsync(-90); //turns to face bottom center cup
    forward(1.5_ft); //moves forwards to cup
    up(3); //moves lift up 3 cubes
    slowForward(0.4_ft); //moves forward towards cup
    outtake(); //outtakes green cube
    delay(75);
    intake_end(); //stops intake
    slowForward(-0.4_ft); //moves back from cup slowly
    down(3); //lift goes down
    delay(2);
}

void red_auton_top2(){

  motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(placer, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(l_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(l_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(r_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(r_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(l_tread, E_MOTOR_BRAKE_HOLD);
  motor_set_brake_mode(r_tread, E_MOTOR_BRAKE_HOLD);

  score(); //sets robot up
  delay(75);
  bringIn(); //brings placer back in
  intake_run(); //starts intake
  forward(1_ft); //moves forward 1 ft to collect orange cube
  intake_end(); //stops intake
  up(3); //moves up
  forward(1_ft); //moves forward 1 ft towards stack
  intake_run(); //starts intake
  down_speed(3,50); //moves down on stack at 50 speed
  delay(75);
  intake_end(); //stops intake
  forward(-2.2_ft); //moves backwards against wall
  delay(50);
  forward(0.2_ft); //moves forward slightly from wall
  chassis.turnAngleAsync(90); //turns to face goal
  forward(2.5_ft); //moves to goal
  score(); //scores stack
  delay(50);
  slowForward(-0.5_ft); //moves backwards slowly
  bringIn(); //brings in placer
  chassis.turnAngleAsync(-180); //robot does 180 facing south
  directionMove(-1.5); //moves robot with strafe motor to right
  forward(8_ft); //moves forward 8 ft towards bottom of field
  chassis.turnAngleAsync(90); //turns towards west
  forward(-0.2_ft); //backs against wall
  intake_run(); //starts intake
  forward(2.5_ft); //moves forward 2.5 ft collecting cubes
  forward(-2_ft); //moves back 2 ft
  chassis.turnAngleAsync(-128); //turns 128 deg facing goal
  forward(3_in); //moves forward towards goal
  score(); //scores stack
  delay(50);
  slowForward(-3_in); //moves back slowly
  bringIn(); //brings placer in
  chassis.turnAngleAsync(38); //turns 38 deg to face south
  forward(-10_in); //moves back 10 in
  chassis.turnAngleAsync(90); //turns towards orange cube west against post
  intake_run(); //starts intake
  forward(3_ft); //moves forward 3 ft to collect orange cube
  delay(75);
  intake_end(); //stops intake
  forward(-5_in); //moves back from post 5 in
  up(3); //moves lift up 3 cubes
  forward(5_in);
  outtake(); //outtakes orange cube
  delay(75);
  intake_end(); //stops intake
  forward(-5_in); //moves back 5 in
  down(3); //moves lift down 3 cubes
  delay(2);
}

void blue_auton_top2(){
  motor_set_brake_mode(placer, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(placer, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(l_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(l_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(r_arm, E_MOTOR_BRAKE_HOLD);
  motor_set_gearing(r_arm, E_MOTOR_GEARSET_36);
  motor_set_brake_mode(l_tread, E_MOTOR_BRAKE_HOLD);
  motor_set_brake_mode(r_tread, E_MOTOR_BRAKE_HOLD);

  score(); //sets robot up
  delay(75);
  bringIn(); //brings placer back in
  intake_run(); //starts intake
  forward(1_ft); //moves forward 1 ft to collect green cube
  intake_end(); //stops intake
  up(3); //moves up
  forward(1_ft); //moves forward 1 ft towards stack
  intake_run(); //starts intake
  down_speed(3,50); //moves down on stack at 50 speed
  delay(75);
  intake_end(); //stops intake
  forward(-2.2_ft); //moves backwards against wall
  delay(50);
  forward(0.2_ft); //moves forward slightly from wall
  chassis.turnAngleAsync(-90); //turns to face goal
  forward(2.5_ft); //moves to goal
  score(); //scores stack
  delay(50);
  slowForward(-0.5_ft); //moves backwards slowly
  bringIn(); //brings in placer
  chassis.turnAngleAsync(180); //robot does 180 facing south
  directionMove(1.5); //moves robot with strafe motor to right
  forward(8_ft); //moves forward 8 ft towards bottom of field
  chassis.turnAngleAsync(-90); //turns towards west
  forward(-0.2_ft); //backs against wall
  intake_run(); //starts intake
  forward(2.5_ft); //moves forward 2.5 ft collecting cubes
  forward(-2_ft); //moves back 2 ft
  chassis.turnAngleAsync(128); //turns 128 deg facing goal
  forward(3_in); //moves forward towards goal
  score(); //scores stack
  delay(50);
  slowForward(-3_in); //moves back slowly
  bringIn(); //brings placer in
  chassis.turnAngleAsync(-38); //turns 38 deg to face south
  forward(-10_in); //moves back 10 in
  chassis.turnAngleAsync(-90); //turns towards green cube west against post
  intake_run(); //starts intake
  forward(3_ft); //moves forward 3 ft to collect green cube
  delay(75);
  intake_end(); //stops intake
  forward(-5_in); //moves back from post 5 in
  up(3); //moves lift up 3 cubes
  forward(5_in);
  outtake(); //outtakes green cube
  delay(75);
  intake_end(); //stops intake
  forward(-5_in); //moves back 5 in
  down(3); //moves lift down 3 cubes
  delay(2);
}

#endif
