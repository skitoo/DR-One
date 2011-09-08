/*
 * Drone.cpp
 *
 *  Created on: 19 nov. 2010
 *      Author: Alexis Couronne
 */

#include "Drone.h"

Drone::Drone()
{
	//motors   = new Motors();
	//receiver = new Receiver();
	sensors = new Sensors();
	/*
	 rollPID = new PID(PID_ROLL_P, PID_ROLL_I, PID_ROLL_D);
	 pitchPID = new PID(PID_PITCH_P, PID_PITCH_I, PID_PITCH_D);
	 yawPID = new PID(PID_YAW_P, PID_YAW_I, PID_YAW_D);
	 */
	//batteryChecker = new BatteryChecker();

}

void Drone::update(unsigned long currentTime)
{
	sensors->update(currentTime);


	//receiver->update(currentTime);
	//motors->setGlobalSpeed(map(receiver->getThrottle(), 0, 100, MIN_SPEED_MOTOR, MAX_SPEED_MOTOR));
	//motors->update(currentTime);

	//batteryChecker->update(currentTime);
}
