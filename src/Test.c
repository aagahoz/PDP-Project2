#include "Bitki.h"

int main(){
	
	printf("\n");
		
	Bitki k = BitkiOlustur(5);




	char* str = k->super->gorunum(k->super,k);
	printf("%s\n",str);
	free(str);
	
	k->yoket(k);
	return 0;
}
