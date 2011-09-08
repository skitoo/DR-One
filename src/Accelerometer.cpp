/*
 * Accelerometer.cpp
 *
 *  Created on: 18 nov. 2010
 *      Author: Alexis Couronne
 */

#include "Accelerometer.h"
#include <math.h>

Accelerometer::Accelerometer()
{
	I2CUpdateRegister(WII_NUNCHUK_I2C_ADDRESS, 0xF0, 0x55);
	delay(100);
	I2CUpdateRegister(WII_NUNCHUK_I2C_ADDRESS, 0xFB, 0x00);
	delay(100);
}

void Accelerometer::update()
{
	I2CRequestData(WII_NUNCHUK_I2C_ADDRESS, 6);

	int i = 0;
	while (I2CHasData())
	{
		_buffer[i++] = I2CReadData();
	}
	I2CSendByte(WII_NUNCHUK_I2C_ADDRESS, 0x00);
	if (i >= 5)
	{
		double x = ((_buffer[2] << 2) + ((_buffer[5] >> 2) & 0x03) - 511) / 1023.0 * PI;
		double y = ((_buffer[3] << 2) + ((_buffer[5] >> 4) & 0x03) - 511) / 1023.0 * PI;
		double z = ((_buffer[4] << 2) + ((_buffer[5] >> 6) & 0x03) - 511) / 1023.0 * PI;

		double xSquared = x * x;
		double ySquared = y * y;
		double zSquared = z * z;

		_angleX = atan2(x, sqrt(ySquared + zSquared));
		_angleY = atan2(y, sqrt(xSquared + zSquared));
	}
}


double Accelerometer::getAngleX()
{
	return _angleX;
}

double Accelerometer::getAngleY()
{
	return _angleY;
}
