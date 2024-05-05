/**
 * @file  Bocek.c
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

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
