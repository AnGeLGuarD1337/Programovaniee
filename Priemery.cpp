// Zamestnani06.cpp : Defines the entry point for the console application.
// funkce: kvadraticky prumer = odmocnina ze součtu čtverců / n
// funkce: geometricky prumer = n-ta odmocnina ze součinu prvků

#include <stdio.h>
#include <math.h>		// potrebujeme kvuli funkci odmocniny sqrt()

double HarmonPrumer(int p[]);	// n / suma prevracenych hodnot vsech prvku
void VstupDat(int p[]);
void VypisDat(int p[]);
double KvadraPrumer(int p[]);
double GeometPrumer(int p[]);

int main()
{
	int pole[10];
	double harmprumer, kvadprumer, geomprumer;
	VstupDat(pole);
	VypisDat(pole);
	harmprumer=HarmonPrumer(pole);
	printf("\nHarmonicky prumer je: %6.2lf\n",harmprumer);
	kvadprumer=KvadraPrumer(pole);
	printf("Kvadraticky prumer je: %6.3lf\n", kvadprumer);
	geomprumer=GeometPrumer(pole);
	printf("Geometricky prumer je: %6.3lf\n", geomprumer);
	fflush(stdin); getchar();
	return 0;
}

void VstupDat(int p[])
{
	int pom;
	for(int i=0; i<10; i++)
	{		// indexy jsou v C++ od 0, ale pro člověka je čitelnější od 1 proto i+1
		printf("Zadejte %2d. prvek celociselneho pole:", i+1);
		scanf("%d",&pom);
		p[i]=pom;
	}
}

void VypisDat(int p[])
{
	for(int i=0; i<10; i++)
		printf("%d ", p[i]);
}

double HarmonPrumer(int p[])
{
	double v, suma=0.0;
	for(int i=0; i<10; i++)
		suma += 1.0/p[i];		// secteme prevracene hodnoty
	v=10/suma;					// n / suma prevracenych hodnot
	return v;
}

double KvadraPrumer(int p[])
{
	double vysledek, suma=0.0;
	for(int i=0; i<10; i++)
		suma += p[i]*p[i];		// součet čtverců všech hodnot
	vysledek=suma/10;
	vysledek=sqrt(vysledek);	// funkce odmocnina sqrt(x) z knihovny math.h
	return vysledek;
}

double GeometPrumer(int p[])
{
	double vysledek, soucin=1.0;
	for(int i=0; i<10; i++)
		soucin *= p[i];			     // ve vyznamu: soucin = soucin * p[i];
	vysledek=pow(soucin, 1.0/10);	// funkce power(x,y) je x na y z knihovny math.h
									// 1/n nahrazuje n-tou odmocninu
	return vysledek;
}