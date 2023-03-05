#include <stdio.h>
#include <stdlib.h>
#define n 5

void printarray(int[], int);
void mergesort(int[], int, int);
void merge(int[], int, int, int);
void main()
{
    int a[n], i;
    printf("Enter %d elements of the array: ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given array i:\n");
    printarray(a, n);
    mergesort(a, 0, n-1);
    printf("The sorted array i:\n");
    printarray(a, n);
}
void printarray(int a[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
void mergesort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low + high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}
void merge(int a[], int low, int mid, int high)
{
    int i=low, j=mid+1, k=low, b[n];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for(i=low; i<=high; i++)
        a[i]=b[i];
}
