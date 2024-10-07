#pragma once

#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor intake(8); // Intake Motor Port
inline pros::adi::DigitalOut mogo_piston('A');
// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');