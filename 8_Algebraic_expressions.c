%yacc file

%{
#include <stdio.h>
#include <ctype.h>
int yylex(void);
void yyerror(char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
start : expr '\n' { printf("Result = %d\n", $1); }
      ;

expr  : expr '+' expr { $$ = $1 + $3; }
      | expr '-' expr { $$ = $1 - $3; }
      | expr '*' expr { $$ = $1 * $3; }
      | expr '/' expr { $$ = $1 / $3; }
      | '(' expr ')'  { $$ = $2; }
      | NUM           { $$ = $1; }
      ;
%%

int yylex(void) {
    int c;
    while ((c = getchar()) == ' ' || c == '\t') ;
    if (isdigit(c)) {
        yylval = c - '0';
        while (isdigit(c = getchar()))
            yylval = yylval * 10 + c - '0';
        ungetc(c, stdin);
        return NUM;
    }
    return c;
}

int main() {
    printf("Enter expression: ");
    yyparse();
    return 0;
}

void yyerror(char *s) { printf("Invalid expression\n"); }
