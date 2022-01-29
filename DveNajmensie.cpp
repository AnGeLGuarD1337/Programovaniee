#include "stdio.h"


int main()
{
	int p[50], min1=999, min2=999, index=0, pom, max1=-999, max2=-999;
	p[0]=999;
	while(p[index] != -13)
	{
		printf("Zadejte hodnotu do 1000 ( -13 je konec):");	
		scanf("%d",&pom);
		index++;
		p[index]=pom;
	}
	for(int i=1; i<=index; i++)			// vypiseme radu cisel
		printf("%d ",p[i]);

	for(int i=1; i<index; i++)			// hledame nejmensi hodnotu
		if(p[i]<min1)
			min1=p[i];
	printf("\nnejmensi cislo je %d ",min1);	

	for(int i=1; i<index; i++)			// hledame druhou nejmensi hodnotu
		if(p[i]<min2 && p[i]!=min1)		// nesmi byt tou nejmensi
			min2=p[i];
	printf("\ndruhe nejmensi je %d ",min2);

	for(int i=1; i<index; i++)			// hledame nejvetsi
		if(p[i]>max1)
			max1=p[i];
    printf("\nNajvacsie cislo je %d ",max1);
	for(int i=1; i<index; i++)			// hledame druhou nejvetsi
		if(p[i]>max2 && p[i]!=max1)
			max2=p[i];
	printf("\ndruhe nejvetsi je %d ",max2);

	fflush(stdin); getchar();
	return 0;
}