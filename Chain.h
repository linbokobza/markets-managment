/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include<typeinfo>
#include "Employee.h"
#include "Shops.h"
#include "Chain.h"
using namespace std;

class Shops;
class Employee;

class Chain {
protected:
	string Name;
	Shops** ListOfShops;
	int ShopsAmount;

public:
	Chain(string Name);
	virtual ~Chain();
	virtual void AddShopToChain(int ShopID);
	void SumSalariesChain();
	void SumSalariesShops(int ShopID);
	void ReturnItem(int ShopID, float value, string EmployeeID);
	void AddEmployee(string Name, string ID, char type, int JopPresent, float salary, int ShopID);
	void Shopping(int ShopID, float value, string EmployeeID);
	int IsShopExist(int ShopID);
	virtual void PrintChain(string ChainType);
	void PrintShop(int ShopID, string ShopType);
	void PrintEmployee(string EmployeeID);
	string GetName() { return this->Name; }
};

