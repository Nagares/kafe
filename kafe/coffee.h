#pragma once
#include "espresse.h"
#include"additive.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class coffee :public espresso {
	public:
		coffee(string, string, string, vector<additive>);
		friend class coffeBase;
		friend class coffeeHouse;
	protected:
		vector<additive> supplements_;
	};
