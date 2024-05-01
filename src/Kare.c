#include "Kare.h"

Kare KareOlustur(int deger){
	Kare this;
	this = (Kare)malloc(sizeof(struct KARE));
	this->super = CanliOlustur(deger);
	// this->super->alan = &alan;
	// this->super->cevre = &cevre;
	this->yoket = &KareYoket;
	return this;
}
// double alan(const Kare this){
// 	return pow(this->deger,2);
// }
// double cevre(const Kare this){
// 	return 4*this->deger;
// }
void KareYoket(const Kare this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
