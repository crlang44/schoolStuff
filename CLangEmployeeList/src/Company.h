/*
 * Company.h
 *
 *  Created on: May 12, 2014
 *      Author: chris
 */

#ifndef COMPANY_H_
#define COMPANY_H_
#include <string>
#include <vector>
#include "Employee.h"

using std::string;
using std::vector;

class Company {
public:
	Company();
	virtual ~Company();
	Company(string nameIn, string addressIn);
	string getAddress();
	void setAddress(string newAddress);
	string getName();
	void setName(string newName);
	vector<Employee*> employeeList;
	int count;
private:
	string name;
	string address;
};

#endif /* COMPANY_H_ */
