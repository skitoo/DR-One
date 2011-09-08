/*
 * PID.cpp
 *
 *  Created on: 28 nov. 2010
 *      Author: skitoo
 */

#include "PID.h"

PID::PID(float p, float i, float d)
{
	P = p;
	I = i;
	D = d;
	integratedError = 0;
	lastPosition = 0;
}


float PID::process(float targetPosition, float currentPosition, int deltaTime)
{
	float error = targetPosition - currentPosition;
	integratedError += error * (deltaTime / 1000);
	integratedError = constrain(integratedError, -WINDUPGUARD, WINDUPGUARD);
	float dTerm = D * (currentPosition - lastPosition) / (deltaTime / 1000);
	lastPosition = currentPosition;
	return P * error + I * integratedError - dTerm;
}

void PID::reset()
{
	integratedError = 0;
}
