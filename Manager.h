/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;


class Manager : public Employee {
private:
	int RankOfManage;

public:

	Manager(string Name, string ID, float BaseSalary, int JobPresent);
	float Employee::CalSalary()const;
	void Print();
	friend ostream& operator << (ostream& output, const Manager& object);
	virtual ~Manager() {};
	void SetRank(int rank) { RankOfManage = rank; }

};
