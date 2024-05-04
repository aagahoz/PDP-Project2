#ifndef KUTUPHANE_H_
#define KUTUPHANE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"

#define MAX_SATIR_UZUNLUGU 100000 // Maksimum satır uzunluğu

int **matrisOlustur(FILE *dosya, int *satir_sayisi, int *sutun_sayisi, int max_satir_uzunlugu);
void matrisiYazdir(int **matris, int satir_sayisi, int sutun_sayisi);
void bellekSerbestBirak(int **matris, int satir_sayisi);
void printGrid(int bitkiIndex, int bocekIndex, int pireIndex, int sinekIndex,
			   Bitki bitkiler[], Bocek bocekler[], Pire pireler[], Sinek sinekler[], int satirSayisi, int sutunSayisi);
void findWinner(int bitkiIndex, int bocekIndex, int pireIndex, int sinekIndex,
                Bitki bitkiler[], Bocek bocekler[], Pire pireler[], Sinek sinekler[], int satirSayisi, int sutunSayisi);

#endif