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

vector<int> adj[100002];
int n;
int dp[100002][2];

int go(int cur, int parent, bool isParentCovered) {
    if(dp[cur][isParentCovered] != -1) return dp[cur][isParentCovered];
    int &ret = dp[cur][isParentCovered];
    ret = 0;
    int i, r;
    if(isParentCovered) {
        repi(i, 0, adj[cur].size()) if(adj[cur][i] != parent) {
            ret += go(adj[cur][i], cur, false);
        }

        r = 1;
        repi(i,0, adj[cur].size()) if(adj[cur][i] != parent) {
            r += go(adj[cur][i], cur, true) ;
        }
        ret = min(ret, r);
    }
    else {
        ret = 1;
        repi(i,0, adj[cur].size()) if(adj[cur][i] != parent) {
            ret += go(adj[cur][i], cur, true) ;
        }
    }
    return ret;
}

class VertexCover {
public:
	void solve(istream& cin, ostream& cout) {
        int i,u,v;
        int r1,r2;
            cin>>n;
            for(i=1;i<=n;i++) adj[i].clear();
            for(i=1;i<n;i++) {
                scanf(" %d %d",&u,&v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            memset(dp,-1,sizeof(dp));
            r1 = 1;
            repi(i,0,adj[1].size()) r1 += go(adj[1][i], 1, true);
            r2 = 0;
            repi(i,0, adj[1].size()) r2 += go(adj[1][i], 1, false);
            printf("%d\n",min(r1,r2));

	}
};
