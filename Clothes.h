/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include "Chain.h"
using namespace std;

class Clothes : public Chain {
protected:
	string NameOfImporter;

public:
	Clothes(string Name, string NameOfImporter);
	void PrintChain(string ChainType);
	virtual ~Clothes() {};
};