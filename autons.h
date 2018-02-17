
void waitTicks(int ticks, int timeout = -1) {

	resetQuads();
	ticks = abs(ticks);
	timeout *= 100;

	while (abs(SensorValue[quadLeft])  - QUAD_TOLERANCE < ticks &&
		   abs(SensorValue[quadRight]) - QUAD_TOLERANCE < ticks && (timeout > 0 || timeout == -10))  {
		wait10Msec(10);
		if (timeout != -10) timeout -= 10;
	}
}

void waitBump(int ticks, int timeout = 2) {

	timeout *= 100;

	while (!SensorValue[mgDetect] && timeout > 0) {
		wait10Msec(10);
		timeout -= 10;
	}
};

void autonNOPE() {
	while (true) {
		wait10Msec(10);
	}
}

void auton60() {

	setDrive(MOTOR_OFF, MOTOR_MAX);
	wait1Msec(FWD_DELAY)

}

void auton15() {

	//Auton Configuration
	const int DRV_FORWARD_TICKS = 5000;
	const int MG_LIFT_RAISE_TIME = 100;
	const int DRV_TURN_TICKS = 500;
	const int DRV_BACK_TICKS = 5000;
	const int MG_LIFT_LOWER_TIME = MG_LIFT_RAISE_TIME;
	const int DRV_BACKWARDS_TIME = 500;

	halt();
	resetQuads();

	//Drive forward.
	setDrive(MOTOR_OFF, MOTOR_MAX);
	waitTicks(DRV_FORWARD_TICKS);
	halt();

	// Lift mobile goal
	setLift(MOTOR_MAX);
	wait10Msec(MG_LIFT_RAISE_TIME);
	halt();

	// turn 180
	setDrive(MOTOR_MAX, MOTOR_OFF);
	waitTicks(DRV_TURN_TICKS, 2);
	halt();

	// drive forward
	setDrive(MOTOR_OFF, MOTOR_MAX);
	waitTicks(DRV_BACK_TICKS);
	halt();

	// lower lift
	setLift(-1 * MOTOR_MAX);
	wait10Msec(MG_LIFT_LOWER_TIME);
	halt();

	// drive backwards
	setDrive(MOTOR_OFF, -1 * MOTOR_MAX);
	wait10Msec(DRV_BACKWARDS_TIME);
	halt();


}
