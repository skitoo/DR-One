/*
 * globals.cpp
 *
 *  Created on: 5 sept. 2011
 *      Author: skitoo
 */

#include "globals.h"

double rad2deg(double rad)
{
	return rad * 57.2957795;
}

double deg2rad(double deg)
{
	return deg * 0.0174532925;
}

float filterSmooth(float currentData, float previousData, float factor)
{
	if (factor != 1.0)
		return (previousData * (1.0 - factor) + (currentData * factor));
	else
		return currentData;
}
