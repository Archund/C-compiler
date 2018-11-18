#include "global.h"

struct entry keywords[] = {
  {"div", DIV},
  {"mod", MOD},
  {"if", IF},	//?
  {"then", THEN},
  {"while", WHILE},
  {"do", DO},
  {"begin", BEGIN},
  {"endo", ENDO},
  {0,     0}
  //anañdirlo a keywords?
};

void start(){
    printf(">>>Start function\n");

    struct entry *p;
    for (p = keywords; p->complex; p++)
        insert(p->aplex, p->complex);
    
    printf(">>>End Start function\n");
}//end start()