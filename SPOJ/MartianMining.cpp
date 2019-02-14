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

int n,m;
pair <int,int> p[501][501];
int dp[504][504];

int martian(int i,int j)
{
	int &ret=dp[i][j];
	int jac1=0,jac2=0;
	if(ret!=-1)
		return ret;
	if((i==0 && j!=0) || (i!=0 && j==0))
		return ret = 0;
	if(i==1 && j==1)
	{
		return ret = max(p[i-1][j-1].first,p[i-1][j-1].second);
	}
	for(int g=j-1;g>=0;g--)
	{
		jac1+=p[i-1][g].first;
	}
	for(int h=i-1;h>=0;h--)
	{
		jac2+=p[h][j-1].second;
	}
	int t1= jac1 + martian(i-1,j);
	int t2= jac2 + martian(i,j-1);
	return ret = max(t1,t2);
}

class MartianMining {
public:
	void solve(istream& cin, ostream& cout) {
		cin>>n>>m;
		while(n!=0 && m!=0)
		{
			memset(dp,-1,sizeof(dp));
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					int k;
					cin>>k;
					p[i][j].first=k;
				}
			}

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					int k;
					cin>>k;
					p[i][j].second=k;
				}
			}
			cout<<martian(n,m)<<endl;
			cin>>n>>m;
		}
	}
};
