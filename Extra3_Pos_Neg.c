%{
#include <stdio.h>
%}

%%
-[0-9]+      { printf("\nNegative Integer\n"); }
[0-9]+       { printf("\nPositive Integer\n"); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("\nEnter Integer: ");
    yylex();
    return 0;
}
