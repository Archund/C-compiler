#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define BUFFER 128 
#define EMPTY -1 
#define EOL '\0'

#define NUM 256
#define DIV 257 
#define MOD 258 
#define ID  259 
#define END 260

#define IF	  261 
#define THEN  262 
#define WHILE 263 
#define DO    264 
#define BEGIN 265 
#define ENDO  266 //todo

#define FALSO  267
#define CIERTO 268
#define VEA    269
#define ALTO   270
#define ETIQ   271
#define ASIGN  272
#define IDL    273

#define MAXSYMBOLS 100


int tokenVal; 
int lineNum;
extern int number;

FILE* in;


struct entry {
  char *lexptr; 
  int token;
};

struct entry symbolTable[MAXSYMBOLS]; //TODO - size not known (temp BUFFER)





void error(char *m);
int lexicalAnalyzer();
void sintaxAnalyzer();
void expression();
void term();
void factor();
int prop();
void props_opc();
int lista_props();
void pair(int t);
void emitter(int t, int tval);
void start();
int find(char s[]);
int insert(char s[], int clex);
int etiqnueva();