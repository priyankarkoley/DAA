#include <stdio.h>
#include <stdlib.h>
#define max 99999

void dijkstra(int n, int s, int cost[10][10], int dist[10])
{
    int i, v=s, count, min, visited[10];
    for(i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=cost[s][i];
    }
    visited[s]=1;
    dist[s]=0;
    for(count=1; count<=n; count++){
        min = max;
        for(i=1;i<=n;i++){
            if(dist[i]<min&&visited[i]==0){
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        for(i=1;i<=n;i++){
            if(dist[i]>dist[v]+cost[v][i] && visited[i]==0)
                dist[i]=dist[v]+cost[v][i];
        }
    }
}

int main()
{
    int i, j, n, s, cost[10][10], dist[10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        //printf("Enter %d th row: ", i);
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)cost[i][j]=max;
        }
    }
    printf("Enter the source vertex:");
    scanf("%d", &s);
    dijkstra(n,s,cost,dist);
    printf("The shortest paths are: ");
    for(i=1;i<=n;i++)
        if(s!=i)printf("\n%d ---> %d = %d",s,i,dist[i]);
}
