#pragma config(Motor,  port1,           FLdrive,       tmotorVex393_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port2,           FRdrive,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           Puncher,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           ChainArmL,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           ChainArmR,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           BLdrive,       tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port10,          BRdrive,       tmotorVex393_HBridge, openLoop, driveRight)

task autonomous()
{
	wait1Msec(1);
}

task main()
{
	//USERCONTROL
	while(1==1)
	{
		//DRIVETRAIN CODE
		motor[FLdrive] = (vexRT[Ch4] + vexRT[Ch3]);
		motor[FRdrive] = (vexRT[Ch1] - vexRT[Ch2]);
		motor[BLdrive] = (vexRT[Ch4] + vexRT[Ch3]);
		motor[BRdrive] = (vexRT[Ch1] - vexRT[Ch2]);
		//FLIPPING CLAW
		motor[Claw] = (vexRT[Btn5U] * 127);
		motor[Claw] = (vexRT[Btn5D] * -127);
		//CLAW BAR
		motor[ChainArmL] = (vexRT[Btn6U] * 127);
		motor[ChainArmL] = (vexRT[Btn6U] * 127);
		motor[ChainArmR] = (vexRT[Btn6D] * -127);
		motor[ChainArmR] = (vexRT[Btn6D] * -127);
		//INTAKE
		if(vexRT[Btn7R] == 1)
		{
			motor[Intake] = 127;
			wait1Msec(10000); //10SEC
			motor[Intake] = 0;
		}
	}

}
