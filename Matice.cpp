// MATICE.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>			// pro funkci odmocnina, cili sqrt()
       // deklarace=prototypy funkci=HLAVICKA; a celé definice jsou až na konci zdrojoveho textu
double MaxHodvMatici(double Matice[3][3], int *indi, int *indj);
	// indi a indj jsou volane odkazem, takto to musí být v c/c++ jako vystupni veliciny funkce
void VypisMatice(double m[3][3]);
// void SoucetMatic(double m1[3][3],double m2[3][3],double vm[3][3]);
// void RozdilMatic(double m1[3][3],double m2[3][3],double vm[3][3]);
void SoucinMatic(double a[3][3],double b[3][3],double v[3][3]);

int main()
{
	double mat1[3][3] =
		{
			{ 3.0, 6.0, 3.0 },
			{ 41.0, 9.0, 7.0 },
			{ 6.0, 4.0, 9.0 }
		};
	double mat2[3][3] =
		{
			{ 1.5, 4.3, 2.0 },
			{ 3.0, 21.0, 8.0 },
			{ 3.0, 9.0, 6.0 }
		};
	//double msoucet[3][3];
	//double mrozdil[3][3];
	//double modmoc[3][3];
	double msoucin[3][3];

	printf("MATICE 1:\n");
	VypisMatice(mat1);
	printf("MATICE 2:\n");
	VypisMatice(mat2);

	/*SoucetMatic(mat1, mat2, msoucet);
	printf("MATICE SOUCET:\n");
	VypisMatice(msoucet);

	RozdilMatic(mat1, mat2, mrozdil);
	printf("MATICE ROZDIL:\n");
	VypisMatice(mrozdil);
*/

	SoucinMatic(mat1,mat2,msoucin);		// volame funkci pro vypocet soucinu matic
	printf("MATICE SOUCIN:\n");
	VypisMatice(msoucin);

	int indexI, indexJ;
	double max;
	max=MaxHodvMatici(msoucin, &indexI, &indexJ);
	printf("max hodnota MSOUCIN je: %7.2lf  na souradnicich \n- radek: %d \n- sloupec: %d",max,indexI+1,indexJ+1);
	
	fflush(stdin); getchar();
	return 0;
}

void VypisMatice(double m[3][3])
{
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			printf("%7.2f",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*void SoucetMatic(double m1[3][3],double m2[3][3],double vm[3][3])
{
	for (int i=0; i<3; i++) 
		for (int j=0; j<3; j++) 
			vm[i][j] = m1[i][j] + m2[i][j];
}

void RozdilMatic(double m1[3][3],double m2[3][3],double vm[3][3])
{
	for (int i=0; i<3; i++) 
		for (int j=0; j<3; j++) 
			vm[i][j] = m1[i][j] - m2[i][j];
}*/

double MaxHodvMatici(double Matice[3][3], int *indi, int *indj)
{
	double m=Matice[0][0];
	*indi=0; *indj=0;	// Inicializace hodnot, jsou proto platné již pro 1. porovnání

	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (Matice[i][j] > m)
			{
				m = Matice[i][j];	// nove maximum
				*indi = i;			// ulozime si jeho indexy
				*indj = j;
			}
		}
	}
	return (m);	// indexy se vraci primo na adresach - tedy volame odkazem
}

void SoucinMatic(double a[3][3],double b[3][3],double v[3][3])
{
	int k;
	for (int i=0; i<3; i++) 
		for (int j=0; j<3; j++)
		{	v[i][j]=0;
			for (k=0; k<3; k++)
				v[i][j] += a[i][k] * b[k][j];
		}
}