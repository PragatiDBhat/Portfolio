/*#include<iostream>
using namespace std;
int main()
{
    long int n,k,t,a,b,x;
    cin>>n>>k;
    long int arr[n];
    for(long int i=0;i<n;i++)
        cin>>arr[i];
    while(k--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>a>>b>>x;
            for(long int i=a-1;i<b;i++)
            {
                arr[i]+=x;
            }
        }
        else if(t==2)
        {
            cin>>a>>b>>x;
            for(long int i=a-1;i<b;i++)
            {
                arr[i]=x;
            }
        }
        else
        {
            cin>>a>>b;
            long int sum=0;
            for(long int i=a-1;i<b;i++)
            {
                sum+=arr[i];
            }
        cout<<sum<<endl;
        }
    }
    return 0;
}*/
#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;
const int MAX=2e5;
int n,q,t,a,b, l[4*MAX],h[4*MAX];
ll x,del[4*MAX], as[4*MAX], sum[4*MAX];
void pull(int i);
void push(int i);
void build(int i, int left, int right);
int len(int i);
void assignment(int i, ll v);
void assignment(int i,int left, int right, ll v);
void increment(int i,int left, int right, ll v);
void increment (int i, ll v);
ll query( int i, int left, int right);
int main()
{
    cin>>n>>q;
    build(1,1,n);
    while(q--)
    {
        cin>>t>>a>>b;
        if(t==1)
        {
            cin>>x;
            increment(1,a,b,x);
        }
        else if(t==2)
        {
            cin>>x;
            assignment(1,a,b,x);
        }
        else{
            cout<<query(1,a,b)<<endl;
        }
    }
}
void pull(int i)
{
    sum[i]=sum[2*i]+sum[2*i+1];
}
void build(int i, int left, int right)
{
    l[i]=left;
    h[i]=right;
    if(left==right)
    {
        cin>>sum[i];
        return;
    }
    int m=(left+right)/2;
    build(2*i,left,m);
    build(2*i+1,m+1,right);
    pull(i);
}
void push(int i)
{
    if(as[i])
    {
        assignment(2*i,as[i]);
        assignment(2*i+1,as[i]);
        as[i]=0;
    }
    if(del[i])
    {
        assignment(2*i,del[i]);
        assignment(2*i+1,del[i]);
        del[i]=0;
    }
}
int len(int i)
{
    return h[i]-l[i]+1;
}
void assignment(int i, ll v)
{
    as[i]=v;
    del[i]=0;
    sum[i]=len(i)*v;
}
void assignment(int i,int left, int right, ll v)
{
    if(left>h[i] || right<l[i])
        return;
    if(left<=l[i] && right>=h[i])
    {

        assignment(i,v);
        return;
    }
    push(i);
    assignment(2*i,left,right,v);
    assignment(2*i+1,left,right,v);
    pull(i);
}



void increment(int i,int left, int right, ll v)
{
    if(left>h[i] || right<l[i])
        return;
    if(left<=l[i] && right>=h[i])
    {
        increment(i,v);
        return;
    }
    push(i);
    increment(2*i,left,right,v);
    increment(2*i+1,left,right,v);
    pull(i);
}
void increment (int i, ll v)
{
    del[i]+=v;
    sum[i]+=len(i)*v;
}
ll query( int i, int left, int right)
{
    if(left>h[i] || right<l[i])
        return 0;
    if(left<=l[i] || right<=h[i])
        return sum[i];
    push(i);
    ll leftsum=query(2*i, left,right);
    ll rightsum=query(2*i+1,left,right);
    pull(i);
    return leftsum+rightsum;
}
