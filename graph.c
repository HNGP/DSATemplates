//countcomponents
#include<stdio.h>

void DFSUntil(int i,int *visited, int *G, int n)
{
    visited[i]=1;
    
    for(int j=0;j<n;j++)
       if(visited[j]==-1 && *((G+i*n)+j)==1)
            DFSUntil(j,visited,G,n);
}

int countComponents(int *visited, int *G,int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==-1)
        {
             DFSUntil(i,visited,G,n);
             count++;
        }
    }
    return count;
}
 
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&n);
    int G[n][n];
    int visited[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    }
       
    for(int i=0;i<n;i++)
        visited[i]=-1;

    int count = countComponents(visited, (int *)G,n);
    printf("%d",count);

    return 0;
}

//dfs
#include<stdio.h>

void DFSUntil(int i,int *visited, int *G, int n)
{
    printf("%d ", i);
    visited[i]=1;
    
    for(int j=0;j<n;j++)
       if(visited[j]==-1 && *((G+i*n)+j)==1)
            DFSUntil(j,visited,G,n);
}

void dfs(int *visited, int *G,int n)
{
    for(int i=0;i<n;i++)
        visited[i]=-1;
    
    DFSUntil(0,visited,G,n);
}
 
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&n);
    int G[n][n];
    int visited[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    }

    dfs(visited, (int *)G,n);

    return 0;
}

//bfs
#include<stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;



void bfs(int v)
{
    for(i = 1; i <= n; i++)
    if(a[v][i] && !visited[i])
    q[++r] = i;
    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}



void main()
{
    int v;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    for(i=1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    printf("\n Enter graph data in matrix form:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    bfs(v);
    printf("\n The node which are reachable are:\n");
    for(i=1; i <= n; i++)
    {
        if(visited[i])
            printf("%d\t", i);
        else
        {
            printf("\n Bfs is not possible. Not all nodes are reachable");
            break;
        }
    }
}



 
