/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include "POSresponsible.h"
using namespace std;


//ctor
POSresponsible::POSresponsible(string Name, string ID, float BaseSalary, int JobPresent) :Employee(Name, ID, BaseSalary, JobPresent), Actions(0) {}

//calculate the salary of POS responsible
float POSresponsible::CalSalary()const {
	return (BaseSalary + Actions) * JobPresent / 100;
}

// prints POS responsible info
void POSresponsible::Print() {
	Employee::Print();
	cout << "I'm a POS responsible!" << endl;
	cout << "Number of actions: " << Actions << endl;
}

// increase the action by 1 
void POSresponsible::UpdateAction() {
	this->Actions++;
}