#include "Bitki.h"
#include "Bocek.h"

int main(){
	
	printf("\n");

	Bocek k = BocekOlustur(5);
	char* str = k->super->gorunum(k->super,k);
	printf("%s\n",str);
	free(str);
	
	k->yoket(k);
	
	return 0;
}



	/*
	Bitki k = BitkiOlustur(5);
	char* str = k->super->gorunum(k->super,k);
	printf("%s\n",str);
	free(str);
	
	k->yoket(k);




	Bocek k = BocekOlustur(5);
	char* str = k->super->gorunum(k->super,k);
	printf("%s\n",str);
	free(str);
	
	k->yoket(k);
	*/