// Zamestnani01.cpp : aplikace resi trohuelnikovou nerovnost
//
#include <stdio.h>

int JeTrojuhelnik(float a, float b, float c);	// prototyp funkce

int main()
{	
	float x, y, z;
	int vysledek;				// 0 když není 1 když je
	printf("zadejte 3 cisla:");
	scanf("%d",&x);scanf("%d",&y);scanf("%d",&z);
	vysledek=JeTrojuhelnik(x,y,z);	// když je tak navraci 1, jinak 0
	printf("Rozhodnuti: %s",(vysledek)?"JE":"NENI");
		//  ternarni vyraz  (podminka)? výraz při platí : výraz při neplatí
		// vlastně podmíněný výraz při platnosti vrací 1. výraz, při neplatí 2. výraz
	fflush(stdin); getchar();
	return 0;
}

int JeTrojuhelnik(float a, float b, float c)
{
	int v=1;
	if( (a+b)<c || (a+c)<b || (b+c)<a )	// znaky || zmamenají nebo, OR, log.součet 
		v=0;
	return v;
}

