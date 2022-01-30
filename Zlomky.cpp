// Zamestnani08.cpp : Defines the entry point for the console application.

#include <stdio.h>

float HodDesetinne(int a, int b);

int main()
{
	int c1cit, c1jme, c2cit, c2jme, vycit, vyjme;
	printf("zadejte prvni zlomek jako 2 cela cisla: ");
	scanf("%d %d",&c1cit, &c1jme);
	printf("zadejte druhy zlomek jako 2 cela cisla: ");
	scanf("%d %d",&c2cit, &c2jme);
	printf("\nPuvodni zlomky: %5.3f   %5.3f",HodDesetinne(c1cit,c1jme),HodDesetinne(c2cit,c2jme));
			// počítáme součet 2 zlomků
	vycit = c1cit*c2jme + c2cit*c1jme;			
	vyjme = c1jme*c2jme;
	printf("\nSoucet zlomku je: %3d \/ %3d  des: %5.3f",vycit,vyjme,HodDesetinne(vycit,vyjme));
			// počítáme součin 2 zlomků
	vycit = c1cit*c2cit;
	vyjme = c1jme*c2jme;
	printf("\nSoucin zlomku je: %3d \/ %3d  des: %5.3f",vycit, vyjme, HodDesetinne(vycit, vyjme));
			// počítáme rozdil 2 zlomků
	vycit = c1cit*c2jme - c2cit*c1jme;	
	vyjme = c1jme*c2jme;
	printf("\nRozdil zlomku je: %3d \/ %3d  des: %5.3f",vycit, vyjme, HodDesetinne(vycit, vyjme));
			// počítáme podil 2 zlomků
	vycit = c1cit*c2jme;
	vyjme = c2cit*c1jme;
	printf("\nPodil zlomku  je: %3d \/ %3d  des: %5.3f",vycit, vyjme, HodDesetinne(vycit, vyjme));
	fflush(stdin); getchar();
	return 0;
}

float HodDesetinne(int a, int b)
{
	return (float)a/b;
}