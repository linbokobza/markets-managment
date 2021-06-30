/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

//ctor
Employee::Employee(string Name, string ID, float BaseSalary, int JobPresent) : Name("UNKNOWN"), ID("0"), JobPresent(100), BaseSalary(0) {
	this->Name = Name;
	this->ID = ID;
	this->BaseSalary = BaseSalary;
	this->JobPresent = JobPresent;
};

// prints employee info
 void Employee::Print()const {
	cout << endl << "---------Employee info---------" << endl;

	cout << "Name:" << Name << endl;
	cout << "ID:" << ID << endl;
	cout << "Job present:" << JobPresent << endl;
	cout << "Salary:" << CalSalary() << endl;
	
};