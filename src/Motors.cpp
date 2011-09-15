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
	previousFront = MIN_SPEED_MOTOR;
	previousRear = MIN_SPEED_MOTOR;
	previousLeft = MIN_SPEED_MOTOR;
	previousRight = MIN_SPEED_MOTOR;
	stopAllMotors();
	update();
}

void Motors::update()
{
#ifdef DEBUG_MODE
	Serial.print("MOTOR_TOP:");
	Serial.print(frontMotorSpeed);
	Serial.print(" MOTOR_REAR:");
	Serial.print(rearMotorSpeed);
	Serial.print(" MOTOR_LEFT:");
	Serial.print(leftMotorSpeed);
	Serial.print(" MOTOR_RIGHT:");
	Serial.print(rightMotorSpeed);
	Serial.print("\n");
#endif
	analogWrite(MOTOR_FRONT_PIN, frontMotorSpeed);
	analogWrite(MOTOR_REAR_PIN, rearMotorSpeed);
	analogWrite(MOTOR_LEFT_PIN, leftMotorSpeed);
	analogWrite(MOTOR_RIGHT_PIN, rightMotorSpeed);
}

void Motors::setFrontMotorSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	frontMotorSpeed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
	frontMotorSpeed = filterSmooth(frontMotorSpeed, previousFront, 0.8);
	previousFront = frontMotorSpeed;
}

void Motors::setRearMotorSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	rearMotorSpeed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
	rearMotorSpeed = filterSmooth(rearMotorSpeed, previousRear, 0.8);
	previousRear = rearMotorSpeed;
}

void Motors::setLeftMotorSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	leftMotorSpeed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
	leftMotorSpeed = filterSmooth(leftMotorSpeed, previousLeft, 0.8);
	previousLeft = leftMotorSpeed;
}

void Motors::setRightMotorSpeed(int speed)
{
	speed = constrain(speed, 0, 100);
	rightMotorSpeed = map(speed, 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR);
	rightMotorSpeed = filterSmooth(rightMotorSpeed, previousRight, 0.8);
	previousRight = rightMotorSpeed;
}

void Motors::setGlobalSpeed(int speed)
{
	setFrontMotorSpeed(speed);
	setRearMotorSpeed(speed);
	setLeftMotorSpeed(speed);
	setRightMotorSpeed(speed);
}

void Motors::stopAllMotors()
{
	/*
	frontMotorSpeed = MIN_SPEED_MOTOR;
	rearMotorSpeed = MIN_SPEED_MOTOR;
	leftMotorSpeed = MIN_SPEED_MOTOR;
	rightMotorSpeed = MIN_SPEED_MOTOR;*/
	setGlobalSpeed(0);
}
