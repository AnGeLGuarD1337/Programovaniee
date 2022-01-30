// sTRUKTURAkomplcislo.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>			// pro definici odmocniny sqrt

typedef struct {
	double re, im;
	double modul;
} KOMP;

KOMP Secti (KOMP a, KOMP b)
{
	KOMP c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return c;
}

KOMP Odecti (KOMP a, KOMP b)
{
	KOMP c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return c;
}

KOMP ZadaniKC(void)
{
	KOMP v;
	double pom;
	printf("\nZadejte realnou cast KC: ");
	scanf("%lf",&pom);
	v.re=pom;
	fflush(stdin);
	printf("Zadejte komplexni cast KC: ");
	scanf("%lf",&pom);
	v.im=pom;
	fflush(stdin);
	return v;
}

KOMP vypoctiModulKC(KOMP k)
{
	k.modul=sqrt(k.re*k.re + k.im*k.im);
	return k;
}

void UkazKC(KOMP v)
{
	printf("\nHodnota je %5.2lf + %5.2lf i, modul= %5.2lf\n ",v.re, v.im, v.modul);
}

KOMP Soucin(KOMP a, KOMP b)
{
	KOMP c;
	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;   
	return c;
}

KOMP Podil(KOMP a, KOMP b)
{
	KOMP c;
	c.re =(a.re*b.re + a.im*b.im) / (b.re*b.re + b.im*b.im);
	c.im =(a.im*b.re - a.re*b.im) / (b.re*b.re + b.im*b.im);   
	return c;
}

int main()
{
	KOMP x, y, z;
	x = ZadaniKC();		x=vypoctiModulKC(x);	UkazKC(x);
	y = ZadaniKC();		y=vypoctiModulKC(y);	UkazKC(y);
	z=Podil(x,y);
	z=vypoctiModulKC(z);	
	printf("PODIL JE: "); UkazKC(z);
	z=Secti(x,y);
	z=vypoctiModulKC(z);	
	printf("SOUCET JE: "); UkazKC(z);
	z=Odecti(x,y);
	z=vypoctiModulKC(z);	
	printf("ROZDIL JE: "); UkazKC(z);
	z=Soucin(x,y);
	z=vypoctiModulKC(z);	
	printf("SOUCIN JE: "); UkazKC(z);
	


	fflush(stdin);getchar(); return 0;
}

