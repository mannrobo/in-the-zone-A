#pragma config(Sensor, in1,    clawLocation,   sensorPotentiometer)
#pragma config(Sensor, dgtl1,  quadRight,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  quadLeft,       sensorQuadEncoder)
#pragma config(Sensor, dgtl10, LEDgreen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, LEDyellow,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, LEDred,         sensorLEDtoVCC)
#pragma config(Motor,  port2,           leftUpperLiftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftLowerLiftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           drvFrontLeft,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           drvBackLeft,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           drvBackRight,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           drvFrontRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightLowerLiftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightUpperLiftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          clawMotor,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)

bool killSwitchState;

#include "Vex_Competition_Includes.c"
#include "constants.h"
#include "settings.h"
#include "control.h"

// Pre Auton
//   Executes before auton; must return for auton to start.

void pre_auton(){

  bStopTasksBetweenModes = true;         // Allow competition modes to control tasks.
	bDisplayCompetitionStatusOnLcd = true; // Use default LCD output from competition.

  // clearing encoders, setting servo positions, etc
}

// Autonomous Task
task autonomous(){

	setLEDs(0, 1, 0);
  AutonomousCodePlaceholderForTesting();

}

// User Control Task
task usercontrol(){

	killSwitchState = KS_DEFAULT;
	setLEDs(0, 0, 1);

	while (true) {
		if (!killSwitch()) {
			driveControl();
			liftControl();
		} else {
			halt();
		}
	}
}
