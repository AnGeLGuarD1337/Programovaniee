// TridaMatOperace.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>			// pro sinus, cos, atan, ...

class MatOper {
private:  float oper1, oper2, vysledek;
		  char operace;			// '+' '-' '*' '/' s=sin c=cos a=atan m=modulo, ...
public:
	MatOper(float,float,char);
	void Vypocet();
	void UkazVysledek();
	void NastavOperaci(char o);
};

double faktorial(int n)
{
	double f=1;
	for(int i=2;i<=n;i++)
		f *= i;
	return f;
}

double kombinace(int n, int k)
{
	double v;
	v=faktorial(n)/faktorial(k)/faktorial(n-k);
	return v;
}

void MatOper::NastavOperaci(char o)
{
	operace=o;
}

void MatOper::UkazVysledek()
{
	printf("vysledek operace %c je %6.2f\n", operace, vysledek);
}

void MatOper::Vypocet()
{
	char oper;
	oper=operace;
	switch(oper)
	{
		case '+': vysledek= oper1 + oper2; break;
		case '-': vysledek= oper1 - oper2; break;
		case '*': vysledek= oper1 * oper2; break;
		case '/': vysledek= oper1 / oper2; break;	
		case '2': vysledek= oper1 * oper1; break;		// hodnota op1 na druhou
		case '3': vysledek= oper1 * oper1 * oper1; break;	// hodnota op1 na treti
		case 's': vysledek= (float)sin((double)oper1*3.141592/180); break;	// hodnota sinus(op1)
		case 'c': vysledek= (float)cos((double)oper1*3.141592/180); break;	// hodnota cosinus(op1)
		case 'a': vysledek= (float)atan((double)oper1/oper2)*180/3.141592; break;	
													// hodnota arcus tangens op1/op2
		case 'm': vysledek= (float)sqrt(oper1*oper1 + oper2*oper2); break;
										// modul, tj. odmocnina ze souctu ctvercu
		case 'n': vysledek= (float)pow((double)oper2,(double)1/oper1); break;	// n-ta odmocnina
		case 'o': vysledek= (float)sqrt((double)oper1); break;	// odmocnina
		case 'f': vysledek=(float)faktorial((int)oper1); break;	// faktorial moji funkci
		case 'k': vysledek=(float)kombinace(oper1, oper2);		// n nad k=kombin. cislo
	}
}

MatOper::MatOper(float o1,float o2,char op)		//	konstruktor
{
	oper1=o1; oper2=o2; operace=op;
}

int main()
{
	class MatOper a(4,1000,'n');
	a.Vypocet();	// n-ta odmocnina 2. operandu
	a.UkazVysledek();

	a.NastavOperaci('m');
	a.Vypocet();
	a.UkazVysledek();

	a.NastavOperaci('s');
	a.Vypocet();
	a.UkazVysledek();

	a.NastavOperaci('o');	// odmocnina 1. operandu
	a.Vypocet();
	a.UkazVysledek();

	getchar();
	return 0;
}

