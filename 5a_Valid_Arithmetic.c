%lex file

%{
#include "y.tab.h"
%}

%%
[0-9]+          { return NUM; }
[+\-*/()]       { return yytext[0];}
[ \t\n]         ;
.               { return yytext[0]; }
%%

int yywrap() {return 1;}

_____________________________________________________________________________________________________________________

%yacc file

%{
#include <stdio.h>
int yylex();
void yyerror(char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
expr:   expr '+' expr |
        expr '-' expr |
        expr '*' expr |
        expr '/' expr |
        '(' expr ')'  |
        NUM
        ;
%%

int main() {
        printf("Enter an expression: ");
        if ( yyparse() == 0) printf("Valid Expression\n");
        return 0;
}
void yyerror( char *s) {
        printf("Invalid Expression\n");
}
