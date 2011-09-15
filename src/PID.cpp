/*
 * PID.cpp
 *
 *  Created on: 28 nov. 2010
 *      Author: skitoo
 */

#include "PID.h"

PID::PID(float p, float i, float d, float minIntegratedError, float maxIntegratedError)
{
	_p = p;
	_i = i;
	_d = d;
	_minIntegratedError = minIntegratedError;
	_maxIntegratedError = maxIntegratedError;
	error = 0.0;
	integratedError = 0.0;
	previousError = 0.0;
	pValue = 0.0;
	iValue = 0.0;
	dValue = 0.0;
	derivative = 0.0;
}


float PID::process(float targetPosition, float currentPosition, float deltaTime)
{
	// P value
	error = targetPosition - currentPosition;
	pValue = error * _p;

	// I value
	integratedError += error * deltaTime;
	integratedError = constrain(integratedError, _minIntegratedError, _maxIntegratedError);
	iValue = integratedError * _i;

	// D value
	derivative = (error - previousError) / deltaTime;
	previousError = error;
	dValue = derivative * _d;

	return pValue + iValue + dValue;
}

void PID::reset()
{
	integratedError = 0.0;
}
