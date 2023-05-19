#include <stdio.h>
#include <stdlib.h>

int n, adj[20][20], visited[20];
void dfs(int s){
    int i;
    for(i=0;i<n;i++){
        if(adj[s][i]!=0&&visited[i]==0){
            visited[i] = 1;
            printf(" ---> %d", i);
            dfs(i);
        }
    }
}

int main()
{
    int i,j,s;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix\n");
    for(i=0;i<n;i++){
        //printf("Enter %d th row: ", i+1);
        for(j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the source vertex:");
    scanf("%d", &s);
    for(i=0;i<n;i++)
        visited[i]=0;
    visited[s]=1;
    printf("%d",s);
    dfs(s);
}
/**
---------INPUT---------
0 1 0 1 0 0 0 0 0 0
1 0 1 0 1 0 1 1 0 0
0 1 0 1 0 0 0 0 1 1
1 0 1 0 0 0 0 0 0 0
0 1 0 0 0 1 1 1 0 0
0 0 0 0 1 0 0 0 0 0
0 1 0 0 1 0 0 1 0 0
0 1 0 0 1 0 1 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
**/
