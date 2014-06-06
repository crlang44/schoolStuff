//============================================================================
// Name        : CLangEmployee.cpp
// Author      : Chris Lang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

#include "Company.h"
#include "Employee.h"
#include "Manager.h"
#include "SalesPerson.h"
#include "WageEarner.h"

/*
 using std::cout;
 using std::cin;

 using std::vector;
 */
using namespace std;

void createCompany(Company &company);
void createEmployee(Company &company);
void deleteEmployee(Company &company);
void displayEmployee(Company &company);
void editEmployee(Company &company);
void displayAll(Company &company);
void displayPayroll(Company &company);
void writeToFile(Company &company);
void readFromFile(Company &company);
void writeAllToFile(Company &company);
void writePayrollToFile(Company &company);

int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	int commandNum;
	Company company;
	cout << "Welcome to the Employee Payroll Program" << endl;
	cout << endl;

	do {
		cout << "Menu" << endl;
		cout << "*************************************************" << endl;
		cout << "1. Create/Edit the Company Info" << endl;
		cout << "2. Create an Employee" << endl;
		cout << "3. Delete an Employee" << endl;
		cout << "4. Display individual Employee" << endl;
		cout << "5. Edit and Employee's info" << endl;
		cout << "6. Display all data to the screen" << endl;
		cout << "7. Display the payroll to the screen" << endl;
		cout << "8. Read Company and Employee data from a file" << endl;
		cout << "9. Write Company and Employee data to a file" << endl;
		cout << "10. Write all data to a file" << endl;
		cout << "11. Write payroll to a file" << endl;
		cout << "12. Quit" << endl;
		cout << "*************************************************" << endl;
		cout << "Enter a command number: ";
		cin >> commandNum;
		cout << endl;
		switch (commandNum) {
		case 1: // Create/Edit the Company Info
			createCompany(company);
			break;
		case 2: // Create an Employee
			createEmployee(company);
			break;
		case 3: // Delete an Employee
			deleteEmployee(company);
			break;
		case 4: // Display individual Employee
			displayEmployee(company);
			break;
		case 5: // Edit an Employee's info
			editEmployee(company);
			break;
		case 6: // Display all data to the screen
			displayAll(company);
			break;
		case 7: // Display the payroll to the screen
			displayPayroll(company);
			break;
		case 8: // Read Company and Employee data from a file
			readFromFile(company);
			break;
		case 9: // Write Company and Employee data to a file
			writeToFile(company);
			break;
		case 10: // Write all data to the screen
			writeAllToFile(company);
			break;
		case 11: // Write payroll to file
			writePayrollToFile(company);
			break;
		case 12: // Quit
			break;
		default:
			cin.ignore(1000, '\n');
			cin.ignore();
			cout << "Enter a valid command!" << endl;
			commandNum = 1; // Set commandNum to an arbitrary value to prevent infinite loop
			break;
		}
	} while (commandNum != 12);
}

/**********************************************************************************************/
/*								Begin Function Section						   				  */
/**********************************************************************************************/

/////////////////////////////////////////////////////////////////
//				Create Company								   //
/////////////////////////////////////////////////////////////////
void createCompany(Company &company) {
	string newAddress;
	string newName;
	int commandNum;
	if (company.getName() != "") {
		do {
			cout << "1. Set the Address" << endl;
			cout << "2. Set the Name" << endl;
			cout << "3. Return to Main Menu" << endl;
			cout << endl;
			cout << "Enter a command number: ";
			cin >> commandNum;
			switch (commandNum) {
			case 1: // Update the Company's Address
				cin.ignore(1000, '\n');
				cout << "Enter the new address: ";
				getline(cin, newAddress);
				cout << endl;
				company.setAddress(newAddress);
				break;
			case 2: // Update the Company's Name
				cin.ignore(1000, '\n');
				cout << "Enter the new name: ";
				getline(cin, newName);
				cout << endl;
				company.setAddress(newName);
				break;
			case 3:
				break;
			default:
				cout << "Enter a valid command!" << endl;
			}
		} while (commandNum != 3);
	} else {
		cout << "Set the Company Name: ";
		cin.ignore(1000, '\n');
		getline(cin, newName);
		company.setName(newName);
		cout << "Set the Company Address: ";
		getline(cin, newAddress);
		company.setAddress(newAddress);

	}
	cout << "Company info has been updated." << endl;
	cout << endl;
}

/////////////////////////////////////////////////////////////////
//				Create Employee								   //
/////////////////////////////////////////////////////////////////

void createEmployee(Company &company) {
	int commandNum = 0;

	Manager *manager;
	WageEarner *wageEarner;
	SalesPerson *salesPerson;

	string newName;
	string newAddress;
	string newID;
	string newJobType;
	float newYearSalary;
	float newWage;
	float newHoursWorked;
	float newCommision;
	float newSales;

	cout << "1. Manager" << endl;
	cout << "2. Wage Earner" << endl;
	cout << "3. Sales Person" << endl;
	cout << "4. Return to Main Menu" << endl;
	cout << endl;
	cout << "Enter a command number: ";
	cin >> commandNum;
	if (commandNum == 4)
		return;
	cout << "Enter the employee's name: ";
	cin.ignore(1000, '\n');
	getline(cin, newName);
	cout << "Enter the employee's address: ";
	getline(cin, newAddress);
	cout << "Enter the employee's ID: ";
	getline(cin, newID);
	switch (commandNum) {
	case 1: // Make a Manager Employee and add it to employeeList
		newJobType = "Manager";
		cout << "Enter the employee's year salary: ";
		cin >> newYearSalary;
		manager = new Manager(newName, newAddress, newID, newJobType,
				newYearSalary);
		company.employeeList.push_back(manager);
		company.count++;
		break;
	case 2: // Make a Wage Earner Employee and add it to employeeList
		newJobType = "WageEarner";
		cout << "Enter the employee's wage: ";
		cin >> newWage;
		cout << "Enter the employee's hours worked: ";
		cin >> newHoursWorked;
		wageEarner = new WageEarner(newName, newAddress, newID, newJobType,
				newWage, newHoursWorked);
		company.employeeList.push_back(wageEarner);
		company.count++;
		break;
	case 3: // Make a Sales Person Employee and add it to employeeList
		newJobType = "Salesperson";
		cout << "Enter the employee's wage: ";
		cin >> newWage;
		cout << "Enter the employee's hours worked: ";
		cin >> newHoursWorked;
		cout << "Enter the employee's commision: ";
		cin >> newCommision;
		cout << "Enter the employee's sales: ";
		cin >> newSales;
		salesPerson = new SalesPerson(newName, newAddress, newID, newJobType,
				newWage, newHoursWorked, newCommision, newSales);
		company.employeeList.push_back(salesPerson);
		company.count++;
		break;
	case 4: // Return to main menu, do nothing
		break;
	default:
		cout << "Enter a valid command!" << endl;
	}
	cout << "The employee has been created." << endl;
	cout << endl;
}

/////////////////////////////////////////////////////////////////
//				Delete Employee								   //
/////////////////////////////////////////////////////////////////

void deleteEmployee(Company &company) {
	int ndx;
	string idToFind;

	cout << "Enter the ID of the employee to edit: ";
	cin >> idToFind;
	for (ndx = 0; ndx < company.count; ndx++) {
		if (company.employeeList[ndx]->getID() == idToFind) {
			company.employeeList.erase(company.employeeList.begin() + ndx);
			company.count--;
			cout << "The Employee has been deleted." << endl;
			return;
		}
	}
	cout << "You did not enter a valid ID!" << endl;
}

/////////////////////////////////////////////////////////////////
//				Display Employee							   //
/////////////////////////////////////////////////////////////////

void displayEmployee(Company &company) {
	int ndx;
	string idToFind;
	string employeeType;
	cout << "Enter the ID of the employee to display: ";
	cin >> idToFind;

	for (ndx = 0; ndx < company.count; ndx++) {
		if (company.employeeList[ndx]->getID() == idToFind) {
			cout << "Name: " << company.employeeList[ndx]->getName() << endl;
			cout << "Address:" << company.employeeList[ndx]->getAddress()
					<< endl;
			cout << "ID: " << company.employeeList[ndx]->getID() << endl;
			employeeType = company.employeeList[ndx]->getJobType();
			cout << "Job Type: " << employeeType << endl;
			Employee *ref = company.employeeList.at(ndx);
			if (employeeType == "Manager") {
				Manager *m = static_cast<Manager*> (ref);
				cout << "Year Salary: " << m->getYearSalary() << endl;
			} else if (employeeType == "WageEarner") {
				WageEarner *w = static_cast<WageEarner*> (ref);
				cout << "5. Wage: " << w->getWage() << endl;
				cout << "6. Hours Worked: " << w->getHoursWorked() << endl;
			} else if (employeeType == "Salesperson") {
				SalesPerson *s = static_cast<SalesPerson*> (ref);
				cout << "Wage: " << s->getWage() << endl;
				cout << "Hours Worked: " << s->getHoursWorked() << endl;
				cout << "Commision: " << s->getCommission() << endl;
				cout << "Sales: " << s->getSales() << endl;
			} else {
				cout << "Error 101: Consult the programmer." << endl;
			}
			cout << endl;
			return;
		}
	}
	cout << "The employee does not exist!" << endl;
	return;

}

/////////////////////////////////////////////////////////////////
//				Edit Employee								   //
/////////////////////////////////////////////////////////////////

void editEmployee(Company &company) {
	int ndx, commandNum;
	string idToFind, newStringAttribute, employeeType, tempName, tempAddress,
			tempID;
	cout << "Enter the ID of the employee to edit: ";
	cin >> idToFind;
	cout << endl;

	for (ndx = 0; ndx < company.count; ndx++) {
		if (company.employeeList[ndx]->getID() == idToFind) {

			employeeType = company.employeeList[ndx]->getJobType();
			Employee *ref = company.employeeList.at(ndx);

			Manager *manager;
			WageEarner *wageEarner;
			SalesPerson *salesPerson;

			SalesPerson *s = static_cast<SalesPerson*> (ref);

			string newJobType;

			// Print the Menu for editing each employee type
			cout << "What field would you like to edit for this employee?"
					<< endl;
			cout << "1. Name" << endl;
			cout << "2. Address" << endl;
			cout << "3. ID" << endl;
			cout << "4. Job Type" << endl;
			if (employeeType == "Manager") {
				cout << "5. Year Salary " << endl;
			} else if (employeeType == "WageEarner") {
				cout << "5. Wage " << endl;
				cout << "6. Hours Worked " << endl;
			} else if (employeeType == "Salesperson") {
				cout << "5. Wage " << endl;
				cout << "6. Hours Worked " << endl;
				cout << "7. Commision " << endl;
				cout << "8. Sales " << endl;
			} else {
				cout << "Error 102: Consult the programmer." << endl;
			}

			cout << "Enter a command number: ";
			cin >> commandNum;

			switch (commandNum) {
			case 1:
				cout << "Enter the employee's name: ";
				cin.ignore(1000, '\n');
				getline(cin, newStringAttribute);
				ref->setName(newStringAttribute);

				break;
			case 2:
				cout << "Enter the employee's address: ";
				getline(cin, newStringAttribute);
				ref->setAddress(newStringAttribute);
				break;
			case 3:
				cout << "Enter the employee's ID: ";
				getline(cin, newStringAttribute);
				ref->setID(newStringAttribute);
				break;
			case 4:
				cout << "What would you like the new job type to be?" << endl;
				cout << "1. Manager" << endl;
				cout << "2. Wage Earner" << endl;
				cout << "3. Sales Person" << endl;
				cout << endl;
				cout << "Enter a command number: ";
				cin >> commandNum;

				tempName = ref->getName();
				tempAddress = ref->getAddress();
				tempID = ref->getID();

				switch (commandNum) {
				case 1: // Change to Manager
					float newYearSalary;
					newJobType = "Manager";
					cout << "What is the new employee's salary: ";
					cin >> newYearSalary;
					company.employeeList.erase(company.employeeList.begin()
							+ ndx);
					manager = new Manager(tempName, tempAddress, tempID,
							newJobType, newYearSalary);
					company.employeeList.push_back(manager);
					break;
				case 2: // Change to WageEarner
					// Change from Manager to wageEarner
					newJobType = "WageEarner";
					if (ref->getJobType() == "Manager") {
						float newWage, newHoursWorked;
						cout << "Enter the employee's wage: ";
						cin >> newWage;
						cout << "Enter the employee's hours worked: ";
						cin >> newHoursWorked;
						company.employeeList.erase(company.employeeList.begin()
								+ ndx);
						wageEarner = new WageEarner(tempName, tempAddress,
								tempID, newJobType, newWage, newHoursWorked);
						company.employeeList.push_back(wageEarner);
					} else if (ref->getJobType() == "Salesperson") {
						//Change from SalesPerson to wageEarner
						SalesPerson *s = static_cast<SalesPerson*> (ref);
						float tempWage, tempHoursWorked;
						cout << "Enter a new wage";
						cin >> tempWage;
						cout << "Enter new hours worked";
						cin >> tempHoursWorked;
						company.employeeList.erase(company.employeeList.begin()
								+ ndx);
						wageEarner = new WageEarner(tempName, tempAddress,
								tempID, newJobType, tempWage, tempHoursWorked);
						company.employeeList.push_back(wageEarner);
					}
					break;
				case 3:// Change to Sales Person
					//Cange from manager to Sales Person
					float newCommission, newSales;
					newJobType = "Salesperson";
					if (ref->getJobType() == "Manager") {
						float newWage, newHoursWorked;
						cout << "Enter the employee's wage: ";
						cin >> newWage;
						cout << "Enter the employee's hours worked: ";
						cin >> newHoursWorked;
						cout << "Enter the employee's commision: ";
						cin >> newCommission;
						cout << "Enter the employee's sales: ";
						cin >> newSales;
						company.employeeList.erase(company.employeeList.begin()
								+ ndx);
						salesPerson = new SalesPerson(tempName, tempAddress,
								tempID, newJobType, newWage, newHoursWorked,
								newCommission, newSales);
						company.employeeList.push_back(salesPerson);
					} else if (ref->getJobType() == "WageEarner") {
						//Change from wageEarner to salesPerson
						float tempWage, tempHoursWorked;
						WageEarner *w = static_cast<WageEarner*> (ref);
						cout << "Enter the employee's wage";
						cin >> tempWage;
						cout << "Enter the employee's hours worked";
						cin >> tempHoursWorked;
						cout << "Enter the employee's commision: ";
						cin >> newCommission;
						cout << "Enter the employee's sales: ";
						cin >> newSales;
						company.employeeList.erase(company.employeeList.begin()
								+ ndx);
						salesPerson = new SalesPerson(tempName, tempAddress,
								tempID, newJobType, tempWage, tempHoursWorked,
								newCommission, newSales);
						company.employeeList.push_back(salesPerson);
					}
					break;
				default:
					cout << "Error 103: Consult the programmer." << endl;
					break;
				}

				break;
			case 5: //Edit wage/salary
				float newSalary, newWage;
				if (employeeType == "Manager") {
					Manager *m = static_cast<Manager*> (ref);
					cout << "Enter the employee's new salary: ";
					cin >> newSalary;
					m->setYearSalary(newSalary);
				} else if (employeeType == "WageEarner") {
					WageEarner *w = static_cast<WageEarner*> (ref);
					cout << "Enter the employee's new wage: ";
					cin >> newWage;
					w->setWage(newWage);
				} else if (employeeType == "Salesperson") {
					SalesPerson *s = static_cast<SalesPerson*> (ref);
					cout << "Enter the employee's new wage: ";
					cin >> newWage;
					s->setWage(newWage);
				} else {
					cout << "Error 104: Consult the programmer." << endl;
				}
				break;
			case 6: //Edit hoursWorked
				float newHoursWorked;
				if (employeeType == "WageEarner") {
					WageEarner *w = static_cast<WageEarner*> (ref);
					cout << "Enter the employee's new hours worked: ";
					cin >> newHoursWorked;
					w->setHoursWorked(newHoursWorked);
				} else if (employeeType == "Salesperson") {
					SalesPerson *s = static_cast<SalesPerson*> (ref);
					cout << "Enter the employee's new hours worked: ";
					cin >> newHoursWorked;
					s->setHoursWorked(newHoursWorked);
				} else {
					cout << "Error 105: Consult the programmer." << endl;
				}
				break;
			case 7: //Edit commission
				float newCommission;
				cout << "Enter the employee's new commission: ";
				cin >> newCommission;
				s->setCommission(newCommission);
				break;
			case 8: //Edit sales
				float newSales;
				cout << "Enter the employee's new sales: ";
				cin >> newSales;
				s->setSales(newSales);
				break;
			default:
				cout << "Error 106: Consult the programmer." << endl;
				break;
			}
			return;
		}
	}
}

/////////////////////////////////////////////////////////////////
//				Print All Data To Screen					   //
/////////////////////////////////////////////////////////////////

void displayAll(Company &company) {
	int ndx;
	cout << left; // Set the output alignment to the left
	cout << "Company: " << company.getName() << ", " << company.getAddress()
			<< endl;
	cout << endl;
	cout << setw(15) << "ID#" << setw(15) << "Type" << setw(20) << "Name"
			<< setw(20) << "Wage Information" << endl
			<< "-------------------------------------------------------------------"
			<< endl;
	for (ndx = 0; ndx < company.count; ndx++) {
		string employeeType = company.employeeList[ndx]->getJobType();
		Employee *ref = company.employeeList.at(ndx);
		cout << setw(15) << company.employeeList.at(ndx)->getID();
		if (employeeType == "Manager") {
			Manager *m = static_cast<Manager*> (ref);
			cout << setw(15) << "Manager" << setw(20)
					<< company.employeeList.at(ndx)->getName() << "$";
			cout << m->getYearSalary() << endl;
		} else if (employeeType == "WageEarner") {
			WageEarner *w = static_cast<WageEarner*> (ref);
			cout << setw(15) << "Hourly" << setw(20)
					<< company.employeeList.at(ndx)->getName() << "$";
			cout << w->getWage() << "/" << w->getHoursWorked() << endl;
		} else if (employeeType == "Salesperson") {
			SalesPerson *s = static_cast<SalesPerson*> (ref);
			cout << setw(15) << "Sales" << setw(20) << company.employeeList.at(
					ndx)->getName() << "$";
			cout << s->getWage() << "/" << s->getHoursWorked() << "/"
					<< (s->getCommission() * 100) << "%/" << s->getSales()
					<< endl;
		} else {
			cout << "Error 107: Consult the programmer." << endl;
		}
	}
	cout << endl;
}

/////////////////////////////////////////////////////////////////
//				Print Payroll To Screen						   //
/////////////////////////////////////////////////////////////////

void displayPayroll(Company &company) {
	int ndx;
	float pay, totalPay;
	cout << left; // Set the output alignment to the left
	cout << "Company: " << company.getName() << ", " << company.getAddress()
			<< endl;
	cout << endl;
	cout << setw(15) << "ID#" << setw(20) << "Name" << setw(15) << "Payroll"
			<< endl
			<< "-------------------------------------------------------------------"
			<< endl;
	for (ndx = 0; ndx < company.count; ndx++) {
		string employeeType = company.employeeList[ndx]->getJobType();
		Employee *ref = company.employeeList.at(ndx);
		cout << setw(15) << ref->getID() << setw(20) << ref->getName() << "$";
		if (employeeType == "Manager") {
			Manager *m = static_cast<Manager*> (ref);
			pay = m->getPay();
			cout << pay << endl;
		} else if (employeeType == "WageEarner") {
			WageEarner *w = static_cast<WageEarner*> (ref);
			pay = w->getPay();
			cout << pay << endl;
		} else if (employeeType == "Salesperson") {
			SalesPerson *s = static_cast<SalesPerson*> (ref);
			pay = s->getPay();
			cout << pay << endl;
		} else {
			cout << "Error 108: Consult the programmer." << endl;
		}
		totalPay += pay;
	}
	cout << setw(35) << "Total Payroll" << "$" << totalPay << endl;
	cout << endl;

}

/////////////////////////////////////////////////////////////////
//					Write To File							   //
/////////////////////////////////////////////////////////////////
void writeToFile(Company &company) {
	int ndx;
	float pay;
	ofstream myFile;
	string fileName;
	cout << "Enter the file to write to: ";
	cin >> fileName;
	cout << endl;
	myFile.open(fileName.c_str());
	myFile << company.getName() << endl;
	myFile << company.getAddress() << endl;
	myFile << company.count << endl;
	myFile << "+++" << endl;
	for (ndx = 0; ndx < company.count; ndx++) {
		Employee *ref = company.employeeList.at(ndx);
		myFile << ref->getID() << endl;
		myFile << "(" << endl;
		myFile << ref->getJobType() << endl;
		myFile << ref->getName() << endl;
		myFile << ref->getAddress() << endl;
		string employeeType = ref->getJobType();
		if (employeeType == "Manager") {
			Manager *m = static_cast<Manager*> (ref);
			pay = m->getYearSalary();
			myFile << pay << endl;
		} else if (employeeType == "WageEarner") {
			WageEarner *w = static_cast<WageEarner*> (ref);
			pay = w->getWage();
			myFile << pay << endl;
			myFile << w->getHoursWorked() << endl;
		} else if (employeeType == "Salesperson") {
			SalesPerson *s = static_cast<SalesPerson*> (ref);
			pay = s->getWage();
			myFile << pay << endl;
			myFile << s->getHoursWorked() << endl;
			myFile << s->getCommission() << endl;
			myFile << s->getSales() << endl;
		} else {
			cout << "Error 109: Consult the programmer." << endl;
		}
		myFile << ")" << endl;
	}
	myFile.close();
}

/////////////////////////////////////////////////////////////////
//					Read From File							   //
/////////////////////////////////////////////////////////////////
void readFromFile(Company &company) {
	ifstream myFile;
	string fileName;
	string companyAddress, companyName, buffer;
	int companyCount, ndx;
	string eID, eJobType, eName, eAddress;
	float ePay, eHoursWorked, eCommission, eSales;
	cout << "Enter the file to read from: ";
	cin >> fileName;
	cout << endl;
	myFile.open(fileName.c_str());
	getline(myFile, companyName);
	getline(myFile, companyAddress);
	myFile >> companyCount;
	company.setAddress(companyAddress);
	company.setName(companyName);
	getline(myFile, buffer);
	for (ndx = 0; ndx < companyCount; ndx++) {
		getline(myFile, buffer); //+++
		getline(myFile, eID);
		getline(myFile, buffer); // (
		getline(myFile, eJobType);
		getline(myFile, eName);
		getline(myFile, eAddress);
		myFile >> ePay;
		if (eJobType == "WageEarner") {
			myFile >> eHoursWorked;
			WageEarner* wageEarner = new WageEarner(eName, eAddress, eID,
					eJobType, ePay, eHoursWorked);
			company.employeeList.push_back(wageEarner);
			company.count++;
		} else if (eJobType == "Salesperson") {
			myFile >> eHoursWorked;
			myFile >> eCommission;
			myFile >> eSales;

			SalesPerson* salesPerson = new SalesPerson(eName, eAddress, eID,
					eJobType, ePay, eHoursWorked, eCommission, eSales);
			company.employeeList.push_back(salesPerson);
			company.count++;
		} else {
			Manager* manager =
					new Manager(eName, eAddress, eID, eJobType, ePay);
			company.employeeList.push_back(manager);
			company.count++;
		}
		getline(myFile, buffer); // )
	}
	myFile.close();

}

/////////////////////////////////////////////////////////////////
//					Write All To File						   //
/////////////////////////////////////////////////////////////////
void writeAllToFile(Company &company) {
	int ndx;
	ofstream myFile;
	string fileName;
	cout << "Enter the file to write to: ";
	cin >> fileName;
	cout << endl;
	myFile.open(fileName.c_str());
	myFile << left; // Set the output alignment to the left
	myFile << "Company: " << company.getName() << ", " << company.getAddress()
			<< endl;
	myFile << endl;
	myFile << setw(15) << "ID#" << setw(15) << "Type" << setw(20) << "Name"
			<< setw(20) << "Wage Information" << endl
			<< "-------------------------------------------------------------------"
			<< endl;
	for (ndx = 0; ndx < company.count; ndx++) {
		string employeeType = company.employeeList[ndx]->getJobType();
		Employee *ref = company.employeeList.at(ndx);
		myFile << setw(15) << company.employeeList.at(ndx)->getID();
		if (employeeType == "Manager") {
			Manager *m = static_cast<Manager*> (ref);
			myFile << setw(15) << "Manager" << setw(20)
					<< company.employeeList.at(ndx)->getName() << "$";
			myFile << m->getYearSalary() << endl;
		} else if (employeeType == "WageEarner") {
			WageEarner *w = static_cast<WageEarner*> (ref);
			myFile << setw(15) << "Hourly" << setw(20)
					<< company.employeeList.at(ndx)->getName() << "$";
			myFile << w->getWage() << "/" << w->getHoursWorked() << endl;
		} else if (employeeType == "Salesperson") {
			SalesPerson *s = static_cast<SalesPerson*> (ref);
			myFile << setw(15) << "Sales" << setw(20)
					<< company.employeeList.at(ndx)->getName() << "$";
			myFile << s->getWage() << "/" << s->getHoursWorked() << "/"
					<< (s->getCommission() * 100) << "%/" << s->getSales()
					<< endl;
		} else {
			cout << "Error 110: Consult the programmer." << endl;
		}
	}
	myFile << endl;
	myFile.close();
}

/////////////////////////////////////////////////////////////////
//					Read From File							   //
/////////////////////////////////////////////////////////////////

void writePayrollToFile(Company &company) {
	int ndx;
	ofstream myFile;
	string fileName;
	cout << "Enter the file to write to: ";
	cin >> fileName;
	cout << endl;
	myFile.open(fileName.c_str());
	float pay, totalPay;
	myFile << left; // Set the output alignment to the left
	myFile << "Company: " << company.getName() << ", " << company.getAddress()
			<< endl;
	myFile << endl;
	myFile << setw(15) << "ID#" << setw(20) << "Name" << setw(15) << "Payroll"
			<< endl
			<< "-------------------------------------------------------------------"
			<< endl;
	for (ndx = 0; ndx < company.count; ndx++) {
		string employeeType = company.employeeList[ndx]->getJobType();
		Employee *ref = company.employeeList.at(ndx);
		myFile << setw(15) << ref->getID() << setw(20) << ref->getName() << "$";
		if (employeeType == "Manager") {
			Manager *m = static_cast<Manager*> (ref);
			pay = m->getPay();
			myFile << pay << endl;
		} else if (employeeType == "WageEarner") {
			WageEarner *w = static_cast<WageEarner*> (ref);
			pay = w->getPay();
			myFile << pay << endl;
		} else if (employeeType == "Salesperson") {
			SalesPerson *s = static_cast<SalesPerson*> (ref);
			pay = s->getPay();
			myFile << pay << endl;
		} else {
			cout << "Error 111: Consult the programmer." << endl;
		}
		totalPay += pay;
	}
	myFile << setw(35) << "Total Payroll" << "$" << totalPay << endl;
	myFile << endl;
	myFile.close();
}

/**********************************************************************************************/
/*								End of Function Section						   				  */
/**********************************************************************************************/
