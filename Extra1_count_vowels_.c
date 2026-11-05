%{
#include <stdio.h>

int count = 0;
%}

%%

[aAeEiIoOuU]      { count++; }

\n                { printf("\nNumber of vowels:\t %d\n", count); return 0; }

.                 ;

%%

int yywrap() {
        return 1;
}

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}
