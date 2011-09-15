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
unsigned long lastTime, lastTimeReceiver;
double deltaTime, deltaTimeReceiver;

double cmdRoll;
double cmdPitch;
double cmdYaw;
bool armed;


void setup()
{
#ifdef DEBUG_MODE
	Serial.begin(115200);
#endif

	batteryChecker = new BatteryChecker();
	receiver = new Receiver();
	sensors = new Sensors();
	motors = new Motors();

	rollPid = new PID(PID_ROLL_P, PID_ROLL_I, PID_ROLL_D, MIN_INTEGRATED_ERROR, MAX_INTEGRATED_ERROR);
	pitchPid = new PID(PID_PITCH_P, PID_PITCH_I, PID_PITCH_D, MIN_INTEGRATED_ERROR, MAX_INTEGRATED_ERROR);
	yawPid = new PID(PID_YAW_P, PID_YAW_I, PID_YAW_D, MIN_INTEGRATED_ERROR, MAX_INTEGRATED_ERROR);

	lastTime = millis();
	lastTimeReceiver = millis();
	armed = false;
}

void loop()
{
	currentTime = millis();
	deltaTime = (currentTime - lastTime) * 0.001;
	deltaTimeReceiver = (currentTime - lastTimeReceiver) * 0.001;

	if (!armed)
	{
		batteryChecker->update(currentTime, armed);
		motors->stopAllMotors();
		motors->update();
		receiver->update(currentTime);
		if (receiver->getThrottle() == 0)
		{
			armed = true;
			delay(2000);
			return;
		}
	}

	batteryChecker->update(currentTime, armed);

	if (deltaTimeReceiver >= 0.02)
	{
		lastTimeReceiver = currentTime;
		receiver->update(currentTime);
	}
	if (deltaTime >= 0.1)
	{
		lastTime = currentTime;
		sensors->update(deltaTime);

		cmdRoll = rollPid->process(receiver->getRollAngle(), sensors->rollAngle(), deltaTime);
		cmdPitch = pitchPid->process(receiver->getPitchAngle(), sensors->pitchAngle(), deltaTime);
		cmdYaw = yawPid->process(receiver->getYawAngularVelocity(), sensors->yawVelocity(), deltaTime);

#ifdef PLUS_MODE
		motors->setFrontMotorSpeed(receiver->getThrottle() - cmdPitch - cmdYaw);
		motors->setRearMotorSpeed(receiver->getThrottle() + cmdPitch - cmdYaw);
		motors->setLeftMotorSpeed(receiver->getThrottle() - cmdRoll + cmdYaw);
		motors->setRightMotorSpeed(receiver->getThrottle() + cmdRoll + cmdYaw);
#elif defined X_MODE
		motors->setFrontMotorSpeed(receiver->getThrottle() - cmdPitch + cmdRoll - cmdYaw);
		motors->setRearMotorSpeed(receiver->getThrottle() + cmdPitch - cmdRoll - cmdYaw);
		motors->setLeftMotorSpeed(receiver->getThrottle() + cmdPitch + cmdRoll + cmdYaw);
		motors->setRightMotorSpeed(receiver->getThrottle() - cmdPitch - cmdRoll + cmdYaw);
#endif
		if (receiver->getThrottle() == 0)
		{
			motors->stopAllMotors();
		}
		motors->update();

#ifdef DEBUG_MODE
		Serial.print("PID_ROLL:");
		Serial.print(cmdRoll);
		Serial.print(" PID_PITCH:");
		Serial.print(cmdPitch);
		Serial.print(" PID_YAW:");
		Serial.print(cmdYaw);
		Serial.print("\n");
#endif
	}
}
