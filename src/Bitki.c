/**
 * @file  Bitki.c
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

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
