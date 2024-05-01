#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

struct CANLI{
	int deger;
	char* tur;

	void (*setDeger)(struct CANLI*,int);
	char* (*gorunum)(struct CANLI*,void*);
	double (*alan)();
	double (*cevre)();
	void (*yoket)(struct CANLI*);
};
typedef struct CANLI* Canli;

Canli CanliOlustur(int);
void setDeger(const Canli,int);
void setTur(const Canli,char*);
char* gorunum(const Canli,void*);
void CanliYoket(const Canli);

#endif
