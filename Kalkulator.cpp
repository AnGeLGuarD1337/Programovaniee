// Kalkulator.cpp : main project file.

#include <stdio.h>
#include "math.h"		// potrebujeme odmocninu sqrt z knihovny

using namespace std;

int Soucet(int a, int b);		// prototyp funkce kod bude dale
float Podil(int a, int b);
float Prepona(int a, int b);	// prepona na zaklade dvou odvesen

int main()
{
    int x, y, s;
	float p, prep, sinus1, sinus2;
	printf("zadejte 2 cisla:"); scanf("%d %d", &x, &y);
	s=Soucet(x,y);		// vyvolani funkce parametry hodnotou
	printf("Soucet je %d\n",s);
	p=Podil(x,y);
	printf("Podil  je %f\n",p);
	prep=Prepona(x,y);
	printf("Prepona je %f\n",prep);
			// goniometricke funkce jsou napsany pro vypocty v radianech
			// na stupne musime upravovat  stupne * Pi / 180
	sinus1=(float)sin((double)x*3.141592653/180);
    sinus2=(float)sin((double)y*3.141592653/180);
	printf("Sinus %d stupnu je %f\n",x, sinus1);
    printf("Sinus %d stupnu je %f\n",y, sinus2);
	fflush(stdin); getchar(); return 0;
}

float Prepona(int a, int b)
{
	// funkce je definovna double sqrt(double)
	return (float)(sqrt((double)(a*a+b*b)));
}

float Podil(int a, int b)
{
			// nutny je casting 1 parametru aby to bylo float/int coz je float
			// obycejne a/b je int/int coz navraci int a usekne to des.cisla
	return ((float)a/b);
}

int Soucet(int a, int b)
{			
	return (a+b);
}