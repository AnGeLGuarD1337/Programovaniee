#include <stdio.h>

#define SOUBOR "soubor.bin"
#include <math.h>
#include <windows.h>    //TCHAR

using namespace std;

int main(int argc, TCHAR* argv[])
{
	FILE *souBIN;
	int z;
	float x,sinx,hu;
	long p;
	souBIN=fopen(SOUBOR,"wb");		// režim binární mode="wb"
											//tabulka x a sin x pro x=0 po 90
	for(x=0.0;x<91;x++){
		z=fwrite(&x, 4, 1, souBIN);		// zapisujeme z adresy x do souboru po 4 bytech //Little endian
		sinx=(float)sin((double)x*3.141592653/180);
		z=fwrite(&sinx, 4, 1, souBIN);	// zapisujeme float tedy 4 x 1 byte binárně
		printf("x= %f sin x= %f\n",x,sinx);
	}
	fclose(souBIN);

	/*souBIN=fopen(SOUBOR,"ab");		// režim binární mode APPEND= doplneni za konec ="ab"
											//tabulka x a sin x pro x=0 po 90
	for(x=91.0f;x<181;x++){
		z=fwrite(&x, 4, 1, souBIN);
		sinx=(float)sin((double)x*3.141592653/180);
		z=fwrite(&sinx, 4, 1, souBIN);
		printf("x= %f sin x= %f\n",x,sinx);
	}
	fclose(souBIN);
	printf("soubor doplnen do 180 stupnu\n");*/

												// hledáme sinus zadané hodnoty v souboru
	printf("zadej uhel: "); scanf("%f",&hu);	// hu je hledany uhel
	souBIN=fopen(SOUBOR,"rb");					// režim binární čtení = "rb"
	while((z=fread(&x, 4, 1, souBIN) != 0)){	// načteme si úhel do proměnné x
		z=fread(&sinx, 4, 1, souBIN);			// načteme si jeho sinus
		if(hu==x){
			printf("x= %f sin x= %f\n",x,sinx);
			break;
		}
	}
	fclose(souBIN);

	fflush(stdin); getchar();
	return 0;
}

/* Overenie

https://gregstoll.com/~gregstoll/floattohex/

*/