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

class CVacations {
    int n;
    int dp[105][5],arr[105];
    int help(int i, int lastActivity)
    {
        if(i==n)
            return 0;
        if(dp[i][lastActivity]!=-1)
            return dp[i][lastActivity];
        
        int ans=n;
        if(arr[i]==0)
        {
            ans=min(ans,1+help(i+1,0));
        }
        if(arr[i]==1)
        {
            if(lastActivity!=1)
                ans=min(ans,help(i+1,1));
            if(lastActivity!=0)
                ans=min(ans,1+help(i+1,0));
        }
        if(arr[i]==2)
        {
            if(lastActivity!=2)
                ans=min(ans,help(i+1,2));
            if(lastActivity!=0)
                ans=min(ans,1+help(i+1,0));
        }
        if(arr[i]==3)
        {
            if(lastActivity!=1)
                ans=min(ans,help(i+1,1));
            if(lastActivity!=2)
                ans=min(ans,help(i+1,2));
            if(lastActivity!=0)
                ans=min(ans,1+help(i+1,0));
        }
        
        dp[i][lastActivity]=ans;
        return ans;
    }
public:

	void solve(istream& cin, ostream& cout) {
        for(int i=0;i<105;i++)
            memset(dp[i],-1, sizeof(dp)/ sizeof(dp[0]));
        cin>>n;
        repi(i,0,n)
        {
            cin>>arr[i];
        }
        cout<<help(0,4);
	}
};
