
#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

// Pre Auton
//   Executes before auton; must return for auton to start.

void pre_auton(){

  bStopTasksBetweenModes = true;         // Allow competition modes to control tasks.
	bDisplayCompetitionStatusOnLcd = true; // Use default LCD output from competition.

  // clearing encoders, setting servo positions, etc
}

// Autonomous Task
task autonomous(){

  AutonomousCodePlaceholderForTesting();

}

// User Control Task
task usercontrol(){

  while (true) {

    UserControlCodePlaceholderForTesting();

  }
}
