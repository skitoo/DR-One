/*
 * Gyroscop.h
 *
 *  Created on: 23 nov. 2010
 *      Author: skitoo
 */

#include "I2C.h"
#include "globals.h"
#include "WProgram.h"

#ifndef GYROSCOP_H_
#define GYROSCOP_H_

class Gyroscop
{
private:
	int _roll;
	int _pitch;
	int _yaw;
	int _rollStart;
	int _pitchStart;
	int _yawStart;
	bool _slowRoll;
	bool _slowPitch;
	bool _slowYaw;
	byte _buffer[6];
	void _calibrateStartPosition();
public:
	Gyroscop();
	void update();
	int getRoll();
	int getPitch();
	int getYaw();
};

#endif /* GYROSCOP_H_ */
