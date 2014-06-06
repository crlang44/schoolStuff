/*
 * Manager.cpp
 *
 *  Created on: May 13, 2014
 *      Author: crlang
 */

#include "Manager.h"

Manager::Manager() {
	name = "";
	address = "";
	ID = "";
	jobType = "";
	yearSalary = 0;
}

Manager::Manager(string newName, string newAddress, string newID, string newJobType, float newYearSalary) {
	name = newName;
	address = newAddress;
	ID = newID;
	jobType = newJobType;
	yearSalary = newYearSalary;
}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}

float Manager::getYearSalary(){
	return yearSalary;
}

void Manager::setYearSalary(float newYearSalary){
	yearSalary = newYearSalary;
}

float Manager::getPay(){
	return yearSalary / 52;
}
