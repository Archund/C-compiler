#include "global.h"


int lookahead;
int number = -2;





// GLC rules, always starts with props_opc
void sintaxAnalyzer() { 
    
    lookahead = lexicalAnalyzer();
    while ( lookahead != END  ) {
        props_opc(); pair(';');

}   }//End sintaxAnalyzer()




// GLC for props_opc
void props_opc() { lista_props(); }




// GLC for lista_props
int lista_props() {
    prop();
    while(1) {
        switch ( lookahead ) {

            case ';':
                pair(lookahead); prop();
                continue;

            default:
                return 0;

}   }   } //End lista_props()




// GLC for prop
int prop() {           
    int etiq, etiq2;
    switch( lookahead ) { 

        case ID:
            emitter(IDL, tokenVal); 
            pair(ID); 
            pair(ASIGN); 
            expression(); 
            emitter(ASIGN, tokenVal);
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
            //ENABLE TO EXTEND ORIGINAL GRAMMAR
            //expression();
            return 0;

} return 0;  } //End prop()




//GLC rule for expression
void expression(){
    term(); 
    while (1) {
        switch ( lookahead ) { 

            case '+': case '-':
                pair(lookahead); term(); emitter(lookahead, EMPTY);
                continue;

            default:
                return;

}   }   } //End expression()
    



// GLC rule for term
void term() { 

    factor();
    while(1) {
        switch ( lookahead ) {

            case '*': case '/': case DIV: case MOD:
                pair(lookahead); factor(); emitter(lookahead, EMPTY);
                continue;

            default:
                return;

}   }   } //End term()




// GLC rule for factor
void factor() {
    switch( lookahead ) { 

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
            error("Sintax Error in factor");
            break;

}   } //End factor()





// searches for input in lookahead string
void pair(int t) {

    if (lookahead == t)
        lookahead = lexicalAnalyzer();
    else 
        error("Sintax Error in pair");

}//end pair()



// add a new tag
int etiqnueva() {
    number--;
    return number;
}