%lex file

%{
#include "y.tab.h"
%}

%%
[a-zA-Z0-9]    { return yytext[0]; }
[+\-*/()]      { return yytext[0]; }
\n             { return '\n'; }
[ \t]          ;
%%

int yywrap()
{
    return 1;
}

__________________________________________________________________________

%yacc file

%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);

char postfix[100];
int pos = 0;

void add(char c)
{
    postfix[pos++] = c;
    postfix[pos] = '\0';
}
%}

%left '+' '-'
%left '*' '/'

%%

input:
    expr '\n'
    ;

expr:
    expr '+' expr { add('+'); }
    | expr '-' expr { add('-'); }
    | expr '*' expr { add('*'); }
    | expr '/' expr { add('/'); }
    | '(' expr ')'
    | operand
    ;

operand:
    'a' { add('a'); }
    | 'b' { add('b'); }
    | 'c' { add('c'); }
    | 'd' { add('d'); }
    | 'e' { add('e'); }
    | 'f' { add('f'); }
    | 'g' { add('g'); }
    | 'h' { add('h'); }
    | 'i' { add('i'); }
    | 'j' { add('j'); }
    | '0' { add('0'); }
    | '1' { add('1'); }
    | '2' { add('2'); }
    | '3' { add('3'); }
    | '4' { add('4'); }
    | '5' { add('5'); }
    | '6' { add('6'); }
    | '7' { add('7'); }
    | '8' { add('8'); }
    | '9' { add('9'); }
    ;

%%

int main()
{
    printf("Enter infix expression: ");
    yyparse();

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

void yyerror(const char *s)
{
    printf("Invalid expression\n");
}
