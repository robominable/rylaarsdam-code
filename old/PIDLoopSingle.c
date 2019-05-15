#pragma config(Sensor, in1,    armPotenTarget, sensorPotentiometer)
#pragma config(Motor,  port1,           URArm,         tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int armPotenTarget = 0; //CHANGE for different rates of checking
	int armPotenVal = 0;

	float TpRLaunch =55; //TUNABLE: [Starting] Power of right launcher
	float errorRightLaunch = 0; //Error of right launcher

	float iRightLaunch = 0; //Integral of right launcher

	float dRightLaunch = 0; //Derivative of right launcher
	float errorRightLaunchPrevious = 0;

	float editRightLaunch = 0; //Edit: How much to change right launch speed


			errorRightLaunch = ( armPotenTarget - SensorValue(armPotenVal) ); // Error = Target - Observed

			if ((errorRightLaunch > 0 && errorRightLaunchPrevious < 0) || (errorRightLaunch < 0 && errorRightLaunchPrevious > 0) || (errorRightLaunch == 0))
			{
				iRightLaunch = 0;
			}

			if (abs(errorRightLaunch)>5)
			{
				playImmediateTone(600,5);
			}
			iRightLaunch = iRightLaunch + errorRightLaunch; // Integral = Integral + Error

			dRightLaunch = errorRightLaunch - errorRightLaunchPrevious; // Derivative = Error - PreviousError

			errorRightLaunchPrevious = errorRightLaunch;

			editRightLaunch = KpArm * errorRightLaunch + KiArm * iRightLaunch + KdArm * dRightLaunch; // Edit = Kp * Error + Ki * Integral + Kd * Derivative
			if  ((TpRLaunch + editRightLaunch) > 0)
			{
				motor[URArm] = TpRLaunch + editRightLaunch; // MotorPower = PreviousMotorPower + Edit
				TpRLaunch = TpRLaunch + editRightLaunch; // MotorPower = PreviousMotorPower + Edit
			}
}