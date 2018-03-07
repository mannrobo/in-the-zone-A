

void safetyCheck() {
	int qR = abs(SensorValue[quadRight]);
	int qL = abs(SensorValue[quadLeft]);

	int diff = abs(qL - qR);

	if (diff > AUTON_SAFETY) {
		writeDebugStreamLine("AUTON SAFETY TRIGGERED. PERMANENT HALT UNTIL DRIVER.");
		lockdown();
	}
}

void waitTicks(int ticks, int timeout = -1) {

	resetQuads();
	ticks = abs(ticks);
	timeout *= 1000;

	while (abs(SensorValue[quadLeft])  - QUAD_TOLERANCE < ticks &&
		   abs(SensorValue[quadRight]) - QUAD_TOLERANCE < ticks && (timeout > 0 || timeout == -1000))  {
		wait1Msec(100);
		safetyCheck();
		if (timeout != -1000) timeout -= 100;
	}
}

void waitBump(int ticks, int timeout = 2) {

	timeout *= 100;

	while (!SensorValue[mgDetect] && timeout > 0) {
		wait10Msec(10);
		timeout -= 10;
	}
};

void auton60() {

	//Auton Configuration
	const int DRV_FORWARDS_TICKS = 1300;
	const int MG_LIFT_RAISE_TIME = 1000;
	const int DRV_TURN_TICKS = 600;
	const int DRV_BACK_TICKS = 1600; //2000 ok for 10 pts
	const int DRV_ADJUST_TURN_TICKS = 170;
	const int DRV_CONTINUE_TICKS = 600;
	const int MG_LIFT_LOWER_TIME = MG_LIFT_RAISE_TIME;
	const int DRV_BACKWARDS_TICKS = 400;

	halt();
	resetQuads();

	//Drive forward.
	setDrive(MOTOR_OFF, MOTOR_MAX);
	waitTicks(DRV_FORWARDS_TICKS);
	halt();

	// Lift mobile goal
	setMGLift(MOTOR_MAX);
	wait1Msec(MG_LIFT_RAISE_TIME);
	halt();

	// turn 180
	setDrive(MOTOR_MAX, MOTOR_OFF);
	waitTicks(DRV_TURN_TICKS, 2);
	halt();

	// drive forward
	setDrive(MOTOR_OFF, MOTOR_MAX);
	waitTicks(DRV_BACK_TICKS);
	halt();

	// adjustment turn
	setDrive(6 * MOTOR_MAX / 16, MOTOR_OFF);
	waitTicks(DRV_ADJUST_TURN_TICKS);
	setDrive(-1 * 6 * MOTOR_MAX / 16, MOTOR_OFF);
	waitTicks(DRV_ADJUST_TURN_TICKS);
	halt();

	//continue forward
	setDrive(MOTOR_OFF, MOTOR_MAX);
	waitTicks(DRV_CONTINUE_TICKS);
	halt();

	// lower lift
	setMGLift(-1 * MOTOR_MAX);
	wait1Msec(MG_LIFT_LOWER_TIME);
	halt();

	// drive backwards
	setDrive(MOTOR_OFF, -1 * MOTOR_MAX);
	waitTicks(DRV_BACKWARDS_TICKS);
	halt();

}

void auton15() {


	//Auton Configuration
	const int DRV_FORWARDS_TICKS = 1600;
	const int MG_LIFT_RAISE_TIME = 500;
	const int DRV_TURN_TICKS = 610; // 640
	const int DRV_BACK_TICKS = 2200; //2000 ok for 10 pts
	const int MG_LIFT_LOWER_TIME = MG_LIFT_RAISE_TIME;
	const int DRV_BACKWARDS_TICKS = 400;

	halt();
	resetQuads();

	//Drive forward.
	setDrive(MOTOR_OFF, MOTOR_MAX);
	waitTicks(DRV_FORWARDS_TICKS);
	halt();

	// Lift mobile goal
	setMGLift(MOTOR_MAX);
	wait1Msec(MG_LIFT_RAISE_TIME);
	halt();

	// turn 180
	setDrive(-1 * MOTOR_MAX, MOTOR_OFF);
	waitTicks(DRV_TURN_TICKS, 2);
	halt();

	// drive forward
	setDrive(MOTOR_OFF, MOTOR_MAX);
	waitTicks(DRV_BACK_TICKS);
	halt();

	// lower lift
	setMGLift(-1 * MOTOR_MAX);
	wait1Msec(MG_LIFT_LOWER_TIME);
	halt();

	// drive backwards
	setDrive(MOTOR_OFF, -1 * MOTOR_MAX);
	waitTicks(DRV_BACKWARDS_TICKS);
	halt();


}
