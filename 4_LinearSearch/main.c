#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int i, flag=1, key, a[size];
    printf("Enter the elements of the array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    for(i=0; i<size; i++)
    {
        if(key==a[i])
        {
            printf("\nThe element is found at: %d", i+1);
            flag = 0;
        }
    }
    if(flag)
        printf("\nThe element is found at: %d", i);
    return 0;
}
