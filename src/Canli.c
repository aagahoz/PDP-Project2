/**
 * @file  Canli.c
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#include "Canli.h"


Canli CanliOlustur(int deger){
	Canli this;
	this = (Canli)malloc(sizeof(struct CANLI));
	this->deger = deger;
	this->tur = "-";
	this->xCoord = -1;
	this->yCoord = -1;

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
	char* str = (char*)malloc(sizeof(char)*3);
	sprintf(str,"%s ",this->tur);
	return str;
}
void CanliYoket(const Canli this){
	if(this == NULL) return;
	free(this);
}
