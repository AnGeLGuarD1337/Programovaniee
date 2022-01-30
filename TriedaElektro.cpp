// TridaElektro.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <string.h>

class Elektro {
private:
	char Typ;			// C=CD player, V=video, M=magnetofon, G=gramofon
	char* Znacka[30];	// Sony, Technics, Akai, Aiwa, ...
	int CenaDnes;
	int NovaCena;
	static int CenaCelkem;			// static znamena, že promenna je jedna pro celou tridu
	static int CenaNovaCelkem;
public:
	char* VZnacku(){
		return (char*)Znacka[0];
	}

	char VTyp(){
		return Typ;
	}
	int VNovaCena(){
		return NovaCena;
	}

	void Nastavit(char t, char z[30], int c, int n){
		Typ=t;
		strcpy(*Znacka,z);
		CenaDnes=c;
		NovaCena=n;
		CenaCelkem += CenaDnes;
		CenaNovaCelkem += NovaCena;
	}
	
	Elektro(char t, char z[30], int c, int n){		// konstruktor
		Typ=t;
		strcpy(*Znacka,z);
		CenaDnes=c;
		NovaCena=n;
		CenaCelkem += CenaDnes;
		CenaNovaCelkem += NovaCena;
	}

	Elektro(){		// konstruktor bez parametru
		Typ='C';
		strcpy(*Znacka,"Sony");
		CenaDnes=0;
		NovaCena=0;
		CenaCelkem += CenaDnes;
		CenaNovaCelkem += NovaCena;
	}

	void HodnotaSbirky(){
		printf("Celkova nova cena je: %d Kc\n",CenaNovaCelkem);
		printf("Celkova hodnota   je: %d Kc\n",CenaCelkem);
	}
};

int Elektro::CenaCelkem = 0;		// inicializace static promennych
int Elektro::CenaNovaCelkem = 0;

int main()
{
	Elektro *A = new Elektro[6];			// pole 6 objektu tridy Elektro
	A[0].Nastavit('C',"Sony", 3600,12400);
	A[1].Nastavit('V',"Philips", 2500,8500);
	A[2].Nastavit('M',"Aiwa", 4870,12450);
	A[3].Nastavit('C',"Technics", 1500,7400);
	A[4].Nastavit('V',"Sony", 1500,7400);
	A[5].Nastavit('M',"Akai", 1800,10250);
	A[5].HodnotaSbirky();
								// jaka byla kupni cena vsech CD prehravacu?
	int c=0;
	for(int i=0; i<6; i++)
		if(A[i].VTyp()=='C')
			c+=A[i].VNovaCena();
	printf("Kupni cena vsech CD playeru je %d Kc\n",c);
								// ktery vyrobek mel nejvyssi kupni cenu?
	int max=A[0].VNovaCena();
	int index=0; 
	for(int i=1; i<6; i++)
	{
		if(A[i].VNovaCena()>max){
			max=A[i].VNovaCena();
			index=i;
		}
	}
	printf("index vyrobku: %i\n",index);

	getchar();
	return 0;
}

