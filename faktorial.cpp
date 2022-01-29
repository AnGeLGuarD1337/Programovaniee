
#include "stdio.h"

double fact_iter(int n);		// funkce pro vypocet faktoriálu: 1*2*3*...*N
double f(int n);				// rekurzivní funkce pro vypocet faktoriálu
double NnadK(int n, int k);		// vypocet n nad k je počet kombinací

// aplikace muze startovat se zadanymi parametry - např.: nazev p1, p2, p3, p4
//		argc=4, argv[0]=p1, .... argv[3]=p4 

int main()
{
	int n,k;
	int mil, tis, jed;
	double vysledek;
	printf("Zadej N:");
	scanf("%d",&n);
							//vysledek=fact_iter(n);
	vysledek=f(n);
	printf("Faktorial je roven: %e\n",vysledek);

	printf("Zadej N a K:");
	scanf("%d %d",&n,&k);
	vysledek=NnadK(n,k);
	printf("N nad K (pocet kombinaci) je: %10.0lf",vysledek);
	mil=vysledek/1000000;			// prevod na miliony
	vysledek -= mil*1000000;		
	tis=vysledek/1000;				//           tisice
	jed = vysledek-tis*1000;		// a zbytek v jednotkach
	getchar();
	printf("\n %d mil %d tis %d",mil,tis,jed);
	fflush(stdin); getchar();
	return 0;
}

double fact_iter(int n)		// funkce pro vypocet faktoriálu: 1*2*3*...*N
{
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;			// result = result * i
    }
    return result;
}

double f(int n){				// rekurzivní funkce pro vypocet faktoriálu
   if (n <= 1)				
        return 1;				// zacina zpetny chod rekurze při dosažení parametru 1
   else 
       return (double)n*f(n-1);		// funkce vola sebe sama s parametrem (n-1)
}

double NnadK(int n, int k){		// vypocet n nad k je počet kombinací
	double vysledek;
	vysledek=f(n)/f(k)/f(n-k);
	return vysledek;
}