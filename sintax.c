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
            pair('('); emitter('(',EMPTY); expression(); pair(')'); emitter(')',EMPTY);
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

void prop() {           
    int etiq, prueba;
    printf(">>Start prop\n");
    switch( preanalisis ) { 
        case ID:
            emitter(ID, valcomplex); pair(ID); pair(ASIGN); expression(); emitter(ASIGN, EMPTY);
            break;
        case IF: 
            pair(IF); 
            expression();
            etiq = etiqnueva();
            emitter(SIFALSOVEA, etiq); 
            pair(THEN); 
            prop(); 
            emitter(ETIQ, etiq);
            break;
        case WHILE:
            prueba = etiqnueva();
            emitter(ETIQ, prueba);
            pair(WHILE); 
            expression();
            etiq = etiqnueva();
            emitter(SIFALSOVEA, etiq); 
            pair(DO);
            prop();
            emitter(VEA, prueba);
            emitter(ETIQ, etiq);
            break;
        case BEGIN:
            pair(BEGIN);
            props_opc(); 
            pair(ENDO);
            emitter(ALTO, EMPTY); 
            break;
        default:
            error("Sintax Error in prop");
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

void lista_props() {    
    printf(">>Start lista_props\n");
    //int t;
    prop(); lista_props1();
    /*while(1) {
        switch ( preanalisis ) {
            case ';':
                t = preanalisis;
                pair(preanalisis); prop(); emitter(t, EMPTY);
                continue;
            default:
                printf("<<End lista_props\n");
                return;
        }
    }*/
    printf("<<End lista_props\n");
}//end lista_props()

void lista_props1() {
    printf(">>Start lista_props1\n");
    switch( preanalisis ) {
        case ';':
            prop(); lista_props1();
        break;
        default:
            printf("<<End lista_props1\n");
        break;
    }
}//end prop1()
//gcc -o Testeo sintax.o emitter.o error.o lexor.o main.o start.o symbols.o
//if 3 then a := a + 2;