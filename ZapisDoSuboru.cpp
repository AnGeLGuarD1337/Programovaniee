// SouborTextVytvoreni.cpp : main project file.

//#include "StdAfx.h"
#include <iostream>
#include "stdio.h"
#include <string>
#include "math.h"
#include "string.h"
#include <ctime>
using namespace std;
#define NAZEV "textak.txt"

int main(void)
{
    FILE *soubor;
    char text[255];
    soubor = fopen(NAZEV, "a+"); /* soubor se otevre pro append tedy doplnovani textu,
                                    neexistujici soubor se vytvori */
    fputs("Zadejte slovo, ktere chcete zapsat do souboru\n"
              "a stisknete \"q\" pro ukonceni: ", stdout);
	do {
        scanf("%254s", text);
        if (!strcmp(text, "q"))
            break;				// konec cyklu jen po zadani "q"
        fprintf(soubor, "%s\n", text);		// zapiseme slovo do souboru
    } while (1);	// vždy pravda=nekonečný cyklus, je proto unkončen přes break

    fclose(soubor);

    return 0;
}

