/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include "Chain.h"
#include "Food.h"
using namespace std;

//ctor
Food::Food(string Name, int ProvidersAmount) : Chain(Name), ProvidersAmount(0) {
	this->ProvidersAmount = ProvidersAmount;
};

// prints food chain info
void Food::PrintChain(string ChainType) {
	cout << "-----------Chain's info-----------" << endl;
	cout << "This chain has " << ProvidersAmount << " providers." << endl;
	cout << "Chain type: " << ChainType << endl;
	Chain::PrintChain(ChainType);
}

