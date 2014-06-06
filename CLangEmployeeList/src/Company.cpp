/*
 * Company.cpp
 *
 *  Created on: May 12, 2014
 *      Author: chris
 */

#include "Company.h"
#include "Employee.h"


Company::Company() {
	name = "";
	address = "";
	count = 0;
}

Company::Company(string nameIn, string addressIn) {
	name = nameIn;
	address = addressIn;
	count = 0;
}

Company::~Company(){

}

string Company::getAddress() {
	return address;
}
void Company::setAddress(string newAddress) {
	address = newAddress;
}
string Company::getName(){
	return name;
}
void Company::setName(string newName){
	name = newName;
}



