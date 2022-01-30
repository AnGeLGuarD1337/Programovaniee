// TridaVypoctiMzdu.cpp : Defines the entry point for the console application.

#include <stdio.h>

class Mzda{
private:
	int hrubeho;
	int odmena_zdan;		// odmena zdanitelna
	int priplatek_nezd;		// priplatek bez dane - diety, cestak, kazen. odmena apod.
	int odecitpol;			// 2570 na poplatnika, podle poctu deti...
	int pocdeti;
	int zdancastka;		// hrubeho + odmena_zdan - odecitpol
	float soczdrpoj;		// 11% z (hrubeho+odmena_zdan)
	float dan;				// 15% ze zdancastky
	float cisteho;			// zdancastka - soczdrpoj - dan + priplatek_nezd
public:
	Mzda(int Hrubeho, int Odmena_zdan, int Priplatek_nezd, int Pocdeti);				// konstruktor
	void NastavHodnoty(int Hrubeho, int Odmena_zdan, int Priplatek_nezd, int Pocdeti);
	void Vypocet();
	int VratHrube();
	int VratZdanC();
	float VratCiste();
	float VratSZP();
	float Vratdan();
};

int Mzda::VratHrube(){
	return hrubeho;	
}

float Mzda::Vratdan(){
	return dan;	
}

float Mzda::VratSZP(){
	return soczdrpoj;	
}

float Mzda::VratCiste(){
	return cisteho;	
}

Mzda::Mzda(int Hrubeho, int Odmena_zdan, int Priplatek_nezd, int Pocdeti) // konstruktor
{
	hrubeho=Hrubeho;
	odmena_zdan=Odmena_zdan;
	priplatek_nezd=Priplatek_nezd;
	pocdeti=Pocdeti;
}

void Mzda::Vypocet(){
	odecitpol=0;
	if(pocdeti==1) odecitpol += 1267;
	if(pocdeti==2) odecitpol += 3127;
	if(pocdeti==3) odecitpol += 5447;
	if(pocdeti>3)  odecitpol += 5447 + 2320*(pocdeti-3);
	zdancastka=hrubeho+odmena_zdan;
	soczdrpoj=(float)0.11*(hrubeho+odmena_zdan);
	dan=(float)0.15*zdancastka-2570-odecitpol;		// 2570 je sleva na poplatika roku 2022
	cisteho=(float)hrubeho+odmena_zdan-soczdrpoj-dan+priplatek_nezd;
}

void Mzda::NastavHodnoty(int Hrubeho, int Odmena_zdan, int Priplatek_nezd, int Pocdeti){
	hrubeho=Hrubeho;
	odmena_zdan=Odmena_zdan;
	priplatek_nezd=Priplatek_nezd;
	pocdeti=Pocdeti;
}

int main()
{
	class Mzda Petr(0,0,0,0);
	int h, oz, pn, deti;
	printf("zadej hrubou mzdu       :"); scanf("%d",&h);
	printf("zadej odmenu zdanitelnou:"); scanf("%d",&oz);
	printf("zadej priplatek nezdanit:"); scanf("%d",&pn);
	printf("zadej pocet deti        :"); scanf("%d",&deti);

	Petr.NastavHodnoty(h,oz,pn,deti);
	Petr.Vypocet();

	printf("Hrube  %7d\n",Petr.VratHrube());
	printf("Dan    %7.0f\n",Petr.Vratdan());
	printf("SZP    %7.0f\n",Petr.VratSZP());
	printf("Ciste  %7.0f\n",Petr.VratCiste());
	
    /*
	class Mzda Petr(0,0,0,0);
	int p;
	printf("          TABULKA CISTE MZDY\n\n");
	printf(" 			   pocet deti\nhrubeho      0        1        2	3	 4\n");
	for(p=20000; p<59000; p+=2500)
	{
		printf("%6d",p);
		for(int d=0; d<5; d++)
		{
			Petr.NastavHodnoty(p,0,0,d);
			Petr.Vypocet();
			printf("  %7.0f",Petr.VratCiste());
		}
		printf("\n");
	}
    */
	fflush(stdin);getchar();
	return 0;
}

