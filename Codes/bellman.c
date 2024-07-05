#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int a[100][100];
int dist[100];
void bellmanford(int a[100][100],int n)
{
    int i,j,k,src,flag;
    printf("Enter source\n");
    scanf("%d",&src);
    for(i=0;i<n;i++)
        dist[i]=9999;
    dist[src]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)
                a[i][j]=9999;
        }
    }
    for(k=0;k<n;k++)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]<999)
                {
                    if((dist[i]+a[i][j])<dist[j])
                    {
                        dist[j]=dist[i]+a[i][j];
                        flag=1;
                    }
                }
            }
        }
        if(flag==0)
            break;
    }
    for(j=0;j<n;j++)
        printf("%d->%d\n",j,dist[j]);
}
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
int checkgraph(int a[100][100],int n)
{
    int i,j,sum;
    sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
                sum=sum+a[i][j];
        }
    }
    if(sum>0)
        return(1);
    else
        return(0);
}
main()
{
    int n,i,j;
    int flag;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("For %d vertice\n",i);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printmatrix(a,n);
    flag=checkgraph(a,n);
    if(flag==1)
       bellmanford(a,n);
    else
        printf("Negative graph\n");
}
