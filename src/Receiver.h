/*
 * Receiver.h
 *
 *  Created on: 18 nov. 2010
 *      Author: Alexis Couronne
 */

#include "globals.h"

#ifndef RECEIVER_H_
#define RECEIVER_H_

class Receiver
{
private:
	int _throttle;
	int _pitch;
	int _roll;
	int _yaw;

	long _initThrottle;
	long _initPitch;
	long _initRoll;
	long _initYaw;

	long _lastGoodThrottle;
	long _lastGoodPitch;
	long _lastGoodRoll;
	long _lastGoodYaw;

	long _tValue;
	long _pValue;
	long _rValue;
	long _yValue;

	unsigned long _lastTime;

	void updateThrottle();
	void updatePitch();
	void updateRoll();
	void updateYaw();
public:
	Receiver();
	void update(unsigned long currentTime);
	int getThrottle();
	int getPitch();
	int getRoll();
	int getYaw();
};

#endif /* RECEIVER_H_ */
