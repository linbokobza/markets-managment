/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include "LowSeller.h"
using namespace std;

//ctor
LowSeller::LowSeller(string Name, string ID, float BaseSalary, int JobPresent) :Employee(Name, ID, BaseSalary, JobPresent), ShoppingTotalAmount(0), ShoppingTotalList(NULL) {}

//calculate the salary of low Seller
float LowSeller::CalSalary()const {
	return (BaseSalary + getAvg() + ShoppingTotalAmount) * JobPresent / 100;
}

// prints low seller info
void LowSeller::Print() {
	Employee::Print();
	cout << "I'm a Low Seller!" << endl;

	cout << "I have " << ShoppingTotalAmount << " orders: " << endl;
	for (size_t i = 0; i < ShoppingTotalAmount; i++)
	{
		cout << ShoppingTotalList[i] << ", ";
	}
	cout << endl;
}

//adds shop to the shops list
void LowSeller::addShopToList(float Purchases) {

	if (!ShoppingTotalList) {
		ShoppingTotalList = new float[++ShoppingTotalAmount];
		ShoppingTotalList[0] = Purchases;
		return;
	}
	float* temp = new float[++ShoppingTotalAmount];
	for (int i = 0; i < ShoppingTotalAmount - 1; i++) {
		temp[i] = ShoppingTotalList[i];
	}
	delete[] ShoppingTotalList;
	ShoppingTotalList = temp;
	ShoppingTotalList[ShoppingTotalAmount - 1] = Purchases;
}

//return the shopping's average 
float LowSeller::getAvg()const {
	float sum = 0;
	if (ShoppingTotalAmount == 0)
		return 0;

	for (size_t i = 0; i < ShoppingTotalAmount; i++)
	{
		sum += ShoppingTotalList[i];
	}
	return sum / ShoppingTotalAmount;
}
