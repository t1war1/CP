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
typedef pair<int,int> pii;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;
 
const int N=2e5+10;
int n,x,y,a,b,k;
int prices[N];
 
bool check(int mid)
{
    // trace(mid);
    int p=n;
    vector<int> arr(mid+1,0);
    int lcm=(a*b)/(__gcd(a,b));
    // trace(lcm);
    int pro=lcm;
    while(pro<=mid)
    {
        arr[pro]=prices[p]*(x+y);
        pro+=lcm;
        p--;
        // assert(p>0);
    }
    // cerr<<arrStr(arr,mid+1)<<endl;
    if(x>y)
    {
        swap(x,y);
        swap(a,b);
    }
    pro=b;
    while(pro<=mid)
    {
        if(arr[pro]!=0)
        {
            pro+=b;
            continue;
        }
        arr[pro]=prices[p]*(y);
        pro+=b;
        p--;
        // assert(p>0);
    }
    // cerr<<arrStr(arr,mid+1)<<endl;
    pro=a;
    while(pro<=mid)
    {
        if(arr[pro]!=0)
        {
            pro+=a;
            continue;
        }
        arr[pro]=prices[p]*(x);
        pro+=a;
        p--;
        // assert(p>0);
    }
    // cerr<<arrStr(arr,mid+1)<<endl;
    int sum=0;
    for(int i=1;i<=mid;i++)
    {
        sum+=arr[i];
    }
    // trace(sum);
    if(sum>=k)
    {
        return 1;
    }
    return 0;
 
}
 
int32_t main()
{
 
 
    fastIO;
 
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>prices[i];
            prices[i]/=100;
        }
        sort(prices+1,prices+n+1);
        cin>>x>>a>>y>>b>>k;
 
        int l=1,r=n,ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
 
    
    
    return 0;
}