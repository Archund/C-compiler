#include <stdio.h>
#include <ctype.h>

#define BUFFER 128 
#define EMPTY -1 
#define EOL '\0'

#define NUM 256 
#define DIV 257 
#define MOD 258 
#define ID  259 
#define END 260



int valcomplex; 
int lineNum;

struct entry {
  char *aplex; 
  int complex;
};

struct entry symbolList[BUFFER]; //TODO- size not known (temp BUFFER)


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