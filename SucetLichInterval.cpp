// SoucetLichInterval.cpp : 
// vstup dm, hm, výstup: součet lichých čísel v intervalu <dm, hm>

//#include "stdafx.h"
#include <stdio.h>

using namespace std;

int SoucetLichychIntervalu(int dm, int hm);	// prototyp funkce, definice bude dále

int main()
{
	int dm, hm;
	printf("Zadej dolni a horni mez:");
	scanf("%d %d",&dm, &hm);		// & znamená načti hodnoty na adresu
	printf("Soucet lichych hodnot v intervalu %d %d je: ", dm, hm);
 	printf("%d",SoucetLichychIntervalu(dm, hm));
				// vyvolani funkce k vypoctu
	fflush(stdin); getchar();
    return 0;
}

int SoucetLichychIntervalu(int dm, int hm)
{
	int soucet=0;
	if(dm%2==0)			// je-li dm sudá tak se posuneme na prvni lichou
		dm++;
	while(dm<=hm)
	{
		soucet += dm;
		dm +=2;			// nastavime se na dalsi liche cislo
	}
	return soucet;
}