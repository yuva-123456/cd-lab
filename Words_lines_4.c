%{
#include <stdio.h>
int words = 0;
int lines = 1;
%}

%%

\n              {lines++;}
[ \t]+          ;
[^ \t\n]+       {words++;}

%%

int yywrap(){return 1;}
int main (){
        printf("Enter text : \n\n");
        yylex();
        printf("\n\nNo. of lines : %d\n", lines);
        printf("No. of words : %d\n", words);
        return 0;
}
