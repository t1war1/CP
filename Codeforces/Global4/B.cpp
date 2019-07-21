/**
 *    author: Gaurav Tiwari, Delhi Technological University
**/        
#include <bits/stdc++.h>
#define mod 1000000007ll
#define mod2 100000009ll
#define mod3 998244353
#define pb push_back
#define fastIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define readi(x) scanf("%d",&x)
#define reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define PI 3.141592653589793238462643383
#define mp make_pair
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define ff first
#define ss second
#define endl "\n"
// #define int long long
 
using namespace std;
typedef pair<int,int> pii;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;
int oo = 0x3f3f3f3f;
 
int arr[1000005];
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
 
    fastIO;
    string str;
    cin>>str;
    arr[0]=0;
    long long ans=0;
    for(int i=1;i<str.size();i++)
    {
        if(str[i]=='v' && str[i-1]=='v')
        {
            arr[i]=arr[i-1]+1;
        }
        else
        {
            arr[i]=arr[i-1];
        }
    }
    long long x=0;
    for(int i=str.size()-2;i>=0;i--)
    {
        if(str[i]=='o')
        {
            ans+=x*arr[i];
        }
        else if(str[i]=='v' && str[i+1]=='v')
        {
            x++;
        }
    }
    cout<<ans;
    return 0;
}