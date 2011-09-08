/*
 * KalmanFilter.h
 *
 *  Created on: 24 nov. 2010
 *      Author: skitoo
 */

#include "globals.h"

#ifndef KALMANFILTER_H_
#define KALMANFILTER_H_

class KalmanFilter
{
public:
	double P_00;
	double P_01;
	double P_10;
	double P_11;

	double Q_angle;
	double Q_gyro;

	double R_angle;

	double X_angle;
	double X_bias;

	double K_0;
	double K_1;
	double Y;
	double S;

	KalmanFilter();

	double update(double angleGyroscop, double angleAccelerometer, int deltaTime);
};

#endif /* KALMANFILTER_H_ */
