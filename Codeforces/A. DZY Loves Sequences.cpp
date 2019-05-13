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
#define repi(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>b;i--)
#define mp make_pair
#define ll long long
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define ff first
#define ss second
#define endl "\n"

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;
int oo = 0x3f3f3f3f;

int n,arr[100005],l[100005],r[100005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;

    cin>>n;
    repi(i,0,n)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    int ans=1;
    r[n-1]=0;r[n-2]=1;
    l[0]=0;l[1]=1;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i-1])
            l[i+1]=l[i]+1;
        else
            l[i+1]=1;
    }
    for(int i=n-1;i>0;i--)
    {
        if(arr[i]<arr[i+1])
            r[i-1]=r[i]+1;
        else
            r[i-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        if( arr[i+1]-arr[i-1]>1)
            ans=max(ans,l[i]+r[i]+1);
        ans=max(ans,r[i]+1);
        ans=max(ans,l[i]+1);
    }
    cout<<ans<<endl;

    return 0;
}
