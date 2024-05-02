#ifndef KUTUPHANE_H_
#define KUTUPHANE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SATIR_UZUNLUGU 100 // Maksimum satır uzunluğu


int **matrisOlustur(FILE *dosya, int *satir_sayisi, int *sutun_sayisi, int max_satir_uzunlugu);
void matrisiYazdir(int **matris, int satir_sayisi, int sutun_sayisi);
void bellekSerbestBirak(int **matris, int satir_sayisi);

#endif

