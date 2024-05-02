#include "Bocek.h"

Bocek BocekOlustur(int deger){
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super = CanliOlustur(deger);
	this->super->tur = "C";
	this->yoket = &BocekYoket;
	return this;
}
void BocekYoket(const Bocek this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
