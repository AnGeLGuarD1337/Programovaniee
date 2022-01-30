// TridaHudbaSbirka.cpp : Defines the entry point for the console application.

#include <iostream>
#include "stdio.h"
#include <string>

using namespace std;

class HudebniSbirka
{
private:
    string Skupina;
    string Deska;
    int RokVydani;
    float Delka;		//  45.24     ve vyznamu 45 min 24 sek
    string Nosic;       // 'C'=CD, 'L'=LP, 'K' = magnet kazeta, 'F' = MP3 soubor
    int Cena;

public:
    static int CelkemMinut;    //hraci doba celkem = soucet hracich dob
	static int CelkemSekund;   //hraci doba celkem = soucet hracich dob
    static int Hodnota;        //Soucet cen

    HudebniSbirka(string S, string D, int RV, float DK, string N, int C)	// KONSTRUKTOR
    {
        Skupina = S;
        Deska   = D;
        RokVydani = RV;
        Delka = DK;
        Nosic = N;
        Cena = C;
        CelkemMinut = CelkemMinut + (int)DK;
		CelkemSekund = CelkemSekund+100*(DK-(int)DK);	// přičteme 100 x desetinnou část ze 45.24 bude 0.24*100=24 
        Hodnota = Hodnota + C;			// pripocitame aktualni cenu k dosavadni hodnote sbirky
    }

    void UkazHodnotu()
    {
        printf("Celkova cena je: %d\n", Hodnota);
    }

    void UkazDoby()
    {
        printf("Celkova hraci doba je: %d min %d sek\n", CelkemMinut, CelkemSekund);
}

	void UkazPoOprave2()		// 124, 112
	{
		int h, m, s;
		h=CelkemMinut/60;			// 2			
		m=CelkemMinut-60*h;			// 124-60*2 = 4
		m += CelkemSekund/60;		// 4+112/60=4+1 = 5
		s=CelkemSekund-(CelkemSekund/60)*60;	// 112-(112/60)*60 = 
												// 112-1*60= 52
		printf("h= %d m= %d s= %d\n",h,m,s);
	}
};
									// inicializace statickych promennych
int HudebniSbirka::Hodnota = 0;
int HudebniSbirka::CelkemMinut = 0;
int HudebniSbirka::CelkemSekund = 0;

void UkazPoOprave(int min, int sek)		// 124, 112
{					// OBECNA FUNKCE - neni tedy ze tridy HudebniSbirka
	int h, m, s;
	h=min/60;			// 2			
	m=min-60*h;			// 124-60*2 = 4
	m += sek/60;		// 4+112/60=4+1 = 5
	s=sek-(sek/60)*60;		// 112-(112/60)*60 = 
							// 112-1*60= 52
	printf("h= %d m= %d s= %d\n",h,m,s);
}

int main()
{
	class HudebniSbirka H1("abba","waterloo", 1977, 42.24, "L", 350);
    class HudebniSbirka H2("abba","voulez-vous", 1980, 43.52, "C", 550);
    class HudebniSbirka H3("beatles","revolver", 1968, 39.36, "L", 400);
	class HudebniSbirka H5("beatles","abbeyroad", 1969, 37.56, "K", 500);
	class HudebniSbirka H6("beatles","whitealbum", 1970, 38.58, "F", 380);

    class HudebniSbirka H4(" "," ", 0, 0, " ", 0);
    H4.UkazDoby();
	printf("Celkova cena je: %d\n", HudebniSbirka::Hodnota);	// static muzeme primo vypsat jako public
	UkazPoOprave(HudebniSbirka::CelkemMinut,HudebniSbirka::CelkemSekund);
	H4.UkazPoOprave2();
	getchar();	
    return 0;
}









