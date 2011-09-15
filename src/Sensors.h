/*
 * Sensors.h
 *
 *  Created on: 23 nov. 2010
 *      Author: skitoo
 */

#include "Accelerometer.h"
#include "Gyroscop.h"
#include "KalmanFilter.h"
#include "RungeKuta.h"
#include <Wire.h>

#ifndef SENSORS_H_
#define SENSORS_H_

class Sensors
{
private:
	Accelerometer *_accelerometer;
	Gyroscop *_gyroscop;
	KalmanFilter *_rollKalman;
	KalmanFilter *_pitchKalman;
	KalmanFilter *_yawKalman;
	RungeKuta *_rungeKuta;
	double _rollAngle;
	double _pitchAngle;
	double _yawAngle, _previousYawAngle, _yawVelocity;
	double _previousRoll, _previousPitch, _previousYaw;
	void switchToAccelerometer();
	void switchToGyroscop();
public:
	Sensors();
	void update(float currentTime);
	double rollAngle();
	double pitchAngle();
	double yawAngle();
	double yawVelocity();
	Gyroscop* getGyro();
};

#endif /* SENSORS_H_ */
