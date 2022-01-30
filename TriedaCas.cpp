// TridaCAS.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

class Cas{
private:
	int hodiny, minuty, sekundy;
public:
	Cas(int,int,int);							// konstruktor

	void Zobrazit()
	{
		printf(" %3d hodin + %3d minut + %3d sekund\n",hodiny,minuty,sekundy);
	}

	void Nastavit(int h,int m,int s)
	{
		hodiny=h;
		minuty=m;
		sekundy=s;
	}

	int PocetSekund();
	float PocetMinut();
	float PocetHodin();

	Cas ChybiDoPulnoci(Cas a)
	{
		Cas vysledek(0,0,0);
		int c1, c2, cv;
		c1=24*3600;				// pocet sekund za celý den
		c2=a.PocetSekund();		// zadany cas v sekundach
		cv=c1-c2;				// vysledny rozdil
		vysledek=vysledek.SekundyNaCas(cv);		// prevedeme na cas h m s
		return vysledek;
	}

	Cas SekundyNaCas(int sek)
	{
		Cas vysledek(0,0,0);
		int zbytek,h,m,s;
		h=sek/3600;
		zbytek=sek-h*3600;
		m=zbytek/60;
		s=zbytek-m*60;
		vysledek.Nastavit(h,m,s);
		return vysledek;
	}

	Cas operator-(Cas c)
	{
		Cas vysledek(0,0,0);
		int c1, c2, cv;
		c2=hodiny*3600+minuty*60+sekundy;
		c1=c.PocetSekund();
		cv=c2-c1;
		vysledek=vysledek.SekundyNaCas(cv);
		return vysledek;
	}

	Cas operator+(Cas c)
	{
		Cas vysledek(0,0,0);
		int h=0,m=0,s;
		s = sekundy + c.sekundy;
		if(s>=60)
		{
			s -= 60;
			m++;
		}
		m += minuty + c.minuty;
		if(m>=60)
		{
			m -= 60;
			h++;
		}
		h += hodiny + c.hodiny; 
		vysledek.Nastavit(h,m,s);
		return vysledek;
	}
};

Cas::Cas(int h,int m,int s)		// konstruktor!!
{
	hodiny=h;
	minuty=m;
	sekundy=s;
}

float Cas::PocetHodin()
{
	return(hodiny+minuty/60.0+sekundy/3600.0);
}

float Cas::PocetMinut()
{
	return ((float)hodiny*60+minuty+sekundy/60.0);
}

int Cas::PocetSekund()
{
	return (hodiny*3600+minuty*60+sekundy);
}

int main()
{
	class Cas a(5,13,9),b(3,38,41),test(0,0,0);
	
	printf("             CAS: "); a.Zobrazit();
	test=test.ChybiDoPulnoci(a);
	printf("Do pulnoci chybi: "); test.Zobrazit();
	printf("\ncas A:"); a.Zobrazit();
	printf("cas B:"); b.Zobrazit();
	test=a-b;
	printf("\nRozdil: A-B:"); test.Zobrazit();

	printf("\npocet hodin: %f",test.PocetHodin());
	printf("\npocet minut: %f",test.PocetMinut());

	test=a+b;
	printf("\n\nSoucet: A+B"); test.Zobrazit();

	printf("\npocet hodin: %f",test.PocetHodin());
	printf("\npocet minut: %f",test.PocetMinut());

	test=test.SekundyNaCas(14721);
	printf("\n\nsekund: 14721 prevod na cas:");
	test.Zobrazit();

	int sekcelkem;
	float minutcelkem, hodincelkem;
	sekcelkem=a.PocetSekund();
	printf("Pocet sekund: %d\n",sekcelkem);
	minutcelkem=a.PocetMinut();
	printf("Pocet minut : %f\n",minutcelkem);
	hodincelkem=a.PocetHodin();
	printf("Pocet hodin : %f\n",hodincelkem);

	getchar();
	return 0;
}

