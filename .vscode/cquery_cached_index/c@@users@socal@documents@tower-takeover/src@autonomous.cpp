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
  pros::lcd::clear_line(2);
  std::string auton;
  switch(mode) {
    case  0: auton = "red_auton_bottom1";   break;
    case  1: auton = "red_auton_top1";  break;
    case  2: auton = "red_auton_top2";  break;
    case  3: auton = "blue_auton_bottom1"; break;
    case  4: auton = "blue_auton_top1"; break;
    case  5: auton = "blue_auton_top2"; break;
    case  6: auton = "skills"; break;
    default: auton = "Invalid";    break;
    }
  pros::lcd::set_text(2, "Auton mode: " + auton);
}

 void inc_auton_mode() {
  if(mode < 6) mode++;
  update_lcd();
 }

 void dec_auton_mode() {
  if(mode > 0) mode--;
  update_lcd();
 }

void autonomous() {
  switch(mode) {
    case  0: red_auton_bottom1(); break;
    case  1: red_auton_top1(); break;
    case  2: red_auton_top2(); break;
    case  3: blue_auton_bottom1(); break;
    case  4: blue_auton_top1(); break;
    case  5: blue_auton_top2(); break;
    case  6: skills(); break;
  }
}
