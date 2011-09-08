/*
 * BatteryChecker.cpp
 *
 *  Created on: 21 nov. 2010
 *      Author: skitoo
 */

#include "BatteryChecker.h"

const float VOLTAGE_FACTOR  = 5.0 / 1023;
const float BRIDGE_FACTOR = 2.0 / 3;

BatteryChecker::BatteryChecker()
{
	pinMode(BATTERY_MONITOR_HALF_EMPTY_LED_PIN, OUTPUT);
	pinMode(BATTERY_MONITOR_EMPTY_LED_PIN, OUTPUT);
	_lastTime = 0;
}

void BatteryChecker::update(unsigned long currentTime)
{
	if (currentTime >= _lastTime + BATTERY_CHECK_LOOP_TIME)
	{
		_lastTime = currentTime;
		int batteryMonitorValue = analogRead(A0);
		float currentVoltage = (VOLTAGE_FACTOR * batteryMonitorValue) / BRIDGE_FACTOR ;

		if (currentVoltage > BATTERY_HALF_EMPTY_VALUE)
		{
			digitalWrite(BATTERY_MONITOR_EMPTY_LED_PIN, LOW);
			digitalWrite(BATTERY_MONITOR_HALF_EMPTY_LED_PIN, LOW);
		}
		else if (currentVoltage > BATTERY_EMPTY_VALUE)
		{
			digitalWrite(BATTERY_MONITOR_EMPTY_LED_PIN, LOW);
			digitalWrite(BATTERY_MONITOR_HALF_EMPTY_LED_PIN, HIGH);
		}
		else
		{
			digitalWrite(BATTERY_MONITOR_EMPTY_LED_PIN, HIGH);
			digitalWrite(BATTERY_MONITOR_HALF_EMPTY_LED_PIN, LOW);
		}
	}
}
