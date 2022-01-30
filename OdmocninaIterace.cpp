// OdmocninaIteracne.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <math.h>			// potřebujeme funkci absolutní hodnota abs(x)

double Odmocnina(double cislo, double presnost);

int main()
{
	double cis, vysledek;
	double pres[8]= {0.9,0.725,0.15,0.005,0.000001,0.0000005,0.00000001,0.0000000005};
	printf("Zadejte cislo   : "); scanf("%lf",&cis);
	printf("Zadejte presnost: "); scanf("%lf",&pres);
	printf("Presnost     Odmocnina\n");
	for(int i=0; i<8; i++)
	{
		vysledek=Odmocnina(cis,pres[i]);
		printf("%12.9lf   %12.9lf\n",pres[i], vysledek);
	}
	printf("Knihovni FCE: %12.9lf\n",sqrt(cis));

	fflush(stdin); getchar();	
	return 0;
}

double Odmocnina(double cislo, double presnost)
{
	double xi, d;
	int kroku=0;
	xi=1;
	do {
		d=(xi*xi-cislo)/(2*xi);
		xi=xi-d;
		kroku++;
	} while(presnost < abs(d));
	printf("pocet kroku k dosazeni presnosti: %3d \n",kroku);
	return xi;
}