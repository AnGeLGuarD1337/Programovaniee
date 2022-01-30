// SouborTextRead.cpp : Defines the entry point for the console application.

//#include "stdafx.h"
#include <stdio.h>
#define SOUBOR "soubor.txt"			// soubor ke cteni je ocekavan ve slozce nasi aplikace 

int main()
{						// hledáme počet znaků na řádcích souboru
	FILE *soubor;		// ukazatel na strukturu FILE, která přebírá po otevření fopen udaje o souboru z OS
	char c;
	int i=0,r=0,radek[130];
	soubor = fopen(SOUBOR, "rt");		// r jako read - tedy cteme, t - textovy soubor

	while ((c = getc(soubor))!= EOF)	// EOF je znak konce souboru "end of file"
	{	i=0;r++;
		ungetc(c,soubor);	// presuneme si cteni zpet o 1 znak jiz nacteny v nadrazenem cyklu while
		while ((c = getc(soubor)) != '\n' && c != EOF)	// neni to konec radku ani konec souboru (c != EOF)))
		{
			printf("%c",c);		// znak po znaku si řádek zobrazime
			i++;
		}
		printf("\n");
		radek[r]=i;		// uložíme si počet znaků na řádku r
	}
	for(int k=1;k<=r;k++)
		printf("\nradek %d. ma %2d znaku",k,radek[k]);
						// zjištění velikosti souboru
	fseek(soubor, 0, SEEK_END);		// nastavíme se na konec souboru
	i=ftell(soubor);				// zjistíme na které jsme pozici, na konci to odpovida velikosti souboru
	printf("\nVelikost souboru je %2d bytu",i);
			// velikost je vetsi nez soucet znaku na radcich vždy o 2B za jeden Enter (0D, 0A)
	fclose(soubor);
	fflush(stdin); getchar();
	return 0;
}
