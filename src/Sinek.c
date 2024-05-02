#include "Sinek.h"


Sinek SinekOlustur(int deger){
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	this->super = BocekOlustur(deger);
	// this->super->alan = &alan;
	// this->super->cevre = &cevre;
	this->yoket = &SinekYoket;
	return this;
}
// double alan(const Bitki this){
// 	return pow(this->deger,2);
// }
// double cevre(const Bitki this){
// 	return 4*this->deger;
// }
void SinekYoket(const Sinek this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
