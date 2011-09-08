/*
 * RungeKuta.cpp
 *
 *  Created on: 4 sept. 2011
 *      Author: skitoo
 */

#include "RungeKuta.h"

RungeKuta::RungeKuta()
{
	previous = 0;
	val1 = 0;
	val2 = 0;
	val3 = 0;
}

double RungeKuta::update(double angle)
{
	previous += 0.16667 * (val3 + 2 * val2 + 2 * val1 + angle);
	val3 = val2;
	val2 = val1;
	val1 = angle;
	return previous;
}
