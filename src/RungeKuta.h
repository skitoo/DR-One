/*
 * RungeKuta.h
 *
 *  Created on: 4 sept. 2011
 *      Author: skitoo
 */

#ifndef RUNGEKUTA_H_
#define RUNGEKUTA_H_

class RungeKuta
{
private:
	double previous;
	double val1;
	double val2;
	double val3;
public:
	RungeKuta();
	double update(double angle);
};

#endif /* RUNGEKUTA_H_ */
