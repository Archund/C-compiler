#include "global.h"

int preanalisis;


void sintaxAnalyzer() {   
  preanalisis = lexicalAnalyzer();
  while ( preanalisis != END  ) {
    expression(); pair(';');
  }
}//end sintaxAnalyzer()

void expression(){
  int t;
  term(); 
  while (1) {
    switch ( preanalisis ) { 
      case '+': case '-': 
        t = preanalisis;
        pair(preanalisis);
        term();
        emitter(t, EMPTY);
        continue;
      default:
        break;
    }
  }

}//end expression()
    
void term() { //TODO
  int t;
  factor();
  while(1) {
    switch ( preanalisis ) {
    case '*': case '/': case DIV: case MOD:
      t = preanalisis;
      pair(preanalisis); factor(); emitter(t, EMPTY);
      continue;
    default:
      return;
    }
  }
}//end term()

void factor() {
  switch( preanalisis ) { 
    case '(':
      pair('('); expression(); pair(')');
      break;
    case NUM:
      emitter(NUM, valcomplex); pair(NUM);
      break;
    case ID:
      emitter(ID, valcomplex); pair(ID);  
      break;
    default:
      error("Sintax Error");
  }
}//end factor()

void pair(int t) {
  if (preanalisis == t)
    preanalisis = lexicalAnalyzer();
  else 
    error("Sintax Error");
}//end pair()