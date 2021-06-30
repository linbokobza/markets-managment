/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;


class LowSeller : public Employee {
protected:
	float* ShoppingTotalList;
	int ShoppingTotalAmount;

public:

	LowSeller(string Name, string ID, float BaseSalary, int JobPresent);

	float Employee::CalSalary()const;
	void Print();
	virtual ~LowSeller() {
		delete[] ShoppingTotalList;
	};//dtor
	virtual void addShopToList(float Purchases);
	float getAvg()const;

};
