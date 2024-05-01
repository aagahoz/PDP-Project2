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
