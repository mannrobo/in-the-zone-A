
void setDrive(int x, int y) {

	int left  = (y + x) / 2;
	int right = (y - x) / 2;

	motor[drvFrontRight] = right;
	motor[drvBackRight]  = right;

	motor[drvFrontLeft]  = left;
	motor[drvBackLeft]   = left;
}

void driveControl() {

	int x = (vexRT[Ch4] > DEADZONE) ? (vexRT[Ch4]) : (0);
	int y = (vexRT[Ch3] > DEADZONE) ? (vexRT[Ch3]) : (0);

	setDrive(x, y);

}

void setClaw(int speed) {
	motor[clawMotor] = speed;
}

void clawControl() {
	if (vexRT[Btn5U]) {
		setClaw(MOTOR_MAX);
	} else if (vexRT[Btn5D]){
		setClaw(-1 * MOTOR_MAX);
	} else {
		setClaw(MOTOR_OFF);
	}
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
		setArm(MOTOR_OFF);
	}
}

void setLift(int speed) {
	motor[leftLiftMotor] = speed;
	motor[rightLiftMotor] = speed;
}

void liftControl() {
	if (vexRT[Btn8U]) {
		setLift(MOTOR_MAX);
	} else if (vexRT[Btn8D]) {
		setLift(-1 * MOTOR_MAX);
	} else {
		setLift(MOTOR_OFF);
	}
}

void halt() {
	setArm(MOTOR_OFF);
	setDrive(MOTOR_OFF, MOTOR_OFF);
	setClaw(MOTOR_OFF);
	setLift(MOTOR_OFF);
}

void lockdown() {
	while(true) {
		halt();
	}
}

bool killSwitch() {
	if (vexRT[Btn7D] == 1 && vexRT[Btn8D] == 1) {
		killSwitchState = true;
		halt();
	} else if (vexRT[Btn7U] == 1 && vexRT[Btn8U] == 1) {
		killSwitchState = false;
	}

	return killSwitchState;
}
