#include "global.h"

int preanalisis;


void sintaxAnalyzer() {   
    printf(">>>Start Syntax Analyzer\n");
    preanalisis = lexicalAnalyzer();
    while ( preanalisis != END  ) {
        expression(); pair(';');
    }
    printf(">>>End Syntax Analyzer\n");
}//end sintaxAnalyzer()

void expression(){

    int searching = 1;

    printf(">>Start Expression()\n");
    int t;
    term(); 
    while (searching == 1) {
        switch ( preanalisis ) { 
            case '+': case '-': 
                t = preanalisis;
                pair(preanalisis);
                term();
                emitter(t, EMPTY);
                continue;
            default:
                searching = 0;
                break;
        }
    }
    printf(">>End Expression?\n");
}//end expression()
    
void term() { //TODO
    printf(">>Start Term()\n");
    int t;
    factor();
    while(1) {
        switch ( preanalisis ) {
            case '*': case '/': case DIV: case MOD:
                t = preanalisis;
                pair(preanalisis); factor(); emitter(t, EMPTY);
                continue;
            default:
                printf(">>End Term\n");
                return;
        }
    }
}//end term()

void factor() {
    printf(">>Start Factor()\n");
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
    printf(">>End Factor\n");
}//end factor()

void pair(int t) {
    printf(">>Start pair of %i\n",t);
    if (preanalisis == t)
        preanalisis = lexicalAnalyzer();
    else 
        error("Sintax Error");
    printf(">>End Pair\n");
}//end pair()