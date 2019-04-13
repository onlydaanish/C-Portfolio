/*
 Name:		RunawayRobot.ino
 Created:	10/28/2015 3:07:13 PM
 Author:	Daanish Bhamla
*/

#include <AddicoreRFID.h>
#include <SPI.h>
#include "Header.h"

USSensor uLeft, uMiddle, uRight;
Motors Right, Left;


float sData[10] = { 0 }, Sum = 0;;
int sDataCounter = 0;
int Blastn = 4; //5x
int OneDig = 0, TwoDig = 0, ThreeDig = 0;

int RevDel= 350;
int Speed = 180;
int WallDist = 3;

int bLED = 26; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer
bool ON = false;
bool sON = false;

int MotionPin = 11, MotionLED = 12;

using namespace std;
void setup() 
{
	//Set BlueTooth Pin
	pinMode(bLED, OUTPUT);
	Serial.begin(9600);       // start serial communication at 9600bps

	//Set Pin Numbers
	uLeft.TrigPin = 2; uLeft.EchoPin = 3; uLeft.LedPin = 8;
	uMiddle.TrigPin = 4; uMiddle.EchoPin = 5; uMiddle.LedPin = 9;
	uRight.TrigPin = 6; uRight.EchoPin = 7; uRight.LedPin = 10;

	pinMode(uLeft.TrigPin, OUTPUT); pinMode(uLeft.EchoPin, INPUT); pinMode(uLeft.LedPin, OUTPUT);
	pinMode(uMiddle.TrigPin, OUTPUT); pinMode(uMiddle.EchoPin, INPUT); pinMode(uMiddle.LedPin, OUTPUT);
	pinMode(uRight.TrigPin, OUTPUT); pinMode(uRight.EchoPin, INPUT); pinMode(uRight.LedPin, OUTPUT);

	//Motor
	Right.Enable = 22; Left.Enable = 24;
	digitalWrite(Right.Enable, HIGH);
	digitalWrite(Left.Enable, HIGH);
	
	Right.A = 46;  Right.B = 47;
	Left.A = 44; Left.B = 49;

	pinMode(Right.Enable, OUTPUT); pinMode(Right.A, OUTPUT); pinMode(Right.B, OUTPUT);
	pinMode(Left.Enable, OUTPUT); pinMode(Left.A, OUTPUT); pinMode(Left.B, OUTPUT);

	//Motion Sensor
	pinMode(MotionPin, INPUT);
	pinMode(MotionLED, OUTPUT);

	Serial.println("PinMode's Set!");
}

void loop()
{
	if (Serial.available())
	{
		BluetoothData = Serial.read();
		if (BluetoothData == '1')
		{
			ON = true;
			digitalWrite(bLED, HIGH);
			Serial.println("ON!");
			//BrakeMotor("b");
		}
		else if (BluetoothData == '0')
		{
			ON = false;
			sON = false;
			digitalWrite(bLED, LOW);
			Serial.println("OFF!");
			BrakeMotor("b");

			digitalWrite(uRight.LedPin, LOW);
			digitalWrite(uLeft.LedPin, LOW);
			digitalWrite(uMiddle.LedPin, LOW);
		}
		else if (BluetoothData == '2')
		{
			sON = true;
			Serial.println("Motion Sensing!");
		}
	}

	if (sON)
	{
		if (digitalRead(MotionPin) == HIGH)
		{
			//Motor Straight
			digitalWrite(uRight.LedPin, LOW);
			digitalWrite(uLeft.LedPin, LOW);
			digitalWrite(uMiddle.LedPin, HIGH);
			Motor(1, Speed);
			delay(2000);
			BrakeMotor("b");
			digitalWrite(uRight.LedPin, LOW);
			digitalWrite(uLeft.LedPin, LOW);
			digitalWrite(uMiddle.LedPin, LOW);
		}
		delay(1000);
	}

	if (ON && ScanMotion())
	{
		if (ScanMotion() && GetMidDistance())
		{
			if (uMiddle.Avg < 30 && uMiddle.Avg > WallDist)
			{
				BrakeMotor("b");
				delay(250);
				GetDistance();
				if (uLeft.Avg < WallDist || uRight.Avg < WallDist)
				{
					Motor(4, 255); //BackWards Were against a Wall...
					Serial.println("Reversing!");
				}
				else if (uLeft.Avg > uRight.Avg)
				{
						Serial.println("Turning Left!");
						digitalWrite(uLeft.LedPin, HIGH);
						digitalWrite(uRight.LedPin, LOW);
						digitalWrite(uMiddle.LedPin, LOW);
						// Turn Motor to Left
						Motor(3, Speed);
				}
				else if (uLeft.Avg < uRight.Avg)
				{
					Serial.println("Turning Right!");
					digitalWrite(uRight.LedPin, HIGH);
					digitalWrite(uLeft.LedPin, LOW);
					digitalWrite(uMiddle.LedPin, LOW);
					//Turn Motor to Right
					Motor(2, Speed);
				}
			}
			else
			{
				GetDistance();
				if (uMiddle.Avg < WallDist || uLeft.Avg < WallDist || uRight.Avg < WallDist)
				{
					Motor(4, 255); //BackWards Were against a Wall...
					Serial.println("Reversing!");
				}
				
				//Motor Straight
				digitalWrite(uRight.LedPin, LOW);
				digitalWrite(uLeft.LedPin, LOW);
				digitalWrite(uMiddle.LedPin, HIGH);
				Motor(1, Speed);
			}
		}
		else
		{
			//Turn off All LED's
			digitalWrite(uLeft.LedPin, LOW);
			digitalWrite(uRight.LedPin, LOW);
			digitalWrite(uMiddle.LedPin, LOW);
		}
	}
	else
	{
		BrakeMotor("b");
		digitalWrite(uLeft.LedPin, LOW);
		digitalWrite(uRight.LedPin, LOW);
		digitalWrite(uMiddle.LedPin, LOW);
	}
	delay(50);
}

bool ScanMotion()
{
	if (digitalRead(MotionPin) == HIGH)
	{
		digitalWrite(MotionLED, HIGH);
		return true;
	}
	else
	{
		digitalWrite(MotionLED, LOW);
		return false;
	}
}

bool GetMidDistance()
{
	for (int i = 0; i <= Blastn; i++)
	{
		uMiddle.Distance[i] = CalcDistance(uMiddle, i);
		//delay(5);
	}
	Serial.println("Middle Distances Calculated!");
	uMiddle.Avg = AvgDistance(uMiddle);
	if (uMiddle.Avg < 0)
	{
		Serial.println("Middle Sensor ZERO!!!");
		return false;
	}

	Serial.println("Middle Sensor: ");
	Serial.println(uMiddle.Avg);
	Serial.println("");
	return true;
}

bool GetDistance()
{
	for (int i = 0; i <= Blastn; i++)
	{
		uRight.Distance[i] = CalcDistance(uRight, i);
		//delay(5);
	}
	for (int i = 0; i <= Blastn; i++)
	{
		uLeft.Distance[i] = CalcDistance(uLeft, i);
		//delay(5);
	}
	
	Serial.println("Distances Calculated!");

	uLeft.Avg = AvgDistance(uLeft);
	delay(5);
	uRight.Avg = AvgDistance(uRight);
	
	Serial.println("Averages Calculated!");

	Serial.println("Right Sensor: ");
	Serial.println(uRight.Avg);
	Serial.println("Left Sensor: ");
	Serial.println(uLeft.Avg);
	Serial.println("");

	delay(10);
}

int CalcDistance(USSensor x, int i)
{
	//Middle Sensor
	digitalWrite(x.TrigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(x.TrigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(x.TrigPin, LOW);
	x.Duration[i] = pulseIn(x.EchoPin, HIGH);
	digitalWrite(x.EchoPin, LOW);
	return (x.Duration[i] / 74 / 2);
}

float AvgDistance(USSensor x)
{
	for (int i = 0; i <= Blastn; i++)
	{
		sData[i] = 0;
		//delay(5);
	}
	sDataCounter = 0;
	OneDig = 0; TwoDig = 0; ThreeDig = 0;

	for (int i = 0; i <= Blastn; i++)
	{
		if (x.Distance[i] >= 0 && x.Distance[i] <= 9)
			OneDig++;

		if (x.Distance[i] >= 10 && x.Distance[i] <= 99)
			TwoDig++;

		if (x.Distance[i] >= 100 && x.Distance[i] <= 999)
			ThreeDig++;

		//delay(5);
	}
///////////////////////////ONE DIGITS ARE MAX////////////////////////////
	if (OneDig > TwoDig && OneDig > ThreeDig)
	{
		for (int i = 0; i <= Blastn; i++)
		{
			if (x.Distance[i] >= 0 && x.Distance[i] <= 9)
			{
				sData[sDataCounter] = x.Distance[i];
				sDataCounter++;
			}
			//delay(5);
		}
		Sum = 0;
		for (int i = 0; i <= sDataCounter; i++)
		{
			Sum += sData[i];
			delay(5);
		}		
		return Sum / sDataCounter;
	}
/////////////////////////////TWO DIGITS ARE MAX//////////////////////////////////
	else if (TwoDig > OneDig && TwoDig > ThreeDig)
	{
		for (int i = 0; i <= Blastn; i++)
		{
			if (x.Distance[i] >= 10 && x.Distance[i] <= 99)
			{
				sData[sDataCounter] = x.Distance[i];
				sDataCounter++;
			}
			//delay(5);
		}
		Sum = 0;
		for (int i = 0; i <= sDataCounter; i++)
		{
			Sum += sData[i];
			//delay(5);
		}
		return Sum / sDataCounter;
	}
//////////////////////////////THREE DIGITS ARE MAX/////////////////////////////////////
	else if (ThreeDig > OneDig && ThreeDig > TwoDig)
	{
		for (int i = 0; i <= Blastn; i++)
		{
			if (x.Distance[i] >= 100 && x.Distance[i] <= 999)
			{
				sData[sDataCounter] = x.Distance[i];
				sDataCounter++;
			}
			delay(5);
		}
		Sum = 0;
		for (int i = 0; i <= sDataCounter; i++)
		{
			Sum += sData[i];
			delay(5);
		}
		return Sum / sDataCounter;
	}

	return 0;
}

int Motor(int Direction, int Speed)
{
	if (Direction == 1) // For
	{
		digitalWrite(Left.A, HIGH);
		digitalWrite(Left.B, LOW);
		digitalWrite(Right.A, HIGH);
		digitalWrite(Right.B, LOW);
		analogWrite(Left.A, Speed);
		analogWrite(Right.A, Speed);
	}
	else if (Direction == 3) // Left
	{
		digitalWrite(Left.A, LOW);
		digitalWrite(Left.B, HIGH);
		digitalWrite(Right.A, HIGH);
		digitalWrite(Right.B, LOW);
		delay(200);
		BrakeMotor("b");
		Motor(1, Speed);
	}
	else if (Direction == 2) //Right
	{
		digitalWrite(Left.A, HIGH);
		digitalWrite(Left.B, LOW);
		digitalWrite(Right.A, LOW);
		digitalWrite(Right.B, HIGH);
		delay(200);
		BrakeMotor("b");
		Motor(1, Speed);
	}
	else if (Direction == 4)
	{
		BrakeMotor("b");
		digitalWrite(Left.A, LOW);
		digitalWrite(Left.B, HIGH);
		digitalWrite(Right.A, LOW);
		digitalWrite(Right.B, HIGH);
		delay(500);
		digitalWrite(Left.A, HIGH);
		digitalWrite(Left.B, LOW);
		digitalWrite(Right.A, LOW);
		digitalWrite(Right.B, HIGH);
		delay(RevDel);
		Motor(1, Speed);
	}
}

int BrakeMotor(String X)
{
	if (X == "b")
	{
		digitalWrite(Right.A, HIGH);
		digitalWrite(Right.B, HIGH);
		digitalWrite(Left.A, HIGH);
		digitalWrite(Left.B, HIGH);
	}
	if (X == "r")
	{
		digitalWrite(Right.A, HIGH);
		digitalWrite(Right.B, HIGH);
	}

	if (X == "l")
	{
		digitalWrite(Left.A, HIGH);
		digitalWrite(Left.B, HIGH);
	}
}
