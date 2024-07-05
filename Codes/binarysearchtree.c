#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
    int data;
    struct node *rnode;
    struct node *lnode;
};
struct node * getnode(int key)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->rnode=NULL;
    newnode->lnode=NULL;
    return(newnode);
}
struct node* createtree(struct node*root,int key)
{
    if(root==NULL)
    {
        root=getnode(key);
        return(root);
    }
    if(root->data < key)
    {
        root->rnode=createtree(root->rnode,key);
        return(root);
    }
    else if(root->data > key)
    {
        root->lnode=createtree(root->lnode,key);
        return(root);
    }
}
void left(struct node*root)
{
    if(root==NULL)
        return;
    else
    {
        left(root->lnode);
        printf("%d\t",root->data);
    }
}
void right(struct node*root)
{
    if(root==NULL)
        return;
    else
    {
        printf("%d\t",root->data);
        right(root->rnode);
    }
}
void displaytopview(struct node*root)
{
    if(root==NULL)
        return;
    left(root);
    right(root->rnode);
    printf("\n");
}
void min(struct node *root)
{
    do
    {
        root=root->lnode;
    }
    while(root->lnode !=NULL);
    printf("Minimum=%d\n",root->data);
}
void max(struct node *root)
{
    do
    {
        root=root->rnode;
    }
    while(root->rnode !=NULL);
    printf("Maximum=%d\n",root->data);
}
void displaylevel(struct node * root,int current,int key)
{
    if(root==NULL)
        return;
    if(root->data == key)
    {
        printf("Level is %d\n",current);
    }
    if(root->data < key)
          displaylevel(root->rnode,current+1,key);
    else if(root->data > key)
          displaylevel(root->lnode,current+1,key);
}
void displayleafnodes(struct node *root)
{
    if(root==NULL)
        return;
    if(root->rnode==NULL && root->lnode==NULL)
    {
        printf("%d\n",root->data);
    }
    displayleafnodes(root->lnode);
    displayleafnodes(root->rnode);
}

void displaysubtree(struct node *root,int key)
{
    if(root==NULL)
        return;
    if(root->data==key)
    {
        min(root);
        max(root);
    }
    if(root->data < key)
        displaysubtree(root->rnode,key);
    else
        displaysubtree(root->lnode,key);
}
void path(struct node*root,int key)
{
    if(root==NULL)
        return;
    if(root->data==key)
        return;
    if(root->data < key)
    {
        printf("%d->",root->data);
        path(root->rnode,key);
    }
    else if(root->data > key)
    {
        printf("%d->",root->data);
        path(root->lnode,key);
    }
}
int minimum(struct node*root)
{
    int c=1;
    while(root->lnode !=NULL)
    {
        root=root->lnode;
        c++;
    }
    return(c);
}
int maximum(struct node*root)
{
    int c=1;
    while(root->rnode !=NULL)
    {
        root=root->rnode;
        c++;
    }
    return(c);
}
void display(struct node *root)
{
    if(root==NULL)
        return;
    display(root->lnode);
    printf("%d\n",root->data);
    display(root->rnode);
}
void largestsubtree(struct node*root)
{
    int l,r;
    if(root==NULL)
        return;
    else
    {
        l=minimum(root);
        r=maximum(root);
        if(l>=r)
            display(root->lnode);
        else
            display(root->rnode);
    }
}
void common(int m[100],int n[100])
{
    int i,j;
    for(i=0;m[i];i++)
    {
        for(j=0;n[j];j++)
        {
            if(m[i]==n[j])
                printf("%d\t",m[i]);
        }
    }
}
void pathnew(int m[100],int a,struct node *root,int i)
{
    if(root==NULL)
        return;
    if(root->data==a)
        return;
    if(root->data < a)
    {
        m[i]=root->data;
        i++;
        pathnew(m,a,root->rnode,i);
    }
    else if(root->data > a)
    {
        m[i]=root->data;
        i++;
        pathnew(m,a,root->lnode,i);
    }
}
int lessorequal(struct node*root,int n)
{
    if(root==NULL)
        return(0);
    else if(n <= root->data)
        return(lessorequal(root->lnode,n));
    else
    {
        int t=lessorequal(root->rnode,n);
        return t>root->data ? t:root->data;
    }
    return(0);
}
void add(struct node *root,int *sum)
{
    if(root==NULL)
        return;
    add(root->rnode,sum);
    *sum=*sum+root->data;
    root->data=*sum;
    add(root->lnode,sum);
}
void addition(struct node *root)
{
    int sum=0;
    add(root,&sum);
}
int main()
{
    int ch,key,n,a,b;
    int m[100];
    int p[100];
    int i;
    struct node *root,*temp;
    temp=NULL;
    int high,low;
    root=NULL;
    while(1)
    {
        printf("1.Insert\n2.Find maximum\n3.Display top view\n4.Level of given element\n");
        printf("5.Print leaf nodes\n6.Print max and min of given subtree\n7.Largest subtree\n");
        printf("8.Addition\n9.Greatest number in tree which is lesser then or equal to n\n");
        printf("10.Path of given node\n11.Common ancestors\n");
        printf("0.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter key to be inserted\n");
                    scanf("%d",&key);
                    root=createtree(root,key);
                    break;
            case 2:max(root);
                    break;
            case 3:displaytopview(root);
                    break;
            case 4:printf("Enter key to be searched\n");
                    scanf("%d",&key);
                    displaylevel(root,1,key);
                    break;
            case 5:displayleafnodes(root);
                    break;
            case 6:printf("Enter root for the sub tree\n");
                   scanf("%d",&key);
                   displaysubtree(root,key);
                   break;
            case 7:largestsubtree(root);
                    break;
            case 8:addition(root);
                   display(root);
                   break;
            case 9:printf("Enter n\n");
                   scanf("%d",&n);
                   a=lessorequal(root,n);
                   printf("%d\n",a);
                   break;
            case 10:printf("Enter key\n");
                    scanf("%d",&key);
                    path(root,key);
                    printf("\n");
                    break;
            case 11:printf("Enter the numbers\n");
                    scanf("%d%d",&a,&b);
                    pathnew(m,a,root,0);
                    pathnew(p,b,root,0);
                    common(m,p);
                    printf("\n");
                    break;
            case 0:exit(0);
                   break;

        }
    }
}


