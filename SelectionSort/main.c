#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int i, j, min,temp, a[size];
    printf("Enter the elements of the array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given array: ");
    for(i=0; i<size; i++)
    {
        printf("%d\t", a[i]);
    }
    for(i=0; i<size-1; i++)
    {
        min=i;
        for(j=i+1; j<size; j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    printf("\nThe sorted array: ");
    for(i=0; i<size; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
