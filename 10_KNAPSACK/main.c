#include <stdio.h>
#include <stdlib.h>

void printarray(float a[], int size)
{
    int i;
    for(i=0; i<size; i++)
        printf("%f\t", a[i]);
    printf("\n");
}

void BubbleSort(float a[], float b[], int size)
{
    int i, j;
    float temp;
    float c[size];//ARRAY for profit/weight ratio
    for(i=0; i<size; i++)
        c[i]=a[i]/b[i];
    //printf("\nRatio: ");
    //printarray(c, size);
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-1-i; j++)
        {
            if(c[j]<c[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;

                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
    //printf("\nRatio now: ");
    //printarray(c, size);
}
float knapsack(float p[], float w[], int size)
{
    float m, profit;
    int i;
    //PROFIT AND WEIGHTS AS GIVEN
    //printf("Profit: ");
    //printarray(p, size);
    //printf("Weight: ");
    //printarray(w, size);

    //printf("\nSORTING..\n");
    BubbleSort(p, w, size);//SORTING ACORDING TO P/W ratio (function call)

    //printf("Profit now: ");
    //printarray(p, size);
    //printf("Weight now: ");
    //printarray(w, size);
    printf("Enter the total capacity: ");
    scanf("%f", &m);
    for(i=0; i<size; i++)
    {
        if(m>0 && w[i]<=m)
        {
            m=m-w[i];
            profit=profit+p[i];
        }
        else break;
    }
    if(m>0)
        profit = profit+(p[i]*(m/w[i]));
    return profit;
}

void main()
{
    int i, size;
    float profit;
    printf("Enter the size of the array: ");//The number of items
    scanf("%d", &size);
    float p[size], w[size];
    //INPUTS OF PROFIT AND WEIGHT
    printf("Enter the profits: ");
    for(i=0; i<size; i++)
        scanf("%f", &p[i]);
    printf("Enter the weights: ");
    for(i=0; i<size; i++)
        scanf("%f", &w[i]);
    profit = knapsack(p,w, size);
    printf("\nThe maximum profit is: %f", profit);
}
