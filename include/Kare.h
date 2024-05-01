#ifndef KARE_H
#define KARE_H

#include "Canli.h"

struct KARE{
	Canli super;
	
	void (*yoket)(struct KARE*);
};
typedef struct KARE* Kare;

Kare KareOlustur(int);
// double alan(const Kare);
// double cevre(const Kare);
void KareYoket(const Kare);
#endif
