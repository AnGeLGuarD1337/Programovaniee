// faktorialfunkci.cpp : Defines the entry point for the console application.
#include "stdio.h"

double Faktorial(int n)
{
	int i;
	double f=1.0;
	for(i=2;i<=n;i++)
		f*=i;		// f=f*i
	return f;
}

double NnadK(int n, int k)
{
	double vysledek;
	vysledek=Faktorial(n)/Faktorial(k)/Faktorial(n-k);
	return(vysledek);
}


int main()
{
	int n=69;                            //Zadanie faktorial
	double vysledek;
	vysledek=Faktorial(n);
	printf("fakt %d je %10.8e\n",n,vysledek);
	vysledek=NnadK(49,6);
	printf(" pocet kombinaci ve Sportce: %d nad %d je  %10.0lf",49,6, vysledek);   //Zadanie Kombinacneho cisla

	getchar();

	return 0;
}