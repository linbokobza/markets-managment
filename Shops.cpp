/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include<typeinfo>
#include "Shops.h"
#include "Manager.h"
#include "HighSeller.h"
#include "POSresponsible.h"
#include "LowSeller.h"

//ctor
Shops::Shops(int ShopID, string ChainName) : ShopID(0), ChainName("UNKNOWN"), ListOfWorkers(NULL), WorkersAmount(0) {
	this->ChainName = ChainName;
	this->ShopID = ShopID;
}

//checks what is the type of the employee
void Shops::AddEmployee(string Name, string EmployeeID, char type, int JopPresent, float salary) {
	for (size_t i = 0; i < WorkersAmount; i++)
	{
		if (ListOfWorkers[i]->GetEmployeeID() == EmployeeID) {
			cout << "This employee already exist" << endl;
			return;
		}
	}

	if (type == 'A') 
		AddWorker(new Manager(Name, EmployeeID, salary, JopPresent));
	else if (type == 'B')
		AddWorker(new HighSeller(Name, EmployeeID, salary, JopPresent));
	else if (type == 'C')
		AddWorker(new LowSeller(Name, EmployeeID, salary, JopPresent));
	else if (type == 'D')
		AddWorker(new POSresponsible(Name, EmployeeID, salary, JopPresent));
	else cout << "Unknown worker" << endl;
}

//adds employee to the employee list
void Shops::AddWorker(Employee* newEmployee) {
	Manager* helpManager;
	if (helpManager = dynamic_cast<Manager*> (newEmployee)) {
		int Rank;
		cout << "Please enter Rank [1-3]:" << endl;
		cin >> Rank;
		helpManager->SetRank(Rank);
	}
	if (!ListOfWorkers) {
		ListOfWorkers = new Employee * [++WorkersAmount];
		ListOfWorkers[0] = newEmployee;
		cout << "The worker has been added" << endl;
		return;
	}
	Employee** temp = new Employee * [++WorkersAmount];
	for (int i = 0; i < WorkersAmount - 1; i++) {
		temp[i] = ListOfWorkers[i];
	}
	delete[] ListOfWorkers;
	ListOfWorkers = temp;
	ListOfWorkers[WorkersAmount - 1] = newEmployee;
	
	cout << "The worker has been added" << endl;
}

//adds purcheses to employee list
void Shops::Shopping(float value, string EmployeeID) {
	if (isEmployeeExist(EmployeeID) == -1) {
		cout << "This employee dosen't exist!" << endl;
		return;
	}

	for (int i = 0; i < WorkersAmount; i++) {
		if (ListOfWorkers[i]->GetEmployeeID() == EmployeeID)
		{
			Manager* helpManager;
			LowSeller* helpLow;
			HighSeller* helpHigh;
			POSresponsible* helpPOS;

			if (helpManager = dynamic_cast<Manager*> (ListOfWorkers[i]))
				cout << "I'm a manager, I'm not responsible about the shopping!" << endl;

			else if (helpLow = dynamic_cast<LowSeller*> (ListOfWorkers[i])) {
				cout << "The purchese has been added" << endl;
				helpLow->addShopToList(value);
			}

			else if (helpHigh = dynamic_cast<HighSeller*> (ListOfWorkers[i])) {
				cout << "The purchese has been added" << endl;
				helpHigh->LowSeller::addShopToList(value);
			}

			else if (helpPOS = dynamic_cast<POSresponsible*> (ListOfWorkers[i])) {
				cout << "The purchese has been added to POS responsible " << endl;
				helpPOS->UpdateAction();
			}
			else
				cout << "Unknown worker" << endl;
		}
	}
}

//cancel purchases from shops list
void Shops::ReturnItem(float value, string EmployeeID) {
	if (isEmployeeExist(EmployeeID) == -1) {
		cout << "This employee dosen't exist!" << endl;
		return;
	}
	for (int i = 0; i < WorkersAmount; i++) {
		if (ListOfWorkers[i]->GetEmployeeID() == EmployeeID)
		{
			Manager* helpManager;
			LowSeller* helpLow;
			HighSeller* helpHigh;
			POSresponsible* helpPOS;

			if (helpManager = dynamic_cast<Manager*> (ListOfWorkers[i]))
				cout << "I'm a Manager, I cannot return item!" << endl;

			else if (helpHigh = dynamic_cast<HighSeller*> (ListOfWorkers[i])) {
				helpHigh->CancelShopFromList(value);
			}

			else if (helpLow = dynamic_cast<LowSeller*> (ListOfWorkers[i])) {
				cout << "I'm a low seller, I cannot return item!" << endl;
			}

			else if (helpPOS = dynamic_cast<POSresponsible*> (ListOfWorkers[i])) {
				cout << "I'm a POS responsible, I cannot return item!" << endl;
			}
			else
				cout << "Unknown worker" << endl;
		}
	}
}

//calculate all salaries in the chain
float Shops::SumSalariesChain() {
	float sum = 0;
	for (size_t i = 0; i < WorkersAmount; i++)
	{
		sum += ListOfWorkers[i]->CalSalary();
	}
	return sum;
}

//calculate all salaries in the shop
void Shops::SumSalariesShops() {
	float sum = 0;
	for (size_t i = 0; i < WorkersAmount; i++)
	{
		sum += ListOfWorkers[i]->CalSalary();
	}
	cout << "Sum of salary in " << ChainName << " is: " << sum << endl;
}

//check if specific employee exist
int  Shops::isEmployeeExist(string ID) {
	for (size_t i = 0; i < WorkersAmount; i++)
	{
		if (ListOfWorkers[i]->GetEmployeeID() == ID)
			return i;
	}
	return -1;
}

//return employee by specific value
Employee* Shops::indexEmployee(int index) {
	if (index >= 0 && index < WorkersAmount)
		return ListOfWorkers[index];
	else {
		cout << "Out of boundary of the array!" << endl;
		return NULL;
	}
}

// prints shops info
void Shops::Print(string ShopType) {
	cout << endl << "---------Shop's info---------" << endl;
	cout << "shop type: " << ShopType << endl;

	cout << "shop ID: ";
	cout << ShopID<< endl;

	cout << "Employees amount: ";
	cout << WorkersAmount<< endl;

}

//dtor
Shops::~Shops() {
	for (size_t i = 0; i < WorkersAmount; i++)
	{
		delete[] ListOfWorkers[i];
	}
	delete ListOfWorkers;
};