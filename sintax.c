#include "global.h"

int preanalisis;
int number = -2;

void sintaxAnalyzer() {   
    printf(">>>>Start Syntax Analyzer\n");
    preanalisis = lexicalAnalyzer();
    while ( preanalisis != END  ) {
        props_opc(); pair(';');
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
                pair(preanalisis); factor(); emitter(t, EMPTY);
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
            emitter(NUM, valcomplex); pair(NUM);
            break;
        case ID:
            emitter(ID, valcomplex); pair(ID);  
            break;
        default:
            error("Sintax Error in factor");
            break;
    }
    printf("<<End Factor\n");
}//end factor()

void pair(int t) {
    printf(">>Start pair of %i\n",t);
    if (preanalisis == t)
        preanalisis = lexicalAnalyzer();
    else 
        error("Sintax Error in pair");
    printf("<<End Pair\n");
}//end pair()

int etiqnueva() {
    number--;
    return number;
}

int prop() {           
    int etiq, etiq2;
    printf(">>Start prop\n");
    switch( preanalisis ) { 
        case ID:
            emitter(IDL, valcomplex); 
            pair(ID); 
            pair(ASIGN); 
            expression(); 
            emitter(ASIGN, valcomplex);
            break;
        case IF: 
            pair(IF); 
            expression();
            etiq = etiqnueva();
            emitter(FALSO, etiq); 
            pair(THEN); 
            prop(); 
            emitter(ETIQ, etiq);
            break;
        case WHILE:
            etiq2 = etiqnueva();
            emitter(ETIQ, etiq2);
            pair(WHILE); 
            expression();
            etiq = etiqnueva();
            emitter(FALSO, etiq); 
            pair(DO);
            prop();
            emitter(VEA, etiq2);
            emitter(ETIQ, etiq);
            break;
        case BEGIN:
            pair(BEGIN);
            props_opc(); 
            pair(ENDO);
            emitter(ALTO, EMPTY); 
            break;
        default:
            //expression();
            return 0;
    }
    printf("<<End prop\n");
}//end prop()

void props_opc() {      
    printf(">>Start props_opc\n");
    lista_props();
    printf("<<End props_opc\n");
}//end props_opc()

int lista_props() {    
    printf(">>Start lista_props\n");
    int t;
    prop();
    while(1) {
        switch ( preanalisis ) {
            case ';':
                t = preanalisis;
                pair(preanalisis); prop(); lista_props();
                continue;
            default:
                printf("<<End lista_props\n");
                return 0;
        }
    }
    printf("<<End lista_props\n");
}//end lista_props()

//gcc -o Testeo sintax.o emitter.o error.o lexor.o main.o start.o symbols.o
//if 3 then a := a + 2;