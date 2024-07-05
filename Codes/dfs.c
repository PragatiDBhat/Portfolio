#include<stdio.h>
int a[100][100];
int visited[100];
int st[100];
int n;
int top=-1;
void push(int st[100],int ele)
{
    top=top+1;
    st[top]=ele;
}
int pop(int st[100])
{
    return(st[top]);
}
void dfs(int a[100][100],int n,int v)
{
    int i;
    visited[v]=1;
    push(st,v);
    for(i=1;i<=n;i++)
    {
        if(a[v][i]==1 && visited[i]==0)
        {
            dfs(a,n,i);
        }
    }
}
void printmatrix(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}
main()
{
    int i,j,v,ele;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("For %d\n",i);
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printmatrix(n);
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter the starting vertice");
    scanf("%d",&v);
    dfs(a,n,v);
    while(top!=-1)
    {
        ele=pop(st);
        top--;
        printf("%d\t",ele);
    }
}
