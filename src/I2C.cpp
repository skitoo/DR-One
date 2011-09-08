/*
 * I2C.c
 *
 *  Created on: 18 nov. 2010
 *      Author: Alexis Couronne
 */

#include "WProgram.h"
#include <Wire.h>

void I2CSendByte(int deviceAddress, byte data)
{
	Wire.beginTransmission(deviceAddress);
	Wire.send(data);
	Wire.endTransmission();
}

void I2CUpdateRegister(int deviceAddress, byte dataAddress, byte data)
{
	Wire.beginTransmission(deviceAddress);
	Wire.send(dataAddress);
	Wire.send(data);
	Wire.endTransmission();
}

void I2CRequestData(int deviceAddress, int length)
{
	Wire.requestFrom(deviceAddress, length);
}

byte I2CReadData()
{
	return Wire.receive();
}

byte I2CHasData()
{
	return Wire.available();
}

