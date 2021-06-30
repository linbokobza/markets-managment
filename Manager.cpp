/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include "Manager.h"
using namespace std;

//ctor
Manager::Manager(string Name, string ID, float BaseSalary, int JobPresent) :Employee(Name, ID, BaseSalary, JobPresent), RankOfManage(1) {}

//calculate the salary of manager
float Manager::CalSalary()const {
	return BaseSalary * JobPresent / 100 * RankOfManage;
}

// prints manager info
void Manager::Print() {
	Employee::Print();
	cout << "I'm a Manager!" << endl;
	cout << "Rank: " << RankOfManage << endl;
}