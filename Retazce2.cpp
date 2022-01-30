// Retezce02.cpp : Defines the entry point for the console application.
// vytvořte tento text:
// A
// AB
// ABC
//...
// ABCDEFGHIJKLMNOPQRSTUVWXYZ

#include <stdio.h>
#include <string.h>			// knihovna funkci pro praci s retezci

//void Zretezit(char a[], char b[]);
//void ZretezitN(char a[], char b[], int n);
void vypisASCII(void);

int main()
{
	/*char s[]= "Hello World";
	int delka;
	delka= strlen(s);				// délka řetězce
	printf("Delka retezce %s je %d\n",s,delka);

	char p1[50] = "Hello ";
	char p2[30] = "World druha verze";
	char zretezeno[80];
	Zretezit(p1,p2);					// zřetězení p1=p1+p2 "concatenation"
	delka= strlen(p1);
	printf("Delka retezce %s je %d\n",p1,delka);
									// strncat(char *dest, const char *src, size_t n);
	ZretezitN(p1,p2,5);				// zřetězení p1 = p1 + 5 znaků z p2
	delka= strlen(p1);
	printf("Delka retezce %s je %d\n",p1,delka);*/

	vypisASCII();

	fflush(stdin); getchar();
	return 0;
}

void Zretezit(char a[], char b[])		// obdoba knihovni funkce strcat
{
	int i=0;
	while(a[i]!='\0')
		i++;
	int j=0;
	while(b[j]!='\0')
		a[i++]=b[j++];
}

void ZretezitN(char a[], char b[], int n)		// obdoba knihovni funkce strncat
{
	int i=0;
	while(a[i]!='\0')
		i++;
	int j=0;
	while(j<n)
		a[i++]=b[j++];
}

void vypisASCII(void)
{
	int posun;
	posun='a'-'A';
	for(int i=0; i<26; i++)
	{		// 65 je kod velkeho A v ASCII, tj. 41 hexa = 4*16+1
		for(int z=65; z<=65+i; z++)
			printf("%c%c",z,z+posun);		// %c znamená znak podle kodu int, byte, apod.
		printf("\n");
	}
}

// úkol přetvořte to do podoby:
//  Aa
//	AaBb
//  AaBbCc
//  ...
//	AaBbCc .... XxYyZz
