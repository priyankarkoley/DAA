#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int i, a[size], min, max;
    printf("Enter the elements of the array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
    min=a[0];
    max=a[0];
    for(i=0; i<size; i++)
    {
        if(min>a[i])
        {
            min=a[i];
        }
        if(max<a[i])
        {
            max=a[i];
        }
    }
    printf("Minimum: %d\t", min);
    printf("Maximum: %d", max);
    return 0;
}
