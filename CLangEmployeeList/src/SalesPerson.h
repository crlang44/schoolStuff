/*
 * SalesPerson.h
 *
 *  Created on: May 13, 2014
 *      Author: crlang
 */

#ifndef SALESPERSON_H_
#define SALESPERSON_H_

#include "WageEarner.h"

class SalesPerson: public WageEarner {
public:
	SalesPerson();
	SalesPerson(string newName, string newAddress, string newID, string newJobType, float newWage,
			float newHoursWorked, float newCommission, float newSales);
	virtual ~SalesPerson();
	float getCommission();
	float getSales();
	void setCommission(float newCommission);
	void setSales(float newSales);
	virtual float getPay();
protected:
	float commission;
	float sales;
};

#endif /* SALESPERSON_H_ */
