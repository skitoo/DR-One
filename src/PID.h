/*
 * PID.h
 *
 *  Created on: 28 nov. 2010
 *      Author: skitoo
 */

#include "globals.h"
#include "WProgram.h"

#ifndef PID_H_
#define PID_H_

class PID
{
private:
	float P, I, D;
	float lastPosition;
	float integratedError;
public:
	PID(float p, float i, float d);
	float process(float targetPosition, float currentPosition, int deltaTime);
	void reset();
};

#endif /* PID_H_ */
