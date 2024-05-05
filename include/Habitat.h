/**
 * @file  Habitat.h
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef HABITAT_H
#define HABITAT_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

struct HABITAT{
	int yasiyorMu;

	void (*setDeger)(struct HABITAT*,int);
	char* (*gorunum)(struct HABITAT*,void*);
	double (*alan)();
	double (*cevre)();
	void (*yoket)(struct HABITAT*);
};
typedef struct HABITAT* Habitat;

Habitat HabitatOlustur(int);
void setYasiyorMu(const Habitat,int);
char* gorunumHabitat(const Habitat,void*);
void HabitatYoket(const Habitat);

#endif
