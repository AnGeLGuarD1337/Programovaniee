// TridaZlomek.cpp : Defines the entry point for the console application.
// matice pro výpočet hodnot zlomku
//	c=		1		2		3		4		5		6		7		8		9		10
//j= 1		1.00	2.00	3.00	4.00	5.00	6.00	7.00	8.00	9.00	10.00
//	 2		0.50	1.00	1.50	2.00	2.50	3.00	3.50	4.00	4.50	5.00
//	 3		0.33
//	...
//	10		0.10																	1.00

#include <stdio.h>
#include <math.h>		// kvuli funkci abs()

class Zlomek
{
	private:
		int Jmenovatel, Citatel;
		float hodnota, odmocnina;
	public:
		Zlomek(int cit, int jme);	// konstruktor 1 - pouze prototyp! pozdeji  bude definice
        Zlomek(int cislo);			// konstruktor 2
        Zlomek();					// bezparametrický konstruktor

		Zlomek operator +(Zlomek b)			// pretizeni operatoru +
		{
			Zlomek vysledek(0,1);
			vysledek.NastavCit(Citatel*b.Jmenovatel+Jmenovatel*b.Citatel);
			vysledek.NastavJme(b.Jmenovatel*Jmenovatel);
			return vysledek;
		}

		Zlomek operator -(Zlomek b)			// pretizeni operatoru -
		{
			Zlomek vysledek(0,1);
			vysledek.NastavCit(Citatel*b.Jmenovatel-Jmenovatel*b.Citatel);
			vysledek.NastavJme(b.Jmenovatel*Jmenovatel);
			return vysledek;
		}

		Zlomek operator *(Zlomek b)			// pretizeni operatoru *
		{
			Zlomek vysledek(0,1);
			vysledek.NastavCit(Citatel*b.Citatel);
			vysledek.NastavJme(b.Jmenovatel*Jmenovatel);
			return vysledek;
		}

		Zlomek operator /(Zlomek b)			// pretizeni operatoru /
		{
			Zlomek vysledek(0,1);
			vysledek.NastavCit(Citatel*b.Jmenovatel);
			vysledek.NastavJme(Jmenovatel*b.Citatel);
			return vysledek;
		}

		void ZakladniTvar(double number, double precision)
		{
			int c=1, j=1;
            while (abs((float)c/(float)j-number)>precision)
            {
                if ((float)c / (float)j > number)
                    j++;	// jsem-li vetsi tak zlomek zmensim zvetsenim jmenovatele 
                else
                    c++;	// jsem-li MENsi tak zlomek zvetsim zvetsenim čitatele
            }
            Citatel = c;
            Jmenovatel = j;
		}

		void VypHodnoty()
		{
			hodnota=(float)Citatel/Jmenovatel;		
		}

		void VypOdmocniny()
		{
			odmocnina=(float)sqrt((double)hodnota);		
		}

		float DejOdm()
        {
            return odmocnina;
        }

		void NastavCit(int c)
        {
            Citatel = c;
        }

        void NastavJme(int j)
        {
            if (j != 0) Jmenovatel = j;
			else Jmenovatel = 1;

        }
        
		int DejCit()
        {
            return Citatel;
        }
        
		int DejJme()
        {
            return Jmenovatel;
        }

		float DejHodnotu()
		{
			return hodnota;
		}
        
		/* ~Zlomek()			destruktor - volá se při rušení objektu
        {	// znak tilda a název třídy bez mezery, pouze 1 destruktor ve třídě!!
            printf("Rusim zlomek S hodnotou: %f\n",hodnota);
        }*/

        float Hodnota()
        {
            return (float)Citatel / Jmenovatel;
        }

        Zlomek(double number, double precision)		// dalsi konstruktor viz zakladni tvar
        {
				// X = new fraction(3.141lf, 0.0001lf) - this should generate:  355 / 113
            int c=1, j=1;
            while (abs((float)c/(float)j-number)>precision)
            {
                if ((float)c / (float)j > number)
                    j++;
                else
                    c++;
            }
            Citatel = c;
            Jmenovatel = j;
        }
};

Zlomek::Zlomek(int cit, int jme)			// konstruktor 1
{
     Citatel = cit;
     if (jme != 0)
        Jmenovatel = jme;
     else
     {
        Jmenovatel = 1;
     }
}

Zlomek::Zlomek(int cislo)					// konstruktor 2
{
     Citatel = cislo;
     Jmenovatel = 1;
}

Zlomek::Zlomek()							// bezparametrický konstruktor
{
     Citatel = 0;
     Jmenovatel = 1;
}

int main()
{
	class Zlomek Z(0,1);
	
	printf("c=	1	2	3	4	5	6	7	8	9     10\n");
	for(int j=1; j<11; j++){
		printf("%2d",j);
		for(int c=1; c<11; c++)
		{
			Z.NastavCit(c);
			Z.NastavJme(j);
			Z.VypHodnoty();
			printf("   %5.2f",Z.DejHodnotu());
		}
		printf("\n");
	}
// vypoctete vyraz:
//					3/7  +  5/12
//					------------
//					6/14 -  4/20


	//Z.~Zlomek();			// volame si sami destruktor

	class Zlomek a(3,7), b(5,12),cit(0,1),c(6,14),d(4,20), jme(0,1), vys(0,1);
	cit=a+b;
	jme=c-d;
	vys=cit/jme;
	vys.VypHodnoty();
	vys.ZakladniTvar(vys.DejHodnotu(),0.0001);

	printf("c= %3d\n", vys.DejCit());
	printf("j= %3d\n", vys.DejJme());
	printf("Hodnota= %f\n", vys.DejHodnotu());
	
	getchar();
	return 0;
}

