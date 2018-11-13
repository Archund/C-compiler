#include "global.h"

char buflex[BUFFER];
int lineNum = 1;
int valcomplex = EMPTY;

int lexicalAnalyzer() {  
    printf(">>Start Lexical Analyzer\n");

    int t;
    while (1) {
        printf("Insert code:\n");
        t = getchar();
        if ( t == ' ' || t == '\t' )
            ;
        else if (t == '\n')
            lineNum++;
        else if ( isdigit(t) ) {   
            ungetc(t, stdin);
            scanf("%d", &valcomplex);
            printf(">>End Lexical Analyzer\n");
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
            printf(">>End Lexical Analyzer\n");
            return symbolList[p].complex;
        }
        else if (t == EOF){
            printf(">>End Lexical Analyzer\n");
            return END;
        }
        else {
            valcomplex = EMPTY;
            printf(">>End Lexical Analyzer\n");
            return t;
        }
    }

}//end lexicalAnalyzer()