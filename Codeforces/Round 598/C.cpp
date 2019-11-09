#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m, d;
    cin>>n>>m>>d;
 
    int c[n];
    for(int i=0; i<n; i++)  
    {
        cin>>c[i];
    }
 
    int plank[n], last[m];
    memset(plank, -1, sizeof(plank));
    int ind=0;
 
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<c[i]; j++)
        {
            plank[ind]=i;
            ind++;
        }
        last[i]=ind-1;
    }
 
    int currPos=n, lastPlank=m-1;
    for(int i=n-1; i>=0; i--)
    {
        if((currPos-i)==d && plank[i]==-1)
        {
            int currPlank=lastPlank;
            if(currPlank<0)
            {
                cout<<"NO";
                return 0;
            }
            lastPlank--;
            
            for(int j=0; j<c[currPlank]; j++)
            {
                plank[last[currPlank]-j]=-1;
            }
            for(int j=0; j<c[currPlank]; j++)
            {
                plank[i-j]=currPlank;
            }
        }
        if(plank[i]!=-1)
        {
            currPos=i;
        }
    }
    cout<<"YES\n";
    for(int i=0; i<n; i++)
    {
        cout<<plank[i]+1<<" ";
    }
    
}