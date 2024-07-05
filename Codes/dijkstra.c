#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int a[100][100];
int dist[100];
int path[100];
int p[100];
int visited[100];
void printmatrix(int a[100][100],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}
int minimumindex(int dist[100],int n)
{
    int min=INT_MAX;
    int min_index;
    int i;
    for(i=0;i<n;i++)
    {
        if(dist[i]<min && visited[i]==0)
        {
            min=dist[i];
            min_index=i;
        }
    }
    return(min_index);
}
int minimum(int dist[100],int n)
{
    int min=INT_MAX;
    int min_index;
    int i;
    for(i=0;i<n;i++)
    {
        if(dist[i]<min && visited[i]==0)
        {
            min=dist[i];
        }
    }
    return(min);
}
void dijkstra(int a[100][100],int n,int v)
{
    int i,j,edge,m;
    visited[v]=1;
    p[0]=v;
    int k=1;
    for(j=0;j<n;j++)
    {
        dist[j]=a[v][j];
        path[j]=v;
    }
    dist[v]=0;
    for(i=0;i<n;i++)
    {
        edge=minimumindex(dist,n);
        m=minimum(dist,n);
        visited[edge]=1;
        for(j=0;j<n;j++)
        {
            if((a[edge][j]+m)<dist[j] && visited[j]==0)
            {
                dist[j]=a[edge][j]+m;
                path[j]=edge;
                p[k]=j;
                k++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d->%d->%d=%d\n",v,path[i],i,dist[i]);
    }
    for(i=0;i<k;i++)
    {
        printf("%d->",p[i]);
    }
}
main()
{
    int n,i,j,v;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter values of vertex %d\n",i);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                a[i][j]=999;
        }
    }
    printmatrix(a,n);
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("Enter the source vertex\n");
    scanf("%d",&v);
    dijkstra(a,n,v);
}
