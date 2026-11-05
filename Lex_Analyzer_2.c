#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][20] = {"int", "float", "char", "if", "else", "for", "while", "void", "return"};

int isKeyword (char str[] ){
        int n = sizeof(keywords)/sizeof(keywords[0]);
        for ( int i = 0; i < n; i ++){
                if ( strcmp ( str, keywords[i]) == 0) return 1;
        }
        return 0;
}

int main(){
        char input[30];
        printf("Enter a statement in C: ");
        fgets( input, sizeof(input) , stdin);
        int i = 0;
        while ( input[i] != '\0'){
                //Space
                if ( isspace(input[i])){
                        i++;
                        continue;
                }
                //Keyword or identifier
                if ( isalpha(input[i]) || input[i] == '_'){
                        char word[10];
                        int j = 0;
                        while ( isalnum(input[i]) || input[i] == '_') word[j++] = input[i++];
                        word[j] = '\0';
                        if ( isKeyword(word) ) printf("Keyword   \t:\t%s\n", word);
                        else printf("Identifier\t:\t%s\n", word);
                }
                //Constant
                else if ( isdigit(input[i])){
                        char num[10];
                        int j = 0;
                        while ( isdigit(input[i]) ) num[j++] = input[i++];
                        num[j] = '\0';
                        printf("Constant\t:\t%s\n", num);
                }
                //Operator
                else if ( strchr("+-*/%=!<>", input[i])) printf("Operator\t:\t%c\n", input[i++]);
                //Special Symbols
                else if ( strchr("(){}[];.#,", input[i])) printf("Special Symbol\t:\t%c\n", input[i++]);
                else printf("Unknown\t:\t%c\n", input[i++]);
        }
        return 0;
}
