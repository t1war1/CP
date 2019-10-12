#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define all(v)  v.begin(),v.end()
#define int     long long
 
using namespace std;
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
 
    int k;
    cin>>k;
    int x=-1,y=-1;
    for(int n=5;n<=100;n++)
    {
        if(k%n==0)
        {
            if((k/n)>=5)
            {
                x=n;
                y=k/n;
                break;
            }
        }
    }
    if(x==-1)
    {
        cout<<-1;
        return 0;
    }
    if(x<y)
    {
        swap(x,y);
    }
    char arr[x][y];
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            arr[i][j]='a';
        }
    }
    char vowels[5]={'a','e','i','o','u'};
    int j=0;
    for(int k=0;k<5;k++)
    {
        int j=k;
        for(int i=0;i<x;i++)
        {   
            arr[i][j]=vowels[k];
            j=(j+1)%y;
        }
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<arr[i][j];
        }
        
    }
 
    return 0;
}