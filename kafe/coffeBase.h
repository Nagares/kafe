#pragma once


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "coffee.h"
class coffeBase {
public:
	coffeBase();
	void saveCoffeBase();
	void readCoffeBase();
protected:
	vector<coffee> coffeBase_;
};


