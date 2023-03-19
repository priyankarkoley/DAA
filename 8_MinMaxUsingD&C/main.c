#include <stdio.h>
#include <stdlib.h>

int max, min;
int a[100];
void maxmin(int i, int j)
{
    int max1, min1, mid;
    if(i==j)
        min-max-a[i];
    else if (i-j-1)
    {
        if(a[i] <a[j])
        {
            min=a[i];
            max=a[j];
        }
        else
        {
            min=a[i];
            max=a[j];
        }
    }
    else
    {
        mid = (i+j)/2;
        maxmin (0,mid);
        max1 = max;
        min1 = min;
        maxmin(mid+1,j);
        if(max1>max)
            max=max1;
        if(min1<min)
            min = min1;
    }
}
void main()
{
    int i,n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    printf("\nThe array is: ");
    for(i=0; i<n; i++)
    {
        a[i] = rand();
        printf("%d\t", a[i]);
    }
    max=a[0];
    min=a[0];
    maxmin(0, n-1);
    printf("\n\nThe maximum value is: %d", max);
    printf("\nThe minmium value is: %d\n", min);
}
