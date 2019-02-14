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

int n,k,d;
ll cache[2][200];

ll dp(int found,int weight)
{

	if(weight<0 || (weight==0 && !found))
	{
		return 0;
	}
	if(weight==0 && found){
		return 1;
	}
	if(cache[found][weight]!=-1)
		return cache[found][weight];

	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		if(i>=d)
			ans=(ans%mod+dp(1,weight-i)%mod)%mod;
		else
			ans=(ans%mod+dp(found,weight-i)%mod)%mod;
	}
	cache[found][weight]=ans;
	return ans%mod;
}

class CKTree {
public:
	void solve(istream& cin, ostream& cout) {
		memset(cache,-1, sizeof(cache));
	    cin>>n>>k>>d;
	    int w=n;
		cout<<dp(0,w);
	}
};