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

int n;
ll arr[20],freqCache[16][1<<16],cache[16][1<<16];

ll dp(int prev,int mask)
{
	if(mask==(1<<n)-1)
	{
		freqCache[prev][mask]=1;
		return arr[prev];
	}
	
	if(cache[prev][mask]!=-1)
	{
		return cache[prev][mask];
	}
	
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!(mask&(1<<(i-1))))
		{
			ll val=dp(i,mask|(1<<(i-1)));
			if(prev==0)
			{
				val+=arr[i];
			}
			else{
				val+=abs(arr[prev]-arr[i]);
			}
			if(val>ans)
			{
				freqCache[prev][mask]=freqCache[i][mask|(1<<(i-1))];
				ans=val;
			}
			else if(val==ans){
				freqCache[prev][mask]+=freqCache[i][mask|(1<<(i-1))];
			}
		}
	}
	cache[prev][mask]=ans;
	return ans;
}

class Histogram {
public:
	void solve(istream& cin, ostream& cout) {
		while(1)
		{
			cin>>n;
			if(!n)
				break;
			memset(cache,-1, sizeof(cache));
			memset(freqCache,0, sizeof(cache));
			repi(i,1,n+1)
			{
				cin>>arr[i];
			}

			cout<<(dp(0,0)+(ll)2*n)<<" "<<freqCache[0][0]<<"\n";
		}
	}
};