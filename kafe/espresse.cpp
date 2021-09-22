#include "espresse.h"

	espresso::espresso() :name("Espresso"), volume("30"), price("20") {};
	espresso::espresso(string name, string volume, string price):name(name), volume(volume), price(price) {};
	bool espresso:: isCoffe() { return true; }
	
