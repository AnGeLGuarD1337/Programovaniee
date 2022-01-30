// Zamestnani03.cpp : Defines the entry point for the console application.
#include <stdio.h>
#include <string.h>			// kvuli funkci strlen pro zjisteni delky retezce

#include <malloc.h>			// funkce pro alokace paměti

int main()
{
	char vstup[21], liche[11], sude[11], *alokovane;
	alokovane=(char*)malloc(100);

	printf("zadej retezec max 20 znaku: ");
	scanf("%s",vstup);
	int index=0;
	for(int i=0; i<strlen(vstup);i+=2) // indexy od 0 tak 0,2,4,... jsou liche pozice
	{
		liche[index]=vstup[i];
		index++;
	}
	liche[index]='\0';		// doplnime tvrdou nulu pro ukonceni retezce
	printf("liche pozice obsahuji %s\n",liche);
	index=0;
	for(int i=1; i<strlen(vstup);i+=2)
	{
		sude[index]=vstup[i];
		index++;
	}
	sude[index]='\0';		// doplnime tvrdou nulu pro ukonceni retezce
	printf("sude pozice obsahuji  %s\n",sude);
	index=0;
	for(int i=0; i<strlen(vstup); i++)
	{
		alokovane[index]=vstup[i];   // kopie řětězce do alokované paměti
		index++;
	}
	alokovane[index]='\0';
	printf("Alokovana promenna %s\n",alokovane);
	fflush(stdin);getchar();
	return 0;
}

