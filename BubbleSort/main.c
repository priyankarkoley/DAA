#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int i, j, temp, a[size];
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
        for(j=0; j<size-1-i; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nThe sorted array: ");
    for(i=0; i<size; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
