/**
 * @file  Sinek.c
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

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
