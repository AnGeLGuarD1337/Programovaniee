// Zamestnani02.cpp
#include <stdio.h>

int max3hodnot(int a, int b, int c);	// vrací největší hodnotu ze 3 parametrů

int main()
{
	int h1, h2, h3, max;
	printf("zadej 3 cisla:");
	scanf("%d %d %d",&h1,&h2,&h3);
	max=max3hodnot(h1,h2,h3);	// volame funkci s našimi 3 hodnotami
	printf("Nejvetsi je: %d\n",max );

	fflush(stdin);getchar();
	return 0;
}

int max3hodnot(int a, int b, int c)
{
	int vysledek=a;
	if(b>vysledek) vysledek=b;
	if(c>vysledek) vysledek=c;
	return vysledek;
}

