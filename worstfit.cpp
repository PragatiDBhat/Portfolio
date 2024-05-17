#include<iostream>
#include<vector>
using namespace std;
void worstFit(vector<int>& blockSize,int b, vector<int>& processSize,int p)
{
    vector<int>allocation(p,-1);
    for(int i=0; i<p; i++)
    {
        int worstIndex=-1;
        for(int j=0; j<b; j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                if(worstIndex==-1 || blockSize[worstIndex]<blockSize[j])
                {
                    worstIndex=j;
                }
            }
        }
        if(worstIndex!=-1)
        {
            allocation[i]=worstIndex;
            blockSize[worstIndex]-=processSize[i];
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
    worstFit(blockSize,b,processSize,p);
}
