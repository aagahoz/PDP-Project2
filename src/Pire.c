#include "Pire.h"


Pire PireOlustur(int deger){
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->super = BocekOlustur(deger);
	this->super->super->tur = "P";
	this->yoket = &PireYoket;
	return this;
}
void PireYoket(const Pire this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
