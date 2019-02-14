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

string str;
ll cache[350][350];

ll dp(int l,int r)
{
	if(l>r)
		return 0;
	if(l==r)
		return 1;
	if(cache[l][r]!=-1)
		return cache[l][r];
	ll ans=0;
	for(int i=l+1;i<=r;i++)
	{
		if(str[l]==str[i])
		{
			ans=(ans+(dp(l+1,i-1)%1000000000)*(dp(i,r)%1000000000))%1000000000;
		}
	}
	cache[l][r]=ans;
	return ans;
}

class ExploringPyramids {
public:
	void solve(istream& cin, ostream& cout) {
		while(cin>>str)
		{
			memset(cache,-1, sizeof(cache));
			cout<<dp(0,str.length()-1)<<endl;
		}
	}
};