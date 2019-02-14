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

int n,k,arr[10005],cache[10005][150];

int dp(int i,int rem)
{
	if(i==n)
	{
		if(rem==0)
			return 1;
		return 0;
	}
	if(cache[i][rem]!=-1)
		return cache[i][rem];

	if(dp(i+1,(rem+arr[i]%k)%k) || dp(i+1,(rem-arr[i]+k)%k))
	{
		cache[i][rem]=1;
		return 1;
	}
	cache[i][rem]=0;
	return 0;

}

class Divisibility {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
		{
			memset(cache,-1, sizeof(cache));
			cin>>n>>k;
			repi(i,0,n)
				cin>>arr[i];
			if(dp(1,arr[0]%k))
				cout<<"Divisible\n";
			else
				cout<<"Not divisible\n";
		}
	}
};
