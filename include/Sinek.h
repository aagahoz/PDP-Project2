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
