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

int cache[2][1005],n,m,x,y,countC[2][1000];
char mat[1001][1001];

int dp(int type, int i)
{
    if(i==0)
    {
        return 0;
    }
    if(cache[type][i]!=-1)
        return cache[type][i];
    int ans=n*m+1;
    for(int j=x;j<=y && j<=i;j++)
    {
        ans=min(ans,dp(1-type,i-j)+countC[1-type][i]-countC[1-type][i-j]);
    }

    cache[type][i]=ans;
    return cache[type][i];
}

class CBarcode {
public:
	void solve(istream& cin, ostream& cout) {
        memset(cache,-1, sizeof(cache));
        memset(countC,0, sizeof(countC));
        cin>>n>>m>>x>>y;

        repi(i,1,n+1)
        {
            repi(j,1,m+1)
            {
                cin>>mat[i][j];
                if(mat[i][j]=='#')
                    countC[0][j]++;
                else
                    countC[1][j]++;
            }
        }
        repi(i,1,m+1)
        {
            countC[0][i]+=countC[0][i-1];
            countC[1][i]+=countC[1][i-1];
        }
        cout<<min(dp(0,m),dp(1,m));
	}
};
