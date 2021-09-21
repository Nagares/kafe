#pragma once
#include<vector>
#include<fstream>
#include"client.h"
class clientBase {
public:
	clientBase();
	void saveClientBase();
	void readClientBase();
	client findByNumber(string);
protected:
	vector<client> clientBase_;
};
