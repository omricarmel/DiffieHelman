#include "diffieHelman.h"

//todo - init()

unsigned int modularPower(unsigned int base, unsigned int power, unsigned int module){ // lose information each iteration due to modulus
	
	unsigned int INT_MAX = -1; // to avoid overflow during calculation  
	unsigned int result;
	unsigned int temp;
	
	if ( module < INT_MAX/2 ) // module * 2 should not overflow int (result , temp <= module -> result + temp <= 2module )
		 result = temp = base % module;
	else
		return 0;
	
	
	// by module arithmetics this is (base ^ power  % module) but this way overflow is less likely
	for(int i = 1; i < power; i++){ // base * ... * base power times = base ^ power (% module)
		for (int j = 1; j < base % module ; j++){ // base + base base times = base * base (% module)
			result += temp % module;
			result = result % module;
		}
		temp = result;
	}
	return result;
}