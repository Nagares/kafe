#pragma once

#include"order.h"
#include"additive.h"
#include"espresse.h"
#include"additiveBase.h"
#include"coffee.h"
#include "coffeBase.h"
#include"client.h"
#include"clientBase.h"
#include"coffeeHouse.h"
using namespace std;


int main()
{
	coffeeHouse jomba("Jomba","admin");
	jomba.readBases();
	jomba.menu();
	
	
	
	
}

