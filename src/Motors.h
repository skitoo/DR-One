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
	int frontMotorSpeed;
	int rearMotorSpeed;
	int leftMotorSpeed;
	int rightMotorSpeed;
public:
	Motors();
	void update();
	void setFrontMotorSpeed(int speed);
	void setRearMotorSpeed(int speed);
	void setLeftMotorSpeed(int speed);
	void setRightMotorSpeed(int speed);
	void setGlobalSpeed(int speed);
	/*
	void setRollCommand(int command);
	void setPitchCommand(int command);
	void setYawCommand(int command);*/

	void stopAllMotors();
};

#endif /* MOTORS_H_ */
