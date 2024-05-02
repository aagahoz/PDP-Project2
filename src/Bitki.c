#include "Bitki.h"

Bitki BitkiOlustur(int deger){
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	this->super = CanliOlustur(deger);
	this->super->tur = "B";
	this->yoket = &BitkiYoket;
	return this;
}
void BitkiYoket(const Bitki this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
