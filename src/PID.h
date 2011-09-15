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
	float _p, _i, _d;
	float pValue, iValue, dValue;
	float error, integratedError, previousError;
	float derivative;
	float _minIntegratedError, _maxIntegratedError;
public:
	PID(float p, float i, float d, float minIntegratedError, float maxIntegratedError);
	float process(float targetPosition, float currentPosition, float deltaTime);
	void reset();
};

#endif /* PID_H_ */
