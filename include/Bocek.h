/**
 * @file  Bocek.h
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK{
	Canli super;
	
	void (*yoket)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;

Bocek BocekOlustur(int);
// double alan(const Bocek);
// double cevre(const Bocek);
void BocekYoket(const Bocek);


#endif 