// JednotkovaM.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

void UkazMatici(int m[5][5])
{
	for(int r=0; r<5; r++)
	{	printf("\n");
		for(int s=0; s<5; s++)
			printf("%3d ",m[r][s]);
	}
}

int main()
{
	int M[5][5], N[5][5], S[5][5], r, s;
	for(int r=0; r<5; r++)
		for(int s=0; s<5; s++)
			if(r==s)		// radek a sloupec jsou stejne tak bude 1 jinak 0
				M[r][s]=1;
			else
				M[r][s]=0;
	UkazMatici(M);

	for(int r=0; r<5; r++)
		for(int s=0; s<5; s++)
			if((r+s)==4)		// soucet radku a sloupce je n-1, tak 1, jinak 0
				N[r][s]=1;		// jednicky na vedlejsi diagonale
			else
				N[r][s]=0;
	printf("\n"); UkazMatici(N);

	for(int r=0; r<5; r++)
		for(int s=0; s<5; s++)
			S[r][s] = M[r][s] + N[r][s];	
	printf("\n"); UkazMatici(S);
	
	getchar(); return 0;
}