#include "Sinek.h"


Sinek SinekOlustur(int deger){
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	this->super = BocekOlustur(deger);
	this->super->super->tur = "S";
	
	this->yoket = &SinekYoket;
	return this;
}
void SinekYoket(const Sinek this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
