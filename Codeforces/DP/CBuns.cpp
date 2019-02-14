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

int n,m,c0,d0;
int a[15],b[15],c[15],d[15],cache[15][1005];


int dp(int ind, int doughLeft)
{
    if(doughLeft<=0 || ind>=m)
        return 0;

    if(cache[ind+1][doughLeft]!=-1)
        return cache[ind+1][doughLeft];

    if(ind==-1){
        int ans=INT_MIN;
        for(int i=0;i<=(doughLeft/c0);i++)
        {
            ans=max(ans,d0*i+dp(ind+1,doughLeft-i*c0));
        }
        cache[ind+1][doughLeft]=ans;
        return ans;
    }
    else{
        int ans=INT_MIN;
        for(int i=0;i<=min(doughLeft/c[ind],a[ind]/b[ind]);i++)
        {
            ans=max(ans,i*d[ind]+dp(ind+1,doughLeft-i*c[ind]));
        }
        cache[ind+1][doughLeft]=ans;
        return ans;
    }
}

class CBuns {
public:
	void solve(istream& cin, ostream& cout) {
	    memset(cache,-1, sizeof(cache));
        cin>>n>>m>>c0>>d0;
        repi(i,0,m)
        {
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        }

        cout<<dp(-1,n);

	}
};
