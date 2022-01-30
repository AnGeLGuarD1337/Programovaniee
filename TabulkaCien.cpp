// TabulkaCen.cpp : Defines the entry point for the console application.

#include <stdio.h>

int main()
{
	float cena1ks, c5proc,c10proc, c21proc;
	printf("ZADEJTE CENU ZA KUS BEZ DANE: ");
	scanf("%f",&cena1ks);
	printf("		  DPH\nkusu	   5\%%	  10\%%	  21\%%\n");
	c5proc=cena1ks*1.05;	// % je specialni znak proto se musi psat takto \%%
	c10proc=cena1ks*1.10;
	c21proc=cena1ks*1.21;
	for(int i=1; i<21; i++)
		printf("%2d     %7.2f	%7.2f	%7.2f\n",i,i*c5proc,i*c10proc,i*c21proc);
	
	fflush(stdin); getchar();
	return 0;
}

