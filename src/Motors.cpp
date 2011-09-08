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


	stopAllMotors();
	_lastTime = 0;
}

void Motors::update(unsigned long currentTime)
{
	analogWrite(MOTOR_FRONT_PIN, _topMotorSpeed);
	analogWrite(MOTOR_REAR_PIN, _rearMotorSpeed);
	analogWrite(MOTOR_LEFT_PIN, _leftMotorSpeed);
	analogWrite(MOTOR_RIGHT_PIN, _rightMotorSpeed);
}

void Motors::setTopMotorSpeed(int speed)
{
	_topMotorSpeed = speed;
}

void Motors::setRearMotorSpeed(int speed)
{
	_rearMotorSpeed = speed;
}

void Motors::setLeftMotorSpeed(int speed)
{
	_leftMotorSpeed = speed;
}

void Motors::setRightMotorSpeed(int speed)
{
	_rightMotorSpeed = speed;
}

void Motors::setGlobalSpeed(int speed)
{
	_topMotorSpeed = speed;
	_rearMotorSpeed = speed;
	_leftMotorSpeed = speed;
	_rightMotorSpeed = speed;
}

void Motors::stopAllMotors()
{
	setGlobalSpeed(MIN_SPEED_MOTOR);
}
