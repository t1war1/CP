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
int oo = 0x3f3f3f3f;

vector<int> adj[100012];
int n;
ll cache[100002][2],times[100002][2];

ll dp(int curr, int parent, int parentCovered)
{
	if(cache[curr][parentCovered]!=-1)
		return cache[curr][parentCovered];

	ll ans=0;

	if(parentCovered)
	{
		ll ways=1;
		repi(i, 0, adj[curr].size()) {
			if (adj[curr][i] != parent) {
				ans += dp(adj[curr][i], curr, false);
				ways=((ways%10007)*(times[adj[curr][i]][0]%10007))%10007;
			}
		}
		times[curr][parentCovered]=ways;

		ll r=1;
		ways=1;
		repi(i,0, adj[curr].size()) {
			if (adj[curr][i] != parent) {
				r += dp(adj[curr][i], curr, true);
				ways=((ways%10007)*(times[adj[curr][i]][1]%10007))%10007;
			}
		}
		if(r<ans)
		{
			times[curr][parentCovered]=ways;
			ans=r;
		}
		else if(r==ans)
		{
			times[curr][parentCovered]=(times[curr][parentCovered] + ways%10007)%10007;
		}
	}
	else
	{
		ans=1;
		ll ways=1;
		repi(i,0, adj[curr].size()) {
			if (adj[curr][i] != parent) {
				ans += dp(adj[curr][i], curr, true);
				ways=((ways%10007)*(times[adj[curr][i]][1]%10007))%10007;
			}
		}
		times[curr][parentCovered]=ways;
	}
	cache[curr][parentCovered]=ans;
	return ans;
}

class ConJunctions {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
		{
			cin>>n;
			for(int i=0;i<100012;i++)
			{
				adj[i].clear();
			}
			repi(i,0,n-1)
			{
				int x,y;
				cin>>x>>y;
				adj[x].pb(y);
				adj[y].pb(x);
			}
			if(n==1){
			    cout<<1<<" "<<1<<"\n";
			    continue;
			}
			memset(cache,-1, sizeof(cache));
			memset(times,0, sizeof(times));
			ll ans=1,ways=1,r=0;
			repi(i,0,adj[1].size())
			{
				ans += dp(adj[1][i], 1, true);
				ways=((ways%10007)*(times[adj[1][i]][1]%10007))%10007;
			}
			times[1][0]=ways;
			ways=1;
			repi(i,0, adj[1].size())
			{
				r += dp(adj[1][i], 1, false);
				ways=((ways%10007)*(times[adj[1][i]][0]%10007))%10007;
			}
			if(r<ans)
			{
				times[1][0]=ways;
				ans=r;
			}
			else if(r==ans)
			{
				times[1][0]=(times[1][0] + ways%10007)%10007;
			}
			cout<<ans<<" "<<times[1][0]<<"\n";
		}
	}
};