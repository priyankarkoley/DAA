//CHOOSE K ARRAY ELEMENTS SUCH THAT DIFFERENCE OF MAXIMUM AND MINIMUM IS MINIMIZED
#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int low, int mid, int high)
{
    int b[10];
    int i = low, j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }

        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

void MergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}
void Print(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int Window(int arr[], int length, int k)
{
    int MinDiff, i, j, dif;
    MinDiff = arr[length - 1] - arr[0];

    for(i = 0; i+k-1<length; i++)
    {
        j = i+k-1;
        dif = arr[i+k-1] - arr[i];
        if (dif < MinDiff)
            MinDiff = dif;
    }
    return MinDiff;
}

int main()
{
    int i, length, Mindifference, k;

    printf("\nEnter the length of the array: ");
    scanf("%d", &length);
    int arr[length];
    for(i=0; i<length; i++)
        arr[i] = rand();
    printf("\nEnter the value of k: ");
    scanf("%d", &k);
    printf("\nThe given array: ");
    Print(arr, length);
    MergeSort(arr, 0, length - 1);
    Mindifference = Window(arr, length, k);
    printf("\nThe minimum difference is: %d \n", Mindifference);
    return 0;
}
