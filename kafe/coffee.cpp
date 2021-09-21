#include "coffee.h"
coffee::coffee(string name, string volume, string price, vector<additive> supplements) :espresso(name, volume, price), supplements_(supplements) {};
