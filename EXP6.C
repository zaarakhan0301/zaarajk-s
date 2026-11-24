#include <stdio.h>

void counter()
{
    static int count = 0;

    count++;

    printf("Function called %d times\n", count);
}

int main()
{
    int i;

    for (i = 1; i <= 5; i++)
    {
        counter();
    }

    return 0;
}