// Retezce01.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>			// pro funkci strlen(r)

int PocetSamohlasek(char s[])
{
	int index=0, p=0;
	while(s[index] != '\0')
	{		// operator '||' se užívá ve smyslu logického or, nebo, log.součet
		if(s[index]== 'a' || s[index]== 'e' || s[index]== 'i' || s[index]== 'o' || s[index]== 'u' || s[index]== 'y')
			p++;
		index++;
	}
	return p;
}

int PocetMezer(char s[])
{
	int index=0, p=0;
	while(s[index] != '\0')
	{
		if(s[index]== ' ')
			p++;
		index++;
	}
	return p;
}

// ÚKOL: napište funkci pro nalezení počtu malých písmen a velkých písmen
int PocetMalych(char s[])
{
	int p=0;
	for(int i=0; i<strlen(s); i++)
		if(s[i]>='a' && s[i]<='z') 
			p++;
	return p;
}

int PocetCifer(char s[])
{
	int p=0;
	for(int i=0; i<strlen(s); i++)
		if(s[i]>='0' && s[i]<='9') 
			p++;
	return p;
}

int PocetSouhlasek(char s[])
{
	int index=0, p=0, delka=0;
	while(s[index] != '\0')		// vlastni ekvivalent knihovni funkce delka=strlen(r);
	{
		delka++;
		index++;
	}
	p=delka-PocetSamohlasek(s)-PocetMezer(s)-PocetCifer(s);
	return p;
}

int main()
{
	char r[]="TOHle 24 je NAS pracovni 1 RETEZEC pro 8 analyzu ZNAKU";
								
	int samohlasek, mezer, souhlasek, cifer, malych;
	samohlasek=PocetSamohlasek(r);       // hledame pocet samohlasek a,e,i,o,u,y
	printf("v retezci \"%s\" je \n- samohlasek: %2d",r,samohlasek);
	mezer=PocetMezer(r);
	printf("\n- mezer     : %2d",mezer);
	souhlasek=PocetSouhlasek(r);
	printf("\n- souhlasek : %2d",souhlasek);
	cifer=PocetCifer(r);
	printf("\n- cifer     : %2d",cifer);
	malych=PocetMalych(r);
	printf("\n- mal pismen: %2d",malych);

	getchar();
	return 0;
}

