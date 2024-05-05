/**
 * @file  Sinek.h
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK{
	Bocek super;
	
	void (*yoket)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(int);
// double alan(const Sinek);
// double cevre(const Sinek);
void SinekYoket(const Sinek);


#endif
