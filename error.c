#include "global.h"
#include <stdlib.h>


// Generates Error Messages
void error(char *m) {

    fprintf(stderr, "Line %d:  %s\n", lineNum, m);
    exit(1);

} //End error()