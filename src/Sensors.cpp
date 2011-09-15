/*
 * Sensors.cpp
 *
 *  Created on: 23 nov. 2010
 *      Author: skitoo
 */

#include "Sensors.h"

Sensors::Sensors()
{
	_rollKalman  = new KalmanFilter();
	_pitchKalman = new KalmanFilter();
	_yawKalman   = new KalmanFilter();
	_rungeKuta   = new RungeKuta();

	pinMode(WII_GYRO_PIN_ACTIVATION, OUTPUT);
	pinMode(WII_NUNCHUK_PIN_ACTIVATION, OUTPUT);

	digitalWrite(WII_GYRO_PIN_ACTIVATION, LOW);
	digitalWrite(WII_NUNCHUK_PIN_ACTIVATION, LOW);

	Wire.begin();

	switchToAccelerometer();
	_accelerometer = new Accelerometer();

	switchToGyroscop();
	_gyroscop = new Gyroscop();

	_yawVelocity = 0;
	_previousYawAngle = 0;

	_previousRoll = 0;
	_previousPitch = 0;
	_previousYaw = 0;
}

void Sensors::update(float deltaTime)
{

	switchToGyroscop();
	_gyroscop->update();
	switchToAccelerometer();
	_accelerometer->update();

	_rollAngle  = _rollKalman->update(deg2rad(_gyroscop->getRoll()), _accelerometer->getAngleX(), deltaTime);
	_pitchAngle = _pitchKalman->update(deg2rad(_gyroscop->getPitch()), _accelerometer->getAngleY(), deltaTime);
	_yawAngle   = _rungeKuta->update(deg2rad(_gyroscop->getYaw()) * deltaTime);

	_rollAngle = filterSmooth(_rollAngle, _previousRoll, 0.5);
	_previousRoll = _rollAngle;
	_pitchAngle = filterSmooth(_pitchAngle, _previousPitch, 0.5);
	_previousPitch = _pitchAngle;
	_yawAngle = filterSmooth(_yawAngle, _previousYaw, 0.5);
	_previousYaw = _yawAngle;

	_yawVelocity = (_yawAngle - _previousYawAngle) / deltaTime;
	_previousYawAngle = _yawAngle;

#ifdef DEBUG_MODE
	Serial.print("ACCELEROMTER_X:");
	Serial.print(_accelerometer->getAngleX());
	Serial.print(" ACCELEROMTER_Y:");
	Serial.print(_accelerometer->getAngleY());
	Serial.print(" GYRO_Roll:");
	Serial.print(_gyroscop->getRoll());
	Serial.print(" GYRO_Pitch:");
	Serial.print(_gyroscop->getPitch());
	Serial.print(" GYRO_Yaw:");
	Serial.print(_gyroscop->getYaw());
	Serial.print(" SENSORS_Roll:");
	Serial.print(_rollAngle);
	Serial.print(" SENSORS_Pitch:");
	Serial.print(_pitchAngle);
	Serial.print(" SENSORS_Yaw:");
	Serial.print(_yawAngle);
	Serial.print("\n");
#endif
}

void Sensors::switchToGyroscop()
{
	digitalWrite(WII_NUNCHUK_PIN_ACTIVATION, LOW);
	digitalWrite(WII_GYRO_PIN_ACTIVATION, HIGH);
}

void Sensors::switchToAccelerometer()
{
	digitalWrite(WII_GYRO_PIN_ACTIVATION, LOW);
	digitalWrite(WII_NUNCHUK_PIN_ACTIVATION, HIGH);
}

double Sensors::rollAngle()
{
	return rad2deg(_rollAngle);
}

double Sensors::pitchAngle()
{
	return rad2deg(_pitchAngle);
}

double Sensors::yawAngle()
{
	return rad2deg(_yawAngle);
}

double Sensors::yawVelocity()
{
	return rad2deg(_yawVelocity);
}

Gyroscop* Sensors::getGyro()
{
	return _gyroscop;
}
