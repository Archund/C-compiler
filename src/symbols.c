#include "global.h"
#include <string.h>

#define STRMAX 999                              // size of lexemes table


char lexemes[STRMAX];
int lastChar = -1;                              // last position used for lexemes
struct entry symbolTable[MAXSYMBOLS];
int lastEntry = 0;                              // last position used in symbolTable




//returns the position of input s
int find(char s[]) {

    for (int p = lastEntry; p>0; p = p-1) {
        if (strcmp(symbolTable[p].lexptr, s) == 0) {
            return p;
    }   }

    return 0;

} //End find()



//returns the position of the entry struct of input s
int insert(char s[], int clex) {
    
    int lon = strlen(s);

    if (lastEntry + 1 >= MAXSYMBOLS)
        error("Symbol list is full");
    if (lastChar + lon + 1 >= STRMAX)
        error("Lexemes Matrix is full");

    lastEntry++;

    symbolTable[lastEntry].token = clex;
    symbolTable[lastEntry].lexptr = &lexemes[lastChar + 1];
    lastChar = lastChar + lon + 1;

    strcpy( symbolTable[lastEntry].lexptr, s );
    
    return lastEntry;

} //End insert()