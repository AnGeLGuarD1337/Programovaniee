// FibonacihoCisla.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
// UKOL - kolik se jich vejde do 300000 ?

int main()
{ 
			int max, x=2, y=3, pocet=0;
			printf("ZADEJ HORNI MEZ: ");
			scanf("%d",&max);

Znovu:		if(x>max) goto Konec;
			printf("%2d. cislo je %6d \n",pocet+1,x);		// alt 92 = backslash
			pocet++;
			x=x+y;
			if(y>max) goto Konec;
			printf("%2d. cislo je %6d \n",pocet+1,y);
			pocet++;
			y=x+y;
 			goto Znovu;
Konec:		printf("do maxima jich je %6d \n",pocet);
			getchar();	

			fflush(stdin); getchar();
			return 0;
}
