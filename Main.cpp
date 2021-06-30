/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include "Employee.h"
#include "Shops.h"
#include "Food.h"
#include "Clothes.h"
#include "Chain.h"
#define N 3
using namespace std;

class Shops;
class Employee;
class Chain;

//function declartion
void AddShop(Chain**);
void AddEmployee(Chain**);
void Shopping(Chain**);
void ReturnItem(Chain** ptr);
void PrintChain(Chain** ptr);
void SumSalariesChain(Chain** ptr);
void SumSalariesShpos(Chain** ptr);
void PrintShop(Chain** ptr);
void PrintEmployee(Chain** ptr);
void menu(Chain**);
bool IsShopExist(string Name, int ShopID);
bool isChainExist(string ChainName);
typedef enum { Golbary = 1, SuperSal} Chains;


int main() {
	Chain* ptr[N];
	ptr[0] = new Clothes("Golbary", "Moshe Gabay");
	ptr[0]->AddShopToChain(65);
	ptr[1] = new Food("Super Sal", 4);
	ptr[1]->AddShopToChain(3);
	ptr[1]->AddShopToChain(81);
	ptr[2] = new Clothes("TNT", "Ruti Sulemani ");
	ptr[2]->AddShopToChain(3);
	system("CLS");
	menu(ptr);
	return 0;
}

//adds shop to the shop list
void AddShop(Chain** ptr) {
	string ChainName;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter shop name:" << endl;
	getline(cin, ChainName);
	cout << endl;

	int ShopID;
	cout << "Enter shop ID:" << endl;
	cin >> ShopID;
	cout << endl;

	if (!isChainExist(ChainName))
	{
		cout << "This chain doesn't exist." << endl;
		return;
	}

	for (size_t i = 0; i < N; i++)
	{
		if ((*ptr[i]).GetName() == ChainName)
			(*ptr[i]).AddShopToChain(ShopID);

	}
}

//adds employee to the employee list
void AddEmployee(Chain** ptr) {
		string EmployeeName;
		cin.ignore(INT_MAX, '\n');
		cout << "Enter employee name:" << endl;
		getline(cin, EmployeeName);
		cout << endl;

		string EmployeeID;
		cout << "Enter employee ID:" << endl;
		cin >> EmployeeID;
		cout << endl;

		char type;
		cout << "Enter employee type:" << endl;
		cin >> type;
		cout << endl;

		int JobPreset;
		cout << "Enter job preset:" << endl;
		cin >> JobPreset;
		cout << endl;

		float Salary;
		cout << "Enter base salary:" << endl;
		cin >> Salary;
		cout << endl;

		string ChainName;
		cin.ignore(INT_MAX, '\n');
		cout << "Enter shop name:" << endl;
		getline(cin, ChainName);
		cout << endl;

		int ShopID;
		cout << "Enter shop ID:" << endl;
		cin >> ShopID;
		cout << endl;

		if (!isChainExist(ChainName))
		{
			cout << "This chain doesnt exist." << endl;
			return;
		}

		for (size_t i = 0; i < N; i++)
		{
			if ((*ptr[i]).GetName() == ChainName)
				(*ptr[i]).AddEmployee(EmployeeName, EmployeeID, type, JobPreset, Salary, ShopID);
		}
	

}

//check if specific chain exist
bool isChainExist(string ChainName) {

	if (ChainName == "Golbary" || ChainName == "Super Sal"|| ChainName == "TNT")
		return true;
	else {
		return false; // not exist
	}
}

//adds purcheses to employee list
void Shopping(Chain** ptr) {

	int ShopID;
	cout << "Enter shop ID:" << endl;
	cin >> ShopID;
	cout << endl;

	string ChainName;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter shop name:" << endl;
	getline(cin, ChainName);
	cout << endl;

	float Value;
	cout << "Enter price:" << endl;
	cin >> Value;
	cout << endl;

	string EmployeeID;
	cout << "Enter employee ID:" << endl;
	cin >> EmployeeID;
	cout << endl;

	if (!isChainExist(ChainName))
	{
		cout << "This chain doesnt exist." << endl;
		return;
	}

	for (size_t i = 0; i < N; i++)
	{
		if ((*ptr[i]).GetName() == ChainName)
			(*ptr[i]).Shopping(ShopID, Value, EmployeeID);
	} 

}

// prints chain info
void PrintChain(Chain** ptr) {
	string ShopName;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter shop name:" << endl;
	getline(cin, ShopName);
	cout << endl;

	if (!isChainExist(ShopName))
	{
		cout << "This chain doesnt exist." << endl;
		return;
	}

	//for (size_t i = 0; i < N; i++)
	//{
	//	if ((*ptr[i]).GetName() == ShopName)
	//		(*ptr[i]).print();
	//}

	for (size_t i = 0; i < N; i++)
	{
		string ShopType;
		if ((*ptr[i]).GetName() == ShopName) {
			Clothes* helpClothes;
			Food* helpFood;
			if (helpClothes = dynamic_cast<Clothes*> (ptr[i])) {
				ShopType = "Clothes";
				helpClothes->Clothes::PrintChain(ShopType);
			}

			else if (helpFood = dynamic_cast<Food*> (ptr[i])) {
				ShopType = "Food";
				helpFood->Food::PrintChain(ShopType);
			}
			else
				cout << "Unknown chain" << endl;
		}
	}
}

//cancel purchases from shops list
void ReturnItem(Chain** ptr) {

	int ShopID;
	cout << "Enter shop ID:" << endl;
	cin >> ShopID;
	cout << endl;

	string ChainName;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter shop name:" << endl;
	getline(cin, ChainName);
	cout << endl;

	float Value;
	cout << "Enter price:" << endl;
	cin >> Value;
	cout << endl;

	string EmployeeID;
	cout << "Enter employee ID:" << endl;
	cin >> EmployeeID;
	cout << endl;

	if (!isChainExist(ChainName))
	{
		cout << "This chain doesnt exist." << endl;
		return;
	}

	for (size_t i = 0; i < N; i++)
	{
		if ((*ptr[i]).GetName() == ChainName)
			(*ptr[i]).ReturnItem(ShopID, Value, EmployeeID);
	}


}

//calculate all salaries in the chain
void SumSalariesChain(Chain** ptr) {
	string ChainName;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter shop name:" << endl;
	getline(cin, ChainName);
	cout << endl;


	if (!isChainExist(ChainName))
	{
		cout << "This chain doesnt exist." << endl;
		return;
	}

	for (size_t i = 0; i < N; i++)
	{
		if ((*ptr[i]).GetName() == ChainName)
			(*ptr[i]).SumSalariesChain();
	}

}

//calculate all salaries in the shop
void SumSalariesShpos(Chain** ptr) {
	int ShopID;
	cout << "Enter shop ID:" << endl;
	cin >> ShopID;
	cout << endl;

	string ChainName;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter shop name:" << endl;
	getline(cin, ChainName);
	cout << endl;

	if (!isChainExist(ChainName))
	{
		cout << "This chain doesnt exist." << endl;
		return;
	}

	for (size_t i = 0; i < N; i++)
	{
		if ((*ptr[i]).GetName() == ChainName)
			(*ptr[i]).SumSalariesShops(ShopID);
	}
}

// prints shops info
void PrintShop(Chain** ptr) {
	int ShopID;
	cout << "Enter shop ID:" << endl;
	cin >> ShopID;
	cout << endl;

	string ChainName;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter shop name:" << endl;
	getline(cin, ChainName);
	cout << endl;

	if (!isChainExist(ChainName))
	{
		cout << "This chain doesnt exist." << endl;
		return;
	}

	for (size_t i = 0; i < N; i++)
	{
		string ShopType;
		if ((*ptr[i]).GetName() == ChainName){
			Clothes* helpClothes;
			Food* helpFood;
			if (helpClothes = dynamic_cast<Clothes*> (ptr[i])) {
				ShopType = "Clothes";
				helpClothes->PrintShop(ShopID, ShopType);
			}

			else if (helpFood = dynamic_cast<Food*> (ptr[i])) {
				ShopType = "Food";
				helpFood->PrintShop(ShopID, ShopType);
			}
			else
				cout << "Unknown Shop" << endl;
		}
	}
}

// prints employee info
void PrintEmployee(Chain** ptr) {
	string EmployeeID;
	cout << "Enter employee ID:" << endl;
	cin >> EmployeeID;
	cout << endl;

	string ChainName;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter shop name:" << endl;
	getline(cin, ChainName);
	cout << endl;

	for (size_t i = 0; i < N; i++)
	{
		if ((*ptr[i]).GetName() == ChainName)
			(*ptr[i]).PrintEmployee(EmployeeID);
	}
}

//manage the menu
void menu(Chain ** ptr)
{
	while (1)
	{
		cout << "*************************************************************************" << endl;
		cout << "*************************************************************************" << endl;
		cout << "*************************************************************************" << endl;
		cout << "Welcome to chain organize. What would you like to do?" << endl;
		cout << "*************************************************************************" << endl;
		cout << "[1] - Add a shop to chain." << endl;
		cout << "[2] - Add a employee to chain." << endl;
		cout << "[3] - Shopping." << endl;
		cout << "[4] - Return item." << endl;
		cout << "[5] - Print chain." << endl;
		cout << "[6] - Print sum salaries chain." << endl;
		cout << "[7] - Print sum salaries shop." << endl;
		cout << "[8] - Print shop." << endl;
		cout << "[9] - Print employee." << endl;
		cout << "[10]- Exit." << endl;
		cout << "*************************************************************************" << endl;

		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			AddShop(ptr);
			break;
		case 2:
			AddEmployee(ptr);
			break;
		case 3:
			Shopping(ptr);
			break;
		case 4:
			ReturnItem(ptr);
			break;
		case 5:
			PrintChain(ptr);
			break;
		case 6:
			SumSalariesChain(ptr);
			break;
		case 7:
			SumSalariesShpos(ptr);
			break;
		case 8:
			PrintShop(ptr);
			break;
		case 9:
			PrintEmployee(ptr);
			break;
		case 10:
			cout << "Thank you, goodbye." << endl;
			return;
			break;
		default:
			cout << "No such option , sorry. Choose again please." << endl;
		}
	}
}

