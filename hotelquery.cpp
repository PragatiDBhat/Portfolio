#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN=2e5+1;
int n,q,ans,k,a[MAXN], l[4*MAXN],h[4*MAXN],mx[4*MAXN],mp[4*MAXN];
void pull( int i)
{
    mx[i]=(a[mx[2*i]]>=a[mx[2*i+1]] ? mx[2*i] : mx[2*i+1]);
}
void build(int i, int left, int right)
{
    l[i]=left;
    h[i]=right;
    if(left==right)
    {
        mp[left]=i;
        mx[i]=left;
        return;
    }
    int m=(left+right)/2;
    build(2*i,left,m);
    build(2*i+1,m+1,right);
    pull(i);
}
void update(int i, int v)
{
    a[i]-=v;
    i=mp[i];
    i>>=1;
    while(i>0)
    {
        pull(i);
        i>>=1;
    }
}
int findroom(int i,int val)
{
    if(l[i] == h[i])  return l[i];
    return (a[mx[2*i]] >= val ? findroom(2*i, val) : findroom(2*i+1, val));
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        cin>>k;
        if(a[mx[1]]<k)
            ans=0;
        else
            ans=findroom(1,k);
        if(ans)
            update(ans,k);
        cout<<ans<<endl;
    }
    return 0;
}
