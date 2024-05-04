#include "kutuphane.h"

#include <stdio.h>


// Dosyadan matrisi oluşturan fonksiyon
int **matrisOlustur(FILE *dosya, int *satir_sayisi, int *sutun_sayisi, int max_satir_uzunlugu) {
    char satir[max_satir_uzunlugu];
    int satirIndex = 0;
    int sutunIndex = 0;

    // Dosyadaki satır ve sütun sayısını bul
    while (fgets(satir, max_satir_uzunlugu, dosya) != NULL) {
        char *token = strtok(satir, " "); // Boşluk karakterlerine göre satırı parçala

        sutunIndex = 0;
        while (token != NULL) {
            token = strtok(NULL, " "); // Bir sonraki rakamı al
            sutunIndex++;
        }

        if (sutunIndex > *sutun_sayisi)
            *sutun_sayisi = sutunIndex;

        (*satir_sayisi)++;
    }

    // Dosyayı tekrar başa al
    fseek(dosya, 0, SEEK_SET);

    // Matrisi dinamik olarak oluştur
    int **matris = (int **)malloc((*satir_sayisi) * sizeof(int *));
    for (int i = 0; i < *satir_sayisi; i++) {
        matris[i] = (int *)malloc((*sutun_sayisi) * sizeof(int));
    }

    // Matrisi sıfırla
    for (int i = 0; i < *satir_sayisi; i++) {
        for (int j = 0; j < *sutun_sayisi; j++) {
            matris[i][j] = 0;
        }
    }

    // Dosyadan verileri oku ve matrise yerleştir
    while (fgets(satir, max_satir_uzunlugu, dosya) != NULL && satirIndex < *satir_sayisi) {
        char *token = strtok(satir, " "); // Boşluk karakterlerine göre satırı parçala

        sutunIndex = 0;
        while (token != NULL && sutunIndex < *sutun_sayisi) {
            matris[satirIndex][sutunIndex] = atoi(token); // Stringi integera dönüştür ve matrise kaydet
            token = strtok(NULL, " "); // Bir sonraki rakamı al
            sutunIndex++;
        }

        satirIndex++;
    }

    return matris;
}

// Matrisi ekrana yazdıran fonksiyon
void matrisiYazdir(int **matris, int satir_sayisi, int sutun_sayisi) {
    printf("Matris:\n");
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

// Belleği serbest bırakan fonksiyon
void bellekSerbestBirak(int **matris, int satir_sayisi) {
    for (int i = 0; i < satir_sayisi; i++) {
        free(matris[i]);
    }
    free(matris);
}

void printGrid(int bitkiIndex, int bocekIndex, int pireIndex, int sinekIndex,
			   Bitki bitkiler[], Bocek bocekler[], Pire pireler[], Sinek sinekler[])
{

	int i, j, k;
	for (int i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			int xCoord = i;
			int yCoord = j;
			for (k = 0; k < bitkiIndex; k++)
			{
				if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
				{
					printf("%s ", bitkiler[k]->super->tur);
					break;
				}
			}

			for (k = 0; k < bocekIndex; k++)
			{
				if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
				{
					printf("%s ", bocekler[k]->super->tur);
					break;
				}
			}

			for (k = 0; k < pireIndex; k++)
			{
				if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
				{
					printf("%s ", pireler[k]->super->super->tur);
					break;
				}
			}

			for (k = 0; k < sinekIndex; k++)
			{
				if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
				{
					printf("%s ", sinekler[k]->super->super->tur);
					break;
				}
			}
		}
		printf("\n");
	}
}