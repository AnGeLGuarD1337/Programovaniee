// TridaKomplexCisel.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <math.h>					// pro odmocninu na vypocet modulu

class komplexni_cislo {				// definice tridy
private:
	double realna_cast, imag_cast;
	double modul;
public:
	double rc();					// vrac� re�lnou ��st kompl. ��sla
	double ic();					// vrac� imagin. ��st kompl. ��sla
	double m();						// vrac� modul        kompl. ��sla
	komplexni_cislo(double r, double i);		// konstruktor 1
	komplexni_cislo(double r);					// konstruktor 2
	void nastav_hodnotu(double x, double y);
	void vypoctimodul();
	komplexni_cislo operator +(komplexni_cislo y);		// pretizeni operatoru +
	komplexni_cislo operator -(komplexni_cislo y);		// pretizeni operatoru -
	komplexni_cislo operator *(komplexni_cislo y);		// pretizeni operatoru *
	komplexni_cislo operator /(komplexni_cislo y);		// pretizeni operatoru /
	void UkazSe();
};	

// vypoctete v�raz: 
//					(4+2i)*(3-6i)
//					-------------
//					(3-6i)-(4+2i)

int main()
{
	class komplexni_cislo a(4,2), b(3,-6);
	class komplexni_cislo cit(0), jme(0), vys(0);
	cit=a*b;
	jme=b-a;
	vys=cit/jme;
	cit.vypoctimodul();
	jme.vypoctimodul();
	vys.vypoctimodul();
	cit.UkazSe();
	jme.UkazSe();
	vys.UkazSe();

	/*class komplexni_cislo a(8,3);		// deklarace instance ze tridy, pouzity 1. konstruktor
	class komplexni_cislo b(4,-3);		//								pouzity 1. konstruktor
	class komplexni_cislo c(0);			//								pouzity 2. konstruktor
						
	a.vypoctimodul();
	b.vypoctimodul();
	c=a/b;			// vol�m p�et�en� oper�tor pro komplexn� ��sla
					// a je objekt ktery vola metodu, b je parametr
	c.vypoctimodul();

	a.UkazSe();
	b.UkazSe();
	c.UkazSe();*/

	fflush(stdin);getchar();
	return 0;
}

komplexni_cislo komplexni_cislo:: operator /(komplexni_cislo y)
{
	komplexni_cislo vysledek(0,0);
	double rc, ic, jme;
	jme=y.realna_cast*y.realna_cast+y.imag_cast*y.imag_cast;
	rc=(realna_cast*y.realna_cast+imag_cast*y.imag_cast)/jme;
	ic=(imag_cast*y.realna_cast-realna_cast*y.imag_cast)/jme;
	vysledek.nastav_hodnotu(rc,ic);
	return vysledek;
}

komplexni_cislo komplexni_cislo:: operator *(komplexni_cislo y)
{
	komplexni_cislo vysledek(0,0);
	vysledek.nastav_hodnotu(realna_cast*y.realna_cast-imag_cast*y.imag_cast,realna_cast*y.imag_cast+y.realna_cast*imag_cast);
	return vysledek;
}

komplexni_cislo komplexni_cislo:: operator +(komplexni_cislo y)	// v=x+y, x se bere z objektu, kter� se vyvolal
{
	komplexni_cislo vysledek(0,0);
	vysledek.nastav_hodnotu(realna_cast+y.realna_cast, imag_cast+y.imag_cast);
	return vysledek;
}

komplexni_cislo komplexni_cislo:: operator -(komplexni_cislo y)
{
	komplexni_cislo vysledek(0,0);
	vysledek.nastav_hodnotu(realna_cast-y.realna_cast, imag_cast-y.imag_cast);
	return vysledek;
}

void komplexni_cislo::nastav_hodnotu(double x, double y)
{
	realna_cast=x;
	imag_cast=y;
}

komplexni_cislo::komplexni_cislo(double r)		// konstruktor 2
{
	realna_cast=r;
	imag_cast=0;
}

void komplexni_cislo::UkazSe()
{
	printf("\nRealna cast je %lf\n",realna_cast);
	printf("Imagin cast je %lf i\n",imag_cast);
	printf("Modul       je %lf\n",modul);

}

komplexni_cislo::komplexni_cislo(double r, double i)	// konstruktor 1
{
	realna_cast=r;
	imag_cast=i;
}

void komplexni_cislo::vypoctimodul()
{
	modul=sqrt(realna_cast*realna_cast+imag_cast*imag_cast);
}

