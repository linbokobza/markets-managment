/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#pragma once
#include <iostream>
#include <string>
#include "Chain.h"
using namespace std;

class Food : public Chain {
protected:
	int ProvidersAmount;

public:
	Food(string Name, int ProvidersAmount);
	void PrintChain(string ChainType);
	virtual ~Food() {};
};