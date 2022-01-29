#include <stdio.h>
using namespace std;


void VstupDat(int p[]);
void VypisDat(int p[]);
double AritPrumer(int p[]);

int main()
{
    int pole[10];
	double aritprumer;
	VstupDat(pole);
	VypisDat(pole);
	aritprumer=AritPrumer(pole);
	printf("\nAritmeticky prumer je: %6.2lf\n",AritPrumer(pole));
    fflush(stdin); getchar();
    return 0;
}

void VstupDat(int p[])
{
	int pom;
	for(int i=0; i<10; i++)
	{
		printf("Zadejte %2d. prvek celociselneho pole:", i);
		scanf("%d",&pom);
		p[i]=pom;
	}
}

void VypisDat(int p[])
{
	for(int i=0; i<10; i++)
		printf("%d ", p[i]);
}

double AritPrumer(int p[])
{
	double v, suma=0.0;
	for(int i=0; i<10; i++)
		suma += p[i];
	v=suma/10.0;
	return v;
}

/* https://www.tutorialride.com/cpp-array-programs/calculate-arithmetic-mean-c-program.htm
#include<iostream>
using namespace std;
int main()
{
        int num, i, arr[50], sum=0;
        cout<<"\n How Many Numbers You Want to Enter? \n";
        cin>>num;
        cout<<"\n Enter "<<num<<" Numbers : \n";
        for(i=0; i<num; i++)
        {
                cin>>arr[i];
                sum=sum+arr[i];
        }
        int armean=sum/num;
        cout<<"\n Arithmetic Mean = "<<armean;
        return 0;
}
*/