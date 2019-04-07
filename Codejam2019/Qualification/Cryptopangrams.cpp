
#include <bits/stdc++.h>
using namespace std;

int arr[101];
set<int> primes;
map<int,int> m;

int __gcd(int a, int b)
{
    if (b == 0)
        return a;
    return __gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        primes.clear();
        m.clear();
        int n,l;
        cin>>n>>l;
        for(int i=0;i<l;i++)
        {
            cin>>arr[i];
        }

        int gcd=__gcd(arr[0],arr[1]);
        primes.insert(arr[0]/gcd);primes.insert(gcd);
        for(int i=1;i<l;i++)
        {
            primes.insert(arr[i]/gcd);
            gcd=arr[i]/gcd;
        }
        int k=0;
        for(int tmp:primes)
        {
            m.insert({tmp,k});
            k++;
        }
        gcd=__gcd(arr[0],arr[1]);
        cout<<"Case #"<<x<<": ";
        string str="";
        str+='A'+m[arr[0]/gcd];
        str+='A'+ m[gcd];
        for(int i=1;i<l;i++)
        {
            str+=('A'+ m[arr[i]/gcd]);
            gcd=arr[i]/gcd;
        }
        cout<<str<<"\n";
    }

}
