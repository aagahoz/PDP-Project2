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

	int **matris = matrisOlustur(dosya, &satir_sayisi, &sutun_sayisi, MAX_SATIR_UZUNLUGU);

	matrisiYazdir(matris, satir_sayisi, sutun_sayisi);

	fclose(dosya);

	printf("\n");

	Bitki bitkiler[1000];
	Bocek bocekler[1000];
	Sinek sinekler[1000];
	Pire pireler[1000];

	int bitkiIndex = 0;
	int bocekIndex = 0;
	int sinekIndex = 0;
	int pireIndex = 0;

	int i, j, k, m, n;
	for (int i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (matris[i][j] >= 1 && matris[i][j] <= 9) // Bitki
			{
				// printf("B ");
				bitkiler[bitkiIndex] = BitkiOlustur(matris[i][j]);
				bitkiler[bitkiIndex]->super->xCoord = i;
				bitkiler[bitkiIndex]->super->yCoord = j;
				bitkiIndex++;
			}
			else if (matris[i][j] >= 10 && matris[i][j] <= 20) // Bocek
			{
				// printf("C ");
				bocekler[bocekIndex] = BocekOlustur(matris[i][j]);
				bocekler[bocekIndex]->super->xCoord = i;
				bocekler[bocekIndex]->super->yCoord = j;
				bocekIndex++;
			}
			else if (matris[i][j] >= 21 && matris[i][j] <= 50) // Sinek
			{
				// printf("S ");
				sinekler[sinekIndex] = SinekOlustur(matris[i][j]);
				sinekler[sinekIndex]->super->super->xCoord = i;
				sinekler[sinekIndex]->super->super->yCoord = j;
				sinekIndex++;
			}
			else if (matris[i][j] >= 51 && matris[i][j] <= 99) // Pire
			{
				// printf("P ");
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

	printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);
	printf("\n");

	int bulunanBocekMi = 0;
	int bulunanPireMi = 0;
	int bulunanSinekMi = 0;
	int bulunanBitkiMi = 0;

	Bocek tempBocekPointer;
	Pire tempPirePointer;
	Sinek tempSinekPointer;
	Bitki tempBitkiPointer;

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
					if (!strcmp(durum, "B"))
					{
						printf("Bitki %d  %d \n", xCoord, yCoord);
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
						printf("Bocek %d  %d \n", xCoord, yCoord);
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
						printf("Pire %d  %d \n", xCoord, yCoord);
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
						printf("Sinek %d  %d \n", xCoord, yCoord);
						bulunanSinekMi = 1;
						tempSinekPointer = sinekler[k];
						break;
					}
				}
			}

			printf("\n");
			// -----------------------------------------------------------------------------
			// -----------------------------------------------------------------------------
			// -----------------------------------------------------------------------------

			if (bulunanBitkiMi)
			{
				char *durum = tempBitkiPointer->super->tur;
				int xKoordinat = tempBitkiPointer->super->xCoord;
				int yKoordinat = tempBitkiPointer->super->yCoord;
				int degeri = tempBitkiPointer->super->deger;
				printf("Bulunan Bitkinin durumu: %s Konumu: %d %d degeri: %d \n", durum, xKoordinat, yKoordinat, degeri);
				bulunanBitkiMi = 0;

				int icDongu = j + 1;
				for (m = i; m < 4; m++)
				{
					for (n = icDongu; n < 5; n++)
					{
						// printf("m %d n %d -", m, n);

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
									printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Bocek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Pire Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Sinek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
									break;
								}
							}
						}
					}
					if (n == 5)
					{
						if (m != 3)
						{
							int x = m + 1;
							int y = 0;
							// printf("yeni satir : m %d n %d -", x, y);

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
										printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										int yenilecekDeger = bitkiler[k]->super->deger;
										printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
										break;
									}
								}
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
				printf("Bulunan Bocekin durumu: %s Konumu: %d %d degeri: %d \n", durum, xKoordinat, yKoordinat, degeri);
				bulunanBocekMi = 0;

				int bocekYasiyorMu = 0;
				if (strcmp(durum, "X"))
				{
					printf("Bocek Yasiyor\n");
					bocekYasiyorMu = 1;
				}

				int icDongu = j + 1;
				for (m = i; m < 4; m++)
				{
					for (n = icDongu; n < 5; n++)
					{
						// printf("m %d n %d -", m, n);

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
									printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
									bitkiler[k]->super->tur = "X";
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);


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
							// printf(">>bocekler[k]->super->xCoord %d xcoord: %d - bocekler[k]->super->yCoord %d ycoord %d\n\n", bocekler[k]->super->xCoord, xCoord, bocekler[k]->super->yCoord, yCoord);
							if (bocekler[k]->super->xCoord == xCoord && bocekler[k]->super->yCoord == yCoord)
							{

								char *durum = bocekler[k]->super->tur;
								if (!strcmp(durum, "C"))
								{
									int yenilecekDeger = bocekler[k]->super->deger;
									printf("Bocek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
									int ilkDeger = tempBocekPointer->super->deger;
									int ikinciDeger = bocekler[k]->super->deger;

									// printf("ilkdeger : %d -- ikincideger %d \n", ilkDeger, ikinciDeger);

									if (ilkDeger > ikinciDeger)
									{
										bocekler[k]->super->tur = "X";
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);
									}
									else
									{
										tempBocekPointer->super->tur = "X";
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);
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
									printf("Pire Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
									pireler[k]->super->super->tur = "X";
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);
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
									printf("Sinek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
									bocekYasiyorMu = 0;
									tempBocekPointer->super->tur = "X";
									printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);
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
					if (n == 5)
					{
						if (m != 3)
						{
							int x = m + 1;
							int y = 0;
							// printf("yeni satir : m %d n %d -", x, y);

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
										printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Bocek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
										int ilkDeger = tempBocekPointer->super->deger;
										int ikinciDeger = bocekler[k]->super->deger;

										// printf("ilkdeger : %d -- ikincideger %d \n", ilkDeger, ikinciDeger);

										if (ilkDeger > ikinciDeger)
										{
											bocekler[k]->super->tur = "X";
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);
										}
										else
										{
											tempBocekPointer->super->tur = "X";
											printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);
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
										printf("Pire Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Sinek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
										bocekYasiyorMu = 0;
										tempBocekPointer->super->tur = "X";
										printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);
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
				printf("Bulunan Pirenin durumu: %s Konumu: %d %d degeri: %d \n", durum, xKoordinat, yKoordinat, degeri);
				bulunanPireMi = 0;

				int icDongu = j + 1;
				for (m = i; m < 4; m++)
				{
					for (n = icDongu; n < 5; n++)
					{
						// printf("m %d n %d -", m, n);

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
									printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Bocek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Pire Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Sinek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
									break;
								}
							}
						}
					}
					if (n == 5)
					{
						if (m != 3)
						{
							int x = m + 1;
							int y = 0;
							// printf("yeni satir : m %d n %d -", x, y);

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
										printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Bocek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Pire Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Sinek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
										break;
									}
								}
							}
						}
						icDongu = 1;
					}
				}
			}
			else if (bulunanSinekMi)
			{
				char *durum = tempSinekPointer->super->super->tur;
				int xKoordinat = tempSinekPointer->super->super->xCoord;
				int yKoordinat = tempSinekPointer->super->super->yCoord;

				int degeri = tempSinekPointer->super->super->deger;
				printf("Bulunan Sinekin durumu: %s Konumu: %d %d degeri: %d \n", durum, xKoordinat, yKoordinat, degeri);
				bulunanSinekMi = 0;

				int icDongu = j + 1;
				for (m = i; m < 4; m++)
				{
					for (n = icDongu; n < 5; n++)
					{
						// printf("m %d n %d -", m, n);

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
									printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Bocek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Pire Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
									printf("Sinek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
									break;
								}
							}
						}
					}
					if (n == 5)
					{
						if (m != 3)
						{
							int x = m + 1;
							int y = 0;
							// printf("yeni satir : m %d n %d -", x, y);

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
										printf("Bitki Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Bocek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Pire Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
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
										printf("Sinek Konum %d  %d deger: %d\n", xCoord, yCoord, yenilecekDeger);
										break;
									}
								}
							}
						}
						icDongu = 1;
					}
				}
			}
			printf("\n\n");
		}
	}

	printf("\n");

	printGrid(bitkiIndex, bocekIndex, pireIndex, sinekIndex, bitkiler, bocekler, pireler, sinekler);

	printf("\n");

	return 0;
}