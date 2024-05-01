#include "Canli.h"


Canli CanliOlustur(int deger){
	Canli this;
	this = (Canli)malloc(sizeof(struct CANLI));
	this->deger = deger;
	this->tur = "X";

	this->setDeger = &setDeger;
	this->gorunum = &gorunum;
	this->yoket = &CanliYoket;
	return this;
}
void setDeger(const Canli this,int deger){
	this->deger = deger;
}

void setTur(const Canli this,char* tur){
	this->tur = tur;
}

char* gorunum(const Canli this,void* p){
	int toplamUzunluk = 36;

	char* str = (char*)malloc(sizeof(char)*toplamUzunluk+1);
	sprintf(str,"\n Tur: %s\n\n",this->tur);
	return str;
}
void CanliYoket(const Canli this){
	if(this == NULL) return;
	free(this);
}
