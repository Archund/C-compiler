#include <stdio.h>
#include <ctype.h>

#define BUFFER      128 
#define NONE        -1 
#define EOS         '\0'

#define NUM         256 
#define DIV         257 
#define MOD         258 
#define ID          259 
#define DONE        260

#define MAXSYMBOLS  100



int tokenVal; 
int lineNum;


//Symbol Table Entry
struct entry {
    char *aplex; 
    int complex;
};

//SymbolTable
struct entry symbolTable[MAXSYMBOLS]; //TODO- size not known (temp BUFFER)


void error(char *m);
int lexicalAnalyzer();
void sintaxAnalyzer();
void expression();
void term();
void factor();
void pair(int t);
void emitter(int t, int tval);
void start();
int find(char s[]);
int insert(char s[], int clex);