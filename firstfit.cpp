
#include<iostream>
#include<vector>
using namespace std;
void firstFit(vector<int>& blockSize,int b, vector<int>& processSize,int p)
{
    vector<int>allocation(p,-1);
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<b; j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }
        }
    }
    cout<<"Process no \t Process Size \t bBlock No\n";
    for(int i=0; i<p; i++)
    {
        cout<<i+1<<" \t \t "<<processSize[i]<<" \t \t ";
        if(allocation[i]!=-1)
            cout<<allocation[i]+1<<endl;
        else
            cout<<"Not Allocated"<<endl;
    }
}
int main()
{
    int b,p;
    cout<<"Enter number of blocks(b) and number of processes(p)"<<endl;
    cin>>b>>p;
    vector<int> blockSize(b);
    vector<int> processSize(p);
    cout<<"Enter Block size"<<endl;
    for(int i=0; i<b; i++)
    {
        cin>>blockSize[i];
    }
    cout<<"Enter Process size"<<endl;
    for(int i=0; i<p; i++)
    {
        cin>>processSize[i];
    }
    firstFit(blockSize,b,processSize,p);
}
