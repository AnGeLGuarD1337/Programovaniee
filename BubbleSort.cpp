#include <stdio.h>
#include <math.h>		// potrebujeme kvuli funkci odmocniny sqrt()
#define POCET 11		// definujeme si jako konstantu počet prvků

void SortBubble(int p[]);		// setřídění podle velikosti kvůli mediánu
double Median(int p[]);
void VstupDat(int p[]);
void VypisDat(int p[]);

int main()
{
	int pole[POCET];	// ve funkci volam pole = &pole[0] tedy probehne volani odkazem
	double median;
	VstupDat(pole);
	VypisDat(pole);
	SortBubble(pole);	// pole je nutné setřídit kvůli mediánu!
	VypisDat(pole);
	median=Median(pole);		// volame funkci pro výpočet mediánu
	printf("\nMedian             je: %6.3lf\n", median);
	fflush(stdin); getchar();
	return 0;
}

void VstupDat(int p[])
{
	int pom;
	for(int i=0; i<POCET; i++)
	{			// ukazujeme i+1 protože index 0 je pro člověka 1. prvek
		printf("Zadejte %2d. prvek celociselneho pole:", i+1);
		scanf("%d",&pom);
		p[i]=pom;			// hodnotu ukládáme ale n index i
	}
}

void VypisDat(int p[])
{
	for(int i=0; i<POCET; i++)
		printf("%d ", p[i]);
	printf("\n");
}

void SortBubble(int p[])
{
	int Rozmer=POCET, pom;
	for (int cykl = 1; cykl < Rozmer; cykl++) {
       for (int bublani = Rozmer - 1; bublani >= cykl; bublani--) {
           if (p[bublani - 1] > p[bublani]) {
						  /* mensi cislo probubla o jeden prvek smerem k zacatku */
               pom = p[bublani - 1];	// prohození přes pomocnou proměnnou
               p[bublani - 1] = p[bublani];
               p[bublani] = pom;
           }
       }
	}
}
                                                                                    //https://sk.wikipedia.org/wiki/Medi%C3%A1n
double Median(int p[])          
{
	int index; 
	if((POCET % 2) == 1)		// a % b je operace modulo zbytek po celočís. dělení 
	{							// lichy počet prvků
		index=POCET/2;			// 11 vede na index 5
		return p[index];
	} else
	{							// sudý počet prvků
		index=POCET/2-1;		// 10 vede na 4, použijeme průměr p[4] a p[5]
		return (p[index]+p[index+1])/2.0;		
	}
}