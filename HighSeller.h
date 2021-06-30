/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include "LowSeller.h"
using namespace std;

class HighSeller : public LowSeller {
private:
	float* CancelledShopping;
	int CancelledShoppingAmount;

public:
	HighSeller(string Name, string ID, float BaseSalary, int JobPresent);

	float Employee::CalSalary()const;
	void Print();
	virtual ~HighSeller() {delete[] CancelledShopping;};//dtor
	void CancelShopFromList(float purchase);
};

