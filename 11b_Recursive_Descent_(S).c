#include <stdio.h>
#include <string.h>
char input[100];
int i = 0;
int err = 0;
void S();
void L();
void LP();
void S() {
    if (input[i] == 'a')  i++;
    else if (input[i] == '(') {
        i++;
        L();
        if (input[i] == ')') i++;
        else err = 1;
    }
    else err = 1;
}

void L() {
    S();
    LP();
}
void LP() {
    if (input[i] == ',') {
        i++;
        S();
        LP();
    }
}

int main() {
    printf("Enter String: ");
    scanf("%s", input);
    S();
    if (!err && input[i] == '\0') printf("\nString Accepted\n");
    else printf("\nInvalid String\n");
    return 0;
}
