#include <stdio.h>
#include <stdlib.h>
#define n 5

void printarray(int[], int);
void quicksort(int[], int, int);
int partition(int[], int, int);
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
    quicksort(a, 0, n-1);
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
void quicksort(int a[], int low, int high)
{
    int partitionindex;
    if(low<high)
    {
        partitionindex = partition(a, low, high);
        quicksort(a, low, partitionindex-1);
        quicksort(a, partitionindex+1, high);
    }
}
int partition(int a[], int low, int high)
{
    int temp, i, j, pivot = a[low];
    i=low+1;
    j=high;
    do
    {
        while(a[i]<=pivot)
            {i++;
            printf("%d ", a[i]);}
        while(a[j]>pivot)
            j--;
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i<j);
    temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}
