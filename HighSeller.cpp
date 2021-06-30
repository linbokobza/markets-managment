/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include "Employee.h"
#include "HighSeller.h"
#include "LowSeller.h"

using namespace std;

//ctor
HighSeller::HighSeller(string Name, string ID, float BaseSalary, int JobPresent) : LowSeller(Name, ID, BaseSalary, JobPresent), CancelledShoppingAmount(0), CancelledShopping(NULL) {}

//calculate the salary of High Seller
float HighSeller::CalSalary()const {
	return (BaseSalary + getAvg() + ShoppingTotalAmount) * JobPresent / 100 * 1.5;
}

// prints high seller info
void HighSeller::Print() {
	Employee::Print();
	cout << "I'm a High Seller!" << endl;

	cout << "I have " << ShoppingTotalAmount << " orders: " << endl;
	for (size_t i = 0; i < ShoppingTotalAmount; i++)
	{
		cout << ShoppingTotalList[i] << ", ";
	}
	cout << endl;

	cout << "I returned " << CancelledShoppingAmount << " orders: " << endl;
	for (size_t i = 0; i < CancelledShoppingAmount; i++)
	{
		cout << CancelledShopping[i] << ", " << endl;
	}
	cout << endl;
}

//cancel purchases from shops list
void HighSeller::CancelShopFromList(float purchase) {
	int j = 0;
	if (!ShoppingTotalList) {
		cout << "There are no purchases!" << endl;
		return;
	}

	for (size_t i = 0; i < ShoppingTotalAmount; i++)
	{
		if (ShoppingTotalList[i] == purchase) {
			if (!CancelledShopping) {
				CancelledShopping = new float[++CancelledShoppingAmount];
				CancelledShopping[0] = purchase;
				float* temp2 = new float[--ShoppingTotalAmount];
				for (int i = 0; i < ShoppingTotalAmount + 1; i++) {
					if (ShoppingTotalList[i] != purchase) {
						temp2[j] = ShoppingTotalList[i];
						j++;
					}
				}
				delete[] ShoppingTotalList;
				ShoppingTotalList = temp2;
				cout << "The item was returned!" << endl;
				return;
			}

			float* temp = new float[++CancelledShoppingAmount];
			for (int i = 0; i < CancelledShoppingAmount - 1; i++) {
				temp[i] = CancelledShopping[i];
			}
			delete[] CancelledShopping;
			CancelledShopping = temp;
			CancelledShopping[CancelledShoppingAmount] = purchase;

			float* temp2 = new float[--ShoppingTotalAmount];
			for (int i = 0; i < ShoppingTotalAmount + 1; i++) {
				if (ShoppingTotalList[i] != purchase) {
					temp2[j] = ShoppingTotalList[i];
					j++;
				}
			}
			delete[] ShoppingTotalList;
			ShoppingTotalList = temp2;
			cout << "The item was returned!" << endl;
			return;
		}
	}
	cout << "There are no purchases." << endl;
}

