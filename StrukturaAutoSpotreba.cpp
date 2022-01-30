// StrukturaAutoSpotreba.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>

typedef struct {
	int km, litru;
	double spotreba;		// evropský zvyk: litrů na 100 km
	double spotUS;			// mile/galon, 1 mile=1.6 km 1 galon=3.87 litru
} AUTO;						// US zvyk: kolik mil ujedu na 1 galon benzínu

AUTO ZadaniDAT(void)
{
	AUTO v;
	int pom;
	printf("Zadejte pocet ujetych km: ");
	scanf("%d",&pom);
	v.km=pom;
	fflush(stdin);
	printf("Zadejte projeto litru   : ");
	scanf("%d",&pom);
	v.litru=pom;
	fflush(stdin);
	return v;
}

AUTO VypocetSpotreby(AUTO a)
{
	a.spotreba=(double)a.litru*100/a.km;
	a.spotUS=(100/1.6)/(a.spotreba/3.87);
	return a;
}

AUTO VstupDAT(int km, int litru)
{
	AUTO v;
	v.km=km;
	v.litru=litru;
	return v;
}

void UkazAuto(AUTO v)
{
	printf("UJETO      KM: %3d\nPROJETO LITRU: %3d\nOdpovida spotrebe: %5.2lf l/100km\n",v.km, v.litru,v.spotreba);
	printf("Spotreba US cini : %5.2lf mil/gal\n",v.spotUS);
}

int main()
{
	AUTO Fiat;
	Fiat=ZadaniDAT();
	Fiat=VypocetSpotreby(Fiat);
	UkazAuto(Fiat);

	AUTO a;
	/*                                                                    //Tabulky
	printf("Spotreba       Ujeto km\nlitru          ");
	for(int i=100; i<1001; i+=100)
		printf("%5d  ",i);
	printf("\n");
	for(int litru=10; litru<101; litru+=10)
	{	
		printf("%3d           ",litru);
		for(int km=100; km<1001; km+=100)
		{
			a=VstupDAT(km,litru);
			a=VypocetSpotreby(a);
			printf(" %6.2lf",a.spotreba);
		}
		printf("\n");
	}
	printf("Spotreba mpg   Ujeto km\nlitru          ");
	for(int i=100; i<1001; i+=100)
		printf("%5d  ",i);
	printf("\n");
	for(int litru=10; litru<101; litru+=10)
	{	
		printf("%3d           ",litru);
		for(int km=100; km<1001; km+=100)
		{
			a=VstupDAT(km,litru);
			a=VypocetSpotreby(a);
			printf(" %6.2lf",a.spotUS);
		}
		printf("\n");
	}
	*/
	fflush(stdin);getchar();
	return 0;
	
}