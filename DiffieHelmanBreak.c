//-------- diffieHelman Breaker --------------
//takes two intercepts and detects is numbers can they have in common

#include <stdio.h>
#include <stdlib.h>
#include "diffieHelman.h"

// f(_, x) = intercept1 , f(_, y) = intercept2 | f(intercept1, y) = f(intercept2, x)
int main(int argc, char * KEYS[]){
	
	unsigned int publicBaseKey = (unsigned int) atoi(KEYS[1]);
	unsigned int publicModuleKey = (unsigned int) atoi(KEYS[2]);
	unsigned int intercept1 = (unsigned int) atoi(KEYS[3]);
	unsigned int intercept2 = (unsigned int) atoi(KEYS[4]);
	
	unsigned int SEARCH_LIMIT = (unsigned int) atoi(KEYS[4]);
	
	for(unsigned int x = 1; x < SEARCH_LIMIT; x++){
		unsigned int tryIntercept = modularPower(publicBaseKey, x, publicModuleKey);
		for(unsigned int y = 1; y < SEARCH_LIMIT; y++){
			if ( tryIntercept == intercept1 && modularPower(publicBaseKey, y, publicModuleKey) == intercept2)
				if(modularPower(intercept1, y, publicModuleKey) == modularPower(intercept2, x, publicModuleKey)){
					printf("u1private: %u\nu2private: %u\nsharedSeceret: %u\n",x,y,modularPower(intercept1, y, publicModuleKey));
					return 0;
				}
		}
	}
	return 0;
} 