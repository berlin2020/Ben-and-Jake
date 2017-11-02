#pragma config(Sensor, S1,     sound,          sensorSoundDB)
#pragma config(Motor,  motorB,          light,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int clapCount = 0;
	int moveMode = 0;

	while (true)
	{
		displayTextLine(4, "Sound %d", SensorValue(sound));

		if(moveMode == 0 && SensorValue(sound) >= 50)
		{
			clapCount = clapCount + 1;
		}

		if(clapCount == 1)
		{
			moveMode = 1;
			clapCount = 0;
		}

		if(moveMode == 1 && SensorValue(sound) <= 40)
		{
			motor(light) = 20;
			wait1Msec(300);
			clapCount = 0;
			moveMode = 0;
		}

	}

}
