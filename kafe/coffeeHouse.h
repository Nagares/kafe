#pragma once
#include "coffeBase.h"
#include"additiveBase.h"
#include"clientBase.h"

class coffeeHouse :protected coffeBase, protected additiveBase, protected clientBase {
public:
	coffeeHouse(string, string);
	void readBases();
	void saveBase();
	bool getDiscount(string);
	bool reconcilePass(string);
	void menu();
	void toOrder();
	bool orderCoffe();
	void orderAdditive();
	void adminMenu();
	friend void showOrder(vector<order*>&, bool);
	friend void saveOrder(vector<order*>&, bool);
private:
	vector<order*> order_;
	string nameCafe_;
	string adminPass_;
	bool discount_ = false;
};
void showOrder(vector<order*>& order, bool discount);
void saveOrder(vector<order*>& order, bool discount);
