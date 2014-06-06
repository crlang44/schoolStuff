/*
 * Employee.h
 *
 *  Created on: May 12, 2014
 *      Author: chris
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>

using std::string;

class Employee {
public:
	Employee();
	virtual ~Employee();
	string getName();
	string getAddress();
	string getID();
	string getJobType();
	virtual float getPay() = 0;
	void setName(string newName);
	void setAddress(string newAddress);
	void setID(string newID);
	void setJobType(string newJobType);


protected:
	string name;
	string address;
	string ID;
	string jobType;
};

#endif /* EMPLOYEE_H_ */
