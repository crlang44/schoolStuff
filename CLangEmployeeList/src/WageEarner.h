/*
 * WageEarner.h
 *
 *  Created on: May 13, 2014
 *      Author: crlang
 */

#ifndef WAGEEARNER_H_
#define WAGEEARNER_H_

#include "Employee.h"

class WageEarner: public Employee {
public:
	WageEarner();
	WageEarner(string newName, string newAddress, string newID, string newJobType, float newWage,
			float newHoursWorked);
	virtual ~WageEarner();
	float getWage();
	float getHoursWorked();
	float getPay();
	void setWage(float newWage);
	void setHoursWorked(float newHoursWorked);
protected:
	float wage;
	float hoursWorked;
};

#endif /* WAGEEARNER_H_ */
