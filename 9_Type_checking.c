%c file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isFloat(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == '.')
            return 1;
    return 0;
}

int main()
{
    char a[20], b[20], op;

    printf("Enter expression (example: 10 + 20): ");
    scanf("%19s %c %19s", a, &op, b);

    if (isFloat(a) == isFloat(b))
        printf("Type checking successful\n");
    else
        printf("Type mismatch\n");

    return 0;
}
