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

using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
int oo = 0x3f3f3f3f;
class FGraphWithoutLongDirectedPaths {
    int n,m;
    vector<vector<int>> graph;
    set<int> visited;
    map<pii,int> edges;
    vector<pii> xx;
    map<int,bool> status;
    bool flag=0;
   
    void dfs(int curr, int parent, int last)
    {
        visited.insert(curr);
        status[curr]=!last;
        for(int i=0;i<graph[curr].size();i++)
        {
            if(graph[curr][i]==parent)
            {
                continue;
            }
            else{
                edges[{curr, graph[curr][i]}] = !last;
                edges[{graph[curr][i],curr}]=last;
                if(visited.find(graph[curr][i])==visited.end())
                {
                    dfs(graph[curr][i], curr, !last);
                } else{
                    if(status[curr]==status[graph[curr][i]])
                    {
                        flag=1;
                        return;
                    }
                }
            }
        }
    }


public:
	void solve(istream& cin, ostream& cout) {
		cin>>n>>m;
		graph.resize(n+1);
		repi(i,0,m)
        {
		    int x,y;
		    cin>>x>>y;
		    xx.pb({x,y});
		    graph[x].pb(y);graph[y].pb(x);
        }
        
        dfs(1,0,0);
		if(!flag) {
            cout << "YES" << "\n";
            for (int i = 0; i < m; i++) {
                cout << edges[xx[i]];
            }
        } else{
		    cout<<"NO";
		}

	}
};
