/*
 * Accelerometer.h
 *
 *  Created on: 18 nov. 2010
 *      Author: Alexis Couronne
 */

#include "WProgram.h"
#include "I2C.h"
#include "globals.h"

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

class Accelerometer
{
private:
	double _angleX;
	double _angleY;
	byte _buffer[6];
public:
	Accelerometer();
	void update();
	double getAngleX();
	double getAngleY();
};

#endif /* ACCELEROMETER_H_ */
