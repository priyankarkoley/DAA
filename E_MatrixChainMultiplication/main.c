#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 99999999

int dp[100][100];

int getMin(int a, int b)
{
    if(a<=b)return a;else return b;
}

int findMinMul(int* p, int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
        dp[i][j] = getMin(dp[i][j], findMinMul(p, i, k)+ findMinMul(p, k + 1, j)+ p[i - 1] * p[k] * p[j]);
    return dp[i][j];
}

int main()
{
    int i, j, arr[] = {3,2,4,2,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    printf("Minimum no of multiplication is: %d\n\n", findMinMul(arr, 1, n-1));
}
