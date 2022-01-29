// funkce pro obecny soucet dvou casu (h,m,s)+(h,m,s)=(h,m,s)

//#include "StdAfx.h"
#include <iostream>
#include "stdio.h"
#include <string>
#include "math.h"
#include "string.h"
#include <ctime>
using namespace std;

void SoucetCasu(int h1, int m1, int s1,int h2, int m2, int s2, int *h, int *m, int *s);
void RozdilCasu(int h1, int m1, int s1,int h2, int m2, int s2, int *h, int *m, int *s);

int main()
{
	int h1,m1,s1,h2,m2,s2,h,m,s;
	
	printf("zadej 1. cas - hodiny : ");
	scanf("%d",&h1);
	printf("zadej 1. cas - minuty : ");
	scanf("%d",&m1);
	printf("zadej 1. cas - sekundy: ");
	scanf("%d",&s1);
	printf("zadej 2. cas - hodiny : ");
	scanf("%d",&h2);
	printf("zadej 2. cas - minuty : ");
	scanf("%d",&m2);
	printf("zadej 2. cas - sekundy: ");
	scanf("%d",&s2);
	SoucetCasu(h1, m1, s1, h2, m2, s2, &h, &m, &s);
	printf("Soucet casu je %2d hod %2d min %2d sek\n",h,m,s);
	RozdilCasu(h1, m1, s1, h2, m2, s2, &h, &m, &s);
	printf("Rozdil casu je %2d hod %2d min %2d sek\n",h,m,s);

	fflush(stdin);getchar();
	return 0;
}

void RozdilCasu(int h1, int m1, int s1,int h2, int m2, int s2, int *h, int *m, int *s)
{	
	int sekcelkem1, sekcelkem2, sekvysledne, hv, mv, sv;
	sekcelkem1=h1*3600+m1*60+s1;
	sekcelkem2=h2*3600+m2*60+s2;
	sekvysledne=sekcelkem1-sekcelkem2;
	hv=sekvysledne/3600;		// hodiny po celociselnem deleni
	sekvysledne -= hv*3600;		// zbyva jeste tolik sekund k prevodu na min a sek
	mv=sekvysledne/60;			// minuty po celociselnem deleni
	sv = sekvysledne-60*mv;		// zbyva jeste tolik sekund
	*h=hv;
	*m=mv;
	*s=sv;
}

void SoucetCasu(int h1, int m1, int s1,int h2, int m2, int s2, int *h, int *m, int *s)
{
	int ho=0, mi=0, se;
	se=s1+s2;
	if(se>59)
	{
		mi++;
		se -= 60;
	}
	mi=mi+m1+m2;
	if(mi>59)
	{
		ho++;
		mi -= 60;
	}
	ho=ho+h1+h2;
	*h=ho;
	*m=mi;
	*s=se;
}