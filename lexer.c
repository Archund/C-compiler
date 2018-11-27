#include "global.h"


char lexbuf[BUFFER];
int lineNum             = 1;
int tokenVal            = EMPTY;


char prueba[]           = "if A then B:=C;\n  ";
int plen                = sizeof(prueba)/sizeof(char);
int count               = 0;
char* cp                = prueba;



int lexicalAnalyzer() {
    printf("Pruebas------------------------\n\n");
    printf("Codigo:\n\n%s\n\n\n", prueba);

    int c;
    while (1) {

        //c = getchar();
        c = prueba[count];
        count++;
        cp++;

        if ( c == ' ' || c == '\t' ){
            ; // Do nothing


        }else if ( c == '\n' ){
            lineNum++;


        }else if ( isdigit(c) ) {   
            //ungetc(c, stdin);
            count--;
            cp--;
            //scanf("%d", &tokenVal);
            //strcpy(prueba[count],&tokenVal);//TODO, get number
            sscanf(cp, "%d", &tokenVal);

            return NUM;


        }else if ( isalpha(c) ) {   
            int p, b = 0;

            while  ( isalnum(c) ) {   
                lexbuf[b] = c;
                //c = getchar();
                c = prueba[count];
                count++;
                cp++;

                b++;
                if ( b >= BUFFER )
                    error("Compiler error");
            }

            lexbuf[b]  =  EOL;

            if (c != EOF){
                //ungetc(c, stdin);
                count--;
                cp--;
            }

            p = find(lexbuf);

            if (p == 0)
                p = insert(lexbuf, ID);

            tokenVal = p;
            
            return symbolTable[p].token;


        }else if ( c == ':' ) {
            //c = getchar();
            c = prueba[count];
            count++;
            cp++;

            if ( c == '=' ) return ASIGN;


        }else if (c == EOF) {
            return END;


        }else {
            tokenVal = EMPTY;
            
            return c;


}/*End if*/   }/*End while*/  } //End lexicalAnalyzer()