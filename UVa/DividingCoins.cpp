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

int n,sum=0,arr[105],cache[105][1000000];

int dp(int i, int sumTillNow)
{
    if(i==n)
    {
        return abs(sum-2*sumTillNow);
    }
    if(cache[i][sumTillNow]!=-1)
        return cache[i][sumTillNow];
    int ans=min(dp(i+1,sumTillNow+arr[i]),dp(i+1,sumTillNow));
    cache[i][sumTillNow]=ans;
    return ans;
}

class DividingCoins {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
        {
		    memset(cache,-1, sizeof(cache));
		    sum=0;
		    cin>>n;
		    repi(i,0,n)
            {
		        cin>>arr[i];
		        sum+=arr[i];
            }
		    cout<<dp(0,0)<<endl;
        }
	}
};
