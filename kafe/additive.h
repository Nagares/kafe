#pragma once
#include "order.h"
#include <iostream>
#include <string>
using namespace std;
class additive : public order{
	public:
		additive();
		additive(string, string);
		bool isCoffe()override;
		string name;
		string price;
};


