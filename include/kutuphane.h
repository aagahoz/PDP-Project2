/**
 * @file  kutuphane.h
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#ifndef KUTUPHANE_H_
#define KUTUPHANE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"

#define MAX_SATIR_UZUNLUGU 30000 // Maksimum satır uzunluğu

int **matrisOlustur(FILE *dosya, int *satir_sayisi, int *sutun_sayisi, int max_satir_uzunlugu);
void matrisiYazdir(int **matris, int satir_sayisi, int sutun_sayisi);
void bellekSerbestBirak(int **matris, int satir_sayisi);
void printGrid(int bitkiIndex, int bocekIndex, int pireIndex, int sinekIndex,
			   Bitki bitkiler[], Bocek bocekler[], Pire pireler[], Sinek sinekler[], int satirSayisi, int sutunSayisi);
void findWinner(int bitkiIndex, int bocekIndex, int pireIndex, int sinekIndex,
                Bitki bitkiler[], Bocek bocekler[], Pire pireler[], Sinek sinekler[], int satirSayisi, int sutunSayisi);

#endif