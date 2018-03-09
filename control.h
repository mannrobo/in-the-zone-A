
void setDrive(int a, int b) {

	a *= DRIVE_SPEED;
	b *= DRIVE_SPEED;

	if (INV_DRV_A) {
		a *= -1;
		b *= -1;
	}

	int left  = (INV_DRV_B) ? (b + a) : (a + b);
	int right = (INV_DRV_B) ? (b - a) : (a - b);

	motor[drvTopRight] = right;
	motor[drvBottomRight]  = right;

	motor[drvTopLeft]  = left;
	motor[drvBottomLeft]   = left;
}

void driveControl() {

	int x = (abs(vexRT[Ch4]) > DEADZONE) ? (vexRT[Ch4]) : (0);
	int y = (abs(vexRT[Ch3]) > DEADZONE) ? (vexRT[Ch3]) : (0);


	setDrive(x, y);
}

void setMGLift(int speed) {
	motor[leftMGLift]  = speed;
	motor[rightMGLift]  = speed;
}

void mgLiftControl() {
	if (vexRT[Btn6U] || vexRT[Btn8L]) {
		setMGLift(MG_LIFT_SPEED);
	} else if (vexRT[Btn6D] || vexRT[Btn8R]) {
		setMGLift(-1 * MG_LIFT_SPEED);
	} else {
		setMGLift(MOTOR_OFF);
	}
}


void setConeLift(int speed) {
	motor[leftCLift]  = speed;
	motor[rightCLift]  = speed;
}

void coneLiftControl() {
	if (vexRT[Btn5U]) {
		setConeLift(CONE_LIFT_R_SPEED);
	} else if (vexRT[Btn5D]) {
		setConeLift(-1 * CONE_LIFT_L_SPEED);
	} else {
		setConeLift(CONE_LIFT_HOLD);
	}
}

void setClaw(int speed) {
	motor[claw]  = speed;
}

void clawControl() {
	if (vexRT[Btn7L]) {
		setClaw(CLAW_SPEED);
	} else if (vexRT[Btn7R]) {
		setClaw(-1 * CLAW_SPEED);
	} else {
		setClaw(MOTOR_OFF);
	}
}

void resetQuads() {
	SensorValue[quadLeft] = 0;
	SensorValue[quadRight]  = 0;
}

void encoderControl() {
	if (vexRT[Btn7L]) {
		resetQuads();
	}
}

void setLEDs(int red = -1, int yellow = -1, int green = -1) {
	if (red    > -1 && red    < 2) SensorValue[LEDred]    = red;
	if (yellow > -1 && yellow < 2) SensorValue[LEDyellow] = yellow;
	if (green  > -1 && green  < 2) SensorValue[LEDgreen]  = green;
}

void halt() {
	setDrive(MOTOR_OFF, MOTOR_OFF);
	setMGLift(MOTOR_OFF);
	setConeLift(MOTOR_OFF);
	setClaw(MOTOR_OFF);
}

void lockdown() {
	bool locked = true;

	while(locked) {
		halt();
		if (nPgmTime % 1000 == 0) setLEDs(1, 0, 0);
		else if (nPgmTime % 500 == 0) setLEDs(0,0,0);
	}
}

bool killSwitch() {
	if (vexRT[Btn7D] == 1 && vexRT[Btn8D] == 1) {
		killSwitchState = true;
		halt();
	} else if (vexRT[Btn7U] == 1 && vexRT[Btn8U] == 1) {
		killSwitchState = false;
	}

	if (killSwitchState) setLEDs(1);
	else                 setLEDs(0);

	return killSwitchState;
}
