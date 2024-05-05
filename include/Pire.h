/**
 * @file  Pire.h
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE{
	Bocek super;
	
	void (*yoket)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireOlustur(int);
// double alan(const Pire);
// double cevre(const Pire);
void PireYoket(const Pire);


#endif
