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