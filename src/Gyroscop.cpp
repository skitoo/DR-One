/*
 * Gyroscop.cpp
 *
 *  Created on: 23 nov. 2010
 *      Author: skitoo
 */

#include "Gyroscop.h"

Gyroscop::Gyroscop()
{
	I2CUpdateRegister(WII_GYRO_I2C_START_ADDRESS, 0xfe, 0x04);
	_calibrateStartPosition();
}

void Gyroscop::_calibrateStartPosition()
{
	long roll = 0;
	long pitch = 0;
	long yaw = 0;

	for (int i = 0; i < WII_GYRO_CALIBRATE_ITERATION; i++)
	{
		I2CSendByte(WII_GYRO_I2C_ADDRESS, 0x00);
		I2CRequestData(WII_GYRO_I2C_ADDRESS, 6);
		for (int j = 0; j < 6; j++)
		{
			_buffer[j] = I2CReadData();
		}
		yaw += (((_buffer[3] >> 2) << 8) + _buffer[0]);
		roll += (((_buffer[4] >> 2) << 8) + _buffer[1]);
		pitch += (((_buffer[5] >> 2) << 8) + _buffer[2]);
	}
	_rollStart = roll / WII_GYRO_CALIBRATE_ITERATION;
	_pitchStart = pitch / WII_GYRO_CALIBRATE_ITERATION;
	_yawStart = yaw / WII_GYRO_CALIBRATE_ITERATION;
}

void Gyroscop::update()
{
	I2CSendByte(WII_GYRO_I2C_ADDRESS, 0x00);
	I2CRequestData(WII_GYRO_I2C_ADDRESS, 6);
	for (int j = 0; j < 6; j++)
	{
		_buffer[j] = I2CReadData();
	}
	_yaw = (((_buffer[3] >> 2) << 8) + _buffer[0]);
	_roll = (((_buffer[4] >> 2) << 8) + _buffer[1]);
	_pitch = (((_buffer[5] >> 2) << 8) + _buffer[2]);

	_slowPitch = _buffer[3] & 1;
	_slowYaw = _buffer[3] & 2;
	_slowRoll = _buffer[4] & 2;

	_yaw -= _yawStart;
	_pitch -= _pitchStart;
	_roll -= _rollStart;

	_yaw   = _yaw / (_slowYaw ? WII_GYRO_SLOW_SENSIVITY : WII_GYRO_FAST_SENSIVITY);
	_pitch = -(_pitch / (_slowPitch ? WII_GYRO_SLOW_SENSIVITY : WII_GYRO_FAST_SENSIVITY));
	_roll  = -(_roll / (_slowRoll ? WII_GYRO_SLOW_SENSIVITY : WII_GYRO_FAST_SENSIVITY));

}

int Gyroscop::getRoll()
{
	return _roll;
}

int Gyroscop::getPitch()
{
	return _pitch;
}

int Gyroscop::getYaw()
{
	return _yaw;
}
