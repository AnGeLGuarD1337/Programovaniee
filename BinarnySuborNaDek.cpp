// BinHodnotaNaDek.cpp : Defines the entry point for the console application.
//

#include <string.h>				// pro pouziti funkce strlen
#include <malloc.h>				// pro alokaci pam�ti pro n� �et�zec
#include <math.h>				// pro pouziti funkce pow  je obecna mocnina x na y
#include <windows.h>
#include <stdio.h>

int BinRetNaDekHod( char *r);		// prototypy funkc� kon�� ;, vlastn� k�d je pod main()
char * DekHodNaBinRet( int h);
									//int BinRet16bitNaDekHod( char *r);		
									//char * DekHodNaBinRet16bit( int h);

int main(int argc, TCHAR* argv[])
{
	int dek;
	char *binret;
	binret = (char*)malloc(9);		// mame zaru�eno �e se najde 9 volnych bytu pro na� �et�zec

	printf("Zadej bin retezec 8 znaku nul a jednicek: ");
	scanf("%s",binret);
	dek = BinRetNaDekHod(binret);
	printf("retezec %s ma hodnotu %d\n",binret,dek);
	fflush(stdin); getchar();

	printf("Zadej cislo 0 - 255: ");
	scanf("%d",&dek);
	binret=DekHodNaBinRet(dek);
	printf("hodnota %d odpovida bin retezci %8s\n",dek,binret);
	
	fflush(stdin); getchar();
	return 0;
}

int BinRetNaDekHod(char *r)
{
	int v=0, vaha;
	for (int i=0;i<8;i++)		// indexy v C a C++ v�dy od 0
	{
		vaha=7-i;		// index 0 vede na 2 na 7, ..., index 7 vede na 2 na 0
		if(r[i]=='1')	// fce pow je power - obecna mocnina x na y je pow(x,y)
			v += (int)pow((double)2,(double)vaha);
	}			
	return v;
}

char * DekHodNaBinRet( int h){
	char *vysledek;
	vysledek = (char*)malloc(9);	// mame zaru�eno �e se najde 9 volnych bytu pro na� �et�zec
	for (int i=7;i>=0;i--)		// indexy v C a C++ v�dy od 0
	{
		if(h >= (int)pow((double)2,(double)i))
		{
			vysledek[7-i]='1';		// je-li hodnota > ne� 2 na i tak p�u 1, jinak 0
			h -= (int)pow((double)2,(double)i);	// ode�tu 2 na i od h
		}
		else
			vysledek[7-i]='0';
	}
	vysledek[8]='\0';		// konec �et�zce je tvrd� nula tedy byte sam�ch nul '\0' nesta�� '0' to je v ASCII !=0 !!!
	return vysledek;
}