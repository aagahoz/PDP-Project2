/**
 * @file  Habitat.c
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#include "Habitat.h"


Habitat HabitatOlustur(int deger){
	Habitat this;
	this = (Habitat)malloc(sizeof(struct HABITAT));
	this->yasiyorMu = deger;

	this->setDeger = &setYasiyorMu;
	this->gorunum = &gorunumHabitat;
	this->yoket = &HabitatYoket;
	return this;
}
void setYasiyorMu(const Habitat this,int deger){
	this->yasiyorMu = deger;
}

char* gorunumHabitat(const Habitat this,void* p){
	char* str = (char*)malloc(sizeof(char)*3);
	sprintf(str,"%s ",this->yasiyorMu);
	return str;
}
void HabitatYoket(const Habitat this){
	if(this == NULL) return;
	free(this);
}
