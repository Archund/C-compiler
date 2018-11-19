#include "global.h"

char buflex[BUFFER];
int lineNum = 1;
int tokenVal = NONE;

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
            scanf("%d", &tokenVal);
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
            buflex[b]  =  EOS;
            if (t != EOF)
                ungetc(t, stdin);
            p = find(buflex);
            if (p == 0)
                p = insert(buflex, ID);
            tokenVal = p;
            printf(">>End Lexical Analyzer\n");
            return symbolTable[p].complex;
        }
        else if (t == EOF){
            printf(">>End Lexical Analyzer\n");
            return DONE;
        }
        else {
            tokenVal = NONE;
            printf(">>End Lexical Analyzer\n");
            return t;
        }
    }

}//end lexicalAnalyzer()