#include "Bocek.h"

Bocek BocekOlustur(int deger){
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super = CanliOlustur(deger);
	// this->super->alan = &alan;
	// this->super->cevre = &cevre;
	this->yoket = &BocekYoket;
	return this;
}
// double alan(const Bitki this){
// 	return pow(this->deger,2);
// }
// double cevre(const Bitki this){
// 	return 4*this->deger;
// }
void BocekYoket(const Bocek this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
