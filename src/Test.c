#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "kutuphane.h"

int main()
{

	printf("\n");

	FILE *dosya;
	dosya = fopen("src/Veri.txt", "r");

	if (dosya == NULL)
	{
		printf("Dosya bulunamadı veya açılamadı.\n");
		return 1;
	}

	int satir_sayisi = 0;
	int sutun_sayisi = 0;

	// Matrisi oluştur
	int **matris = matrisOlustur(dosya, &satir_sayisi, &sutun_sayisi, MAX_SATIR_UZUNLUGU);

	// Matrisi ekrana yazdır
	matrisiYazdir(matris, satir_sayisi, sutun_sayisi);

	fclose(dosya);

	printf("\n");

	Bitki bitkiler[100];
	Bocek bocekler[100];
	Sinek sinekler[100];
	Pire pireler[100];

	int bitkiIndex = 0;
	int bocekIndex = 0;
	int sinekIndex = 0;
	int pireIndex = 0;

	int i, j, k;
	for (int i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (matris[i][j] >= 1 && matris[i][j] <= 9) // Bitki
			{
				printf("B ");
				bitkiler[bitkiIndex] = BitkiOlustur(matris[i][j]);
				bitkiler[bitkiIndex]->super->xCoord = i;
				bitkiler[bitkiIndex]->super->yCoord = j;
				bitkiIndex++;
			}
			else if (matris[i][j] >= 10 && matris[i][j] <= 20) // Bocek
			{
				printf("C ");
				bocekler[bocekIndex] = BocekOlustur(matris[i][j]);
				bocekler[bocekIndex]->super->xCoord = i;
				bocekler[bocekIndex]->super->yCoord = j;
				bocekIndex++;
			}
			else if (matris[i][j] >= 21 && matris[i][j] <= 50) // Sinek
			{
				printf("S ");
				sinekler[sinekIndex] = SinekOlustur(matris[i][j]);
				sinekler[sinekIndex]->super->super->xCoord = i;
				sinekler[sinekIndex]->super->super->yCoord = j;
				sinekIndex++;
			}
			else if (matris[i][j] >= 51 && matris[i][j] <= 99) // Pire
			{
				printf("P ");
				pireler[pireIndex] = PireOlustur(matris[i][j]);
				pireler[pireIndex]->super->super->xCoord = i;
				pireler[pireIndex]->super->super->yCoord = j;
				pireIndex++;
			}
			else
			{
				printf("Girilen sayı belirtilen aralıklarda değil.\n");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");

	// printf("Bitkiler\n");
	for (int i = 0; i < bitkiIndex - 1; i++)
	{
		char *str = bitkiler[i]->super->gorunum(bitkiler[i]->super, bitkiler[i]);
		// printf("%s\n", str);
	}

	// printf("Bocekler\n");
	for (int i = 0; i < bocekIndex; i++)
	{
		char *str = bocekler[i]->super->gorunum(bocekler[i]->super, bocekler[i]);
		// printf("%s\n", str);
	}

	// printf("Sinekler\n");
	for (int i = 0; i < sinekIndex; i++)
	{
		char *str = sinekler[i]->super->super->gorunum(sinekler[i]->super->super, sinekler[i]);
		// printf("%s\n", str);
	}
	// printf("Pireler\n");
	for (int i = 0; i < pireIndex; i++)
	{
		char *str = pireler[i]->super->super->gorunum(pireler[i]->super->super, pireler[i]);
		// printf("%s\n", str);
	}

	int bulundu = 0;
	for (int i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			int xCoord = i;
			int yCoord = j;
			for (k = 0; k < bitkiIndex; k++)
			{
				if ( bitkiler[k]->super->xCoord == xCoord  && bitkiler[k]->super->yCoord == yCoord )
				{
					printf("%s ", bitkiler[k]->super->tur);
					break;
				}
			}

			for (k = 0; k < bocekIndex; k++)
			{
				if ( bocekler[k]->super->xCoord == xCoord  && bocekler[k]->super->yCoord == yCoord )
				{
					printf("%s ", bocekler[k]->super->tur);
					break;
				}
			}

			for (k = 0; k < pireIndex; k++)
			{
				if ( pireler[k]->super->super->xCoord == xCoord  && pireler[k]->super->super->yCoord == yCoord )
				{
					printf("%s ", pireler[k]->super->super->tur);
					break;
				}
			}

			for (k = 0; k < sinekIndex; k++)
			{
				if ( sinekler[k]->super->super->xCoord == xCoord  && sinekler[k]->super->super->yCoord == yCoord )
				{
					printf("%s ", sinekler[k]->super->super->tur);
					break;
				}
			}
		}
		printf("\n");
	}

	return 0;
}