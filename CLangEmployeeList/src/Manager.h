/*
 * Manager.h
 *
 *  Created on: May 13, 2014
 *      Author: crlang
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"

class Manager: public Employee {
public:
	Manager();
	Manager(string newName, string newAddress, string newID, string newJobType,
			float newYearSalary);
	virtual ~Manager();
	float getYearSalary();
	void setYearSalary(float newYearSalary);
	virtual float getPay();
private:
	float yearSalary;
};

#endif /* MANAGER_H_ */
