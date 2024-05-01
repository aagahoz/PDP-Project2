#include "Bitki.h"

Bitki BitkiOlustur(int deger){
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	this->super = CanliOlustur(deger);
	// this->super->alan = &alan;
	// this->super->cevre = &cevre;
	this->yoket = &BitkiYoket;
	return this;
}
// double alan(const Bitki this){
// 	return pow(this->deger,2);
// }
// double cevre(const Bitki this){
// 	return 4*this->deger;
// }
void BitkiYoket(const Bitki this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
