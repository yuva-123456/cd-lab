Prg 12


#include <stdio.h>
#include <ctype.h>
char production[10][10];
char first[10];
int n, count;
void findFirst(char c) {
    if (!isupper(c)) {
        first[count++] = c;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (production[i][0] == c) {
            if (production[i][2] == '$' ) first[count++] = '$';
            else if (!isupper(production[i][2])) first[count++] = production[i][2];
            else findFirst(production[i][2]);
        }
    }
}

int main(){
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (Example: E=TR):\n");
    for (int i = 0; i < n; i++) scanf("%s", production[i]);
    printf("\nFIRST Sets:\n");
    for (int i = 0; i < n; i++){
        char nt = production[i][0];
        int printed = 0;
        /* Skip duplicate non-terminals */
        for (int j = 0; j < i; j++) {
            if (production[j][0] == nt) {
                printed = 1;
                break;
            }
        }
        if (printed) continue;
        count = 0;
        findFirst(nt);
        printf("FIRST(%c) = { ", nt);
        for (int j = 0; j < count; j++) printf("%c ", first[j]);
        printf("}\n");
    }
    return 0;
}
