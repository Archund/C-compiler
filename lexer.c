#include "global.h"


char lexbuf[BUFFER];
int lineNum = 1;
int tokenVal = EMPTY;






int lexicalAnalyzer() {

    int c;
    while (1) {

        c = getchar();

        if ( c == ' ' || c == '\t' ){
            ; // Do nothing


        }else if ( c == '\n' ){
            lineNum++;


        }else if ( isdigit(c) ) {   
            ungetc(c, stdin);
            scanf("%d", &tokenVal);
            
            return NUM;


        }else if ( isalpha(c) ) {   
            int p, b = 0;

            while  ( isalnum(c) ) {   
                lexbuf[b] = c;
                c = getchar();
                b++;
                if ( b >= BUFFER )
                    error("Compiler error");
            }

            lexbuf[b]  =  EOL;

            if (c != EOF)
                ungetc(c, stdin);

            p = find(lexbuf);

            if (p == 0)
                p = insert(lexbuf, ID);

            tokenVal = p;
            
            return symbolTable[p].token;


        }else if ( c == ':' ) {
            c = getchar();

            if ( c == '=' ) return ASIGN;


        }else if (c == EOF) {
            return END;


        }else {
            tokenVal = EMPTY;
            
            return c;


}/*End if*/   }/*End while*/  } //End lexicalAnalyzer()