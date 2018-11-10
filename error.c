#include "global.h"
#include <stdlib.h>

 void error(char *m) {        /*  genera todos  los mensajes de error  */
    fprintf(stderr, "Line %d:  %s\n", lineNum, m);
    exit(1);                  /*  terminación sin éxito */
 }//end error()