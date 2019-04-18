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

vector<vector<int> > graph;
bool visited[2001];
int gende[2001];
bool flag;
void dfs(int curr, int gender)
{
	visited[curr]=1;
	gende[curr]=gender;

	for(int i=0;i<graph[curr].size();i++)
	{
		if(visited[graph[curr][i]] && gender==gende[graph[curr][i]])
		{
			flag=1;
			return;
		}
		if(!visited[graph[curr][i]])
		dfs(graph[curr][i],gender^1);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	fastIO;

    int testcases;cin>>testcases;
    for(int t=1;t<=testcases;t++)
    {
    	int n,m;
    	cin>>n>>m;
    	graph.clear();
    	graph.resize(n+1);
    	memset(visited,0,sizeof(visited));
    	memset(gende,0,sizeof(gende));
    	for(int i=0;i<m;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		graph[x].pb(y);
    		graph[y].pb(x);
    	}

    	flag=0;
    	for(int i=1;i<=n;i++)
    	{
    		if(!visited[i])
    		{
    			dfs(i,0);
    		}
    	}

    	cout<<"Scenario #"<<t<<":\n";
    	if(flag)
    	{
    		cout<<"Suspicious bugs found!\n";
    	}
    	else
    	{
    		cout<<"No suspicious bugs found!\n";
    	}

    }

	return 0;
}
