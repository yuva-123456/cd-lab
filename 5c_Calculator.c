%lex file

%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUM; }
[+\-*/()]   { return yytext[0]; }
[ \t]       ;
\n          { return '\n'; }
.           { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}

_____________________________________________________________________________

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
start : expr '\n' { printf("Result = %d\n", $1); };

expr  : expr '+' expr { $$ = $1 + $3; }
      | expr '-' expr { $$ = $1 - $3; }
      | expr '*' expr { $$ = $1 * $3; }
      | expr '/' expr { $$ = $1 / $3; }
      | '(' expr ')'  { $$ = $2; }
      | NUM           { $$ = $1; }
      ;
%%

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

void yyerror(char *s) { printf("Invalid expression\n"); }
