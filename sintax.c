#include "global.h"

int preanalisis;


void sintaxAnalyzer() {   
    printf(">>>>Start Syntax Analyzer\n");
    preanalisis = lexicalAnalyzer();
    while ( preanalisis != DONE  ) {
        expression(); pair(';');
    while ( preanalisis != END  ) {
        props_opc();//?
        //expression(); pair(';');
    }
    printf("<<<<End Syntax Analyzer\n");
}//end sintaxAnalyzer()

void expression(){
    printf(">>Start Expression\n");
    int t;
    term(); 
    while (1) {
        switch ( preanalisis ) { 
            case '+': case '-': 
                t = preanalisis;
                pair(preanalisis);
                term();
                emitter(t, NONE);
                pair(preanalisis); term(); emitter(t, EMPTY);
                continue;
            default:
                printf("<<End Expression\n");
                return;
        }
    }
}//end expression()
    
void term() { 
    printf(">>Start Term\n");
    int t;
    factor();
    while(1) {
        switch ( preanalisis ) {
            case '*': case '/': case DIV: case MOD:
                t = preanalisis;
                pair(preanalisis); factor(); emitter(t, NONE);
                continue;
            default:
                printf("<<End Term\n");
                return;
        }
    }
}//end term()

void factor() {
    printf(">>Start Factor\n");
    switch( preanalisis ) { 
        case '(':
            pair('('); expression(); pair(')');
            break;
        case NUM:
            emitter(NUM, tokenVal); pair(NUM);
            break;
        case ID:
            emitter(ID, tokenVal); pair(ID);  
            break;
        default:
            error("Sintax Error");
            break;
    }
    printf("<<End Factor\n");
}//end factor()

void pair(int t) {
    printf(">>Start pair of %i\n",t);
    if (preanalisis == t)
        preanalisis = lexicalAnalyzer();
    else 
        error("Sintax Error");
    printf("<<End Pair\n");
}//end pair()


void prop() {           //?
    printf(">>Start prop\n");
    switch( preanalisis ) { 
        case ID:
            emitter(ID, valcomplex); pair(ID); pair(':'); pair('='); expression(); 
            break;
        case IF:
            pair(IF); emitter(IF, EMPTY); expression(); pair(THEN); emitter(THEN, EMPTY); prop();
            break;
        case WHILE:
            pair(WHILE); emitter(WHILE, EMPTY); expression(); pair(DO); emitter(DO, EMPTY); prop();
            break;
        case BEGIN:
            pair(BEGIN); emitter(BEGIN, EMPTY); props_opc(); pair(END); emitter(END, EMPTY);
            break;
        default:
            error("Sintax Error");
            break;
    }
    printf("<<End prop\n");
}//end prop()

void props_opc() {      //?
    printf(">>Start props_opc\n");
    lista_props();
    /* switch ( preanalisis ) {
        case '?':
            lista_props();
            break;
        default:
            printf("<<End props_opc\n");
            break; 
    } */
    printf("<<End props_opc\n");
}//end props_opc()

void lista_props() {    //?
    printf(">>Start lista_props\n");
    int t;
    prop();
    while(1) {
        switch ( preanalisis ) {
            case ';':
                t = preanalisis;
                pair(preanalisis); prop(); emitter(t, EMPTY);
                continue;
            default:
                printf("<<End lista_props\n");
                return;
        }
    }
}//end lista_props()