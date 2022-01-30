// Tabulka male nasobilky.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
	printf("        1    2    3    4    5    6    7    8    9   10\n");	
	for(int x=1; x<11; x++)
	{
		printf("%3d:",x);			// záhlaví zleva pro každý řádek
		for(int y=1; y<11; y++)
			printf("%5d",x*y);		// soucin x * y
		printf("\n");				// přechod na další řádek
	}

	fflush(stdin); getchar();
	return 0;
}

