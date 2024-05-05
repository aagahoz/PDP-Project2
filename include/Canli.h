/**
 * @file  Canlı.h
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

#include "Habitat.h"

struct CANLI{
	Habitat superHabitat;
	int deger;
	char* tur;
	int xCoord;
	int yCoord;

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
