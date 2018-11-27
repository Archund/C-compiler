#include "global.h"

//FILE* in;

int main() {

    in=fopen ("pruebas.txt","r");
    if (in==NULL) perror ("Error opening file");

    printf("Pruebas------------------------\n\n");
    //printf("Codigo:\n\n%s\n\n\n", prueba);
    start();
    sintaxAnalyzer();
    
    return 0;
  
}//End main()