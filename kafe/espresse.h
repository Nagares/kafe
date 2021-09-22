#pragma once
#include "order.h"
#include <iostream>
#include <string>
using namespace std;
class espresso :public order {
public:
	espresso();
	espresso(string, string, string);
	bool isCoffe() override;
	string name;
	string volume;
	string price;
};

