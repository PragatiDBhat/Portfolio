#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
int a[100][100];
void floydwarshall(int a[100][100],int n)
{
  int i,j,k;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        if(a[i][j]==0&& i!=j)
        {
            a[i][j]=9999;
        }
    }
  }
  for(k=0;k<n;k++)
  {
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              if(((a[i][k]+a[k][j])<a[i][j])&& i!=j)
                    a[i][j]=a[i][k]+a[k][j];
          }
      }
  }
  printmatrix(a,n);
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
main()
{
    int n,i,j;
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
    printf("All source shortest path\n");
    floydwarshall(a,n);
}
