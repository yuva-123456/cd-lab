%lex file

%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*    { return ID;}
\n                      { return '\n';}
.                       { return yytext[0];}
%%

int yywrap() { return 1; }

________________________________________________________________________________

%yacc file

%{
#include <stdio.h>
int yylex();
void yyerror( char *s);
%}

%token ID

%%
stmt : ID '\n';
%%

int main() {
        printf("Enter a Variable: ");
        if ( yyparse() == 0) printf("Valid Variable\n");
        return 0;
}

void yyerror( char *s )  { printf("Invalid Variable\n"); }
