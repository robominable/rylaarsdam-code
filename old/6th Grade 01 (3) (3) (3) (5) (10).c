task main()
#pragma config(Motor,  port1,           FRWheel,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           BRWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FLWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           BLWheel,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           ULR,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           ULL,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           DLR,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           DLL,           tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)
//Global Variables

//Prototyped Functions
task autonomous()
{
	motor[FRWheel] = 127;
	motor[BRWheel] = 127;
	motor[FLWheel] = 127;
	motor[BLWheel] = 127;
	wait1Msec(5150);
	motor[FRWheel] = 127;
	motor[BRWheel] = 127;
	motor[FLWheel] = -127;
	motor[BLWheel] = -127;
	wait1Msec (800);
	motor[FRWheel] = 127;
	motor[BRWheel] = 127;
	motor[FLWheel] = 127;
	motor[BLWheel] = 127;
	wait1Msec(3000);
	motor[FRWheel] = 127;
	wait1Msec(1350);
	delay(100);
	motor[DLL] = 127;
	motor[DLR] = 127;
	motor[ULL] = 127;
	motor[ULR] = 127;
	wait1Msec(1000);
	motor[DLL] = -127;
	motor[DLR] = -127;
	motor[ULL] = -127;
	motor[ULR] = -127;
	wait1Msec(1000);
	motor[FRWheel] = -127;
	motor[BRWheel] = -127;
	motor[FLWheel] = -127;
	motor[BLWheel] = -127;
	wait1Msec(6000);
	motor[FRWheel] = 0;
	motor[BRWheel] = 0;
	motor[FLWheel] = 0;
	motor[BLWheel] = 0;
}

task usercontrol()
{
	while(true)
	motor[FLWheel] = vexRT[Ch3];
	motor[FRWheel] = vexRT[Ch2];
	motor[BLWheel] = vexRT[Ch3];
	motor[BRWheel] = vexRT[Ch2];
	motor[ULL] = vexRT[Btn5U];
	motor[ULR] = vexRT[Btn5U];
	motor[DLL] = vexRT[Btn5U];
	motor[DLR] = vexRT[Btn5U];
}
