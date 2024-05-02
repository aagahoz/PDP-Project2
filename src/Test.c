#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"

int main(){
	
	printf("\n");

	Pire k = PireOlustur(5);
	char* str = k->super->super->gorunum(k->super->super,k);
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



	Sinek k = SinekOlustur(5);
	char* str = k->super->super->gorunum(k->super->super,k);
	printf("%s\n",str);
	free(str);
	
	k->yoket(k);
	*/