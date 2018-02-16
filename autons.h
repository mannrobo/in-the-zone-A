
void waitTicks(int ticks) {

	resetQuads();
	ticks = abs(ticks);

	while (abs(SensorValue[quadLeft])  - QUAD_TOLERANCE < ticks &&
		   abs(SensorValue[quadRight]) - QUAD_TOLERANCE < ticks)  {
		wait10Msec(10);
	}
}

void auton60() {

	setDrive(MOTOR_OFF, MOTOR_MAX);
	waitTicks(500);
	setDrive(MOTOR_OFF, MOTOR_OFF);

}

void auton15() {
	AutonomousCodePlaceholderForTesting();
}
