/*
 * KalmanFilter.cpp
 *
 *  Created on: 24 nov. 2010
 *      Author: skitoo
 */

#include "KalmanFilter.h"

KalmanFilter::KalmanFilter()
{
	P_00 = 0;
	P_01 = 0;
	P_10 = 0;
	P_11 = 0;

	X_angle = 0;
	X_bias = 0;

	Q_angle = KALMAN_Q_ANGLE;
	Q_gyro = KALMAN_Q_GYRO;
	R_angle = KALMAN_R_ANGLE;
}

double KalmanFilter::update(double angleGyroscop, double angleAccelerometer, int deltaTime)
{
	// Prédiction
	X_angle += deltaTime * (angleGyroscop - X_bias);
	P_00 += -1 * deltaTime * (P_10 + P_01) + deltaTime * deltaTime * P_11 + Q_angle;
	P_01 += -1 * deltaTime * P_11;
	P_10 += -1 * deltaTime * P_11;
	P_11 += Q_gyro;

	// Calcul
	Y = angleAccelerometer - X_angle;
	S = P_00 + R_angle;
	K_0 = P_00 / S;
	K_1 = P_10 / S;

	X_angle += K_0 * Y;
	X_bias += K_1 * Y;

	P_00 -= K_0 * P_00;
	P_01 -= K_0 * P_01;
	P_10 -= K_1 * P_00;
	P_11 -= K_1 * P_01;

	return X_angle;
}
