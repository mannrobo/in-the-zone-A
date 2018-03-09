
#ifndef ROBOT_SETTINGS
#define ROBOT_SETTINGS

const bool INV_DRV_A = true; //DEFAULT: true
const bool INV_DRV_B = false; //DEFAULT: true

const bool KS_DEFAULT = false;  //DEFAULTS: { true  for practice
							    //            false for competition }

const int QUAD_TOLERANCE = 20;

const int MG_LIFT_SPEED = MOTOR_MAX; //DEFAULT: MOTOR_MAX
const int CONE_LIFT_R_SPEED = MOTOR_MAX; //DEFAULT: MOTOR_MAX
const int CONE_LIFT_L_SPEED = MOTOR_MAX / 4; //DEFAULT: MOTOR_MAX / 4
const int CONE_LIFT_HOLD = 15; //DEFAULT: 15
const int CLAW_SPEED = MOTOR_MAX; //DEFAULT: MOTOR_MAX


const int DEADZONE = 40; //DEFAULT: 40

const bool ENABLE_MATCH_AUTON = true;
const bool NO_AUTONOMOUS_WHATSOEVER = false;

const int AUTON_SAFETY = 100;

const float DRIVE_SPEED = 1.0;

#endif
