#include "global.h"

void emitter(int t, int tval) { /* genera  la salida  */
  switch(t) {
    case '+': case '-': case '*': case '/':
      printf("%c\n", t); 
    break;
    case DIV:
      printf("DIV\n");
    break;
    case MOD:
      printf("MOD\n");
    break;
    case IF:
      printf("IF\n");
    break;
    case THEN:
      printf("THEN\n");
    break;
    case WHILE:
      printf("WHILE\n");
    break;
    case DO:
      printf("DO\n");
    break;
    case BEGIN:
      printf("BEGIN\n");
    break;
    case ENDO:
      printf("ENDO\n");
    break;
    case NUM:
      printf("inserta %d\n", tval); 
    break;
    case ASIGN:
      printf(":=\n");
    break;
    case FALSO:
      printf("sifalsovea %d\n",tval);
    break;
    case CIERTO:
      printf("siciertovea %d\n",tval);
    break;
    case VEA:
      printf("vea %d\n",tval);
    break;
    case ETIQ:
      printf("etiqueta %d\n",tval);
    break;
    case ALTO:
      printf("alto\n");
    break;
    case IDL:
      printf("valori(%s)\n", symbolList[tval].aplex);
    break;
    case ID:
      printf("valord(%s)\n", symbolList[tval].aplex);
    break;
    default:
      printf("complex %d,  valcomplex %d\n", t, tval);
  }
}//end emitter()