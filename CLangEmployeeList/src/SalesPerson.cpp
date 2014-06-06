/*
 * SalesPerson.cpp
 *
 *  Created on: May 13, 2014
 *      Author: crlang
 */

#include "SalesPerson.h"

SalesPerson::SalesPerson() {
	name = "";
	address = "";
	ID = "";
	jobType = "";
	wage = 0;
	hoursWorked = 0;
	commission = 0;
	sales = 0;
}


SalesPerson::SalesPerson(string newName, string newAddress, string newID, string newJobType, float newWage,
		float newHoursWorked, float newCommission, float newSales) {
	name = newName;
	address = newAddress;
	ID = newID;
	jobType = newJobType;
	wage = newWage;
	hoursWorked = newHoursWorked;
	commission = newCommission;
	sales = newSales;
}

SalesPerson::~SalesPerson() {
	// TODO Auto-generated destructor stub
}

float SalesPerson::getCommission(){
	return commission;
}
float SalesPerson::getSales(){
	return sales;
}

void SalesPerson::setCommission(float newCommission){
	commission = newCommission;
}

void SalesPerson::setSales(float newSales){
	sales = newSales;
}

float SalesPerson::getPay(){
	return (wage * hoursWorked) + (commission * sales);
}
