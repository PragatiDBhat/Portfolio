#include<stdio.h>
#include<stdlib.h>
int a[10][10];
int un[100];
struct graph
{
    int src;
    int dest;
    int weight;
};
struct graph g[100];
void printmatrix(int a[10][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
           printf("%d\t",a[i][j]);
    printf("\n");
    }
}
void printedge(struct graph g[100])
{
    int i=0;
    while(g[i].weight)
    {
        printf("%d->(%d,%d)\n",g[i].weight,g[i].src,g[i].dest);
        i++;
    }
}
int count(struct graph g[100])
{
    int i=0;
    int c=0;
    while(g[i].weight)
    {
        c++;
        i++;
    }
    return(c);
}
int sort(struct graph g[100])
{
    int ts,td,tw,i,j;
    int m=count(g);
    for(i=0;i<m;i++)
    {
        for(j=0;j<m-i-1;j++)
        {
            if(g[j].weight>g[j+1].weight)
            {
                tw=g[j].weight;
                ts=g[j].src;
                td=g[j].dest;
                g[j].weight=g[j+1].weight;
                g[j].src=g[j+1].src;
                g[j].dest=g[j+1].dest;
                g[j+1].weight=tw;
                g[j+1].src=ts;
                g[j+1].dest=td;
            }
        }
    }
    return(m);
}
int find(int u)
{
      u=un[u];
    return(u);
}
int uni(int u,int v,int n)
{
    int i;
    if(u!=v)
    {
        for(i=0;i<n;i++)
        {
            if(un[i]==u)
                un[i]=v;
        }
        return(1);
    }
    else if(u==v)
        return(0);
}
void kruskal(struct graph g[100],int m,int n)
{
    int i,u,v,e;
    int weight=0;
    e=1;
    for(i=0;i<m,e<n;i++)
    {
        u=find(g[i].src);
        v=find(g[i].dest);
        if(uni(u,v,n))
        {
            printf("%d: %d->(%d,%d)\n",e,g[i].weight,g[i].src,g[i].dest);
            weight=weight+g[i].weight;
            e++;
        }
    }
    printf("\t\tMinimum weight=%d\n",weight);
}
main()
{
    int n,i,j,k,m;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        un[i]=i;
    for(i=0;i<n;i++)
    {
        printf("Enter the value for vertex %d\n",i);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printmatrix(a,n);
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                g[k].weight=a[i][j];
                g[k].src=i;
                g[k].dest=j;
                k++;
                a[j][i]=0;
            }
        }
    }
    printf("Before sorting\n");
    printedge(g);
    m=sort(g);
    printf("After sorting\n");
    printedge(g);
    printf("Minimum spanning tree:\n");
    kruskal(g,m,n);
}
