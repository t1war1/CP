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
#define fi first
#define se second

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;

int cache[100008][2],n;
vector<pair<int,int>>arr;

int binarysearch(int i,int j,int x)
{
    int l=i,r=j,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid].fi>=x)
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    if(ans==-1)
    {
            return j+1;
    }
    return ans;
}

int dp(int i,int taken)
{
    if(i<=0)
        return 0;
    if(cache[i][taken]!=-1)
        return cache[i][taken];

    if(taken==0) {
        cache[i][taken]= min(dp(i - 1, 0), dp(i - 1, 1)) + 1;
        return cache[i][taken];
    }

    int x=binarysearch(0,i-1,arr[i].fi-arr[i].se);
    if(x!=i)
    {
        cache[i][taken]=dp(x-1,1)+i-x;
        return cache[i][taken];
    }
    else{
        cache[i][taken]=dp(i-1,1);
        return cache[i][taken];
    }
}

class CChainReaction {
public:
	void solve(istream& cin, ostream& cout) {

        cin>>n;
        memset(cache,-1, sizeof(cache));
        repi(i,0,n)
        {
            int a,b;
            cin>>a>>b;
            arr.pb({a,b});
        }
        sort(arr.begin(),arr.end());
        cout<<min(dp(n-1,0),dp(n-1,1));
	}
};
