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
#define ff first
#define ss secondgr
#define endl "\n"

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;
int oo = 0x3f3f3f3f;

int n;
vector<vector<int> > tree;
int diameter=0;

int dfs(int curr, int parent)
{
	int maxx=0,smax=0;
	for(int i=0;i<tree[curr].size();i++)
	{
		if(tree[curr][i]!=parent)
		{
			int h=dfs(tree[curr][i],curr)+1;
			if(h>maxx)
			{
				smax=maxx;
				maxx=h;
			}
			else if(h>smax)
			{
				smax=h;
			}
		}
	}
	diameter=max(diameter,maxx+smax);
	return maxx;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	fastIO;

    int testcases;cin>>testcases;
    while(testcases--)
    {
    	cin>>n;
    	tree.clear();
    	tree.resize(n);
    	for(int i=0;i<n-1;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		tree[x].pb(y);tree[y].pb(x);
    	}
    	diameter=0;
    	dfs(0,-1);
    	cout<<(int)ceil(1.0*diameter/2)<<"\n";

    }

	return 0;
}
