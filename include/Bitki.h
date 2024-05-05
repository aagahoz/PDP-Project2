/**
 * @file  Bitki.h
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI{
	Canli super;
	
	void (*yoket)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int);
// double alan(const Bitki);
// double cevre(const Bitki);
void BitkiYoket(const Bitki);
#endif
