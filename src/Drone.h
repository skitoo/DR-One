/*
 * Drone.h
 *
 *  Created on: 19 nov. 2010
 *      Author: skitoo
 */

#include "Motors.h"
#include "Receiver.h"
#include "Sensors.h"
#include "PID.h"
#include "BatteryChecker.h"

#include "globals.h"

#include "WProgram.h"

#ifndef DRONE_H_
#define DRONE_H_

class Drone
{
private:
	Motors *motors;
	Receiver *receiver;
	Accelerometer *accelerometer;
	Sensors *sensors;
	BatteryChecker *batteryChecker;

	PID *rollPID;
	PID *pitchPID;
	PID *yawPID;
public:
	Drone();
	void update(unsigned long currentTime);
};

#endif /* DRONE_H_ */
