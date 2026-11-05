#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

void E();
void EP();
void T();
void TP();
void F();

void E()
{
    T();
    EP();
}

void EP()
{
    if (input[i] == '+')
    {
        i++;
        T();
        EP();
    }
}

void T()
{
    F();
    TP();
}

void TP()
{
    if (input[i] == '*')
    {
        i++;
        F();
        TP();
    }
}

void F()
{
    if (input[i] == '(')
    {
        i++;
        E();

        if (input[i] == ')')
            i++;
        else
        {
            printf("Rejected\n");
            return;
        }
    }
    else if (input[i] == 'i' && input[i + 1] == 'd')
    {
        i += 2;
    }
    else
    {
        printf("Rejected\n");
    }
}

int main()
{
    printf("Enter Expression: ");
    scanf("%s", input);

    E();

    if (input[i] == '\0')
        printf("\nString Accepted\n");
    else
        printf("\nRejected\n");

    return 0;
}
