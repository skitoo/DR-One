#include "main.h"
#include "globals.h"

#include "Motors.h"
#include "Receiver.h"
#include "Sensors.h"
#include "PID.h"
#include "BatteryChecker.h"



Sensors *sensors;
Receiver *receiver;
Motors *motors;
BatteryChecker *batteryChecker;
PID *rollPid;
PID *pitchPid;
PID *yawPid;



unsigned long currentTime;
unsigned long lastTime;
double deltaTime;

void setup()
{
	Serial.begin(9600);

	//batteryChecker = new BatteryChecker();
	//receiver = new Receiver();
	sensors = new Sensors();

	rollPid = new PID(PID_ROLL_P, PID_ROLL_I, PID_ROLL_D);
	pitchPid = new PID(PID_PITCH_P, PID_PITCH_I, PID_PITCH_D);
	yawPid = new PID(PID_YAW_P, PID_YAW_I, PID_YAW_D);

	lastTime = millis();
}

void loop()
{
	currentTime = millis();
	deltaTime = (currentTime - lastTime) * 0.001;

	if(deltaTime >= 0.01)
	{
		lastTime = currentTime;

		//batteryChecker->update(currentTime);
		//receiver->update(currentTime);
		sensors->update(deltaTime);
	}
}
