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

int n,m,cache[105][105][105];
char grid[105][105];

int cost(int rows1, int cols1, int rows2, int cols2)
{
	if(rows1==rows2 && cols1==cols2)
	{
		if(grid[rows1][cols1]=='*')
			return 1;
		return 0;
	}
	int ans=0;
	if(grid[rows1][cols1]=='*')
		ans++;
	if(grid[rows2][cols2]=='*')
		ans++;
	return ans;
}

int dp(int rows1, int cols1, int rows2)
{
	int cols2=(rows1+cols1)-rows2;
	if(rows1==n-1 && rows2==n-1 && cols1==m-1 && cols2==m-1)
	{
		return cost(rows1,cols1,rows2,cols2);
	}
	if(rows1>=n || cols1>=m || rows2>=n || cols2>=m)
	{
		return -1*oo;
	}
	if(cache[rows1][cols1][rows2]!=-1)
	{
		return cache[rows1][cols1][rows2];
	}
	int ans=-1*oo;
	if(grid[rows1][cols1+1]!='#' && grid[rows2+1][cols2]!='#')
		ans= max(ans, cost(rows1,cols1+1,rows2+1,cols2)+dp(rows1,cols1+1,rows2+1));
	if(grid[rows1][cols1+1]!='#' && grid[rows2][cols2+1]!='#')
		ans=max(ans,cost(rows1,cols1+1,rows2,cols2+1)+dp(rows1,cols1+1,rows2));
	if(grid[rows1+1][cols1]!='#' && grid[rows2][cols2+1]!='#')
		ans=max(ans, cost(rows1+1,cols1,rows2,cols2+1)+dp(rows1+1,cols1,rows2) );
	if(grid[rows1+1][cols1]!='#' && grid[rows2+1][cols2]!='#')
		ans=max(ans, cost(rows1+1,cols1,rows2+1,cols2)+dp(rows1+1,cols1,rows2+1));
	cache[rows1][cols1][rows2]=ans;
	return ans;
}

class Tourist {
public:
	void solve(istream& cin, ostream& cout) {
		int t;
		cin>>t;
		while(t--)
		{
			cin>>m>>n;
			memset(cache,-1, sizeof(cache));
			repi(i,0,n)
			{
				repi(j,0,m)
				{
					cin>>grid[i][j];
				}
			}
			int ans=0;
			if(grid[n-1][m-1]=='#' || grid[0][0]=='#'  )
				ans=-1*oo;
			if(grid[0][0]=='*')
				ans++;
			grid[0][0]='.';
			if(grid[n-1][m-1]=='*')
				ans++;
			grid[n-1][m-1]='.';
			ans+=dp(0,0,0);
			ans=max(ans,0);
			cout<<ans<<"\n";
		}
	}
};
