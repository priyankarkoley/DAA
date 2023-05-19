#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 999999999

void dijkstra(int n, int s, int cost[10][10], int dist[10])
{

}

int main()
{
    int i, j, n, s, cost[10][10], dist[10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)cost[i][j]=INT_MAX;
        }
    }
    printf("Enter the source vertex:");
    scanf("%d", &s);
    dijkstra(n,s,cost,dist);
    printf("The shortest paths are: ");
    for(i=1;i<=n;i++)
        if(s!=i)printf("%d ---> %d = %d",s,i,dist[i]);
}
