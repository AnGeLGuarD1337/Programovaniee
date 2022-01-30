// SortBubble.cpp : Defines the entry point for the console application.
// tridici algoritmus
//#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// pro nahodne hodnoty rand() navrací random čísla
				// (rand() % 100) + 1;	      navrací náhodne číslo v rozsahu <1-100>
#define ROZMER 10

void vypis2_pole(short int cykl, unsigned int pole[])
{
   unsigned short int i;
   printf("Prvky pole po %2i. prubehu:\n", cykl);					
   for (i = 0; i < ROZMER; i++)
      printf("%3u ", pole[i]);			
}

int main()	
{
    int cykl, bublani;
    unsigned int pole[ROZMER], pom;
			/* nejdrive inicializuji pole nahodnymi hodnotami a vypisi jej */
    srand((unsigned int) time(NULL));	// nastavení generátoru podle aktuálního času
    for (cykl = 0; cykl < ROZMER; cykl++)
        pole[cykl] = (rand() % 100) + 1;		// nahodne cislo v rozsahu <1-100>
    printf("Inicializace: \n");
    vypis2_pole(0, pole);
	printf("\n");
						 /* ted pole setridim algoritmem bubble sort */
    for (cykl = 1; cykl < ROZMER; cykl++) {
       for (bublani = ROZMER - 1; bublani >= cykl; bublani--) {
           if (pole[bublani - 1] > pole[bublani]) {
						/* mensi cislo probubla o jeden prvek smerem k zacatku */
               pom = pole[bublani - 1];
               pole[bublani - 1] = pole[bublani];
               pole[bublani] = pom;
           }
       }
//vypise se mezivysledek, kde "cykl" nejmensich cisel uz je zarucene na zacatku pole *
       vypis2_pole(cykl, pole);
	   fflush(stdin); getchar(); // čekáme na ENTER před provedením dalšího kroku
   }
   printf("hotovo ...\n");
   fflush(stdin); getchar();
   return 0;
}


