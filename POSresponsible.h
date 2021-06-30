/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class POSresponsible : public Employee {
protected:
	int Actions;

public:
	POSresponsible(string Name, string ID, float BaseSalary, int JobPresent);

	float Employee::CalSalary()const;
	void Print();
	void UpdateAction();
	virtual ~POSresponsible() {};//dtor
};
