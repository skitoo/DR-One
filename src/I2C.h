/*
 * I2C.h
 *
 *  Created on: 18 nov. 2010
 *      Author: Alexis Couronne
 */

#include "WProgram.h"

#ifndef I2C_H_
#define I2C_H_



void I2CSendByte(int deviceAddress, byte data);

void I2CRequestData(int deviceAddress, int length);

byte I2CReadData();

byte I2CHasData();

void I2CUpdateRegister(int deviceAddress, byte dataAddress, byte data);


#endif /* I2C_H_ */
