/*
 * constants.h
 *
 *  Created on: 18 nov. 2010
 *      Author: Alexis Couronne
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define DEBUG_MODE

// TIMING ------------------------ //

#define RECEIVER_LOOP_TIME 20
#define CONTROL_LOOP_TIME 2
#define BATTERY_CHECK_LOOP_TIME 1000

// RECEIVER ---------------------- //

#define RECEIVER_THROTTLE_PIN 4
#define RECEIVER_PITCH_PIN    5
#define RECEIVER_ROLL_PIN     6
#define RECEIVER_YAW_PIN	  7


// MOTORS ------------------------ //

#define MOTOR_FRONT_PIN 3
#define MOTOR_REAR_PIN 9
#define MOTOR_LEFT_PIN 10
#define MOTOR_RIGHT_PIN 11

#define MIN_SPEED_MOTOR 124
#define MAX_SPEED_MOTOR 250


// SENSORS ----------------------- //

#define WII_NUNCHUK_PIN_ACTIVATION 2
#define WII_GYRO_PIN_ACTIVATION 8

#define WII_NUNCHUK_I2C_ADDRESS 0x52
#define WII_GYRO_I2C_START_ADDRESS 0x53
#define WII_GYRO_I2C_ADDRESS 0x52

#define WII_GYRO_CALIBRATE_ITERATION 100

#define WII_GYRO_SLOW_SENSIVITY 20
#define WII_GYRO_FAST_SENSIVITY  4

#define KALMAN_Q_GYRO  0.1
#define KALMAN_Q_ANGLE 0.002
#define KALMAN_R_ANGLE 0.3


// BATTERY MONITOR ---------------- //

#define BATTERY_MONITOR_HALF_EMPTY_LED_PIN 12
#define BATTERY_MONITOR_EMPTY_LED_PIN 13
#define BATTERY_MONITOR_PIN A0

#define BATTERY_FULL_VALUE 7.5
#define BATTERY_HALF_EMPTY_VALUE 6.85
#define BATTERY_EMPTY_VALUE 6.2


// PID ---------------------------- //

#define PID_ROLL_P 1.5
#define PID_ROLL_I 0.0
#define PID_ROLL_D 0.05

#define PID_PITCH_P 1.5
#define PID_PITCH_I 0.0
#define PID_PITCH_D 0.05

#define PID_YAW_P 3.0
#define PID_YAW_I 0.05
#define PID_YAW_D 0.0


#define WINDUPGUARD 1000



// FUNCTIONS ------------------------- //

double rad2deg(double rad);

double deg2rad(double deg);


#endif /* CONSTANTS_H_ */
