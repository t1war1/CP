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

int n,q,c;
map<pair<int,int>,vector<int>> m;
int cache[105][105][15];


int dp(int x, int y, int brightness)
{
	if(x==0 || y==0)
	{
		cache[x][y][brightness]=0;
		return 0;
	}

	if(cache[x][y][brightness]!=-1)
		return cache[x][y][brightness];
	cache[x][y][brightness]=dp(x-1,y,brightness)+dp(x,y-1,brightness)-dp(x-1,y-1,brightness);
	if(m.find({x,y})!=m.end())
	{
		vector<int> bs=m[{x,y}];
		for(int i:bs)
			if(i==brightness)
				cache[x][y][brightness]++;
	}

	return cache[x][y][brightness];
}


class CStarSky {
public:
	void solve(istream& cin, ostream& cout) {
		m.clear();
		memset(cache,-1, sizeof(cache));
	    cin>>n>>q>>c;
		for(int i=0;i<n;i++)
		{
			int x,y,s;
			cin>>x>>y>>s;
			m[{x,y}].pb(s);
		}

		for(int i=0;i<=c;i++){
			dp(100,100,i);
		}

		for(int i=0;i<q;i++)
		{
			int t,x1,y1,x2,y2;
			cin>>t>>x1>>y1>>x2>>y2;
			int sum=0;
			for(int j=0;j<=c;j++)
			{
				sum+=((j+t)%(c+1))
						*(cache[x2][y2][j]+cache[x1-1][y1-1][j]-cache[x1-1][y2][j]-cache[x2][y1-1][j]);
			}
			cout<<sum<<"\n";
		}
		
	}
};
