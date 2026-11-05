%{
#include <stdio.h>
#include <string.h>
int count = 0;
char words[100][20];
int lengths[100];
%}

%%
[a-zA-Z]{6,9}   {
                        strcpy(words[count], yytext);
                        lengths[count] = yyleng;
                        count++;
                }

\n              {
                        int i;
                        printf("\nNo. of words with length > 5 and < 10 = %d\n\n", count);
                        printf("Words with length > 5 and < 10:\n");
                        for(i = 0; i < count; i++)
                        { printf("%d. %s\t(Length = %d)\n",i + 1,words[i],lengths[i]);}

                }
.               ;

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
