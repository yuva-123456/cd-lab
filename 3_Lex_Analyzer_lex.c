%{
#include <stdio.h>
%}

LETTER          [a-zA-Z]
DIGIT           [0-9]

%%

"int"|"char"|"if"|"else"|"for"|"while"  {printf("%-12s: Keyword\n", yytext);}
{LETTER}({LETTER}|{DIGIT})*             {printf("%-12s: Identifier\n", yytext);}
{DIGIT}+                                {printf("%-12s: Constant\n", yytext);}
"+"|"-"|"*"|"/"|"%"                     {printf("%-12s: Operator\n", yytext);}
"("|")"|"{"|"}"|"["|"]"|";"|","         {printf("%-12s: Special Symbol\n", yytext);}
[\t\n]                                  ;
.                                       ;

%%

int yywrap(){return 1;}

int main(){
        yylex();
        return 0;
}
