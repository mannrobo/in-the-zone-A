
void setDrive(int x, int y) {

	int left  = (y + x) / 2;
	int right = (y - x) / 2;

	motor[drvFrontRight] = right;
	motor[drvBackRight]  = right;

	motor[drvFrontLeft]  = left;
	motor[drvBackLeft]   = left;
}

void driveControl() {

	setDrive(vexRT[Ch4], vexRT[Ch3]);

}

void clawControl() {
	bool DONOTHING = false;
}

void setArm(int speed) {
	motor[leftArmMotor]  = speed;
	motor[rightArmMotor] = -speed;
}

void armControl() {
	if (vexRT[Btn6U]) {
		setArm(MOTOR_MAX);
	} else if (vexRT[Btn6D]) {
		setArm(-1 * MOTOR_MAX);
	} else {
		setArm(0);
	}
}
