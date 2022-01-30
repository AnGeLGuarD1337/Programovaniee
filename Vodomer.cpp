// vodojem.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int osob=15, litru;
	float prumer,objem, dnu=0;
	/*printf("zadejte pocet osob: "); scanf("%d",&osob);
	printf("zadejte prumer vodojemu v metrech: "); scanf("%f",&prumer);
	printf("zadejte spotrebu osoby/den v litrech: "); scanf("%d",&litru);
	objem=4.0/3.0*3.141592653*(prumer/2.0)*(prumer/2.0)*(prumer/2.0);
	dnu=objem*1000/litru/osob;
	printf("objem %6.1f litru vystaci na %4.1f dnu\n",1000*objem,dnu)*/

	printf("                Denni spotreba/osobu v litrech\n");
	printf("Prumer vod 	60    70   80   90   100  110  120\n",dnu);
	for(prumer=1.5; prumer<4.5; prumer+=0.5)
	{
		printf("    %4.1f       ",prumer);
		for(litru=60; litru<130; litru+=10)
		{
			objem=(float)4.0/3.0*3.141592653*(prumer/2)*(prumer/2)*(prumer/2);
			dnu=objem*1000/litru/osob;
			printf("%5.1f",dnu);
		}
		printf("\n");
	}
	/*printf("hvezdicky\n");
	int p=4;
	for(int i=0; i<p;i++)
		printf("*");
	for(int i=1; i<p;i++)
		printf("\n*");*/


	fflush(stdin);getchar();
	return 0;
}

