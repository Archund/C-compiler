#include "global.h"

struct entry keywords[] = {
  {"div", DIV},
  {"mod", MOD},
  {0,     0}
};

void start(){
  struct entry *p;
  for (p = keywords; p->complex; p++)
    insert(p->aplex, p->complex);
}//end start()