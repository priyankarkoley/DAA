#include <stdio.h>
#include <stdlib.h>

int n, d[20][20], a[20][20];

int getMin(int a, int b){return(a<=b)?a:b;}

//for weighted graph[0/weight/infinty in matrix]
void floyd(){
    int i,j,k;
    for (k=0;k<n;k++){
        for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                d[i][j]= getMin(d[i][j] , d[i][k]+d[k][j]);
            }
        }
    }
}

//for unweighted graph[0/1 in matrix]
void warshall(){
    int i,j,k;
    for (k=0;k<n;k++){
        for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                if((d[i][j]) || (d[i][k]&&d[k][j]))
                    d[i][j] = 1;
            }
        }
    }
}

int main()
{
    int i,j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix\n");
    for(i=0;i<n;i++){
        //printf("Enter %d th row: ", i+1);
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            d[i][j] = a[i][j];
        }
    }
    floyd();
    //-------------------PRINTING RESULT-------------------
    printf("\nThe all pair min-distances are: \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%d ",d[i][j]);
        printf("\n");
    }
}
/**
---------WEIGHTED INPUT---------
00 08 99 01
99 00 01 99
04 99 00 99
99 02 09 00

99-INFINITY HERE
ans of above--

0 3 4 1
5 0 1 6
4 7 0 5
7 2 3 0

**/
