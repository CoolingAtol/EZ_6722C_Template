#include "main.h"

int tile = 24;

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Drive, Turn, Swing Speeds; these are out of 127
const int D = 100;
const int T = 80;
const int S = 80;

// 85 = ~400 RPM
// 106 = ~500 RPM
// 116 = ~550 RPM
// 127 = 600 RPM
const int INTAKE_SPEED = 85;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

// . . .
// Make your own autonomous functions here!
// . . .

// Red 4 Ring Auton and AWP
void red_top_four_rings_awp() {
  // Pick up MoGo
  chassis.pid_drive_set(-15, D, true);
  chassis.pid_wait();
  mogo_piston.set_value(true);
  chassis.pid_drive_set(-2, 0.5 * D);
  chassis.pid_wait();
  chassis.pid_drive_set(2, 0.5 * D);
  chassis.pid_wait();
  pros::delay(100);

  // Turn Right toward Ring Stack
  chassis.pid_turn_set(90, T);
  chassis.pid_wait();

  // Activate Intake, Drive to Ring Stack
  intake.move(INTAKE_SPEED);
  chassis.pid_drive_set(tile, D, true);
  chassis.pid_wait_until(0.7 * tile);
  intake.move(0);
  chassis.pid_wait();
  pros::delay(100);

  // Intake Ring from 1st Stack
  intake.move(INTAKE_SPEED);
  pros::delay(1000);
  intake.move(0);
  pros::delay(100);

  // Turn to 2nd stack, Intake Ring
  chassis.pid_turn_set(80, T);
  chassis.pid_wait();
  chassis.pid_drive_set(20.3, D);
  chassis.pid_wait();
  pros::delay(200);
  intake.move(INTAKE_SPEED);
  pros::delay(1000);

  // Drive backwards
  chassis.pid_drive_set(-20.3, D);
  chassis.pid_wait();
  intake.move(0);

  // Turn to 3rd stack, Intake Ring
  chassis.pid_turn_set(20, T);
  chassis.pid_wait();
  chassis.pid_drive_set(20.3, D);
  chassis.pid_wait();
  pros::delay(200);
  intake.move(INTAKE_SPEED);
  pros::delay(1000);

  // Drive backwards
  chassis.pid_drive_set(-20.3, D);
  chassis.pid_wait();
  intake.move(0);
  pros::delay(100);

  // Turn Right & Drive Forward
  chassis.pid_turn_set(70, T);
  chassis.pid_wait();
  chassis.pid_drive_set(tile, D);
  chassis.pid_wait();
  pros::delay(100);
  
  // For now drive straight to ladder
  chassis.pid_drive_set(tile, D);

  /** For 5 Ring AWP
  // Turn Toward 4th Ring Stack
  chassis.pid_turn_set(45, T);
  chassis.pid_wait();
  chassis.pid_drive_set(34, D);
  chassis.pid_wait();
  pros::delay(200);

  // Intake 5th Ring
  intake.move(INTAKE_SPEED);
  pros::delay(1000);
  intake.move(0);


  // Turn and Drive Forward into Ladder
  chassis.pid_turn_set(-45, T);
  chassis.pid_wait();
  chassis.pid_drive_set(0.7 * tile, D);
  */
}

// Blue 4 Ring Auton and AWP
void blue_top_four_rings_awp() {
  // Pick up MoGo
  chassis.pid_drive_set(-15, D, true);
  chassis.pid_wait();
  mogo_piston.set_value(true);
  chassis.pid_drive_set(-2, 0.5 * D);
  chassis.pid_wait();
  chassis.pid_drive_set(2, 0.5 * D);
  chassis.pid_wait();
  pros::delay(100);

  // Turn Right toward Ring Stack
  chassis.pid_turn_set(-90, T);
  chassis.pid_wait();

  // Activate Intake, Drive to Ring Stack
  intake.move(INTAKE_SPEED);
  chassis.pid_drive_set(tile, D, true);
  chassis.pid_wait_until(0.7 * tile);
  intake.move(0);
  chassis.pid_wait();
  pros::delay(100);

  // Intake Ring from 1st Stack
  intake.move(INTAKE_SPEED);
  pros::delay(1000);
  intake.move(0);
  pros::delay(100);

  // Turn to 2nd stack, Intake Ring
  chassis.pid_turn_set(-80, T);
  chassis.pid_wait();
  chassis.pid_drive_set(20.3, D);
  chassis.pid_wait();
  pros::delay(200);
  intake.move(INTAKE_SPEED);
  pros::delay(1000);

  // Drive backwards
  chassis.pid_drive_set(-20.3, D);
  chassis.pid_wait();
  intake.move(0);

  // Turn to 3rd stack, Intake Ring
  chassis.pid_turn_set(-20, T);
  chassis.pid_wait();
  chassis.pid_drive_set(20.3, D);
  chassis.pid_wait();
  pros::delay(200);
  intake.move(INTAKE_SPEED);
  pros::delay(1000);

  // Drive backwards
  chassis.pid_drive_set(-20.3, D);
  chassis.pid_wait();
  intake.move(0);
  pros::delay(100);

  // Turn Right & Drive Forward
  chassis.pid_turn_set(-70, T);
  chassis.pid_wait();
  chassis.pid_drive_set(tile, D, true);
  chassis.pid_wait();
  pros::delay(100);

  // For now drive straight to ladder
  chassis.pid_drive_set(tile, D);

  /** For 5 Ring AWP
  // Turn Toward 4th Ring Stack
  chassis.pid_turn_set(-45, T);
  chassis.pid_wait();
  chassis.pid_drive_set(34, D);
  chassis.pid_wait();
  pros::delay(200);

  // Intake 5th Ring
  intake.move(INTAKE_SPEED);
  pros::delay(1000);
  intake.move(0);
 
  // Turn and Drive Forward into Ladder
  chassis.pid_turn_set(45, T);
  chassis.pid_wait();
  chassis.pid_drive_set(0.7 * tile, D);
  */
}

// Red 2 Ring Auton and AWP
void red_top_two_rings_awp() {
  // Pick up MoGo
  chassis.pid_drive_set(-15, D, true);
  chassis.pid_wait();
  mogo_piston.set_value(true);
  chassis.pid_drive_set(-2, 0.5 * D);
  chassis.pid_wait();
  chassis.pid_drive_set(2, 0.5 * D);
  chassis.pid_wait();
  pros::delay(100);

  // Turn Right toward Ring Stack
  chassis.pid_turn_set(90, T);
  chassis.pid_wait();
  pros::delay(100);

  // Activate Intake, drive to Ring Stack
  intake.move(INTAKE_SPEED);
  chassis.pid_drive_set(tile, D, true);
  chassis.pid_wait_until(0.7 * tile);
  intake.move(0);
  chassis.pid_wait();
  pros::delay(100);
  
  // Intakes Ring, drives Back
  intake.move(INTAKE_SPEED);
  chassis.pid_drive_set(-2 * tile, D, true);
  chassis.pid_wait_until(-1.5 * tile);
  intake.move(0);
  chassis.pid_wait();

}

// Blue 2 Ring Auton and AWP
void blue_top_two_rings_awp() {
  // Pick up MoGo
  chassis.pid_drive_set(-15, D, true);
  chassis.pid_wait();
  mogo_piston.set_value(true);
  chassis.pid_drive_set(-2, 0.5 * D);
  chassis.pid_wait();
  chassis.pid_drive_set(2, 0.5 * D);
  chassis.pid_wait();
  pros::delay(100);

  // Turn Right toward Ring Stack
  chassis.pid_turn_set(-90, T);
  chassis.pid_wait();
  pros::delay(100);

  // Activate Intake, drive to Ring Stack
  intake.move(INTAKE_SPEED);
  chassis.pid_drive_set(tile, D, true);
  chassis.pid_wait_until(0.7 * tile);
  intake.move(0);
  chassis.pid_wait();
  pros::delay(200);
  
  // Intakes Ring, drives Back
  intake.move(INTAKE_SPEED);
  pros::delay(200);
  chassis.pid_drive_set(-2 * tile, D, true);
  chassis.pid_wait_until(-1.5 * tile);
  intake.move(0);
  chassis.pid_wait();

}

// Autonomous Test Run
void test_auton() {
  chassis.pid_drive_set(48_in, D, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, T);
  chassis.pid_wait();

  chassis.pid_drive_set(48_in, D, true);
  chassis.pid_wait();
}

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

  chassis.pid_drive_set(24_in, D, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, D);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, D);
  chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, T);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, T);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, T);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, D, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, T);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, T);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, T);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, D, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(D);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at D
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, T);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, T);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, T);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(D);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at D
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, S, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, S, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, S, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, S, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, D, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, T);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, T);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, T);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, D, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, D, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, T);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, S, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, T);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, D, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, D, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, T);
  chassis.pid_wait();
}