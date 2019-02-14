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

map<ll,ll> m;
vector<pll> v;
ll cache[100005];

ll dp(int i)
{
	if(cache[i]!=-1)
		return cache[i];
	int x=i-1;
	while(x>=0 && v[x].fi+1==v[i].fi) x--;
	if(x==-1)
	{
		cache[i]=(ll)v[i].fi*v[i].se;
	}
	else
		cache[i]=(ll)v[i].fi*v[i].se+dp(x);
	if(i!=0)
		cache[i]=max(cache[i],dp(i-1));
	return cache[i];
}

class CBoredom {
public:
	void solve(istream& cin, ostream& cout) {
		m.clear();
		v.clear();
		memset(cache,-1, sizeof(cache));
		int n;
		cin>>n;
		repi(i,0,n)
		{
			ll t;
			cin>>t;
			m[t]++;
		}
		map<ll,ll>::iterator itr=m.begin();
		while(itr!=m.end())
		{
			v.pb({itr->fi,itr->se});
			itr++;
		}
		cout<<dp(v.size()-1);

	}
};
