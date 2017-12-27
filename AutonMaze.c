#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  armQuad,        sensorNone)
#pragma config(Sensor, dgtl2,  button,         sensorTouch)
#pragma config(Motor,  port1,           LeftMotor1,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           LeftMotor2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RightMotor1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RightMotor2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           Arm1,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Arm3,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           Arm4,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Claw,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
This program will make the robot move autonomously. The robot will have to go through a maze
with walls on the sides. The gyroscope sensor is going to be used to help the robot turn. The
touch sensor which is a button is used to direct the robot when it hits a wall.
*/

task main()
{
SensorValue[Gyro]=0;	//Sets gyroscope initial value to 0;
wait1Msec(2000);			//waits 2 seconds
int counter = 0;

while(SensorValue[button]==0)
{
motor[LeftMotor1]=64;		//Moves the robot forward while button is not pressed
motor[LeftMotor2]=64;
motor[RightMotor1]=-64;
motor[RightMotor2]=-64;
}

if(SensorValue[button]==1 && counter==0)
{
	while(SensorValue[Gyro]<90)		//Turns right 90 degrees
	{
		motor[LeftMotor1]=25;
		motor[LeftMotor2]=25;
		motor[RightMotor1]=25;
		motor[RightMotor2]=25;
	}
	counter++;								//resets gyroscope value to 0
	SensorValue[Gyro]=0;
	wait1Msec(1000);
}

if(SensorValue[button]==1 && counter==1)
{
	while(SensorValue[Gyro]<180)	//if turning right hit another wall, turns robot 180 around
	{
		motor[LeftMotor1]=-25;
		motor[LeftMotor2]=-25;
		motor[RightMotor1]=-25;
		motor[RightMotor2]=-25;
	}
	counter=0;
	SensorValue[Gyro]=0;
	wait1Msec(1000);
}

}
