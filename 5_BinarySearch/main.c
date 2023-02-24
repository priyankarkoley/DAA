#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int i, key, a[size];
    printf("Enter the elements of the array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int low = 0, high = size, mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            printf("\nThe element is found at: %d", mid+1);
            exit(0);
        }
        else if(key<a[mid])
            high=mid-1;
        else if(key>a[mid])
            low=mid+1;
    }
    printf("\nThe element not found");
    return 0;
}
