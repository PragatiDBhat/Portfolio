#include<stdio.h>
int a[100][100];
int visited[100];
int queue[100];
int n;
int f=1;
int r=1;
void enqueue(int ele)
{
    queue[r]=ele;
    r++;
}
int dequeue()
{
    return(queue[f]);
}
void bfs(int v)
{
    int i,u;
    enqueue(v);
    visited[v]=1;
    while(f<r)
    {
        u=dequeue();
        printf("%d\t",u);
        f++;
        for(i=0;i<n;i++)
        {
            if(a[u][i]==1 && visited[i]==0)
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}
void printmatrix(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}
main()
{
    int i,j,v;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printmatrix(n);
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("Enter the starting vertice");
    scanf("%d",&v);
    bfs(v);
}
