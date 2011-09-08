/*
 * BatteryChecker.h
 *
 *  Created on: 21 nov. 2010
 *      Author: skitoo
 */

#include "globals.h"
#include "WProgram.h"

#ifndef BATTERYCHECKER_H_
#define BATTERYCHECKER_H_

class BatteryChecker
{
private:
	unsigned long _lastTime;
public:
	BatteryChecker();
	void update(unsigned long currentTime);
};

#endif /* BATTERYCHECKER_H_ */
