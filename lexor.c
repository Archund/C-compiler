#include "global.h"

char buflex[BUFFER];
int lineNum = 1;
int valcomplex = EMPTY;

int lexicalAnalyzer() {  

  int t;
  while (1) {
    t = getchar();
    if ( t == ' ' || t == '\t' )
      ;
    else if (t == '\n')
      lineNum++;
    else if ( isdigit(t) ) {   
      ungetc(t, stdin);
      scanf("%d", &valcomplex);
      return NUM;
    }
    else if ( isalpha(t) ) {   
      int p, b = 0;
      while  ( isalnum(t) ) {   
        buflex[b] = t;
        t = getchar();
        b++;
        if ( b >= BUFFER )
          error("Compiler eror");
      }
      buflex[b]  =  EOL;
      if (t != EOF)
        ungetc(t, stdin);
      p = find(buflex);
      if (p == 0)
        p = insert(buflex, ID);
      valcomplex = p;
      return symbolList[p].complex;
    }
    else if (t == EOF)
      return END;
    else {
      valcomplex = EMPTY;
      return t;
    }
  }
}//end lexicalAnalyzer()