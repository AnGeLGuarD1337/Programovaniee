// Tabelace funkci sin a cos.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "math.h"

int main()
{
	double sinus, cosinus;
	int uhel;
	printf("uhel     sin(x)      cos(x)\n");
	for(uhel=0; uhel<361; uhel+=10)
	{
		sinus  =sin(uhel*3.141592/180.0);		// převedeme stupně na radiány
		cosinus=cos(uhel*3.141592/180.0);
		printf("%4d    %6.4lf    %s%6.4lf\n",uhel,sinus,(cosinus>=0)?"  ":" ",cosinus);
	}

	fflush(stdin); getchar();
	return 0;
}

