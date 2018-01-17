/* ------------------- diffie helman key exchange -------------------- */
#include <stdio.h>
#include <stdlib.h>
#include "diffieHelman.h"

int main(int argc, char * KEYS[]){
	// keys contains 2 private keys and one public key
	
	unsigned int publicBaseKey = (unsigned int) atoi(KEYS[1]);
	unsigned int publicModuleKey = (unsigned int) atoi(KEYS[2]);
	unsigned int u1PrivateKey = (unsigned int) atoi(KEYS[3]);
	unsigned int u2PrivateKey = (unsigned int) atoi(KEYS[4]);
	
	unsigned int u1Public;
	unsigned int u2Public;
	
	//printf("publicBaseKey: %u\npublicModuleKey %u\nu1PrivateKey %u\nu2PrivateKey %u\n",publicBaseKey,publicModuleKey,u1PrivateKey,u2PrivateKey);
	
	unsigned int sharedSecretKey;
	
	printf("\nUser1 Sent: %u\n",u1Public = modularPower(publicBaseKey, u1PrivateKey, publicModuleKey));
	printf("\nUser2 Sent: %u\n",u2Public =  modularPower(publicBaseKey, u2PrivateKey, publicModuleKey));
	
	printf("\nUser1 secret is: %u\n", sharedSecretKey = modularPower(u2Public, u1PrivateKey, publicModuleKey));
	printf("\nUser2 secret is: %u\n", sharedSecretKey = modularPower(u1Public, u2PrivateKey, publicModuleKey));
	
	printf("\n");
	return 0;
}

