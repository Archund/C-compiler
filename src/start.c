#include "global.h"

struct entry keywords[] = {
    {"div",             DIV},
    {"mod",             MOD},
    {"if",              IF},	
    {"then",            THEN},
    {"while",           WHILE},
    {"do",              DO},
    {"begin",           BEGIN},
    {"end",             ENDO},
    {"sifalsovea",      FALSO},
    {"siciertovea",     CIERTO},
    {"etiqueta",        ETIQ},
    {"vea",             VEA},
    {"alto",            ALTO},
    {0,                 0}
};

void start(){

    struct entry *p;
    for (p = keywords; p->token; p++)
        insert(p->lexptr, p->token);
    
} //End start()