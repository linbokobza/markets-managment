/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
	string Name;
	string ID;
	int JobPresent;
	float BaseSalary;

public:
	Employee(string Name, string ID, float BaseSalary, int JobPresent);

	string GetEmployeeID() { return ID; }
	virtual float CalSalary()const = 0;
	virtual void Print()const;
	virtual ~Employee() {};//dtor
};