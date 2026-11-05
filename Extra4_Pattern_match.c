%{
#include <stdio.h>
#include <string.h>
char words[100][50];
int counts[100];
int total = 0;

int findWord(char *w)
{
    for (int i = 0; i < total; i++)
    {
        if (strcmp(words[i], w) == 0)
            return i;
    }
    return -1;
}
%}

%%
[a-zA-Z]+   {
                int idx = findWord(yytext);
                if (idx == -1)
                {
                    strcpy(words[total], yytext);
                    counts[total] = 1;
                    total++;
                }
                else
                {
                    counts[idx]++;
                }
            }
[ \t]+      ;
\n          {
                for (int i = 0; i < total; i++)
                {
                    printf("Pattern %s found %d time%s\n",
                           words[i], counts[i], counts[i] > 1 ? "s" : "");
                }
            }
.           ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter text:\n");
    yylex();
    return 0;
}
