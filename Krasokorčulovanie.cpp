// kRASOBRUSLENI.cpp : Defines the entry point for the console application.
// 8 rozhodcich znamkuje 60-100, škrtá se max a min hodnota, a bere se průměr zbývajících 6 známek

#include <stdio.h>

void VstupPole(int p[8])
{
	int nove, i=1;
	while(i<9)
	{
		printf("zadej %d. znamku: ",i);
		scanf("%d",&nove);
		if((nove>59) && (nove<101))
		{	
			p[i-1]=nove;
			i++;
		}
		else
			printf("Hodnota je mimo povoleny interval, zadejte znovu \n");
	}
}

int MinZnamka(int p[8])
{
	int min=p[0];
	for(int i=1; i<8; i++)
		if(p[i]<min)
			min=p[i];
	return min;
}

int MaxZnamka(int p[8])
{
	int max=p[0];
	for(int i=1; i<8; i++)
		if(p[i]>max)
			max=p[i];
	return max;
}

void UkazPole(int x[8])
{
	for(int i=0; i<8; i++)
		printf("%d  ", x[i]);
}

float VyslHodnoceni(int x[8])
{	int suma=0;
	for(int i=0; i<8; i++)
		suma += x[i];
	suma -= MinZnamka(x);		// nebereme v potaz min a max znamku
	suma -= MaxZnamka(x);
	return ((float)suma/6);		// vysledek je prumer zbyvajicich 6 hodnot
}

int main()
{
	int zn[8];			// pole známek od rozhodcich
	int minimum, maximum;
	VstupPole(zn);
	UkazPole(zn);
	minimum=MinZnamka(zn);
	printf("\nSkrtame minimum = %d",minimum);
	maximum=MaxZnamka(zn);
	printf("\nSkrtame maximum = %d",maximum);
	printf("\nVysledna znamka = %6.2f",VyslHodnoceni(zn));

	fflush(stdin); getchar();
	return 0;
}

