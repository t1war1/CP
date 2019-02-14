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

	int n1,n2,k1,k2,mod4=100000000;
	ll cache[105][105][3];

	ll dp(int n1,int n2,int prev)
	{
		if(n1==0 && n2==0)
			return 1;

		if(cache[n1][n2][prev]!=-1)
			return cache[n1][n2][prev];

		ll ans=0;
		if(prev!=0) {
			for (int i = 1; i <= min(k1, n1); i++) {
				ans = (ans % mod4 + dp(n1 - i, n2, 0) % mod4) % mod4;
			}
		}

		if(prev!=1){
			for(int i=1;i<=min(k2,n2);i++){
				ans=( ans%mod4 + dp(n1,n2-i,1)%mod4 )%mod4;
			}
		}
		cache[n1][n2][prev]=ans%mod4;

		return cache[n1][n2][prev];


	}

	class DCaesarsLegions {
	public:
		void solve(istream& cin, ostream& cout) {
			memset(cache,-1, sizeof(cache));
			cin>>n1>>n2>>k1>>k2;
			cout<<dp(n1,n2,2);
		}
	};
