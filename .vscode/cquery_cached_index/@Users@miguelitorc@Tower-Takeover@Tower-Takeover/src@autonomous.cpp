#include "main.h"
#include "autonraw.hpp"

int mode = 0;

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void update_lcd() {
  pros::lcd::clear_line(4);
  pros::lcd::set_text(4, std::to_string(mode));
}

 void inc_auton_mode() {
  if(mode < 6) {
    mode++;
  }
  update_lcd();
 }

 void dec_auton_mode() {
  if(mode > 0) {
    mode--;
  }
  update_lcd();
 }

void autonomous() {
  /*
  pros::lcd::set_text(6, "Running auton #" + std::to_string(mode));
  switch(mode){
    case 0: pros::lcd::set_text(5, "red_auton_top1"); red_auton_top1(); break;
    case 1: pros::lcd::set_text(5, "red_auton_top2"); red_auton_top2(); break;
    case 2: pros::lcd::set_text(5, "red_auton_bottom1"); red_auton_bottom1(); break;
    case 3: pros::lcd::set_text(5, "blue_auton_top1"); blue_auton_top1(); break;
    case 4: pros::lcd::set_text(5, "blue_auton_top2"); blue_auton_top2(); break;
    case 5: pros::lcd::set_text(5, "blue_auton_bottom1"); blue_auton_bottom1(); break;
    case 6: pros::lcd::set_text(5, "skills"); skills(); break;
  }
  */
  red_auton_bottom1();
}
