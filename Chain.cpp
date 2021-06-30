/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include<typeinfo>
#include "Chain.h"
#include "Manager.h"
#include "HighSeller.h"
#include "POSresponsible.h"
#include "LowSeller.h"

using namespace std;

//ctor
Chain::Chain(string Name) : Name("UNKNOWN"), ListOfShops(NULL), ShopsAmount(0) {
	this->Name = Name;
};

//dtor
Chain:: ~Chain() {
	for (size_t i = 0; i < ShopsAmount; i++)
		delete[] ListOfShops[i];
	delete ListOfShops;
};

//adds shop to the chain list
void Chain::AddShopToChain(int ShopID) {
	Shops *NewShop= new Shops(ShopID, this->Name);
	if (!ListOfShops) {
		ListOfShops = new Shops * [++ShopsAmount];
		ListOfShops[0] = NewShop;
		cout << "The shop has been added" << endl;
		return;
	}
	for (int i = 0; i < ShopsAmount ; i++) {
		if (ListOfShops[i]->GetID() == ShopID) {
			cout << "This shop already exist!" << endl;
			return;
		}
	}
	Shops** temp = new Shops * [++ShopsAmount];
	for (int i = 0; i < ShopsAmount - 1; i++) {
		temp[i] = ListOfShops[i];
	}
	delete[] ListOfShops;
	ListOfShops = temp;
	ListOfShops[ShopsAmount - 1] = NewShop;
	cout << "The shop has been added" << endl;
}

// prints chain info
void Chain::PrintChain(string ChainType) {
	cout << "Chain: ";
	cout <<Name << endl;

	cout << "This chain has "<< ShopsAmount<< " shops!" << endl;
	for (size_t i = 0; i < ShopsAmount; i++)
	{
		ListOfShops[i]->Print(ChainType);
	}
}

//calculate all salaries in the chain
void Chain::SumSalariesChain() {
	float sum = 0;
	for (size_t i = 0; i < ShopsAmount; i++)
	{
		sum += ListOfShops[i]->SumSalariesChain();
	}
	cout << "Sum of salary in " << Name << "is: " << sum << endl;
}

//calculate all salaries in the shop
void Chain::SumSalariesShops(int ShopID) {
	for (size_t i = 0; i < ShopsAmount; i++)
	{
		if (ListOfShops[i]->GetID() == ShopID) {
			ListOfShops[i]->SumSalariesShops();
			return;
		}
	}
	cout << "This shop dosen't exist!" << endl;
}

//cancel purchases from shops list
void Chain::ReturnItem(int ShopID, float value, string EmployeeID) {
	if (IsShopExist(ShopID) == -1) {
		cout << "This shop dosen't exist" << endl;
		return;
	}
	ListOfShops[IsShopExist(ShopID)]->ReturnItem(value, EmployeeID);
}

//adds employee to the employee list
void Chain::AddEmployee(string Name, string ID, char type, int JopPresent, float salary, int ShopID) {
	if (IsShopExist(ShopID) == -1) {
		cout << "This shop dosen't exist" << endl;
		return;
	}
	ListOfShops[IsShopExist(ShopID)]->AddEmployee(Name, ID, type, JopPresent, salary);
}

//adds purcheses to employee listAA
void Chain::Shopping(int ShopID, float value, string EmployeeID) {
	if (IsShopExist(ShopID) == -1) {
		cout << "This shop dosen't exist" << endl;
		return;
	}
	ListOfShops[IsShopExist(ShopID)]->Shopping(value, EmployeeID);
}

//check if specific shop exist
int Chain::IsShopExist(int ShopID) {
	for (size_t i = 0; i < ShopsAmount; i++)
	{
		if (ListOfShops[i]->GetID() == ShopID)
			return i;
	}
	return -1;
}

// prints shops info
void Chain::PrintShop(int ShopID, string ShopType) {
	if (IsShopExist(ShopID) == -1) {
		cout << "This shop dosen't exist!" << endl;
		return;
	}

	for (int i = 0; i < ShopsAmount; i++)
	{
		if (ListOfShops[i]->GetID() == ShopID) {
			ListOfShops[i]->Print(ShopType);
		}
	}

	for (size_t i = 0; i < ListOfShops[IsShopExist(ShopID)]->GetWorkersAmount(); i++)
	{
		PrintEmployee(ListOfShops[IsShopExist(ShopID)]->indexEmployee(i)->GetEmployeeID());
	}
}

// prints employee info
void Chain::PrintEmployee(string EmployeeID) {
	for (size_t i = 0; i < ShopsAmount; i++)
	{
		int index = ListOfShops[i]->isEmployeeExist(EmployeeID);

		if (index != -1) {
			Manager* helpManager;
			LowSeller* helpLow;
			HighSeller* helpHigh;
			POSresponsible* helpPOS;
			if (helpManager = dynamic_cast<Manager*> (ListOfShops[i]->indexEmployee(index)))
				helpManager->Manager::Print();

			else if (helpHigh = dynamic_cast<HighSeller*> (ListOfShops[i]->indexEmployee(index))) {
				helpHigh->HighSeller::Print();
			}

			else if (helpPOS = dynamic_cast<POSresponsible*> (ListOfShops[i]->indexEmployee(index))) {
				helpPOS->POSresponsible::Print();
			}

			else if (helpLow = dynamic_cast<LowSeller*> (ListOfShops[i]->indexEmployee(index))) {
				helpLow->LowSeller::Print();
			}
			else
				cout << "Unknown worker" << endl;
		}
	}
}


