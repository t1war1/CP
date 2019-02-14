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

int n,x[100001],h[100001],dp[100001][3];

class CWoodcutters {
    int help(int i,int move)
    {
        if(i==0 && move==0) return 0;
        if(i==0 && move==1) return 1;
        if(i==0 && move==2)
        {
            if((n==1 )|| (x[0]+h[0])<x[1])
                return 1;
            return 0;
        }
        if(dp[i][move]!=-1)
            return dp[i][move];

        if(move==0)
            dp[i][move]=max({help(i-1,0),help(i-1,1),help(i-1,2)});
        else if(move==1)
        {
            dp[i][move]=help(i-1,move);
            if(x[i]-h[i]>x[i-1])
                dp[i][move]=max(help(i-1,0),help(i-1,1))+1;
            if(x[i]-h[i]>x[i-1]+h[i-1])
                dp[i][move]=max(dp[i][move],help(i-1,2)+1);
        }
        else if(move==2)
        {
            if(i==n-1)
            {
                dp[i][move]=max({help(i-1,0),help(i-1,1),help(i-1,2)})+1;
            }
            if(x[i]+h[i]<x[i+1])
            {
                dp[i][move]=max({help(i-1,0),help(i-1,1),help(i-1,2)})+1;
            }
            
        }

        return dp[i][move];
    }

public:
	void solve(istream& cin, ostream& cout) {
        for(int i=0;i<100001;i++)
            for(int j=0;j<3;j++)
                dp[i][j]=-1;
        cin>>n;
        repi(i,0,n)
            cin>>x[i]>>h[i];

        cout<<max({help(n-1,0),help(n-1,1),help(n-1,2)});
	}
};
