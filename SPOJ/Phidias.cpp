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

int t,W,H,n,w[205],h[205],cache[650][650];

int dp(int width, int height)
{
    if(cache[width][height]!=-1)
    {
        return cache[width][height];
    }
    int ans=width*height;
    for(int i=0;i<n;i++)
    {
        if(w[i]<=width && h[i]<=height)
        {
            ans=min(ans,dp(width-w[i],h[i]) + dp(width,height-h[i]));
            ans=min(ans,dp(w[i],height-h[i]) + dp(width-w[i],height));
        }
    }
    cache[width][height]=ans;
    return ans;
}

class Phidias {
public:
	void solve(istream& cin, ostream& cout) {
	    cin>>t;
        while(t--)
        {
            memset(cache,-1, sizeof(cache));
            cin>>W>>H>>n;
            repi(i,0,n)
                cin>>w[i]>>h[i];

            cout<<dp(W,H);
            cout<<"\n";
        }
	}
};
