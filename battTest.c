
task main()
{

	while (true) {
		writeDebugStreamLine("%d", nImmediateBatteryLevel);
		wait10Msec(100);
	}

}
