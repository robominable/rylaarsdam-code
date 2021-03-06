#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    RarmPoten,      sensorPotentiometer)
#pragma config(Sensor, in8,    armPoten,       sensorPotentiometer)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           RBLift,        tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           RArm,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           FRWheel,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           FLWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LBLift,        tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port7,           LArm,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           BRWheel,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           BLWheel,       tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//User Created Tasks
//task gripControl();

//Global Variables
int armPotenVal = 0;
int armPotenTarget = 0;

int RarmPotenVal = 4095;
int RarmPotenTarget = 4095;

int liftPotenVal = 0;
int liftPotenTarget = 0;

int RliftPotenVal = 0;
int RliftPotenTarget = 0;

float KpArm =  0.00003;//0.00003
float KiArm =  0.00000001;
float KdArm =  0.08; //0.08

float KpRArm = 0.00003;
float KiRArm = 0.00000001;
float KdRArm = 0.08;

float KpLift =  -0.000000000002;
float KiLift =  -0.0000000000001;
float KdLift =  -1; //2

float KpRLift = -0.000000000002;
float KiRLift = -0.0000000000001;
float KdRLift = -1; //2

int mtrpowerArm = 0;
int mtrpowerRArm = 0;
int mtrpowerLift = 0;
int mtrpowerRLift = 0;

bool autoArm = false;
bool autoArmPrimed = false;
bool autoLift = false;
bool autoLiftPrimed = false;

bool freezeLift = false;
bool freezeArm = false;

bool safetysignal = false;
bool highHang = false;

//Prototyped Functions
void idle(int waitTime);
void moveForward(int waitTime);
void moveBackward(int waitTime);
void strafeLeft(int waitTime);
void strafeRight(int waitTime);
void rotateLeft(int waitTime);
void rotateRight(int waitTime);

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
}

task autonomous()
{

}
task usercontrol()
{
	//startTask(gripControl);
	//int rev = 127;

	//*********************************************************************************************************

	int creep = 25;

	//Arm PID Variables
	//***********************************************************************
	int waitTime = 1;

	float TpArm = 0; //TUNABLE: [Starting] Power of right launcher
	float errorArm = 0; //Error of right launcher

	float iArm = 0; //Integral of right launcher

	float dArm = 0; //Derivative of right launcher
	float errorArmPrevious = 0;

	float editArm = 0; //Edit: How much to change right launch speed

	//*********************************************************************
	float TpRArm = 0; //TUNABLE: [Starting] Power of right launcher
	float errorRArm = 0; //Error of right launcher

	float iRArm = 0; //Integral of right launcher

	float dRArm = 0; //Derivative of right launcher
	float errorRArmPrevious = 0;

	float editRArm = 0; //Edit: How much to change right launch speed

	//*****************************************************************************8

	//Lift PID Variables
	float TpLift = 0; //TUNABLE: [Starting] Power of right launcher
	float errorLift = 0; //Error of right launcher

	float iLift = 0; //Integral of right launcher

	float dLift = 0; //Derivative of right launcher
	float errorLiftPrevious = 0;

	float editLift = 0; //Edit: How much to change right launch speed

	nMotorEncoder[LBLift] = 0;

	//*****************************************************************************8

	//RLift PID Variables
	float TpRLift = 0; //TUNABLE: [Starting] Power of right launcher
	float errorRLift = 0; //Error of right launcher

	float iRLift = 0; //Integral of right launcher

	float dRLift = 0; //Derivative of right launcher
	float errorRLiftPrevious = 0;

	float editRLift = 0; //Edit: How much to change right launch speed

	nMotorEncoder[RBLift] = 0;

	while (true)
	{
		wait1Msec(waitTime);

		if (autoArm == true)
		{
		//Arm PID ****************************************************************************************************

		errorArm = ( armPotenTarget - SensorValue[armPoten] ); // Error = Target - Observed

		if ((errorArm > 0 && errorArmPrevious < 0) || (errorArm < 0 && errorArmPrevious > 0) || (errorArm == 0))
		{
			iArm = 0;
		}

		if (abs(errorArm)>5)
		{
			//playImmediateTone(600,5);
		}
		iArm = iArm + errorArm; // Integral = Integral + Error

		dArm = errorArm - errorArmPrevious; // Derivative = Error - PreviousError

		errorArmPrevious = errorArm;

		editArm = KpArm * errorArm + KiArm * iArm + KdArm * dArm; // Edit = Kp * Error + Ki * Integral + Kd * Derivative
		//if  (autoArm == true)
		//{
		motor[LArm] = TpArm + editArm; // MotorPower = PreviousMotorPower + Edit
		//}
		TpArm += editArm; // MotorPower = PreviousMotorPower + Edit

		//get poten val!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		armPotenVal = SensorValue(armPoten);
		mtrpowerArm = motor[LArm];

		//RArm PID ******************************************************************************************************

		errorRArm = ( RarmPotenTarget - SensorValue(RarmPoten) ); // Error = Target - Observed

		if ((errorRArm > 0 && errorRArmPrevious < 0) || (errorRArm < 0 && errorRArmPrevious > 0) || (errorRArm == 0))
		{
			iRArm = 0;
		}

		if (abs(errorRArm)>5)
		{
			//playImmediateTone(600,5);
		}
		iRArm = iRArm + errorRArm; // Integral = Integral + Error

		dRArm = errorRArm - errorRArmPrevious; // Derivative = Error - PreviousError

		errorRArmPrevious = errorRArm;

		editRArm = KpRArm * errorRArm + KiRArm * iRArm + KdRArm * dRArm; // Edit = Kp * Error + Ki * Integral + Kd * Derivative
		//if  (autoArm == true)
		//{
		motor[RArm] = TpRArm + editRArm; // MotorPower = PreviousMotorPower + Edit
		//}
		TpRArm += editRArm; // MotorPower = PreviousMotorPower + Edit

		//get poten val!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		RarmPotenVal = SensorValue(RarmPoten);
		mtrpowerRArm = motor[RArm];
		}
		//Lift PID ***************************************************************************************************

		if (autoLift == true)
		{
		errorLift = ( nMotorEncoder[LBLift] - liftPotenTarget ); // Error = Target - Observed

		if ((errorLift > 0 && errorLiftPrevious < 0) || (errorLift < 0 && errorLiftPrevious > 0) || (errorLift == 0))
		{
			iLift = 0;
		}

		if (abs(errorLift)>5)
		{
			//playImmediateTone(800,5);
		}
		iLift = iLift + errorLift; // Integral = Integral + Error

		dLift = errorLift - errorLiftPrevious; // Derivative = Error - PreviousError

		errorLiftPrevious = errorLift;

		editLift = KpLift * errorLift + KiLift * iLift + KdLift * dLift; // Edit = Kp * Error + Ki * Integral + Kd * Derivative
		/*if  (autoLift == true)
		{
		motor[LBLift] = -20;
		TpLift = TpLift + editLift;
		}
		else*/
		//if (autoLift == true)
		//{
		motor[LBLift] = TpLift + editLift; // MotorPower = PreviousMotorPower + Edit
		//}
		TpLift = TpLift + editLift; // MotorPower = PreviousMotorPower + Edit

		//get poten val!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		liftPotenVal = nMotorEncoder[LBLift];
		mtrpowerLift = motor[LBLift];

		//RLift PID ***************************************************************************************************

		errorRLift = ( nMotorEncoder[RBLift] - RliftPotenTarget ); // Error = Target - Observed

		if ((errorRLift > 0 && errorRLiftPrevious < 0) || (errorRLift < 0 && errorRLiftPrevious > 0) || (errorRLift == 0))
		{
			iRLift = 0;
		}

		if (abs(errorRLift)>5)
		{
			//playImmediateTone(800,5);
		}
		iRLift = iRLift + errorRLift; // Integral = Integral + Error

		dRLift = errorRLift - errorRLiftPrevious; // Derivative = Error - PreviousError

		errorRLiftPrevious = errorRLift;

		editRLift = KpRLift * errorRLift + KiRLift * iRLift + KdRLift * dRLift; // Edit = Kp * Error + Ki * Integral + Kd * Derivative
		/*if  ((TpRLift + editRLift) <= -20)
		{
		motor[RBLift] = -20;
		TpRLift = TpRLift + editRLift;
		}
		else*/
		//if (autoLift == true)
		//{
		motor[RBLift] = TpRLift + editRLift; // MotorPower = PreviousMotorPower + Edit
		//}
		TpRLift = TpRLift + editRLift; // MotorPower = PreviousMotorPower + Edit

		//get poten val!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		RliftPotenVal = nMotorEncoder[RBLift];
		mtrpowerRLift = motor[RBLift];
		}

		//*Driver Controls ************************************************************************************************

		//Auto Arm Control
		if (autoArm == true)
		{
			//Set Target Arm Position
			if (vexRT[Btn8U]) { RarmPotenTarget = 993; armPotenTarget = 2904; } //closed
			else if (vexRT[Btn8D]) { RarmPotenTarget = 2795; armPotenTarget = 1160; } //middle
			else if (vexRT[Btn8R]) { RarmPotenTarget = 4095; armPotenTarget = 0; } //start

			//Arm Mini Adjust
			if (vexRT[Btn6U]) {armPotenTarget = armPotenTarget + 2; RarmPotenTarget = RarmPotenTarget - 2;}
			if (vexRT[Btn6D]) {armPotenTarget = armPotenTarget - 2; RarmPotenTarget = RarmPotenTarget + 2;}
		}

		//Auto Lift Control
		if (autoLift == true)
		{
			//Set Target Lift Position
			if (vexRT[Btn7D] && (armPotenTarget != 4095) && (RarmPotenTarget != 0)) { liftPotenTarget = 0; RliftPotenTarget = 0;} //full down 	poten4095
			else if (vexRT[Btn7L] && (armPotenTarget != 4095) && (RarmPotenTarget != 0)) { liftPotenTarget = 100; RliftPotenTarget = 100; } //down 	poten2978
			else if (vexRT[Btn7U] && (armPotenTarget != 4095) && (RarmPotenTarget != 0)) { liftPotenTarget = 3000; RliftPotenTarget = 3000; } //up   	poten1528

			//Lift Mini Adjust
			if (vexRT[Btn5U]) {liftPotenTarget = liftPotenTarget + 1; RliftPotenTarget = RliftPotenTarget + 1;}
			if (vexRT[Btn5D]) {liftPotenTarget = liftPotenTarget - 1; RliftPotenTarget = RliftPotenTarget - 1;}

			if (highHang == false)
			{
				if (liftPotenTarget > 3529) {liftPotenTarget = 3529;}
				if (RliftPotenTarget > 3529) {RliftPotenTarget = 3529;}
			}
		}

		//Manual Arm Control
		if (autoArm == false && freezeArm == false)
		{
			motor[RArm] = ( vexRT[Btn6U] - vexRT[Btn6D] ) * -40;
			motor[LArm] = ( vexRT[Btn6U] - vexRT[Btn6D] ) * 40;
		}

		//Manual Lift Control
		if (autoLift == false && freezeLift == false)
		{
			motor[RBLift] = ((vexRT[Btn5U] - vexRT[Btn5D]) * 127) + ((vexRT[Btn7R] - vexRT[Btn7D]) * 40 );
			motor[LBLift] = ((vexRT[Btn5U] - vexRT[Btn5D]) * 127) + ((vexRT[Btn7U] - vexRT[Btn7L]) * 40 );
		}

		//Drive Wheels
		if ((vexRT[Ch3] < creep) && (vexRT[Ch3] >-creep) && (vexRT[Ch4] < creep) && (vexRT[Ch4] >-creep)){motor[FLWheel] = 0;} else {motor[FLWheel] = vexRT[Ch3] + vexRT[Ch4]; }
		if ((vexRT[Ch3] < creep) && (vexRT[Ch3] >-creep) && (vexRT[Ch1] < creep) && (vexRT[Ch1] >-creep)){motor[BLWheel] = 0;} else {motor[BLWheel] = vexRT[Ch3] - vexRT[Ch1]; }
		if ((vexRT[Ch2] < creep) && (vexRT[Ch2] >-creep) && (vexRT[Ch4] < creep) && (vexRT[Ch4] >-creep)){motor[FRWheel] = 0;} else {motor[FRWheel] = vexRT[Ch2] - vexRT[Ch4]; }
		if ((vexRT[Ch2] < creep) && (vexRT[Ch2] >-creep) && (vexRT[Ch1] < creep) && (vexRT[Ch1] >-creep)){motor[BRWheel] = 0;} else {motor[BRWheel] = vexRT[Ch2] + vexRT[Ch1]; }


		//autoLift ON OFF CTRL && LIFT ENCODER RESET
		if ( (vexRT[Btn5U] == true) && (vexRT[Btn5D] == true) )
		{
			freezeLift = true;
			autoLift = false;
			if ( (vexRT[Btn7L] == true) && (vexRT[Btn7U] == true) && (vexRT[Btn7R] == true) && (vexRT[Btn7D] == true) )
			{
				resetMotorEncoder(RBLift);
				resetMotorEncoder(LBLift);
				liftPotenTarget = 0;
				RliftPotenTarget = 0;
			}
			else
			{
				if ( (vexRT[Btn7L] == true) && (vexRT[Btn7U] == true) && (vexRT[Btn7R] == false) && (vexRT[Btn7D] == false) )
				{
					autoLiftPrimed = true;
				}
				if ( (vexRT[Btn7L] == false) && (vexRT[Btn7U] == false) && (vexRT[Btn7R] == true) && (vexRT[Btn7D] == true) )
				{
					autoLiftPrimed = false;
				}
			}
		}
		else
		{
			freezeLift = false;
			if (autoLiftPrimed == true) {autoLift = true;}
		}

		//autoArm ON OFF CTRL
		if ( (vexRT[Btn6U] == true) && (vexRT[Btn6D] == true) )
		{
			freezeArm = true;
			autoArm = false;
			if ( (vexRT[Btn8U] == true) && (vexRT[Btn8R] == true) && (vexRT[Btn8L] == false) && (vexRT[Btn8D] == false) )
			{
				autoArmPrimed = true;
			}
			if ( (vexRT[Btn8U] == false) && (vexRT[Btn8R] == false) && (vexRT[Btn8L] == true) && (vexRT[Btn8D] == true) )
			{
				autoArmPrimed = false;
			}
		}
		else
		{
			freezeArm = false;
			if (autoArmPrimed == true) {autoArm = true;}
		}

		//Manual Safety Signal
		if ( (autoArm == false) && (vexRT[Btn5U] == true) && (vexRT[Btn5D] == true) && (vexRT[Btn6U] == true) && (vexRT[Btn6D] == true) && (safetysignal == false) )
		{
			safetysignal = true;
			playTone(1500, 50);
			wait1Msec(1000);
			if (SensorValue[armPoten] < 11)
			{
				playTone(1500, 50);
				wait1Msec(1000);
				if (SensorValue[RarmPoten] > 4085)
				{
					playTone(1500, 50);
					wait1Msec(1000);
				}
				else
				{
					playTone(1000, 50);
					wait1Msec(1000);
				}
			}
			else
			{
				playTone(1000, 50);
				wait1Msec(1000);
				if (SensorValue[RarmPoten] > 4085)
				{
					playTone(1500, 50);
					wait1Msec(1000);
				}
				else
				{
					playTone(1000, 50);
					wait1Msec(1000);
				}
			}
			safetysignal = false;
		}
	}
}void idle (int waitTime)
{
	wait1Msec(waitTime);
}

void moveForward (int waitTime)
{
	motor[FLWheel] = 127;
	motor[BLWheel] = 127;
	motor[FRWheel] = 127;
	motor[BRWheel] = 127;
	wait1Msec(waitTime);
	motor[FLWheel] = 0;
	motor[BLWheel] = 0;
	motor[FRWheel] = 0;
	motor[BRWheel] = 0;
}

void moveBackward (int waitTime)
{
	motor[FLWheel] = -127;
	motor[BLWheel] = -127;
	motor[FRWheel] = -127;
	motor[BRWheel] = -127;
	wait1Msec(waitTime);
	motor[FLWheel] = 0;
	motor[BLWheel] = 0;
	motor[FRWheel] = 0;
	motor[BRWheel] = 0;
}

void strafeLeft (int waitTime)
{
	motor[FLWheel] = -127;
	motor[BLWheel] = 127;
	motor[FRWheel] = 127;
	motor[BRWheel] = -127;
	wait1Msec(waitTime);
	motor[FLWheel] = 0;
	motor[BLWheel] = 0;
	motor[FRWheel] = 0;
	motor[BRWheel] = 0;
}

void strafeRight (int waitTime)
{
	motor[FLWheel] = 127;
	motor[BLWheel] = -127;
	motor[FRWheel] = -127;
	motor[BRWheel] = 127;
	wait1Msec(waitTime);
	motor[FLWheel] = 0;
	motor[BLWheel] = 0;
	motor[FRWheel] = 0;
	motor[BRWheel] = 0;
}

void rotateLeft (int waitTime)
{
	motor[FLWheel] = -127;
	motor[BLWheel] = -127;
	motor[FRWheel] = 127;
	motor[BRWheel] = 127;
	wait1Msec(waitTime);
	motor[FLWheel] = 0;
	motor[BLWheel] = 0;
	motor[FRWheel] = 0;
	motor[BRWheel] = 0;
}

void rotateRight (int waitTime)
{
	motor[FLWheel] = 127;
	motor[BLWheel] = 127;
	motor[FRWheel] = -127;
	motor[BRWheel] = -127;
	wait1Msec(waitTime);
	motor[FLWheel] = 0;
	motor[BLWheel] = 0;
	motor[FRWheel] = 0;
	motor[BRWheel] = 0;
}

//void armPosition (int
