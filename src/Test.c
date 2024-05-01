#include "Kare.h"

int main(){
	
	printf("\n");
		
	Kare k = KareOlustur(5);
	char* str = k->super->gorunum(k->super,k);
	printf("%s\n",str);
	free(str);
	
	k->yoket(k);
	return 0;
}
