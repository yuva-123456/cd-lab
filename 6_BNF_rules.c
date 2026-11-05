%lex file

%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+      { yylval.num = atoi(yytext); return NUM; }
[+*()]      { return yytext[0]; }
[ \t]       ;
\n          { return '\n'; }
.           { return yytext[0]; }
%%

int yywrap() { return 1;}

_____________________________________________________________________________________________________

%yacc file

%{
#include <stdio.h>
#include <stdlib.h>

struct node {
    char value;
    int num;
    struct node *left, *right;
};

struct node *create(char value, int num, struct node *l, struct node *r) {
    struct node *n = malloc(sizeof(struct node));
    n->value = value;
    n->num = num;
    n->left = l;
    n->right = r;
    return n;
}

void printTree(struct node *n, int level);
int yylex();
void yyerror(char *s);
%}

%union {
    int num;
    struct node *ptr;
}

%token <num> NUM
%type <ptr> expr term factor

%%
start : expr '\n' {
            printf("Abstract Syntax Tree:\n");
            printTree($1, 0);
        }
      ;

expr : expr '+' term { $$ = create('+', 0, $1, $3); }
     | term          { $$ = $1; }
     ;

term : term '*' factor { $$ = create('*', 0, $1, $3); }
     | factor          { $$ = $1; }
     ;

factor : '(' expr ')' { $$ = $2; }
       | NUM          { $$ = create('n', $1, NULL, NULL); }
       ;
%%

void printTree(struct node *n, int level) {
    if (n == NULL) return;
    for (int i = 0; i < level; i++) printf("  ");
    if (n->value == 'n') printf("%d\n", n->num);
    else printf("%c\n", n->value);
    printTree(n->left, level + 1);
    printTree(n->right, level + 1);
}

int main() {
    printf("Enter expression: ");
    yyparse();
    return 0;
}

void yyerror(char *s) { printf("Invalid expression\n");}
