#include "kutuphane.h"

#include <stdio.h>

int **matrisOlustur(FILE *dosya, int *satir_sayisi, int *sutun_sayisi, int max_satir_uzunlugu)
{
    char satir[max_satir_uzunlugu];
    int satirIndex = 0;
    int sutunIndex = 0;

    while (fgets(satir, max_satir_uzunlugu, dosya) != NULL)
    {
        char *token = strtok(satir, " ");

        sutunIndex = 0;
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            sutunIndex++;
        }

        if (sutunIndex > *sutun_sayisi)
            *sutun_sayisi = sutunIndex;

        (*satir_sayisi)++;
    }

    fseek(dosya, 0, SEEK_SET);

    int **matris = (int **)malloc((*satir_sayisi) * sizeof(int *));
    for (int i = 0; i < *satir_sayisi; i++)
    {
        matris[i] = (int *)malloc((*sutun_sayisi) * sizeof(int));
    }

    for (int i = 0; i < *satir_sayisi; i++)
    {
        for (int j = 0; j < *sutun_sayisi; j++)
        {
            matris[i][j] = 0;
        }
    }

    while (fgets(satir, max_satir_uzunlugu, dosya) != NULL && satirIndex < *satir_sayisi)
    {
        char *token = strtok(satir, " "); // Boşluk karakterlerine göre satırı parçala

        sutunIndex = 0;
        while (token != NULL && sutunIndex < *sutun_sayisi)
        {
            matris[satirIndex][sutunIndex] = atoi(token);
            token = strtok(NULL, " ");
            sutunIndex++;
        }

        satirIndex++;
    }

    return matris;
}

void matrisiYazdir(int **matris, int satir_sayisi, int sutun_sayisi)
{
    printf("---------Veriler.txt-------\n");
    for (int i = 0; i < satir_sayisi; i++)
    {
        for (int j = 0; j < sutun_sayisi; j++)
        {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

void bellekSerbestBirak(int **matris, int satir_sayisi)
{
    for (int i = 0; i < satir_sayisi; i++)
    {
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
    printf("\n");
}

void findWinner(int bitkiIndex, int bocekIndex, int pireIndex, int sinekIndex,
                Bitki bitkiler[], Bocek bocekler[], Pire pireler[], Sinek sinekler[])
{
    int xEksen = -1;
    int yEksen = -1;
    char*  kazananTur;
    
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

                    char *durum = bitkiler[k]->super->tur;
                    if (strcmp(durum, "X"))
                    {
                        xEksen = bitkiler[k]->super->xCoord;
                        yEksen = bitkiler[k]->super->yCoord;
                        kazananTur =  durum;
                    }
                    break;
                }
            }

            for (k = 0; k < bocekIndex; k++)
            {
                if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
                {
                    char *durum = bocekler[k]->super->tur;
                    if (strcmp(durum, "X"))
                    {
                        xEksen = bocekler[k]->super->xCoord;
                        yEksen = bocekler[k]->super->yCoord;
                        kazananTur =  durum;
                    }
                    break;
                }
            }

            for (k = 0; k < pireIndex; k++)
            {
                if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
                {
                    char *durum = pireler[k]->super->super->tur;
                    if (strcmp(durum, "X"))
                    {
                        xEksen = pireler[k]->super->super->xCoord;
                        yEksen = pireler[k]->super->super->yCoord;
                        kazananTur =  durum;
                    }
                    break;
                }
            }

            for (k = 0; k < sinekIndex; k++)
            {
                if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
                {
                    char *durum = sinekler[k]->super->super->tur;
                    if (strcmp(durum, "X"))
                    {
                        xEksen = sinekler[k]->super->super->xCoord;
                        yEksen = sinekler[k]->super->super->yCoord;
                        kazananTur =  durum;
                    }
                    break;
                }
            }
        }
        printf("\n");
    }
    printf("Kazanan: %s : (%d,%d)\n\n",kazananTur, xEksen, yEksen);
    printf("\n");
}