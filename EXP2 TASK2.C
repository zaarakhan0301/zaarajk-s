#include <stdio.h>

int main()
{
    int start, end, i, sum = 0;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    if (start > end)
    {
        int temp = start;
        start = end;
        end = temp;
    }

    for (i = start; i <= end; i++)
    {
        if (i % 2 != 0)
        {
            sum = sum + i;
        }
    }

    printf("Sum of odd numbers = %d\n", sum);

    return 0;
}