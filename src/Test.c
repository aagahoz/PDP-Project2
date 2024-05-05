/**
 * @file  Test.c
 * @description Soyut Sınıf Tasarımı ve Nesne Benzetimi
 * @course  2.Öğretim B Grubu 
 * @assignment  2.Ödev
 * @date   5.5.2024
 * @author  Abdullah Agah Özdemir - agah.ozdemir@ogr.sakarya.edu.tr
 */

#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "kutuphane.h"

int main()
{
	printf("\n\n\n\n");
	FILE *dosya;
	dosya = fopen("Veri.txt", "r");
	if (dosya == NULL)
	{
		printf("Veri dosyası bulunamadı veya açılamadı.\n");
		return 1;
	}

	int satir_sayisi = 0;
	int sutun_sayisi = 0;
	int **matris = matrisOlustur(dosya, &satir_sayisi, &sutun_sayisi, MAX_SATIR_UZUNLUGU);
	system("cls");
	matrisiYazdir(matris, satir_sayisi, sutun_sayisi);
	fclose(dosya);

	printf("\n");

	Bitki bitkiler[100000];
	Bocek bocekler[100000];
	Sinek sinekler[10000];
	Pire pireler[10000];

	int bitkiIndex = 0;
	int bocekIndex = 0;
	int sinekIndex = 0;
	int pireIndex = 0;

	int i, j, k, m, n;
	for (int i = 0; i < satir_sayisi; i++)
	{
		for (j = 0; j < sutun_sayisi; j++)
		{
			if (matris[i][j] >= 1 && matris[i][j] <= 9) // Bitki
			{
				bitkiler[bitkiIndex] = BitkiOlustur(matris[i][j]);
				bitkiler[bitkiIndex]->super->xCoord = i;
				bitkiler[bitkiIndex]->super->yCoord = j;
				bitkiIndex++;
			}
			else if (matris[i][j] >= 10 && matris[i][j] <= 20) // Bocek
			{
				bocekler[bocekIndex] = BocekOlustur(matris[i][j]);
				bocekler[bocekIndex]->super->xCoord = i;
				bocekler[bocekIndex]->super->yCoord = j;
				bocekIndex++;
			}
			else if (matris[i][j] >= 21 && matris[i][j] <= 50) // Sinek
			{
				sinekler[sinekIndex] = SinekOlustur(matris[i][j]);
				sinekler[sinekIndex]->super->super->xCoord = i;
				sinekler[sinekIndex]->super->super->yCoord = j;
				sinekIndex++;
			}
			else if (matris[i][j] >= 51 && matris[i][j] <= 99) // Pire
			{
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
	}
	free(matris);
	printf("---------Ilk Durum---------\n\n");
	printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
	system("pause");
	system("cls");
	printf("\n");

	int bulunanBocekMi = 0;
	int bulunanPireMi = 0;
	int bulunanSinekMi = 0;
	int bulunanBitkiMi = 0;

	Bocek tempBocekPointer;
	Pire tempPirePointer;
	Sinek tempSinekPointer;
	Bitki tempBitkiPointer;
	// -----------------------------------------------------------------------------
	// -----------------------------------------------------------------------------
	// YEME KISMI ------------------------------------------------------------------
	printf("---------ADIMLAR-------\n\n");

	for (int i = 0; i < satir_sayisi; i++)
	{
		for (j = 0; j < sutun_sayisi; j++)
		{
			int xCoord = i;
			int yCoord = j;
			for (k = 0; k < bitkiIndex; k++)
			{
				if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
				{
					char *durum = bitkiler[k]->super->tur;
					if (!strcmp(durum, "B"))
					{
						bulunanBitkiMi = 1;
						tempBitkiPointer = bitkiler[k];
						break;
					}
				}
			}

			for (k = 0; k < bocekIndex; k++)
			{
				if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
				{
					char *durum = bocekler[k]->super->tur;
					if (!strcmp(durum, "C"))
					{
						bulunanBocekMi = 1;
						tempBocekPointer = bocekler[k];
						break;
					}
				}
			}

			for (k = 0; k < pireIndex; k++)
			{
				if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
				{
					char *durum = pireler[k]->super->super->tur;
					if (!strcmp(durum, "P"))
					{
						bulunanPireMi = 1;
						tempPirePointer = pireler[k];
						break;
					}
				}
			}

			for (k = 0; k < sinekIndex; k++)
			{
				if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
				{
					char *durum = sinekler[k]->super->super->tur;
					if (!strcmp(durum, "S"))
					{
						bulunanSinekMi = 1;
						tempSinekPointer = sinekler[k];
						break;
					}
				}
			}

			// -----------------------------------------------------------------------------
			// -----------------------------------------------------------------------------
			// YENECEK BULMA KISMI ---------------------------------------------------------
			if (bulunanBitkiMi)
			{
				char *durum = tempBitkiPointer->super->tur;
				int xKoordinat = tempBitkiPointer->super->xCoord;
				int yKoordinat = tempBitkiPointer->super->yCoord;
				int degeri = tempBitkiPointer->super->deger;
				bulunanBitkiMi = 0;

				int bitkiYasiyorMu = 0;
				if (strcmp(durum, "X"))
				{
					// printf("Bitki Yasiyor\n");
					bitkiYasiyorMu = 1;
				}

				int icDongu = j + 1;
				for (m = i; m < satir_sayisi; m++)
				{
					for (n = icDongu; n < sutun_sayisi; n++)
					{
						int xCoord = m;
						int yCoord = n;
						for (k = 0; k < bitkiIndex; k++)
						{
							if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
							{
								char *durum = bitkiler[k]->super->tur;
								if (!strcmp(durum, "B"))
								{
									int yenilecekDeger = bitkiler[k]->super->deger;
									int ilkDeger = tempBitkiPointer->super->deger;
									int ikinciDeger = bitkiler[k]->super->deger;

									if (ilkDeger > ikinciDeger)
									{
										bitkiler[k]->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									else if (ilkDeger == ikinciDeger)
									{
										bitkiler[k]->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									else
									{
										tempBitkiPointer->super->tur = "X";
										bitkiYasiyorMu = 0;
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									break;
								}
								if (bitkiYasiyorMu == 0)
								{
									break;
								}
							}
						}
						if (bitkiYasiyorMu == 0)
						{
							break;
						}

						for (k = 0; k < bocekIndex; k++)
						{
							if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
							{
								char *durum = bocekler[k]->super->tur;
								if (!strcmp(durum, "C"))
								{
									int yenilecekDeger = bocekler[k]->super->deger;
									tempBitkiPointer->super->tur = "X";
									bitkiYasiyorMu = 0;
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (bitkiYasiyorMu == 0)
								{
									break;
								}
							}
						}
						if (bitkiYasiyorMu == 0)
						{
							break;
						}

						for (k = 0; k < pireIndex; k++)
						{
							if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
							{
								char *durum = pireler[k]->super->super->tur;
								if (!strcmp(durum, "P"))
								{
									int yenilecekDeger = pireler[k]->super->super->deger;
									pireler[k]->super->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (bitkiYasiyorMu == 0)
								{
									break;
								}
							}
						}
						if (bitkiYasiyorMu == 0)
						{
							break;
						}

						for (k = 0; k < sinekIndex; k++)
						{
							if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
							{
								char *durum = sinekler[k]->super->super->tur;
								if (!strcmp(durum, "S"))
								{
									int yenilecekDeger = sinekler[k]->super->super->deger;
									sinekler[k]->super->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (bitkiYasiyorMu == 0)
								{
									break;
								}
							}
						}
						if (bitkiYasiyorMu == 0)
						{
							break;
						}
					}
					if (n == sutun_sayisi)
					{
						if (m != (sutun_sayisi - 2))
						{
							int x = m + 1;
							int y = 0;
							int xCoord = x;
							int yCoord = y;
							for (k = 0; k < bitkiIndex; k++)
							{
								if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
								{
									char *durum = bitkiler[k]->super->tur;
									if (!strcmp(durum, "B"))
									{
										int yenilecekDeger = bitkiler[k]->super->deger;
										int ilkDeger = tempBitkiPointer->super->deger;
										int ikinciDeger = bitkiler[k]->super->deger;

										if (ilkDeger > ikinciDeger)
										{
											bitkiler[k]->super->tur = "X";
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										else if (ilkDeger == ikinciDeger)
										{
											bitkiler[k]->super->tur = "X";
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										else
										{
											tempBitkiPointer->super->tur = "X";
											bitkiYasiyorMu = 0;
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										break;
									}
									if (bitkiYasiyorMu == 0)
									{
										break;
									}
								}
							}
							if (bitkiYasiyorMu == 0)
							{
								break;
							}

							for (k = 0; k < bocekIndex; k++)
							{
								if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
								{
									char *durum = bocekler[k]->super->tur;
									if (!strcmp(durum, "C"))
									{
										int yenilecekDeger = bitkiler[k]->super->deger;
										tempBitkiPointer->super->tur = "X";
										bitkiYasiyorMu = 0;
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (bitkiYasiyorMu == 0)
									{
										break;
									}
								}
							}
							if (bitkiYasiyorMu == 0)
							{
								break;
							}

							for (k = 0; k < pireIndex; k++)
							{
								if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
								{
									char *durum = pireler[k]->super->super->tur;
									if (!strcmp(durum, "P"))
									{
										int yenilecekDeger = pireler[k]->super->super->deger;
										pireler[k]->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (bitkiYasiyorMu == 0)
									{
										break;
									}
								}
							}
							if (bitkiYasiyorMu == 0)
							{
								break;
							}

							for (k = 0; k < sinekIndex; k++)
							{
								if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
								{
									char *durum = sinekler[k]->super->super->tur;
									if (!strcmp(durum, "S"))
									{
										int yenilecekDeger = sinekler[k]->super->super->deger;
										sinekler[k]->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (bitkiYasiyorMu == 0)
									{
										break;
									}
								}
							}
							if (bitkiYasiyorMu == 0)
							{
								break;
							}
						}
						icDongu = 1;
					}
				}
			}
			else if (bulunanBocekMi)
			{
				char *durum = tempBocekPointer->super->tur;
				int xKoordinat = tempBocekPointer->super->xCoord;
				int yKoordinat = tempBocekPointer->super->yCoord;
				int degeri = tempBocekPointer->super->deger;
				bulunanBocekMi = 0;

				int bocekYasiyorMu = 0;
				if (strcmp(durum, "X"))
				{
					bocekYasiyorMu = 1;
				}

				int icDongu = j + 1;
				for (m = i; m < satir_sayisi; m++)
				{
					for (n = icDongu; n < sutun_sayisi; n++)
					{
						int xCoord = m;
						int yCoord = n;
						for (k = 0; k < bitkiIndex; k++)
						{
							if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
							{
								char *durum = bitkiler[k]->super->tur;
								if (!strcmp(durum, "B"))
								{
									int yenilecekDeger = bitkiler[k]->super->deger;
									bitkiler[k]->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (bocekYasiyorMu == 0)
								{
									break;
								}
							}
						}
						if (bocekYasiyorMu == 0)
						{
							break;
						}

						for (k = 0; k < bocekIndex; k++)
						{
							if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
							{
								char *durum = bocekler[k]->super->tur;
								if (!strcmp(durum, "C"))
								{
									int yenilecekDeger = bocekler[k]->super->deger;
									int ilkDeger = tempBocekPointer->super->deger;
									int ikinciDeger = bocekler[k]->super->deger;

									if (ilkDeger > ikinciDeger)
									{
										bocekler[k]->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									else if (ilkDeger == ikinciDeger)
									{
										bocekler[k]->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									else
									{
										tempBocekPointer->super->tur = "X";
										bocekYasiyorMu = 0;
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									break;
								}
								if (bocekYasiyorMu == 0)
								{
									break;
								}
							}
						}

						for (k = 0; k < pireIndex; k++)
						{
							if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
							{
								char *durum = pireler[k]->super->super->tur;
								if (!strcmp(durum, "P"))
								{
									int yenilecekDeger = pireler[k]->super->super->deger;
									pireler[k]->super->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (bocekYasiyorMu == 0)
								{
									break;
								}
							}
						}

						for (k = 0; k < sinekIndex; k++)
						{
							if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
							{
								char *durum = sinekler[k]->super->super->tur;
								if (!strcmp(durum, "S"))
								{
									int yenilecekDeger = sinekler[k]->super->super->deger;
									bocekYasiyorMu = 0;
									tempBocekPointer->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (bocekYasiyorMu == 0)
								{
									break;
								}
							}
						}
					}
					if (bocekYasiyorMu == 0)
					{
						break;
					}
					if (n == sutun_sayisi)
					{
						if (m != (sutun_sayisi - 2))
						{
							int x = m + 1;
							int y = 0;
							int xCoord = x;
							int yCoord = y;
							for (k = 0; k < bitkiIndex; k++)
							{
								if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
								{
									char *durum = bitkiler[k]->super->tur;
									if (!strcmp(durum, "B"))
									{
										int yenilecekDeger = bitkiler[k]->super->deger;
										break;
									}
								}
								if (bocekYasiyorMu == 0)
								{
									break;
								}
							}

							for (k = 0; k < bocekIndex; k++)
							{
								if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
								{
									char *durum = bocekler[k]->super->tur;
									if (!strcmp(durum, "C"))
									{
										int yenilecekDeger = bocekler[k]->super->deger;

										int ilkDeger = tempBocekPointer->super->deger;
										int ikinciDeger = bocekler[k]->super->deger;
										if (ilkDeger > ikinciDeger)
										{
											bocekler[k]->super->tur = "X";
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										else if (ilkDeger == ikinciDeger)
										{
											bocekler[k]->super->tur = "X";
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										else
										{
											tempBocekPointer->super->tur = "X";
											bocekYasiyorMu = 0;
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										break;
									}
									if (bocekYasiyorMu == 0)
									{
										break;
									}
								}
							}

							for (k = 0; k < pireIndex; k++)
							{
								if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
								{
									char *durum = pireler[k]->super->super->tur;
									if (!strcmp(durum, "P"))
									{
										int yenilecekDeger = pireler[k]->super->super->deger;
										pireler[k]->super->super->tur = "X";
										break;
									}
									if (bocekYasiyorMu == 0)
									{
										break;
									}
								}
							}

							for (k = 0; k < sinekIndex; k++)
							{
								if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
								{
									char *durum = sinekler[k]->super->super->tur;
									if (!strcmp(durum, "S"))
									{
										int yenilecekDeger = sinekler[k]->super->super->deger;
										bocekYasiyorMu = 0;
										tempBocekPointer->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
								}
							}
						}
						icDongu = 1;
					}
					if (bocekYasiyorMu == 0)
					{
						break;
					}
				}
			}
			else if (bulunanPireMi)
			{
				char *durum = tempPirePointer->super->super->tur;
				int xKoordinat = tempPirePointer->super->super->xCoord;
				int yKoordinat = tempPirePointer->super->super->yCoord;

				int degeri = tempPirePointer->super->super->deger;
				bulunanPireMi = 0;

				int pireYasiyorMu = 0;
				if (strcmp(durum, "X"))
				{
					pireYasiyorMu = 1;
				}

				int icDongu = j + 1;
				for (m = i; m < satir_sayisi; m++)
				{
					for (n = icDongu; n < sutun_sayisi; n++)
					{
						int xCoord = m;
						int yCoord = n;
						for (k = 0; k < bitkiIndex; k++)
						{
							if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
							{
								char *durum = bitkiler[k]->super->tur;
								if (!strcmp(durum, "B"))
								{
									int yenilecekDeger = bitkiler[k]->super->deger;
									pireYasiyorMu = 0;
									tempPirePointer->super->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (pireYasiyorMu == 0)
								{
									break;
								}
							}
						}

						for (k = 0; k < bocekIndex; k++)
						{
							if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
							{
								char *durum = bocekler[k]->super->tur;
								if (!strcmp(durum, "C"))
								{
									int yenilecekDeger = bocekler[k]->super->deger;
									pireYasiyorMu = 0;
									tempPirePointer->super->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (pireYasiyorMu == 0)
								{
									break;
								}
							}
						}

						for (k = 0; k < pireIndex; k++)
						{
							if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
							{
								char *durum = pireler[k]->super->super->tur;
								if (!strcmp(durum, "P"))
								{
									int yenilecekDeger = pireler[k]->super->super->deger;
									int ilkDeger = tempPirePointer->super->super->deger;
									int ikinciDeger = pireler[k]->super->super->deger;
									if (ilkDeger > ikinciDeger)
									{
										pireler[k]->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									else if (ilkDeger == ikinciDeger)
									{
										pireler[k]->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									else
									{
										tempPirePointer->super->super->tur = "X";
										pireYasiyorMu = 0;
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									break;
								}
								if (pireYasiyorMu == 0)
								{
									break;
								}
							}
						}

						for (k = 0; k < sinekIndex; k++)
						{
							if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
							{
								char *durum = sinekler[k]->super->super->tur;
								if (!strcmp(durum, "S"))
								{
									int yenilecekDeger = sinekler[k]->super->super->deger;
									tempPirePointer->super->super->tur = "X";
									pireYasiyorMu = 0;
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (pireYasiyorMu == 0)
								{
									break;
								}
							}
						}
					}
					if (n == sutun_sayisi)
					{
						if (m != (sutun_sayisi - 2))
						{
							int x = m + 1;
							int y = 0;
							int xCoord = x;
							int yCoord = y;
							for (k = 0; k < bitkiIndex; k++)
							{
								if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
								{
									char *durum = bitkiler[k]->super->tur;
									if (!strcmp(durum, "B"))
									{
										int yenilecekDeger = bitkiler[k]->super->deger;
										pireYasiyorMu = 0;
										tempPirePointer->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (pireYasiyorMu == 0)
									{
										break;
									}
								}
							}

							for (k = 0; k < bocekIndex; k++)
							{
								if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
								{
									char *durum = bocekler[k]->super->tur;
									if (!strcmp(durum, "C"))
									{
										int yenilecekDeger = bocekler[k]->super->deger;
										pireYasiyorMu = 0;
										tempPirePointer->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (pireYasiyorMu == 0)
									{
										break;
									}
								}
							}

							for (k = 0; k < pireIndex; k++)
							{
								if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
								{
									char *durum = pireler[k]->super->super->tur;
									if (!strcmp(durum, "P"))
									{
										int yenilecekDeger = pireler[k]->super->super->deger;
										int ilkDeger = tempPirePointer->super->super->deger;
										int ikinciDeger = pireler[k]->super->super->deger;
										if (ilkDeger > ikinciDeger)
										{
											pireler[k]->super->super->tur = "X";
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										else if (ilkDeger == ikinciDeger)
										{
											pireler[k]->super->super->tur = "X";
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										else
										{
											tempPirePointer->super->super->tur = "X";
											pireYasiyorMu = 0;
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										break;
									}
									if (pireYasiyorMu == 0)
									{
										break;
									}
								}
							}

							for (k = 0; k < sinekIndex; k++)
							{
								if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
								{
									char *durum = sinekler[k]->super->super->tur;
									if (!strcmp(durum, "S"))
									{
										int yenilecekDeger = sinekler[k]->super->super->deger;
										tempPirePointer->super->super->tur = "X";
										pireYasiyorMu = 0;
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (pireYasiyorMu == 0)
									{
										break;
									}
								}
							}
							if (pireYasiyorMu == 0)
							{
								break;
							}
						}
						icDongu = 1;
					}
					if (pireYasiyorMu == 0)
					{
						break;
					}
				}
			}
			else if (bulunanSinekMi)
			{
				char *durum = tempSinekPointer->super->super->tur;
				int xKoordinat = tempSinekPointer->super->super->xCoord;
				int yKoordinat = tempSinekPointer->super->super->yCoord;

				int degeri = tempSinekPointer->super->super->deger;
				bulunanSinekMi = 0;

				int sinekYasiyorMu = 0;
				if (strcmp(durum, "X"))
				{
					sinekYasiyorMu = 1;
				}

				int icDongu = j + 1;
				for (m = i; m < satir_sayisi; m++)
				{
					for (n = icDongu; n < sutun_sayisi; n++)
					{
						int xCoord = m;
						int yCoord = n;
						for (k = 0; k < bitkiIndex; k++)
						{
							if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
							{
								char *durum = bitkiler[k]->super->tur;
								if (!strcmp(durum, "B"))
								{
									int yenilecekDeger = bitkiler[k]->super->deger;
									tempSinekPointer->super->super->tur = "X";
									sinekYasiyorMu = 0;
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (sinekYasiyorMu == 0)
								{
									break;
								}
							}
						}

						for (k = 0; k < bocekIndex; k++)
						{
							if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
							{
								char *durum = bocekler[k]->super->tur;
								if (!strcmp(durum, "C"))
								{
									int yenilecekDeger = bocekler[k]->super->deger;
									bocekler[k]->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (sinekYasiyorMu == 0)
								{
									break;
								}
							}
						}

						for (k = 0; k < pireIndex; k++)
						{
							if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
							{
								char *durum = pireler[k]->super->super->tur;
								if (!strcmp(durum, "P"))
								{
									int yenilecekDeger = pireler[k]->super->super->deger;
									pireler[k]->super->super->tur = "X";
									system("cls");
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									break;
								}
								if (sinekYasiyorMu == 0)
								{
									break;
								}
							}
						}

						for (k = 0; k < sinekIndex; k++)
						{
							if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
							{
								char *durum = sinekler[k]->super->super->tur;
								if (!strcmp(durum, "S"))
								{
									int yenilecekDeger = sinekler[k]->super->super->deger;
									int ilkDeger = tempSinekPointer->super->super->deger;
									int ikinciDeger = sinekler[k]->super->super->deger;
									if (ilkDeger > ikinciDeger)
									{
										sinekler[k]->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									else if (ilkDeger == ikinciDeger)
									{
										sinekler[k]->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									else
									{
										tempSinekPointer->super->super->tur = "X";
										sinekYasiyorMu = 0;
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
									}
									break;
								}
								if (sinekYasiyorMu == 0)
								{
									break;
								}
							}
						}
					}
					if (n == sutun_sayisi)
					{
						if (m != (sutun_sayisi - 2))
						{
							int x = m + 1;
							int y = 0;
							int xCoord = x;
							int yCoord = y;
							for (k = 0; k < bitkiIndex; k++)
							{
								if (bitkiler[k]->super->xCoord == xCoord && bitkiler[k]->super->yCoord == yCoord)
								{
									char *durum = bitkiler[k]->super->tur;
									if (!strcmp(durum, "B"))
									{
										int yenilecekDeger = bitkiler[k]->super->deger;
										tempSinekPointer->super->super->tur = "X";
										sinekYasiyorMu = 0;
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (sinekYasiyorMu == 0)
									{
										break;
									}
								}
							}

							for (k = 0; k < bocekIndex; k++)
							{
								if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
								{
									char *durum = bocekler[k]->super->tur;
									if (!strcmp(durum, "C"))
									{
										int yenilecekDeger = bocekler[k]->super->deger;
										bocekler[k]->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (sinekYasiyorMu == 0)
									{
										break;
									}
								}
							}

							for (k = 0; k < pireIndex; k++)
							{
								if (pireler[k]->super->super->xCoord == xCoord && pireler[k]->super->super->yCoord == yCoord)
								{
									char *durum = pireler[k]->super->super->tur;
									if (!strcmp(durum, "P"))
									{
										int yenilecekDeger = pireler[k]->super->super->deger;
										pireler[k]->super->super->tur = "X";
										system("cls");
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										break;
									}
									if (sinekYasiyorMu == 0)
									{
										break;
									}
								}
							}

							for (k = 0; k < sinekIndex; k++)
							{
								if (sinekler[k]->super->super->xCoord == xCoord && sinekler[k]->super->super->yCoord == yCoord)
								{
									char *durum = sinekler[k]->super->super->tur;
									if (!strcmp(durum, "S"))
									{
										int yenilecekDeger = sinekler[k]->super->super->deger;
										int ilkDeger = tempSinekPointer->super->super->deger;
										int ikinciDeger = sinekler[k]->super->super->deger;
										if (ilkDeger > ikinciDeger)
										{
											sinekler[k]->super->super->tur = "X";
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										else if (ilkDeger == ikinciDeger)
										{
											sinekler[k]->super->super->tur = "X";
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										else
										{
											tempSinekPointer->super->super->tur = "X";
											sinekYasiyorMu = 0;
											system("cls");
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
										}
										break;
									}
									if (sinekYasiyorMu == 0)
									{
										break;
									}
								}
							}
						}
						icDongu = 1;
					}
					if (sinekYasiyorMu == 0)
					{
						break;
					}
				}
			}
			printf("\n\n");
		}
	}
	printf("\n");
	printf("---------SONUC-------\n\n");
	system("cls");
	printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
	findWinner(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler, satir_sayisi, sutun_sayisi);
	printf("\n");

	return 0;
}