#include "main.h"
using namespace okapi;

//define port names
#define l_mtr_port 10 //left front motor
#define r_mtr_port 1 //right front motor
#define l_arm_port 19 //left lift motor
#define r_arm_port 12 //right lift motor
#define l_tread_port 20 //left intake motor
#define r_tread_port 11 //right intake
#define strafe_port 18 //strafe motor
#define placer_port 8 //placer lift motor

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	pros::Controller master (CONTROLLER_MASTER);
	pros::Motor l_mtr (l_mtr_port);
	pros::Motor r_mtr (r_mtr_port, true); //reversed
	pros::Motor strafe (strafe_port);

	typedef enum motor_brake_mode_e {
  E_MOTOR_BRAKE_COAST = 0, // Motor coasts when stopped, traditional behavior
  E_MOTOR_BRAKE_BRAKE = 1, // Motor brakes when stopped
  E_MOTOR_BRAKE_HOLD = 2, // Motor actively holds position when stopped
  E_MOTOR_BRAKE_INVALID = INT32_MAX
} motor_brake_mode_e_t;

//Set Brake mode

	pros::Motor l_arm (l_arm_port, MOTOR_GEARSET_36); //should be reversed
	l_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	std::cout << "Brake Mode: " << l_arm.get_brake_mode();

	pros::Motor r_arm (r_arm_port, MOTOR_GEARSET_36);
	r_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	std::cout << "Brake Mode: " << r_arm.get_brake_mode();

	pros::Motor l_tread (l_tread_port, MOTOR_GEARSET_18); //should be reversed
	l_tread.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	std::cout << "Brake Mode: " << l_tread.get_brake_mode();

	pros::Motor r_tread (r_tread_port, MOTOR_GEARSET_18);
	r_tread.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	std::cout << "Brake Mode: " << r_tread.get_brake_mode();

	pros::Motor placer (placer_port, MOTOR_GEARSET_36);
	placer.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	std::cout << "Brake Mode: " << placer.get_brake_mode();

	//Set Brake mode

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int power = master.get_analog(ANALOG_RIGHT_Y); //right joystick moves forward/backward
		int turn = master.get_analog(ANALOG_LEFT_X); //left joystick moves side to side
    int left = power + turn;
    int right = power - turn;
		l_mtr.move(left);
		r_mtr.move(right);

//Start lift * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			if (master.get_digital(DIGITAL_R2))	{
				r_arm.move_velocity(-40);
				l_arm.move_velocity(40);
			}

			else if (master.get_digital(DIGITAL_R1))	{
				r_arm.move_velocity(100);
				l_arm.move_velocity(-100);
			}

			else {
				r_arm.move_velocity (0);
				l_arm.move_velocity (0);
			}
//End lift * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


//Start intake * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
				if (master.get_digital(DIGITAL_L2))	{
					l_tread.move_velocity(-100);
					r_tread.move_velocity(100);
				}

				else if (master.get_digital(DIGITAL_L1)) {
					l_tread.move_velocity (100);
					r_tread.move_velocity (-100);
				}

				else {
					l_tread.move_velocity (0);
					r_tread.move_velocity (0);
				}
//End intake * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

//Start Strafe * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
/*
						if (master.get_digital(DIGITAL_LEFT)){
							strafe.move_velocity (-60);
						}

						else if (master.get_digital(DIGITAL_RIGHT)){
							strafe.move_velocity (60);
						}

						else {
							strafe.move_velocity(0);
						}
*/
//End Strafe * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

//Start placer * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

								if (master.get_digital(DIGITAL_X)){
									placer.move_velocity(50);
								}

								else if (master.get_digital(DIGITAL_A)){
									placer.move_velocity(-50);
								}

								else {
									placer.move_velocity(0);
								}

//End placer * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

		pros::delay(2);

	}
}
