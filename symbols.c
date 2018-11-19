#include "global.h"
#include <string.h>
#define MAXLEX 999        /*  tamaño de  la matriz de  lexemas  */
//MAXSYMBOLS MOVED TO MAIN

char lexemas[MAXLEX];
int lastLexmas = -1;          /*  última posición usada en  los  lexemas  */
struct entry symbolTable[MAXSYMBOLS];
int lastEntry = 0;           /*  última posición usada en symbolTable */

int find(char s[]) {    /* devuelve  la posición del elemento de entryde s */
    printf(">>Start find for %s\n",s);
    int p;
    for (p = lastEntry; p>0; p = p-1)
        if (strcmp(symbolTable[p].aplex, s) == 0)
            return p;
    return 0;
}//end find()

int insert(char s[], int clex) {  /* devuelve  la posición del elemento deentry de s  */
    printf(">>Start insert of %s\n",s);
    int lon;
    lon = strlen(s);            /*  strlen evalúa  la longitud de s  */
    if (lastEntry + 1 >= MAXSYMBOLS)
        error("Symbol list is full");
    if (lastLexmas + lon + 1 >= MAXLEX)
        error("Lexmas Matrix full");

    lastEntry++;
    symbolTable[lastEntry].complex = clex;
    symbolTable[lastEntry].aplex = &lexemas[lastLexmas + 1];
    lastLexmas = lastLexmas + lon + 1;
    strcpy( symbolTable[lastEntry].aplex, s );
    printf(">>End Insert\n");
    return lastEntry;
}//end insert()