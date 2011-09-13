/*
 * Motors.cpp
 *
 *  Created on: 22 nov. 2010
 *      Author: Alexis Couronne
 */

#include "Motors.h"

Motors::Motors()
{
	pinMode(MOTOR_FRONT_PIN, OUTPUT);
	pinMode(MOTOR_REAR_PIN, OUTPUT);
	pinMode(MOTOR_LEFT_PIN, OUTPUT);
	pinMode(MOTOR_RIGHT_PIN, OUTPUT);

	//stopAllMotors();
	leftMotorSpeed = MIN_SPEED_MOTOR;
	rightMotorSpeed = MIN_SPEED_MOTOR;
	frontMotorSpeed = MIN_SPEED_MOTOR;
	rearMotorSpeed = MIN_SPEED_MOTOR;
}

void Motors::update()
{
#ifdef DEBUG_MODE
	 Serial.print("MOTOR_TOP:");
	 Serial.print(map(frontMotorSpeed, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR, 0, 100));
	 Serial.print(" MOTOR_REAR:");
	 Serial.print(map(rearMotorSpeed, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR, 0, 100));
	 Serial.print(" MOTOR_LEFT:");
	 Serial.print(map(leftMotorSpeed, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR, 0, 100));
	 Serial.print(" MOTOR_RIGHT:");
	 Serial.print(map(rightMotorSpeed, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR, 0, 100));
	 Serial.print("\n");
#else
	analogWrite(MOTOR_FRONT_PIN, frontMotorSpeed);
	analogWrite(MOTOR_REAR_PIN, rearMotorSpeed);
	analogWrite(MOTOR_LEFT_PIN, leftMotorSpeed);
	analogWrite(MOTOR_RIGHT_PIN, rightMotorSpeed);
#endif
}

void Motors::setFrontMotorSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	frontMotorSpeed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
}

void Motors::setRearMotorSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	rearMotorSpeed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
}

void Motors::setLeftMotorSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	leftMotorSpeed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
}

void Motors::setRightMotorSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	rightMotorSpeed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
}

void Motors::setGlobalSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	speed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
	frontMotorSpeed = speed;
	rearMotorSpeed = speed;
	leftMotorSpeed = speed;
	rightMotorSpeed = speed;
}

void Motors::stopAllMotors()
{
	setGlobalSpeed(0);
}
