#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int testcases;
    cin>>testcases;
 
    while(testcases--)
    {
        long long n, k;
        cin>>n>>k;
 
        string str;
        cin>>str;
        
        long long i=-1, j=0;
        while(j<n)
        {
            if(str[j]=='0')
            {
                i++;
                if(j-i<=k)
                {
                    k-=j-i;
                    str[j]='1';
                    j++;
                    str[i]='0';
                }
            }
            else
            {
                j++;
            }
        }
        cout<<str<<endl;
    }
}