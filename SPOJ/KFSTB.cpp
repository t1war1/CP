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
#define ss second
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

int c,b,s,t;
vector<vector<int> > graph;
bool visited[10005];
ll cache[10005];

ll dfs(int curr)
{
	if(cache[curr]!=-1)
	{
		return cache[curr];
	}
	if(curr==t)
	{
		cache[curr]=1;
		return 1;
	}
	ll ans=0;
	visited[curr]=1;
	for(int i=0;i<graph[curr].size();i++)
	{
		if(!visited[graph[curr][i]])
		{
			ans=(ans+dfs(graph[curr][i]))%mod;
		}
	}
	cache[curr]=ans%mod;
	visited[curr]=0;
	return cache[curr];	
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
    	cin>>c>>b>>s>>t;
    	graph.clear();graph.resize(c+1);
    	repi(i,0,b)
    	{
    		int x,y;
    		cin>>x>>y;
    		graph[x].pb(y);
    	}
    	for(int i=0;i<10005;i++)
    	{
    		cache[i]=-1;
    	}
    	memset(visited,0,sizeof(visited));
    	cout<<dfs(s)%mod<<endl;
    }
	return 0;
}
