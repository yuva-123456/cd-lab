%{
#include <stdio.h>
int chars = 0, words = 0, spaces = 0, tabs = 0;
%}

%%
[ ]         { spaces++; chars++; }
\t          { tabs++; chars++; }
\n          { chars++; }
[^ \t\n]+   { words++; chars += yyleng; }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter text (Press Ctrl+D when finished):\n");
    yylex();

    printf("\nCharacters = %d", chars);
    printf("\nWords = %d", words);
    printf("\nSpaces = %d", spaces);
    printf("\nTabs = %d\n", tabs);

    return 0;
}
