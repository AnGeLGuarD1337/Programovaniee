// OdkazHodnota.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <malloc.h>

int SectiHodnoty(int a, int b)		// a b se volá hodnotou
{
	return (a+b);
}

void SectiHodnotyOdkazem(int a, int b, int *v)    // deklarace odkazem: vysledek v je na adrese 
{
	*v = a + b;		// zapiš součet na adresu v, tedy po vyvolání to bude do skutečné proměnné
}

void OdectiHodnotyOdkazem(int a, int b, int *v)    // deklarace odkazem 
{
    *v = a - b;
}

int main()
{
    int c = 5, d = 10, v, odkaz, *pointer; 
    v = SectiHodnoty(c,d);
    printf("Primo hodnotou %d\n",v);

    OdectiHodnotyOdkazem(d, c, &odkaz);     // předáme adresu výsledku &odkaz 
    printf("Odkazem1 %d\n",odkaz);

	pointer=(int*)malloc(4);		// najdeme si v pameti 4 byte volne kam nám tedy ukazuje pointer
	SectiHodnotyOdkazem(c, d, pointer);		// dáme také na adresu predem nachystanou v paměti
    printf("pointerem - Odkazem2 %d\n adresa je %p",*pointer, pointer);
	

	fflush(stdin); getchar();
	return 0;
}