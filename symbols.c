#include "global.h"
#include <string.h>
#define MAXLEX 999        /*  tamaño de  la matriz de  lexemas  */
#define MAXSYMBOLS 100      /*  tamaño de symbolList  */

char lexemas[MAXLEX];
int lastLexmas = -1;          /*  última posición usada en  los  lexemas  */
struct entry symbolList[MAXSYMBOLS];
int lastEntry = 0;           /*  última posición usada en symbolList */

int find(char s[])       /* devuelve  la posición del elemento de entryde s */{
  int p;
  for (p = lastEntry; p>0; p = p-1)
    if (strcmp(symbolList[p].aplex, s) == 0)
      return p;
  return 0;
}//end find()

int insert(char s[], int clex) {  /* devuelve  la posición del elemento deentry de s  */
  int lon;
  lon = strlen(s);            /*  strlen evalúa  la longitud de s  */
  if (lastEntry + 1 >= MAXSYMBOLS)
    error("Symbol list is full");
  if (lastLexmas + lon + 1 >= MAXLEX)
    error("Lexmas Matrix full");

  lastEntry++;
  symbolList[lastEntry].complex = clex;
  symbolList[lastEntry].aplex = &lexemas[lastLexmas + 1];
  lastLexmas = lastLexmas + lon + 1;
  strcpy( symbolList[lastEntry].aplex, s );
  return lastEntry;
}//end insert()