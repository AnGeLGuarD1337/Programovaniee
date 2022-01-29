
#include <stdio.h>
#include <windows.h>

int main(int argc, TCHAR* argv[])
{
	long int a,zaloha;
	int suma=0, cifra;
	printf("zadej cislo:");
	scanf("%ld",&a);
	//a=154875246;		// vzor ze zadani prikladu
	zaloha=a;
	while(a>0)
	{
		cifra=a % 10;	// HODNOTA modulo 10 je poslední cifra
		suma += cifra;
		printf("dosavadni soucet po pricteni %d je %d\n",cifra, suma);
		a=a/10;			// dělíme celočíselně takže odsekneme poslední cifru
	}
	printf("cif soucet %ld je %d\n",zaloha,suma);

	fflush(stdin);getchar();
	return 0;
}