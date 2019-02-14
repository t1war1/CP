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
int oo = (1 << 30) - 1;
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;

int n,m,p,a,b;
int tickets[10],graph[31][31];
double cache[31][(1<<8)];

double dp(int curr,int mask)
{
    if(curr==b)
    {
        return 0;
    }


    if(cache[curr][mask]!=-1)
    {
        return cache[curr][mask];
    }

    double ans=oo;
    for(int i=0;i<m;i++)
    {
        if(graph[curr][i]!=-1)
        {
            for(int j=0;j<n;j++)
            {
                if(!(mask&(1<<j)))
                {
                    ans=min(ans,((graph[curr][i]*1.0)/tickets[j]) + dp(i,mask|1<<j));
                }
            }
        }
    }
    cache[curr][mask]=ans;
    return ans;
}

class TravelingByStagecoach {
public:
	void solve(istream& cin, ostream& cout) {
        while(1)
        {
            cin>>n>>m>>p>>a>>b;
            if(!n && !m & !p && !a && !b)
                return;
            a--;b--;

            memset(graph, -1, sizeof(graph));
            repi(i,0,n)
                cin>>tickets[i];

            for(int i=0;i<p;i++)
            {
                int x,y,d;
                cin>>x>>y>>d;
                x--;y--;
                graph[x][y]=d;
                graph[y][x]=d;
            }
            for (int i = 0; i < m; i++)
            {
                fill(cache[i], cache[i] + (1 << n), -1);
            }

            double ans=dp(a,0);
            if(ans==oo)
            {
                cout<<"Impossible\n";
            }
            else{
                cout<<fixed<<ans<<"\n";
            }

        }

	}
};
