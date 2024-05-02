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
