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
}

void Receiver::update(unsigned long currentTime)
{
	if (currentTime >= _lastTime + RECEIVER_LOOP_TIME)
	{
		_lastTime = currentTime;

		updateThrottle();
		updatePitch();
		updateRoll();
		updateYaw();

#ifdef DEBUG_MODE
		/*
		Serial.print("RECEIVER_THROTTLE:");
		Serial.print(_throttle);
		Serial.print(" RECEIVER_PITCH:");
		Serial.print(_pitch);
		Serial.print(" RECEIVER_ROLL:");
		Serial.print(_roll);
		Serial.print(" RECEIVER_YAW:");
		Serial.print(_yaw);
		Serial.print("\n");*/
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
}

void Receiver::updatePitch()
{
	_pValue = pulseIn(RECEIVER_PITCH_PIN, HIGH, 25000);
	if (_pValue == 0)
		_pValue = _lastGoodPitch;
	else
		_lastGoodPitch = _pValue;

	_pitch = constrain((_pValue - _initPitch) * 0.167, -100, 100);
}

void Receiver::updateRoll()
{
	_rValue = pulseIn(RECEIVER_ROLL_PIN, HIGH, 20000);
	if (_rValue == 0)
		_rValue = _lastGoodRoll;
	else
		_lastGoodRoll = _rValue;

	_roll = constrain((_rValue - _initRoll) * 0.167, -100, 100);
}

void Receiver::updateYaw()
{
	_yValue = pulseIn(RECEIVER_YAW_PIN, HIGH, 20000);
	if (_yValue == 0)
		_yValue = _lastGoodYaw;
	else
		_lastGoodYaw = _yValue;

	_yaw = constrain((_yValue - _initYaw) * 0.167, -100, 100);
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
