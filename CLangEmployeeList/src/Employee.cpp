/*
 * Employee.cpp
 *
 *  Created on: May 12, 2014
 *      Author: chris
 */

#include "Employee.h"


string Employee::getName() {
	return name;
}
string Employee::getAddress() {
	return address;
}
string Employee::getID() {
	return ID;
}
string Employee::getJobType() {
	return jobType;
}

void Employee::setName(string newName){
	name = newName;
}

void Employee::setAddress(string newAddress){
	address = newAddress;
}

void Employee::setID(string newID){
	ID = newID;
}

void Employee::setJobType(string newJobType){
	jobType = newJobType;
}

Employee::Employee() {
	name = "";
	address = "";
	ID = "";
	jobType = "";

}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
}

