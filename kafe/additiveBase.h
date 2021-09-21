#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "additive.h"

class additiveBase {
public:
	additiveBase();
	void saveAdditiveBase();
	void readAdditiveBase();

protected:
	vector<additive> additiveBase_;
};
