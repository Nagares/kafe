#include "additive.h"

additive::additive() :name("item"), price("0") {};
additive::additive(string name, string price) :name(name), price(price) {};
bool additive:: isCoffe() { return false; };
	