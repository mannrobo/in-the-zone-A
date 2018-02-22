
void setDrive(int a, int b) {

	a *= DRIVE_SPEED;
	b *= DRIVE_SPEED;

	if (INV_DRV_A) {
		a *= -1;
		b *= -1;
	}

	int left  = (INV_DRV_B) ? (b + a) : (a + b);
	int right = (INV_DRV_B) ? (b - a) : (a - b);

	motor[drvFrontRight] = right;
	motor[drvBackRight]  = right;

	motor[drvFrontLeft]  = left;
	motor[drvBackLeft]   = left;
}

void driveControl() {

	int x = (abs(vexRT[Ch4]) > DEADZONE) ? (vexRT[Ch4]) : (0);
	int y = (abs(vexRT[Ch3]) > DEADZONE) ? (vexRT[Ch3]) : (0);


	setDrive(x, y);
}

void setLift(int speed) {
	motor[leftLowerLiftMotor]  = speed;
	motor[leftUpperLiftMotor]  = speed;
	motor[rightLowerLiftMotor] = speed;
	motor[rightUpperLiftMotor] = speed;
}

void liftControl() {
	if (vexRT[Btn6U] || vexRT[Btn8L]) {
		setLift(LIFT_SPEED);
	} else if (vexRT[Btn6D] || vexRT[Btn8R]) {
		setLift(-1 * LIFT_SPEED);
	} else {
		setLift(MOTOR_OFF);
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

	if (killSwitchState) setLEDs(1);
	else                 setLEDs(0);

	return killSwitchState;
}
