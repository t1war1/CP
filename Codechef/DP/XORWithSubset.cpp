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

int t,n,k,arr[1005];
bool cache[1005][1030];

class XORWithSubset {
public:
	void solve(istream& cin, ostream& cout) {

		cin>>t;
		while(t--){
			cin>>n>>k;
			repi(i,0,n)
			{
				cin>>arr[i];
			}
			memset(cache,0, sizeof(cache));
			cache[0][0]=1;

			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<20;j++)
				{
					int x=j^arr[i-1];
					cache[i][j]=cache[i-1][j]|cache[i-1][x];
				}
			}
			int ans=0;
			for(int i=0;i<1024;i++)
			{
				ans=max(ans,cache[n][i]*(i^k));
			}
			cout<<ans<<"\n";
		}
	}
};
