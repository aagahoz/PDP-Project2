/**
 * @file  Pire.c
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

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
