/*
 * WageEarner.cpp
 *
 *  Created on: May 13, 2014
 *      Author: crlang
 */

#include "WageEarner.h"

WageEarner::WageEarner() {
	name = "";
	address = "";
	ID = "";
	jobType = "";
	wage = 0;
	hoursWorked = 0;
}

WageEarner::WageEarner(string newName, string newAddress, string newID, string newJobType, float newWage,
		float newHoursWorked) {
	name = newName;
	address = newAddress;
	ID = newID;
	jobType = newJobType;
	wage = newWage;
	hoursWorked = newHoursWorked;
}

WageEarner::~WageEarner() {
	// TODO Auto-generated destructor stub
}

float WageEarner::getWage(){
	return wage;
}
float WageEarner::getHoursWorked(){
	return hoursWorked;
}
float WageEarner::getPay(){
	return wage * hoursWorked;
}

void WageEarner::setWage(float newWage){
	wage = newWage;
}

void WageEarner::setHoursWorked(float newHoursWorked){
	hoursWorked = newHoursWorked;
}
