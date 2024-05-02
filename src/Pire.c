#include "Pire.h"


Pire PireOlustur(int deger){
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->super = BocekOlustur(deger);
	// this->super->alan = &alan;
	// this->super->cevre = &cevre;
	this->yoket = &PireYoket;
	return this;
}
// double alan(const Bitki this){
// 	return pow(this->deger,2);
// }
// double cevre(const Bitki this){
// 	return 4*this->deger;
// }
void PireYoket(const Pire this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
