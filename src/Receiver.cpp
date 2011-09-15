/*
 * Receiver.cpp
 *
 *  Created on: 18 nov. 2010
 *      Author: Alexis Couronne
 */
#include "WProgram.h"

#include "Receiver.h"

Receiver::Receiver()
{
	pinMode(RECEIVER_THROTTLE_PIN, INPUT);
	pinMode(RECEIVER_PITCH_PIN, INPUT);
	pinMode(RECEIVER_ROLL_PIN, INPUT);
	pinMode(RECEIVER_YAW_PIN, INPUT);

	_lastTime = 0;

	_initThrottle = pulseIn(RECEIVER_THROTTLE_PIN, HIGH);
	_initPitch = pulseIn(RECEIVER_PITCH_PIN, HIGH);
	_initRoll = pulseIn(RECEIVER_ROLL_PIN, HIGH);
	_initYaw = pulseIn(RECEIVER_YAW_PIN, HIGH);

	_lastGoodPitch = _initPitch;
	_lastGoodRoll = _initRoll;
	_lastGoodThrottle = _initThrottle;
	_lastGoodYaw = _initYaw;

	_lastPitch = 0;
	_lastRoll = 0;
	_lastYaw = 0;
	_lastThrottle = 0;
}

void Receiver::update(unsigned long currentTime)
{
	if (currentTime >= _lastTime + RECEIVER_LOOP_TIME)
	{
		_lastTime = currentTime;

		updateThrottle();
		updateRoll();
		updatePitch();
		updateYaw();

#ifdef DEBUG_MODE
		Serial.print("RECEIVER_THROTTLE:");
		Serial.print(_throttle);
		Serial.print(" RECEIVER_PITCH:");
		Serial.print(_pitch);
		Serial.print(" RECEIVER_ROLL:");
		Serial.print(_roll);
		Serial.print(" RECEIVER_YAW:");
		Serial.print(_yaw);
		Serial.print("\n");
#endif
	}
}

void Receiver::updateThrottle()
{
	_tValue = pulseIn(RECEIVER_THROTTLE_PIN, HIGH, 20000);
	if (_tValue == 0)
		_tValue = _lastGoodThrottle;
	else
		_lastGoodThrottle = _tValue;

	_throttle = constrain((_tValue - _initThrottle) * 0.167, 0, 100);
	_throttle = filterSmooth(_throttle, _lastThrottle, 0.8);
	_lastThrottle = _throttle;
}

void Receiver::updatePitch()
{
	_pValue = pulseIn(RECEIVER_PITCH_PIN, HIGH, 25000);
	if (_pValue == 0)
		_pValue = _lastGoodPitch;
	else
		_lastGoodPitch = _pValue;

	_pitch = constrain((_pValue - _initPitch) * 0.167 * 2 - 1, -100, 100);
	_pitch = filterSmooth(_pitch, _lastPitch, 0.8);
	_lastPitch = _pitch;
}

void Receiver::updateRoll()
{
	_rValue = pulseIn(RECEIVER_ROLL_PIN, HIGH, 25000);//20000
	if (_rValue == 0)
		_rValue = _lastGoodRoll;
	else
		_lastGoodRoll = _rValue;

	_roll = (_rValue - _initRoll) * 0.167;
	if (_roll < 0)
	{
		_roll *= 1.5151;
	}
	else
	{
		_roll *= 1.7543;
	}
	//_roll++;
	_roll = constrain(_roll, -100, 100);
	_roll = filterSmooth(_roll, _lastRoll, 0.8);
	_lastRoll = _roll;
}

void Receiver::updateYaw()
{
	_yValue = pulseIn(RECEIVER_YAW_PIN, HIGH, 25000);//20000
	if (_yValue == 0)
		_yValue = _lastGoodYaw;
	else
		_lastGoodYaw = _yValue;

	_yaw = constrain((_yValue - _initYaw) * 0.167 * 1.66666, -100, 100);
	_yaw = filterSmooth(_yaw, _lastYaw, 0.8);
	_lastYaw = _yaw;
}

int Receiver::getThrottle()
{
	return _throttle;
}

int Receiver::getPitch()
{
	return _pitch;
}

int Receiver::getRoll()
{
	return _roll;
}

int Receiver::getYaw()
{
	return _yaw;
}

float Receiver::getRollAngle()
{
	return map(_roll, -100, 100, MIN_RECEIVER_ANGLE, MAX_RECEIVER_ANGLE);
}

float Receiver::getPitchAngle()
{
	return map(_pitch, -100, 100, MIN_RECEIVER_ANGLE, MAX_RECEIVER_ANGLE);
}

float Receiver::getYawAngularVelocity()
{
	return map(_yaw, -100, 100, -MAX_ANGULAR_VELOCITY, MAX_ANGULAR_VELOCITY);
}
