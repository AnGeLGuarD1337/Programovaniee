// zamestnani04.cpp : Defines the entry point for the console application.

#include <stdio.h>
/*                                                  //Cyklom While
int CyklemWhile(int h)
{
	int cislo=1, soucet=0;
	while(cislo<=h)
	{
		soucet+=cislo;
		cislo++;
	}
	return soucet;
}
*/

int main()
{
	int mez=100, cislo, soucet=0;
	for(cislo=1; cislo<=mez;cislo++)
		soucet += cislo;	                          // soucet=soucet+cislo;
	printf("soucet 1 az 100 je %d\n",soucet);
    /*
	soucet=CyklemWhile(100);	                    // volame funkci s parametrem 100
	printf("soucet 1 az 100 je %d\n",soucet);
    */  
	fflush(stdin); getchar();
	return 0;
}

