/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class Employee;
class Chain;

class Shops {
private:
	int ShopID;
	string ChainName;
	Employee** ListOfWorkers;
	int WorkersAmount;

public:
	Shops(int ShopID, string ChainName);

	void AddEmployee(string Name, string EmployeeID, char type, int JopPresent, float salary);
	void AddWorker(Employee* newEmployee);
	void Shopping(float value, string EmployeeID);
	void ReturnItem(float value, string EmployeeID);
	float SumSalariesChain();
	void SumSalariesShops();
	int isEmployeeExist(string ID);
	Employee* indexEmployee(int index);
	int GetID() { return this->ShopID; }
	int GetWorkersAmount() { return WorkersAmount; }
	void Print(string ShopType);
	~Shops();
};
