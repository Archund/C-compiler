#include "global.h"

char buflex[BUFFER];
int lineNum = 1;
int valcomplex = EMPTY;

int lexicalAnalyzer() {  
    printf(">>Start Lexical Analyzer\n\n");

    int t;
    while (1) {
        t = getchar();
        if ( t == ' ' || t == '\t' )
            ;
        else if ( t == '\n' )
            lineNum++;
        else if ( isdigit(t) ) {   
            ungetc(t, stdin);
            scanf("%d", &valcomplex);
            printf("<<End Lexical Analyzer (isdigit)\n");
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
            printf("<<End Lexical Analyzer (isalpha)\n");
            return symbolList[p].complex;
        }
        else if ( t == ':' ) {
            t = getchar();
            if ( t == '=' ) {
                printf("<<End Lexical Analyzer (is :=)\n");
                return ASIGN;    
            }
            printf("<<End Lexical Analyzer (is :)\n");
        }
        else if (t == EOF) {
            printf("<<End Lexical Analyzer (is EOF)\n");
            return END;
        }
        else {
            valcomplex = EMPTY;
            printf("<<End Lexical Analyzer (is EMPTY)\n");
            return t;
        }
    }

}//end lexicalAnalyzer()