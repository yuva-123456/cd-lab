#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;

    p = (int *)malloc(sizeof(int));

    if(p == NULL) return 1;

    *p = 100;
    printf("Value = %d\n", *p);

    free(p);
    printf("Memory released");

    return 0;
}
