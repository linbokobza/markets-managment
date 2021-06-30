/* Assignment: 3
Author:Lin Bokobza, ID: 209482801 */

#include <iostream>
#include <string>
#include "Chain.h"
#include "Clothes.h"
using namespace std;

//ctor
Clothes::Clothes(string Name, string NameOfImporter) : Chain(Name), NameOfImporter("UNKNOWN") {
	this->NameOfImporter = NameOfImporter;
};

// prints cloher chain info
void Clothes::PrintChain(string ChainType) {
	cout << "-----------Chain's info-----------" << endl;
	cout << "Provider: " << NameOfImporter << endl;
	cout << "Chain type: " << ChainType << endl;
	Chain::PrintChain(ChainType);
}

