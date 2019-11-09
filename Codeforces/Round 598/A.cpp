#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int a, b, n, s;
        cin>>a>>b>>n>>s;
        int ncoins=min(s/n,a);
        s-=ncoins*n;
        if(s<=b)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }
    }
 
}