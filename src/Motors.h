/*
 * Motors.h
 *
 *  Created on: 22 nov. 2010
 *      Author: Alexis Couronne
 */

#include "WProgram.h"
#include "globals.h"

#ifndef MOTORS_H_
#define MOTORS_H_

class Motors
{
private:
	int _topMotorSpeed;
	int _rearMotorSpeed;
	int _leftMotorSpeed;
	int _rightMotorSpeed;

	int _rollCommand;
	int _pitchCommand;
	int _yawCommand;
	int _lastTime;
public:
	Motors();
	void update(unsigned long currentTime);
	void setTopMotorSpeed(int speed);
	void setRearMotorSpeed(int speed);
	void setLeftMotorSpeed(int speed);
	void setRightMotorSpeed(int speed);
	void setGlobalSpeed(int speed);
	void setRollCommand(int command);
	void setPitchCommand(int command);
	void setYawCommand(int command);

	void stopAllMotors();
};

#endif /* MOTORS_H_ */
