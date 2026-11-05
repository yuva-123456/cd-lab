#include <stdio.h>
#include <string.h>

struct Symbol {
        char name[20];
        char type[20];
        char val[20];
};

int main(){
        struct Symbol table[10];
        printf("\nEnter no. of Symbols : ");
        int n;
        scanf("%d", &n);
        for( int i = 0; i < n; i ++){
                //printf("\n\nEnter Symbol %d details:", i+1);
                printf("\nEnter Symbol name: ");
                scanf("%s", table[i].name);
                printf("Enter Symbol data type: ");
                scanf("%s", table[i].type);
                printf("Enter Symbol value: ");
                scanf("%s", table[i].val);
        }
        printf("\n\n\tSYMBOL TABLE\n");
        printf("---------------------------------");
        printf("\nNAME\tTYPE\tVALUE\n");
        printf("---------------------------------");
        for ( int i = 0; i < n; i ++){
                printf("\n%s\t%s\t%s\n", table[i].name, table[i].type, table[i].val);
        }
        return 0;
}
